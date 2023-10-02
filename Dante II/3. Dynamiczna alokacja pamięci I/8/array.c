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

int array_remove_item(struct array_t *a, int value)
{
    if(a==NULL||a->size<0||a->capacity<=0||a->ptr==NULL||a->size>a->capacity)
        return -1;
    int i,k,l=0;
    for(i=0; i<a->size; i++)
    {
        if(*(a->ptr+i)==value)
        {
            l++;
        }
    }
    for(i=0; i<a->size; i++)
    {
        if(*(a->ptr+i)==value)
        {
            for(k=i; k<a->size-1; k++)
                *(a->ptr+k)=*(a->ptr+k+1);
        }
    }
    for(i=0; i<a->size; i++)
    {
        if(*(a->ptr+i)==value)
        {
            for(k=i; k<a->size-1; k++)
                *(a->ptr+k)=*(a->ptr+k+1);
        }
    }
    a->size-=l;
    return l;
}


