#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <assert.h>
#include "file_reader.h"
#include "tested_declarations.h"
#include "rdebug.h"


#define BYTES_PER_SECTOR 512
#define NULLERR(err) perror("err");\
                    return NULL;

#define ERR1(err) perror("err"); \
                    return -1;

#define morei volume->more_info
#define pmorei pvolume->more_info

#define READ_SECTOR t = disk_read(stream->morei->disk, p_current_sector, temp, 1);\
                        if (t == -1) {\
                        free(temp);\
                        ERR1(ERANGE)\
                        }


struct disk_t *disk_open_from_file(const char *volume_file_name) {
    if (volume_file_name == NULL) {
        NULLERR(EFAULT)
    }
    disk_t *disk = (disk_t *) calloc(1, sizeof(disk_t));
    if (disk == NULL) {
        NULLERR(ENOMEM)
    }

    disk->p_disk = fopen(volume_file_name, "rb");
    if (disk->p_disk == NULL) {
        free(disk);
        NULLERR(ENOENT)
    }

    return disk;
}

int disk_read(disk_t *pdisk, int32_t first_sector, void *buffer, int32_t sectors_to_read) {
    fseek(pdisk->p_disk, first_sector * BYTES_PER_SECTOR, SEEK_SET);
    int res = fread(buffer, BYTES_PER_SECTOR, sectors_to_read, pdisk->p_disk);
    if (res != sectors_to_read) {
        perror("ERANGE");
        return -1;
    }
    return res;
}

int disk_close(disk_t *pdisk) {
    if (pdisk == NULL) {
        perror("EFAULT");
        return -1;
    }
    fclose(pdisk->p_disk);
    free(pdisk);
    return 0;
}

int validate(volume_t *volume) {
    if (volume == NULL) {
        return 1;
    }

    if (volume->magic != 0xAA55 ||
        volume->bytes_per_sector != BYTES_PER_SECTOR ||
        volume->reserved_sectors < 1 ||
        volume->fat_count < 1 || volume->fat_count > 2 ||
        volume->root_dir_capacity * sizeof(root_t) % volume->bytes_per_sector != 0 ||
        volume->sectors_per_fat < 1) {
        return 1;
    }
    if (volume->logical_sectors16 != 0) {
        if (volume->logical_sectors32 != 0)
            return 1;
    } else if (volume->logical_sectors32 != 0) {
        if (volume->logical_sectors16 != 0)
            return 1;
        if (volume->logical_sectors32 <= 65535)
            return 1;
    } else {
        return 1;
    }
    uint8_t spc = volume->sectors_per_cluster;
    if (spc != 1)
        if (spc != 2)
            if (spc != 4)
                if (spc != 8)
                    if (spc != 16)
                        if (spc != 32)
                            if (spc != 64)
                                if (spc != 128)
                                    return 1;
    return 0;
}

struct volume_t *fat_open(struct disk_t *pdisk, uint32_t first_sector) {
    if (pdisk == NULL || pdisk->p_disk == NULL) {
        NULLERR(EFAULT)
    }
    volume_t *volume = (volume_t *) calloc(1, sizeof(volume_t));
    if (volume == NULL) {
        NULLERR(ENOMEM)
    }
    int blocks_read = disk_read(pdisk, (int) first_sector, volume, 1);
    if (blocks_read == -1) {
        free(volume);
        NULLERR(ERANGE)
    }

    if (validate(volume)) {
        free(volume);
        NULLERR(EINVAL)
    }
    uint16_t *fat1 = (uint16_t *) calloc(volume->sectors_per_fat, volume->bytes_per_sector);
    if (fat1 == NULL) {
        free(volume);
        NULLERR(ENOMEM)
    }
    uint16_t *fat2 = (uint16_t *) calloc(volume->sectors_per_fat, volume->bytes_per_sector);
    if (fat2 == NULL) {
        free(volume);
        free(fat1);
        NULLERR(ENOMEM)
    }
    fseek(pdisk->p_disk, volume->bytes_per_sector * volume->reserved_sectors, SEEK_SET);
    int t = fread(fat1, volume->bytes_per_sector, volume->sectors_per_fat, pdisk->p_disk);
    if (t != volume->sectors_per_fat) {
        free(volume);
        free(fat1);
        free(fat2);
        NULLERR(ERANGE)
    }
    t = fread(fat2, volume->bytes_per_sector, volume->sectors_per_fat, pdisk->p_disk);
    if (t != volume->sectors_per_fat) {
        free(volume);
        free(fat1);
        free(fat2);
        NULLERR(ERANGE)
    }
    t = memcmp(fat1, fat2, volume->sectors_per_fat * volume->bytes_per_sector);
    if (t != 0) {
        free(volume);
        free(fat1);
        free(fat2);
        NULLERR(EINVAL)
    }


    volume->more_info = (additions *) calloc(1, sizeof(additions));
    if (volume->more_info == NULL) {
        free(volume);
        free(fat1);
        free(fat2);
        NULLERR(ENOMEM)
    }

    morei->disk = pdisk;
    morei->volume_start = 0;
    morei->fat1_start = morei->volume_start + volume->reserved_sectors;
    morei->fat2_start = morei->fat1_start + volume->sectors_per_fat;
    morei->root_start = morei->fat1_start + 2 * volume->sectors_per_fat;
    morei->sectors_per_root = (volume->root_dir_capacity * sizeof(root_t)) / volume->bytes_per_sector;
    morei->data_start = morei->root_start + morei->sectors_per_root;
    morei->available_clusters =
            (volume->logical_sectors16 == 0 ? volume->logical_sectors32 : volume->logical_sectors16 -
                                                                          volume->reserved_sectors -
                                                                          2 * morei->sectors_per_root) /
            volume->sectors_per_cluster;
    morei->available_bytes = morei->available_clusters * volume->sectors_per_cluster * volume->bytes_per_sector;
    morei->fat_entry_count = morei->available_clusters + 2;
    morei->fat1 = fat1;
    morei->fat2 = fat2;

    return volume;
}

int fat_close(volume_t *pvolume) {
    if (pvolume == NULL) {
        perror("EFAULT");
        return -1;
    }

    free(pmorei->fat1);
    free(pmorei->fat2);
    free(pvolume->more_info);
    free(pvolume);
    pvolume = NULL;
    return 0;
}

struct file_t *file_open(struct volume_t *pvolume, const char *file_name) {
    if (pvolume == NULL || file_name == NULL) {
        NULLERR(EFAULT)
    }
    file_t *f = (file_t *) malloc(sizeof(file_t));
    if (f == NULL) {
        NULLERR(ENOMEM)
    }
    f->volume = pvolume;
    f->clusters = NULL;
    f->current = 0;
    f->first_cluster = 0;
    f->no_clusters = 0;
    f->size = 0;

    root_t *root_dir = (root_t *) calloc(pvolume->bytes_per_sector, pmorei->sectors_per_root);
    if (root_dir == NULL) {
        free(f);
        NULLERR(ENOMEM)
    }

    int xd = disk_read(pmorei->disk, pmorei->root_start, root_dir, pmorei->sectors_per_root);
    if (xd == -1) {
        free(f);
        free(root_dir);
        NULLERR(ENOENT)
    }
    root_t *t = (root_t *) calloc(1, sizeof(root_t));
    if (t == NULL) {
        free(f);
        free(root_dir);
        NULLERR(ENOMEM)
    }

    bool found = 0;
    for (int i = 0; i < pvolume->root_dir_capacity; ++i) {
        memmove(t, root_dir + i, sizeof(root_t));
        if (compare_names(t->name, file_name) == 0) {
            if (t->attributes & FAT_ATTR_DIRECTORY || t->attributes & FAT_ATTR_VOLUME_ID) {
                free(t);
                free(root_dir);
                free(f);
                NULLERR(EISDIR)
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        free(f);
        free(t);
        free(root_dir);
        NULLERR(ENOENT)
    }

    f->size = t->size;
    f->first_cluster = t->low_chain_index;

    free(root_dir);
    free(t);


    size_t csize = pvolume->sectors_per_cluster * pvolume->bytes_per_sector;

    f->no_clusters = (f->size / csize) + (f->size % csize ? 1 : 0);
    f->clusters = (cluster_t *) calloc(f->no_clusters, sizeof(cluster_t));
    if (f->clusters == NULL) {
        NULLERR(ENOMEM)
    }

    uint32_t k = f->first_cluster;
    f->clusters[0] = k;
    for (int i = 1; f->clusters[i] < 0xFFF8; ++i) {
        f->clusters[i] = pmorei->fat1[k];
        k = pmorei->fat1[k];
    }


    return f;
}

int compare_names(const char *org, const char *filename) {
    char temp_name[13];
    int i;
    for (i = 0; i < 8; ++i) {
        if (org[i] == ' ') {
            if (org[8] != ' ')
                temp_name[i] = '.';
            else
                temp_name[i] = '\0';
            break;
        }
        temp_name[i] = org[i];
    }
    if (i == 8) {
        temp_name[i] = '.';
    }
    ++i;
    for (int k = 0; k < 3; ++k) {
        if (org[8 + k] == ' ') {
            break;
        }
        temp_name[i] = org[8 + k];
        ++i;
    }
    temp_name[i] = '\0';
    return strcmp(temp_name, filename);

}

int file_close(struct file_t *stream) {
    if (stream == NULL || stream->clusters == NULL) {
        perror("EFAULT");
        return -1;
    }
    free(stream->clusters);
    free(stream);
    return 0;
}

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream) {
    if (ptr == NULL || stream == NULL) {
        ERR1(EFAULT)
    }

    size_t cluster_size = stream->volume->sectors_per_cluster * stream->volume->bytes_per_sector;
    uint64_t current_byte = stream->current % stream->volume->bytes_per_sector;
    cluster_t current_cluster = stream->current / cluster_size;
    uint64_t bytesToLoad =
            size * nmemb > stream->size - stream->current ? stream->size - stream->current : size * nmemb;

    if (bytesToLoad == 0) {
        return 0;
    }

    lba_t current_sector = stream->current / stream->volume->bytes_per_sector % stream->volume->sectors_per_cluster;
    lba_t p_current_sector = current_sector + stream->morei->data_start +
                             (stream->clusters[current_cluster] - 2) * stream->volume->sectors_per_cluster;
    uint16_t no_beginning_bytes =
            stream->volume->bytes_per_sector - current_byte < bytesToLoad ? stream->volume->bytes_per_sector -
                                                                            current_byte : bytesToLoad;
    uint16_t no_ending_bytes = (bytesToLoad - no_beginning_bytes) % stream->volume->bytes_per_sector;
    lba_t no_sectors = (bytesToLoad - no_beginning_bytes) / stream->volume->bytes_per_sector;


    uint16_t *temp = (uint16_t *) calloc(1, stream->volume->bytes_per_sector);
    if (temp == NULL) {
        ERR1(ENOMEM)
    }

    int READ_SECTOR


    memcpy(ptr, (char *) temp + current_byte, no_beginning_bytes);

    uint64_t loadedBytes = no_beginning_bytes;
    stream->current += loadedBytes;
    current_byte += loadedBytes;
    bytesToLoad -= loadedBytes;
    uint32_t read = loadedBytes;

    if (bytesToLoad > 0) {
        current_byte = 0;
        current_sector++;
        if (current_sector == stream->volume->sectors_per_cluster) {
            current_sector = 0;
            current_cluster++;
        }
    }

    for (lba_t i = 0; i < no_sectors; ++i) {

        p_current_sector = current_sector + stream->morei->data_start +
                           (stream->clusters[current_cluster] - 2) * stream->volume->sectors_per_cluster;

        READ_SECTOR

        memcpy((uint8_t *) ptr + read, temp, stream->volume->bytes_per_sector);
        loadedBytes = stream->volume->bytes_per_sector;
        stream->current += loadedBytes;
        current_byte += loadedBytes;
        bytesToLoad -= loadedBytes;
        read += loadedBytes;
        current_sector++;
        if (current_sector == stream->volume->sectors_per_cluster) {
            current_sector = 0;
            current_cluster++;
            if (current_cluster == stream->current)
                return read / size;
        }
    }

    if (no_ending_bytes > 0) {
        p_current_sector = current_sector + stream->morei->data_start +
                           (stream->clusters[current_cluster] - 2) * stream->volume->sectors_per_cluster;

        READ_SECTOR
        memcpy((uint8_t *) ptr + read, temp, no_ending_bytes);
        loadedBytes = no_ending_bytes;
        stream->current += loadedBytes;
        read += loadedBytes;
    }
    free(temp);
    return read / size;
}

int32_t file_seek(struct file_t *stream, int32_t offset, int whence) {
    if (stream == NULL) {
        ERR1(EFAULT)
    }
    int32_t p = offset;
    if (whence == SEEK_SET) {
    } else if (whence == SEEK_CUR) {
        p += stream->current;
    } else if (whence == SEEK_END) {
        p += stream->size;
    } else {
        ERR1(EINVAL)
    }
    if (p < 0 || p > (int32_t) stream->size) {
        ERR1(ENXIO)
    }
    stream->current = p;

    return stream->current;
}


struct dir_t *dir_open(struct volume_t *pvolume, const char *dir_path) {
    if (pvolume == NULL || dir_path == NULL) {
        NULLERR(EFAULT)
    }

    dir_t *dir = (dir_t *) calloc(1, sizeof(dir_t));
    if (dir == NULL) {
        NULLERR(ENOMEM)
    }

    int t = strcmp(dir_path, "\\");
    if (t != 0) {
        free(dir);
        NULLERR(ENOENT)
    }

    dir->volume = pvolume;
    return dir;
}

void copy_name(dir_entry_t *pentry, const char *org) {
    char temp_name[13]={' '};
    int i;
    for (i = 0; i < 8; ++i) {
        if (org[i] == ' ') {
            if (org[8] != ' ')
                temp_name[i] = '.';
            else
                temp_name[i] = '\0';
            break;
        }
        temp_name[i] = org[i];
    }
    if (i == 8 && org[8] != ' ') {
        temp_name[i] = '.';
    }
    ++i;
    for (int k = 0; k < 3; ++k) {
        if (org[8 + k] == ' ') {
            break;
        }
        temp_name[i] = org[8 + k];
        ++i;
    }
    temp_name[i] = '\0';
    strcpy(pentry->name, temp_name);
}

bool is_empty(void *mem, size_t len) {
    uint8_t *t = calloc(len, 1);
    bool xd = memcmp(mem, t, len);
    free(t);
    return xd;
}

int dir_read(struct dir_t *pdir, struct dir_entry_t *pentry) {
    if (pdir == NULL || pentry == NULL) {
        ERR1(EFAULT)
    }
    root_t *root_dir = (root_t *) calloc(pdir->morei->sectors_per_root, pdir->volume->bytes_per_sector);
    if (root_dir == NULL) {
        ERR1(ENOMEM)
    }

    int xd = disk_read(pdir->morei->disk, pdir->morei->root_start, root_dir, pdir->morei->sectors_per_root);
    if (xd == -1) {
        free(root_dir);
        ERR1(EIO)
    }

    root_t *t = (root_t *) calloc(1, sizeof(root_t));
    if (t == NULL) {
        free(root_dir);
        ERR1(ENOMEM)
    }

    while (pdir->pos < pdir->volume->root_dir_capacity) {
        memmove(t, root_dir + pdir->pos, sizeof(root_t));
        copy_name(pentry, t->name);
        pentry->size = t->size;
        pentry->is_archived = t->attributes & FAT_ATTR_ARCHIVE;
        pentry->is_readonly = t->attributes & FAT_ATTR_READ_ONLY;
        pentry->is_system = t->attributes & FAT_ATTR_SYSTEM;
        pentry->is_hidden = t->attributes & FAT_ATTR_HIDDEN;
        pentry->is_directory = t->attributes & FAT_ATTR_DIRECTORY;

        pdir->pos++;
        if ((pentry->name[0] == '\0' || ((uint8_t *) pentry->name)[0] == 0x00 ||
             ((uint8_t *) pentry->name)[0] == 0xE5 || !is_empty(pentry, sizeof(dir_entry_t))))
            continue;
        else {
            free(t);
            free(root_dir);
            return 0;
        }
    }
    free(t);
    free(root_dir);
    return 1;
}


int dir_close(struct dir_t *pdir) {
    if (pdir == NULL) {
        ERR1(EFAULT)
    }
    free(pdir);
    return 0;
}




