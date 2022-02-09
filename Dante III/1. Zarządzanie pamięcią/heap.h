#ifndef ALOKATOR_HEAP_H
#define ALOKATOR_HEAP_H

#define XD 4000

typedef struct memory_manager_t {
    void *memory_start;
    size_t memory_size;
    struct memory_chunk_t *first_memory_chunk;
} memory_manager_t;

typedef struct memory_chunk_t {
    struct memory_chunk_t *prev;
    struct memory_chunk_t *next;
    size_t size;
    int free;
    int checksum;
} memory_chunk_t;

int heap_setup(void);

void heap_clean(void);

void *heap_malloc(size_t size);

void *heap_calloc(size_t number, size_t size);

void *heap_realloc(void *memblock, size_t count);

void heap_free(void *memblock);

size_t heap_get_largest_used_block_size(void);

typedef enum pointer_type_t {
    pointer_null,
    pointer_heap_corrupted,
    pointer_control_block,
    pointer_inside_fences,
    pointer_inside_data_block,
    pointer_unallocated,
    pointer_valid
} pointer_type_t;

enum pointer_type_t get_pointer_type(const void *const pointer);

int heap_validate(void);

void *heap_malloc_aligned(size_t count);

void *heap_calloc_aligned(size_t number, size_t size);

void *heap_realloc_aligned(void *memblock, size_t size);

int calculate_checksum(void *chunk);

#endif //ALOKATOR_HEAP_H
