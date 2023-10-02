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
    int *t;
    if(a->size >= a->capacity)
    {
        t = realloc(a->ptr, (a->capacity*2)*sizeof(int));
        if(t == NULL)
        {
            return 2;
        }
        a->ptr=t;
        a->capacity=(a->capacity)*2;

    }
    *(a->ptr + a->size) = value;
    a->size += 1;
    return 0;

}
void array_display(const struct array_t *a)
{
    if(!(a==NULL || a->ptr==NULL || a->size<=0 || a->capacity<=0 || a->size>a->capacity))
    {
        int i;
        for(i=0; i<a->size-1; i++)
        {
            printf("%d ",*(a->ptr+i));
        }
        printf("%d",*(a->ptr+i));
    }
}
void array_destroy(struct array_t *a)
{
    if(!(a==NULL || a->ptr==NULL))
        free(a->ptr);
}

int array_create_struct(struct array_t **a, int N)
{
    if(a==NULL)
        return 1;
    int t;
    *a=(struct array_t *)malloc(sizeof(struct array_t));
    t=array_create(*a,N);
    if(t==1||t==2)
        free(*a);
    return t;
}

void array_destroy_struct(struct array_t **a)
{
    if(a!=NULL)
    {
        array_destroy(*a);
        free(*a);
    }
}


int array_remove_item(struct array_t *a, int value) {
    if (a == NULL || a->size < 0 || a->capacity <= 0 || a->ptr == NULL || a->size > a->capacity)
        return -1;
    int i,k,l = 0, as, sz = a->size;
    int *xd;
    int spr, lspr = 1;
    if (a->size == 0) {
        if (a->capacity > 1)
            a->capacity = a->capacity / 2;
        return l;
    }
    for (i = 0; i < sz; i++) {
        if (*(a->ptr + i) == value)
            l++;
    }

    spr = *(a->ptr);
    for (i = 1; i < a->size; i++) {
        if (spr == *(a->ptr + i)) {
            lspr++;
        }
    }

    as = a->size;
    for(int o=0;o<5;o++)
        for (i = 0; i < a->size; ++i) {
                if (*(a->ptr + i) == value) {
                    for (k = i; k < as - 1; ++k) {
                        *(a->ptr + k) = *(a->ptr + k + 1);
                    }
                }
            }
    a->size=sz-l;

    if((lspr==sz)&&(spr==value))
    {
        l=lspr;
        a->size=0;
        if(a->capacity>1)
            a->capacity=a->capacity/2;
        return l;
    }

    if((a->size<a->capacity/4))
    {
        xd=(int*)realloc(a->ptr,(a->capacity/2)*sizeof(int));
        if(xd==NULL)
        {
            return l;
        }
        a->ptr=xd;
        if(a->capacity>1)
            a->capacity=a->capacity/2;
    }
    return l;
}

