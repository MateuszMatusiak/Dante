#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

int array_create_float(struct array_t *a, int N)
{
    if(a==NULL)
        return 1;
    if(N<=0)
        return 1;
    a->ptr=(float*)malloc(N*sizeof(float));
    if(a->ptr==NULL)
        return 2;
    a->size=0;
    a->capacity=N;
    return 0;
}
int array_push_back_float(struct array_t *a, float value)
{
    if(a == NULL || a->ptr == NULL || a->capacity <= 0 || a->size < 0 || a->size > a->capacity )
        return 1;
    if(a->size == a->capacity)
        return 2;
    *(a->ptr + a->size) = value;
    a->size=a->size+1;
    return 0;
}
void array_display_float(const struct array_t *a)
{
    if((a==NULL || a->ptr==NULL || a->size<=0 || a->capacity<=0 || a->size>a->capacity))
        return;
    int i;
    for(i=0; i<a->size; i++)
    {
        printf("%.2f ",*(a->ptr+i));
    }

}
void array_destroy_float(struct array_t *a)
{
    if(a==NULL || a->ptr==NULL)
        return;
    free(a->ptr);
}
void array_destroy_struct_float(struct array_t **a)
{
    if(a!=NULL)
    {
        array_destroy_float(*a);
        free(*a);
    }
}
int array_create_struct_float(struct array_t **a, int N)
{
    if(a==NULL)
        return 1;
    int t;
    *a=(struct array_t *)malloc(sizeof(struct array_t));
    t=array_create_float(*a,N);
    if(t==1||t==2)
        free(*a);
    return t;
}
int add_vectors(const struct array_t *a, const struct array_t *b, struct array_t **c)
{
    if(a==NULL || a->ptr==NULL || b==NULL || b->ptr==NULL || c==NULL || a->size!=b->size || a->size<=0 || a->size>a->capacity || b->size>b->capacity)
        return 1;
    int i,t;
    float x;
    t=array_create_struct_float(c, a->size);
    if(t)
        return 2;
    for(i=0; i<a->size; i++)
    {
        x=*(a->ptr+i)+*(b->ptr+i);
        array_push_back_float(*c, x);
    }
    return 0;
}
int subtract_vectors(const struct array_t *a, const struct array_t *b, struct array_t **c)
{
    if(a==NULL || a->ptr==NULL || b==NULL || b->ptr==NULL || c==NULL || a->size!=b->size || a->size<=0 || a->size>a->capacity || b->size>b->capacity)
        return 1;
    int i,t;

    float x;
    t=array_create_struct_float(c, a->size);
    if(t)
        return 2;
    for(i=0; i<a->size; i++)
    {
        x=*(a->ptr+i)-*(b->ptr+i);
        array_push_back_float(*c, x);
    }
    return 0;
}
float dot_product(const struct array_t *a, const struct array_t *b)
{
    if(a==NULL || a->ptr==NULL || b==NULL || b->ptr==NULL || a->size!=b->size || a->size<=0 || a->size>a->capacity || b->size>b->capacity)
        return -1;
    float x=0,w=0;
    int i;
    for(i=0; i<a->size; i++)
    {
        x=*(a->ptr+i) * *(b->ptr+i);
        w=w+x;
    }
    return w;
}
float angle_between_vectors(const struct array_t *a, const struct array_t *b)
{
    if(a==NULL || a->ptr==NULL || b==NULL || b->ptr==NULL || a->size!=b->size || a->size<=0 || a->size>a->capacity || b->size>b->capacity)
        return -1;
    float k,l;
    l=length(a)*length(b);
    if(!l)
    {
        return -1;
    }
    k=dot_product(a,b)/l;
    k=acos(k);
    k=k*180/(2*asin(1));
    return k;
}
float length( const struct array_t *a)
{
    if(a==NULL || a->ptr==NULL || a->size<=0 || a->capacity<=0 || a->size>a->capacity)
        return -1;
    float l=0,x=0;
    int i;
    for(i=0; i<a->size; i++)
    {
        x=pow(*(a->ptr+i),2);
        l=l+x;
    }
    l=sqrt(l);
    return l;
}
int normalize_vector( const struct array_t *a, struct array_t **b)
{
    if( a == NULL || a->ptr == NULL || b == NULL || a->size <= 0 || a->size > a->capacity)
        return 1;
    float l;
    int t,i;
    l=length(a);
    if(l==0)
        return 3;
    t=array_create_struct_float( b, a->size);
    if(t!=0)
        return 2;

    for(i=0; i<a->size; i++)
        array_push_back_float(*b, *(a->ptr+i)/l);
    return 0;
}

