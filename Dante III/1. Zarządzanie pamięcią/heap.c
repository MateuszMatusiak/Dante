#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "custom_unistd.h"
#include "heap.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"


#define FENCE_LENGTH 8

memory_manager_t memoryManager = {NULL, 0, NULL};
char fence_value[] = "1ECDC95B";

#define MAKE_FENCES(name, size)     for (int i = 0; i < FENCE_LENGTH; ++i, name++) \
                                        {*(char *) (name) = *(fence_value + i);    \
                                        *(char *) (name+size+FENCE_LENGTH) = *(fence_value + i);\
                                        }                                          \

#define ALIGNMENT 4096
#define ALIGN(x)    ((((intptr_t) ((uint8_t *) (x) + sizeof(memory_chunk_t) + FENCE_LENGTH))+(ALIGNMENT-1))&~(ALIGNMENT-1))
#define AUTOALIGN(x)    (ALIGN(x) - (intptr_t) ((uint8_t *) (x) + sizeof(memory_chunk_t) + FENCE_LENGTH))

#define AL(x) (((intptr_t) ((uint8_t *) (x) + sizeof(memory_chunk_t) + FENCE_LENGTH) & (intptr_t) (ALIGNMENT - 1)))

#define TORETURN(ptr, chunk) uint8_t *ptr=(uint8_t*)(chunk); \
                        (ptr)+=sizeof(memory_chunk_t);    \
                        (ptr)+=FENCE_LENGTH;\


size_t calculateChunkSize(memory_chunk_t *chunk) {
    size_t xd = chunk->size;
    if (chunk->next != NULL)
        xd = (size_t) ((uint8_t *) chunk->next - (uint8_t *) chunk) - sizeof(memory_chunk_t) - 2 * FENCE_LENGTH;
    return xd;
}

int heap_setup(void) {
    void *temp = custom_sbrk(0);
    if (temp == (void *) -1)
        return -1;
    memoryManager.first_memory_chunk = NULL;
    memoryManager.memory_size = 0;
    memoryManager.memory_start = temp;

    return 0;

}

void heap_clean(void) {
    if (memoryManager.memory_start == NULL || memoryManager.memory_size <= 0) {
        memoryManager.first_memory_chunk = NULL;
        memoryManager.memory_start = NULL;
        memoryManager.memory_size = 0;
        return;
    }
    custom_sbrk(-((long long) memoryManager.memory_size));
    memoryManager.first_memory_chunk = NULL;
    memoryManager.memory_start = NULL;
    memoryManager.memory_size = 0;
}

void *heap_malloc(size_t size) {
    if (size == 0 || heap_validate() != 0)
        return NULL;
    memory_chunk_t *freeChunk = memoryManager.first_memory_chunk;
    memory_chunk_t *prev = NULL;
    while (freeChunk != NULL) {
        if (freeChunk->size >= size)
            if (freeChunk->free == 1)
                break;
        prev = freeChunk;
        freeChunk = freeChunk->next;
        if (freeChunk != NULL)
            freeChunk->prev = prev;
    }
    if (freeChunk == NULL) {
        size_t newblocksize = sizeof(memory_chunk_t) + FENCE_LENGTH * 2 + size;
        memory_chunk_t *freshChunk = custom_sbrk((long) newblocksize);
        if (freshChunk == (void *) -1)
            return NULL;

        memoryManager.memory_size += newblocksize;
        if (memoryManager.first_memory_chunk == NULL) {
            memoryManager.first_memory_chunk = freshChunk;
            memory_chunk_t *first = freshChunk;
            first->next = NULL;
            first->prev = NULL;
            first->size = size;
            first->free = 0;

            uint8_t *ptr = (uint8_t *) first;

            ptr += sizeof(memory_chunk_t);

            MAKE_FENCES(ptr, size)
            first->checksum = calculate_checksum(first);

            return ptr;
        }
        memory_chunk_t *last = memoryManager.first_memory_chunk;
        while (last != NULL) {
            prev = last;
            last = last->next;
            if (last != NULL)
                last->prev = prev;
        }
        last = freshChunk;
        last->next = NULL;
        last->prev = prev;
        last->free = 0;
        last->size = size;

        last->prev->next = last;
        last->prev->checksum = calculate_checksum(last->prev);

        uint8_t *ptr = (uint8_t *) last;
        ptr += sizeof(memory_chunk_t);

        MAKE_FENCES(ptr, size)
        last->checksum = calculate_checksum(last);
        return ptr;


    }
    freeChunk->free = 0;
    freeChunk->size = size;
    uint8_t *ptr = (uint8_t *) freeChunk;
    ptr += sizeof(memory_chunk_t);

    MAKE_FENCES(ptr, size)
    freeChunk->checksum = calculate_checksum(freeChunk);

    return ptr;
}

void *heap_calloc(size_t number, size_t size) {
    void *ptr = heap_malloc(number * size);
    if (ptr == NULL)
        return NULL;

    memset(ptr, 0, size * number);

    return ptr;
}

void *heap_realloc(void *memblock, size_t count) {
    if (heap_validate() != 0)
        return NULL;

    if (count == 0) {
        heap_free(memblock);
        return NULL;
    }
    if (get_pointer_type(memblock) == pointer_null) {
        void *ptr = heap_malloc(count);
        return ptr;
    }

    if (get_pointer_type(memblock) != pointer_valid)
        return NULL;
    if (memoryManager.memory_start == NULL && memoryManager.memory_size == 0 &&
        memoryManager.first_memory_chunk == NULL)
        return NULL;


    memory_chunk_t *chunk = (memory_chunk_t *) ((uint8_t *) memblock - sizeof(memory_chunk_t) - FENCE_LENGTH);
    if (chunk->size == count)
        return memblock;
    if (chunk->size > count) {
        chunk->size = count;
        chunk->checksum = calculate_checksum(chunk);
        TORETURN(ptr, chunk)
        ptr -= FENCE_LENGTH;
        MAKE_FENCES(ptr, count)
        return ptr;
    }
    size_t size = chunk->size;
    if (chunk->next != NULL)
        size = calculateChunkSize(chunk);

    if (chunk->next == NULL) {
        void *t = custom_sbrk((count - chunk->size));
        if (t == (void *) -1)
            return NULL;
        memoryManager.memory_size += (count - chunk->size);
        chunk->size = count;
        TORETURN(ptr, chunk)
        ptr -= FENCE_LENGTH;
        MAKE_FENCES(ptr, count)
        chunk->checksum = calculate_checksum(chunk);

        return ptr;
    }

    if (chunk->next->free == 1)
        if ((chunk->next->size) + sizeof(memory_chunk_t) + FENCE_LENGTH * 2 >= (count - size)) {
//            memory_chunk_t *temp = chunk->next;
//            unsigned int val=count-((uint8_t*)temp-(uint8_t*)memblock)+FENCE_LENGTH;
//            temp = memcpy((uint8_t *) temp + (val), (uint8_t *) temp, sizeof(memory_chunk_t));
//            temp->size -= val;
//            if(temp->next!=NULL)
//            {
//                temp->next->prev = temp;
//                temp->next->checksum = calculate_checksum(temp->next);
//            }
////            uint8_t *pt=(uint8_t*)temp;
////            pt+=sizeof(memory_chunk_t);
////            MAKE_FENCES(pt,temp->size)
//
//            chunk->size = count;
//            uint8_t *ptr=(uint8_t*)chunk;
//            ptr+=sizeof(memory_chunk_t);
//            MAKE_FENCES(ptr,count)
//            chunk->checksum = calculate_checksum(chunk);
//            temp->checksum = calculate_checksum(temp);
//
//            return ptr;


            heap_free(memblock);
            return heap_malloc(count);

        }

    void *ml = heap_malloc(count);
    if (ml == NULL)
        return NULL;
    memcpy(ml, memblock, chunk->size);
    heap_free(memblock);
    return ml;
}

void heap_free(void *memblock) {
    if (heap_validate() != 0 || memblock == NULL || get_pointer_type(memblock) != pointer_valid)
        return;
    memory_chunk_t *chunk = (memory_chunk_t *) ((uint8_t *) memblock - sizeof(memory_chunk_t) - FENCE_LENGTH);
    if (chunk->prev == NULL) {
        if (chunk->next == NULL) {
            chunk->free = 1;
            chunk->checksum = calculate_checksum(chunk);
            size_t sz = memoryManager.memory_size;
            custom_sbrk(-(sz));
            memoryManager.memory_size -= (sz);
            memoryManager.first_memory_chunk = NULL;

            chunk = NULL;

        } else if (chunk->next != NULL) {
            if (chunk->next->free == 0) {
                chunk->free = 1;
                chunk->size = calculateChunkSize(chunk);
                chunk->checksum = calculate_checksum(chunk);

            } else {
                chunk->free = 1;
                chunk->size = calculateChunkSize(chunk) + sizeof(memory_chunk_t) + chunk->next->size + 2 * FENCE_LENGTH;

                chunk->next->next->prev = chunk;
                chunk->next->next->checksum = calculate_checksum(chunk->next->next);

                chunk->next = chunk->next->next;
                chunk->checksum = calculate_checksum(chunk);

            }
        }
    } else if (chunk->prev->free == 0) {
        if (chunk->next == NULL) {
            chunk->free = 1;
            chunk->checksum = calculate_checksum(chunk);
            chunk->prev->next = NULL;
            chunk->prev->checksum = calculate_checksum(chunk->prev);
            size_t sz = sizeof(memory_chunk_t) + 2 * FENCE_LENGTH + chunk->size;
            custom_sbrk(-(sz));
            memoryManager.memory_size -= (sz);
            if (memoryManager.memory_size == 0) {
                memoryManager.first_memory_chunk = NULL;
            }
            chunk = NULL;
        } else if (chunk->next != NULL) {
            if (chunk->next->free == 0) {
                chunk->free = 1;
                chunk->size = calculateChunkSize(chunk);
                chunk->checksum = calculate_checksum(chunk);

            } else {
                chunk->free = 1;
                chunk->size = calculateChunkSize(chunk) + chunk->next->size + sizeof(memory_chunk_t) +
                              2 * FENCE_LENGTH;

                chunk->next->next->prev = chunk;
                chunk->next->next->checksum = calculate_checksum(chunk->next->next);

                chunk->next = chunk->next->next;
                chunk->checksum = calculate_checksum(chunk);

            }
        }
    } else {
        if (chunk->next == NULL) {
            chunk->free = 1;
            chunk->checksum = calculate_checksum(chunk);

            if (chunk->prev->prev != NULL) {
                chunk->prev->prev->next = NULL;
                chunk->prev->prev->checksum = calculate_checksum(chunk->prev->prev);
                size_t sz = (sizeof(memory_chunk_t) * 2 + 4 * FENCE_LENGTH + chunk->size + chunk->prev->size);
                custom_sbrk(-(sz));
                memoryManager.memory_size -= (sz);
                if (memoryManager.memory_size == 0) {
                    memoryManager.first_memory_chunk = NULL;
                }
                chunk = NULL;
                return;
            }

            custom_sbrk(-(memoryManager.memory_size));
            memoryManager.memory_size = 0;
            memoryManager.first_memory_chunk = NULL;


        } else if (chunk->next != NULL) {
            if (chunk->next->free == 0) {
                chunk->free = 1;
                chunk->prev->size =
                        calculateChunkSize(chunk->prev) + sizeof(memory_chunk_t) + calculateChunkSize(chunk) +
                        2 * FENCE_LENGTH;
                chunk->prev->next = chunk->next;
                chunk->next->prev = chunk->prev;

                chunk->next->checksum = calculate_checksum(chunk->next);
                chunk->prev->checksum = calculate_checksum(chunk->prev);
            } else {
                chunk->free = 1;
                chunk->prev->size =
                        calculateChunkSize(chunk->prev) + calculateChunkSize(chunk) + chunk->next->size +
                        2 * sizeof(memory_chunk_t) + 4 * FENCE_LENGTH;

                chunk->prev->next = chunk->next->next;
                chunk->next->next->prev = chunk->prev;

                chunk->next->next->checksum = calculate_checksum(chunk->next->next);
                chunk->prev->checksum = calculate_checksum(chunk->prev);
            }
        }
    }

}

size_t heap_get_largest_used_block_size(void) {
    if (heap_validate() != 0)
        return 0;
    if (memoryManager.first_memory_chunk == NULL)
        return 0;
    if (memoryManager.memory_start == NULL)
        return 0;

    size_t size = 0;
    memory_chunk_t *chunk = memoryManager.first_memory_chunk;
    while (chunk != NULL) {
        if (chunk->free == 0)
            if (chunk->size > size)
                size = chunk->size;
        chunk = chunk->next;
    }
    return size;
}

enum pointer_type_t get_pointer_type(const void *const pointer) {
    if (pointer == NULL)
        return pointer_null;
    if (heap_validate() != 0)
        return pointer_heap_corrupted;

    memory_chunk_t *tempChunk = memoryManager.first_memory_chunk;
    uint8_t *tempPoint;
    while (tempChunk != NULL) {


        tempPoint = (uint8_t *) tempChunk;

        for (unsigned long i = 0; i < sizeof(memory_chunk_t); ++i, tempPoint++)
            if (pointer == tempPoint)
                if (tempChunk->free == 1)
                    return pointer_unallocated;
                else
                    return pointer_control_block;

        for (int i = 0; i < FENCE_LENGTH; ++i, tempPoint++) {
            if (pointer == tempPoint)
                if (tempChunk->free == 1)
                    return pointer_unallocated;
                else
                    return pointer_inside_fences;
            if (pointer == tempPoint + tempChunk->size + FENCE_LENGTH)
                if (tempChunk->free == 1)
                    return pointer_unallocated;
                else
                    return pointer_inside_fences;
        }
        if (pointer == tempPoint)
            if (tempChunk->free == 1)
                return pointer_unallocated;
            else
                return pointer_valid;

        for (unsigned long i = 1; i <= tempChunk->size; ++i, tempPoint++) {
            if (pointer == tempPoint)
                if (tempChunk->free == 1)
                    return pointer_unallocated;
                else
                    return pointer_inside_data_block;
        }

        tempChunk = tempChunk->next;
    }
    return pointer_unallocated;
}

int heap_validate(void) {
    if (memoryManager.memory_start == NULL)
        return 2;
    if (memoryManager.memory_size != 0 && memoryManager.first_memory_chunk == NULL)
        return 3;
    if (memoryManager.memory_size == 0 && memoryManager.first_memory_chunk == NULL)
        return 0;

    memory_chunk_t *chunk = memoryManager.first_memory_chunk;
    while (chunk != NULL) {
        if (chunk->checksum != calculate_checksum(chunk))
            return 3;
        chunk = chunk->next;
    }

    chunk = memoryManager.first_memory_chunk;
    int coc = 1;
    while (chunk != NULL) {
        if (chunk->free == 0) {
            uint8_t *ptr;
            ptr = (uint8_t *) chunk + sizeof(memory_chunk_t);

            char *fence = (char *) ptr;
            for (int i = 0; i < FENCE_LENGTH; ++i, fence++) {
                if (*(fence) != *(fence_value + i))
                    return 1;
                if (*(fence + chunk->size + FENCE_LENGTH) != *(fence_value + i))
                    return 1;

            }
        }
        coc++;
        chunk = chunk->next;
    }
    return 0;
}

void *heap_malloc_aligned(size_t count) {
    if (count == 0 || heap_validate() != 0)
        return NULL;
    memory_chunk_t *freeChunk = memoryManager.first_memory_chunk;
    memory_chunk_t *prev = NULL;
    int nr=0;
    while (freeChunk != NULL) {
        if (calculateChunkSize(freeChunk) >= count)
            if (freeChunk->free == 1)
                if (AL(freeChunk)==0)
                    break;
        prev = freeChunk;
        nr++;
        freeChunk = freeChunk->next;
        if (freeChunk != NULL)
            freeChunk->prev = prev;
    }
    if (freeChunk == NULL) {
        size_t newblocksize = sizeof(memory_chunk_t) + FENCE_LENGTH * 2 + count;
        memory_chunk_t *freshChunk = custom_sbrk((long) newblocksize);
        if (freshChunk == (void *) -1)
            return NULL;

        int a = AUTOALIGN(freshChunk);
        a += (a < (int) sizeof(memory_chunk_t) + FENCE_LENGTH) ? ALIGNMENT : 0;

        void *temp = custom_sbrk(a);
        if (temp == (void *) -1) {
            custom_sbrk(-((long) newblocksize));
            return NULL;
        }
        memoryManager.memory_size += newblocksize + a;
//        uint8_t x=ALIGN(freshChunk)-sizeof(memory_chunk_t)-FENCE_LENGTH;
//        freshChunk=(memory_chunk_t*)((uint8_t*)memoryManager.memory_start + x);
//        freshChunk+=4096*(nr);
        if (memoryManager.first_memory_chunk == NULL) {
            memory_chunk_t *first =(memory_chunk_t*)((uint8_t*)memoryManager.memory_start+a);
            memoryManager.first_memory_chunk = first;
            first->next = NULL;
            first->prev = NULL;
            first->size = count;
            first->free = 0;

            uint8_t *ptr = (uint8_t *) first;

            ptr += sizeof(memory_chunk_t);

            MAKE_FENCES(ptr, count)
            first->checksum = calculate_checksum(first);

            return ptr;
        }
        memory_chunk_t *last = memoryManager.first_memory_chunk;
        while (last != NULL) {
            prev = last;
            last = last->next;
            if (last != NULL)
                last->prev = prev;
        }
        last = (memory_chunk_t*)((uint8_t*)freshChunk+a);
        last->next = NULL;
        last->prev = prev;
        last->free = 0;
        last->size = count;

        last->prev->next = last;
        last->prev->checksum = calculate_checksum(last->prev);

        uint8_t *ptr = (uint8_t *) last;
        ptr += sizeof(memory_chunk_t);

        for (int i = 0; i < FENCE_LENGTH; ++i) {
            *(char *) (ptr + i) = *(fence_value + i);
            *(char *) (ptr + i + last->size + FENCE_LENGTH) = *(fence_value + i);
        }
        ptr += FENCE_LENGTH;
        last->checksum = calculate_checksum(last);
        return ptr;


    }
    freeChunk->free = 0;
    freeChunk->size = count;
    uint8_t *ptr = (uint8_t *) freeChunk;
    ptr += sizeof(memory_chunk_t);

    for (int i = 0; i < FENCE_LENGTH; ++i) {
        *(char *) (ptr + i) = *(fence_value + i);
        *(char *) (ptr + i + freeChunk->size + FENCE_LENGTH) = *(fence_value + i);
    }
    ptr += FENCE_LENGTH;
    freeChunk->checksum = calculate_checksum(freeChunk);

    return ptr;
}

void *heap_calloc_aligned(size_t number, size_t size) {
    void *ptr = heap_malloc_aligned(number * size);
    if (ptr == NULL)
        return NULL;

    memset(ptr, 0, size * number);

    return ptr;
}

void *heap_realloc_aligned(void *memblock, size_t count) {
    if (heap_validate() != 0)
        return NULL;

    if (count == 0) {
        heap_free(memblock);
        return NULL;
    }
    if (get_pointer_type(memblock) == pointer_null) {
        void *ptr = heap_malloc_aligned(count);
        return ptr;
    }

    if (get_pointer_type(memblock) != pointer_valid)
        return NULL;
    if (memoryManager.memory_start == NULL && memoryManager.memory_size == 0 &&
        memoryManager.first_memory_chunk == NULL)
        return NULL;


    memory_chunk_t *chunk = (memory_chunk_t *) ((uint8_t *) memblock - sizeof(memory_chunk_t) - FENCE_LENGTH);
    if (chunk->size == count)
        return memblock;

    size_t size = chunk->size;
    if (chunk->next != NULL)
        size = calculateChunkSize(chunk);
    if (size > count) {
        chunk->size = count;
        chunk->checksum = calculate_checksum(chunk);
        TORETURN(ptr, chunk)
        ptr -= FENCE_LENGTH;
        MAKE_FENCES(ptr, count)
        return ptr;
    }

    if (chunk->next == NULL) {
        void *t = custom_sbrk((count - chunk->size));
        if (t == (void *) -1)
            return NULL;
        memoryManager.memory_size += (count - chunk->size);
        chunk->size = count;
        TORETURN(ptr, chunk)
        ptr -= FENCE_LENGTH;
        MAKE_FENCES(ptr, count)
        chunk->checksum = calculate_checksum(chunk);

        return ptr;
    }

    if (chunk->next->free == 1)
        if ((chunk->next->size) + sizeof(memory_chunk_t) + FENCE_LENGTH * 2 >= (count - size)) {
            heap_free(memblock);
            return heap_malloc_aligned(count);
        }

    void *ml = heap_malloc_aligned(count);
    if (ml == NULL)
        return NULL;
    memcpy(ml, memblock, chunk->size);
    heap_free(memblock);
    return ml;
}

int calculate_checksum(void *chunk) {
    if (chunk == NULL)
        return -1;

    memory_chunk_t *chunkPtr = (memory_chunk_t *) chunk;
    int size = (int) ((uint8_t *) &chunkPtr->checksum - (uint8_t *) chunk);
    uint8_t *p = (uint8_t *) chunk;

    int res = 0;
    for (int i = 0; i < size; ++i) {
        res += *(p + i);
    }
    return res;
}


