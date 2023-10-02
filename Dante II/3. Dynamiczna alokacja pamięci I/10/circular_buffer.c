#include <stdio.h>
#include <stdlib.h>
#include "circular_buffer.h"
#include "tested_declarations.h"
#include "rdebug.h"

int circular_buffer_create(struct circular_buffer_t *cb, int N)
{
    if(cb==NULL||N<=0)
    {
        return 1;
    }
    cb->ptr=(int*)calloc(N,sizeof(int));
    if(cb->ptr==NULL)
    {
        return 2;
    }
    cb->begin=0;
    cb->end=0;
    cb->capacity=N;
    cb->full=0;
    return 0;
}
int circular_buffer_create_struct(struct circular_buffer_t **cb, int N)
{
    int t;
    if(cb==NULL||N<=0)
    {
        return 1;
    }
    *cb=(struct circular_buffer_t *)malloc(sizeof(struct circular_buffer_t));
    t=circular_buffer_create(*cb,N);
    if(t!=0)
    {
        free(*cb);
    }
    return t;
}


void circular_buffer_destroy(struct circular_buffer_t *cb)
{
    if(!(cb==NULL||cb->ptr==NULL))
    {
        free(cb->ptr);
    }
}
void circular_buffer_destroy_struct(struct circular_buffer_t **cb)
{
    if(cb!=NULL)
    {
        circular_buffer_destroy(*cb);
        free(*cb);
    }
}
int circular_buffer_push_back(struct circular_buffer_t *cb, int value)
{
    int x;
    if(cb==NULL||cb->ptr==NULL||cb->begin<0||cb->end<0||cb->capacity<0||cb->begin>=cb->capacity||cb->end>=cb->capacity)
    {
        return 1;
    }
    *(cb->ptr+cb->end)=value;

    x=cb->end+1;
    while(x>=cb->capacity)
    {
        x=x-cb->capacity;
    }
    cb->end=x;
    if(cb->full==1)
        cb->begin=cb->end;
    if(cb->begin==cb->end)
        cb->full=1;
    return 0;
}
int circular_buffer_pop_front(struct circular_buffer_t *cb, int *err_code)
{
    int x,y;
    if(cb==NULL||cb->ptr==NULL||cb->begin<0||cb->end<0||cb->capacity<0||cb->begin>=cb->capacity||cb->end>=cb->capacity)
    {
        if(err_code!=NULL)
            *err_code=1;
    }
    else if(circular_buffer_empty(cb)!=0)
    {
        if(err_code!=NULL)
            *err_code=2;
    }
    else
    {
        y=*(cb->ptr+cb->begin);
        x=cb->begin+1;
        while(x>=cb->capacity)
        {
            x=x-cb->capacity;
        }
        cb->begin=x;
        cb->full=0;
        if(err_code!=NULL)
            *err_code=0;
    }
    return y;
}
int circular_buffer_pop_back(struct circular_buffer_t *cb, int *err_code)
{
    int x,y;
    if(cb==NULL||cb->ptr==NULL||cb->begin<0||cb->end<0||cb->capacity<0||cb->begin>=cb->capacity||cb->end>=cb->capacity)
    {
        if(err_code!=NULL)
            *err_code=1;
    }
    else if(circular_buffer_empty(cb)!=0)
    {
        if(err_code!=NULL)
            *err_code=2;
    }
    else
    {
        y=*(cb->ptr+cb->begin);
        x=(cb->end+cb->capacity-1);
        while(x>=cb->capacity)
        {
            x=x-cb->capacity;
        }
        cb->end=x;
        y=*(cb->ptr+x);
        cb->full=0;
        if(err_code!=NULL)
            *err_code=0;
    }
    return y;
}
int circular_buffer_empty(const struct circular_buffer_t *cb)
{
    if(cb==NULL||cb->ptr==NULL||cb->begin<0||cb->end<0||cb->capacity<0||cb->begin>=cb->capacity||cb->end>=cb->capacity)
    {
        return -1;
    }
    else if(cb->full==0&&cb->begin==cb->end)
    {
        return 1;
    }
    return 0;
}
int circular_buffer_full(const struct circular_buffer_t *cb)
{
    if(cb==NULL||cb->ptr==NULL||cb->begin<0||cb->end<0||cb->capacity<0||cb->begin>=cb->capacity||cb->end>=cb->capacity)
    {
        return -1;
    }
    else if(cb->full==1)
    {
        return 1;
    }
    return 0;
}
void circular_buffer_display(const struct circular_buffer_t *cb)
{
    if(!(cb==NULL||cb->ptr==NULL||cb->begin<0||cb->end<0||cb->capacity<0||cb->begin>=cb->capacity||cb->end>=cb->capacity||circular_buffer_empty(cb)!=0))
    {
        int i,x;
        i=cb->begin;
        do
        {
            printf("%d ", *(cb->ptr+i));
            x=(i+1);
            while(x>=cb->capacity)
            {
                x=x-cb->capacity;
            }
            i=x;
        }
        while(i!=cb->end);
    }
}

