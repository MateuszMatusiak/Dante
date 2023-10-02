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
int array_copy(const struct array_t *src, struct array_t *dest)
{
    if(src==NULL||dest==NULL||dest==src||src->ptr==NULL||src->size<=0||src->capacity<=0)
        return 1;
    int t,i;
    t=array_create(dest,src->size);
    if(t==1||t==2)
        return 2;
    for(i=0; i<src->size; i++)
    {
        *(dest->ptr+i)=*(src->ptr+i);
    }
    (dest->size)=(src->size);
    (dest->capacity)=(src->capacity);
    return 0;
}
int array_separate(const struct array_t *a, struct array_t *odd, struct array_t *even)
{
    if(a==NULL||odd==NULL||even==NULL||a->ptr==NULL||odd==even||odd==a||even==a||a->size<=0||a->capacity<=0||a->size!=a->capacity)
        return -1;
    int np=0, p=0,i,kp,knp,t;
    for(i=0; i<a->size; i++)
    {
        if(*(a->ptr+i)%2==0)
        {
            p++;
        }
        else
            np++;
    }
    odd->size=np;
    even->size=p;
    if(p==0&&np==0)
        return 1;
    else if(np>0&&p==0)
    {
        t=array_copy(a,odd);
        if(t!=0)
            return 0;
        return 1;
    }
    else if(np==0&&p>0)
    {
        t=array_copy(a,even);
        if(t!=0)
            return 0;
        return 2;
    }
    else
    {
        odd->ptr=(int*)malloc(np*sizeof(int));
        if(odd->ptr==NULL)
            return 0;

        even->ptr=(int*)malloc(p*sizeof(int));
        if(even->ptr==NULL)
        {
            free(odd->ptr);
            return 0;
        }
        kp=0;
        knp=0;
        for(i=0; i<a->size; i++)
        {
            if(*(a->ptr+i)%2==0)
            {
                *(even->ptr+kp)=*(a->ptr+i);
                kp++;
            }
            else
            {
                *(odd->ptr+knp)=*(a->ptr+i);
                knp++;
            }
        }
        odd->capacity=knp;
        even->capacity=kp;
        if(kp==0&&knp>0)
            return 1;
        if(kp>0&&knp==0)
            return 2;
    }
    return 3;
}


