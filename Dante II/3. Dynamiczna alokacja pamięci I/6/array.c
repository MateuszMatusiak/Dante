#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include "tested_declarations.h"
#include "rdebug.h"

int array_create(struct array_t *a, int N)
{
    if(a==NULL)
        return 1;
    if(N<=0)
        return 1;
    a->ptr=(int*)calloc(N,sizeof(int));
    if(a->ptr==NULL)
        return 2;
    a->size=0;
    a->capacity=N;
    return 0;
}
int array_push_back( struct array_t *a, int value)
{
    if(a == NULL || a->ptr == NULL || a->capacity <= 0 || a->size < 0 || a->size > a->capacity )
        return 1;

    if(a->size == a->capacity)
        return 2;

    *(a->ptr + a->size) = value;
    a->size += 1;
    return 0;
}
void array_display(const struct array_t *a)
{
    if(!(a==NULL || a->ptr==NULL || a->size<=0 || a->capacity<=0 || a->size>a->capacity))
    {
        int i;
        for(i=0; i<a->size; i++)
        {
            printf("%d ",*(a->ptr+i));
        }
    }
}
void array_destroy(struct array_t *a)
{
    if(!(a==NULL || a->ptr==NULL))
        free( a->ptr);
}

