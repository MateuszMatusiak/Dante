#ifndef FAT_FILE_READER_H
#define FAT_FILE_READER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <stdbool.h>
#include "file_reader.h"

typedef uint32_t lba_t;
typedef uint32_t cluster_t;


typedef struct disk_t {
    FILE *p_disk;
} __attribute__ ((packed)) disk_t;


struct disk_t *disk_open_from_file(const char *volume_file_name);

int disk_read(struct disk_t *pdisk, int32_t first_sector, void *buffer, int32_t sectors_to_read);

int disk_close(struct disk_t *pdisk);

typedef struct additions {
    disk_t *disk;
    uint16_t *fat1;
    uint16_t *fat2;
    lba_t volume_start;
    lba_t fat1_start;
    lba_t fat2_start;
    lba_t root_start;
    lba_t sectors_per_root;
    lba_t data_start;
    lba_t available_clusters;
    uint64_t available_bytes;
    uint32_t fat_entry_count;

}__attribute__ ((packed)) additions;

typedef struct volume_t {
    uint8_t jump_code[3];
    char oem_name[8];
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t fat_count;
    uint16_t root_dir_capacity;
    uint16_t logical_sectors16;
    uint8_t media_type;
    uint16_t sectors_per_fat;
    uint16_t chs_sectors_per_track;
    uint16_t chs_tracks_per_cylinder;
    uint32_t hidden_sectors;
    uint32_t logical_sectors32;
    uint8_t media_id;
    uint8_t chs_head;
    uint8_t ext_bpb_signature;
    uint32_t serial_number;
    char volume_label[11];
    char fsid[8];
    uint8_t boot_code[448];
    uint16_t magic;

    additions *more_info;
} __attribute__ ((packed)) volume_t;


struct volume_t *fat_open(struct disk_t *pdisk, uint32_t first_sector);

int fat_close(struct volume_t *pvolume);


struct file_t *file_open(struct volume_t *pvolume, const char *file_name);

int file_close(struct file_t *stream);

size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);

int32_t file_seek(struct file_t *stream, int32_t offset, int whence);


typedef struct fat_date_t {
    uint16_t day: 5;
    uint16_t month: 4;
    uint16_t year: 7;
} fat_date_t;

typedef struct fat_time_t {
    uint16_t seconds: 5;
    uint16_t minutes: 6;
    uint16_t hours: 5;
} fat_time_t;

typedef enum fat_attributes_t {
    FAT_ATTR_READ_ONLY = 0x01,      //(Read - only)
    FAT_ATTR_HIDDEN = 0x02,         //(Hidden)
    FAT_ATTR_SYSTEM = 0x04,         //(System)
    FAT_ATTR_VOLUME_ID = 0x08,      //(Volume label)
    FAT_ATTR_DIRECTORY = 0x10,      //(Directory)
    FAT_ATTR_ARCHIVE = 0x20,        //(Archive)
    FAT_ATTR_LONG_FILE_NAME = 0x0F //(LFN entry)
} __attribute__ ((packed)) fat_attributes_t;


typedef struct file_t {
    cluster_t *clusters;
    uint16_t no_clusters;
    uint64_t current;
    uint32_t first_cluster;
    size_t size;
    volume_t *volume;
}__attribute__((packed)) file_t;


typedef struct dir_entry_t {
    char name[8 + 3 + 2];
    size_t size;
    bool is_archived;
    bool is_readonly;
    bool is_system;
    bool is_hidden;
    bool is_directory;
}__attribute__((packed)) dir_entry_t;


typedef struct dir_t {
    char name[8 + 3];
    fat_attributes_t attributes;
    uint8_t __reserved0;
    uint8_t cration_time_ms;
    int pos;
    volume_t* volume;
    uint16_t low_chain_index;
    uint32_t size;
}__attribute__((packed)) dir_t;


typedef struct root_t{
    char name[8 + 3];
    fat_attributes_t attributes;
    uint8_t __reserved0;
    uint8_t cration_time_ms;
    fat_time_t creation_time;
    fat_date_t creation_date;
    fat_time_t last_access_time;
    fat_date_t high_chain_index;
    fat_time_t last_modification_time;
    fat_date_t last_modification_date;
    uint16_t low_chain_index;
    uint32_t size;
}__attribute__((packed)) root_t;
struct dir_t *dir_open(struct volume_t *pvolume, const char *dir_path);

int dir_read(struct dir_t *pdir, struct dir_entry_t *pentry);

int dir_close(struct dir_t *pdir);

int compare_names(const char *org, const char *filename);

#endif //FAT_FILE_READER_H
