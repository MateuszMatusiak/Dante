#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main()
{
    struct array_t *a1, *a2, *a3, *a4, *a5, *a6;
    int t,x,i,wi,t1=0,t2=0;
    float n,wf;
    printf("Daj: ");
    t=scanf("%d", &x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(x<=0)
    {
        printf("Incorrect input data");
        return 2;
    }
    t=array_create_struct_float(&a1, x);
    if(t!=0)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    for(i=0; i<x; i++)
    {
        t=scanf("%f",&n);
        if(t!=1)
        {
            printf("Incorrect input");
            array_destroy_struct_float(&a1);
            return 1;
        }
        array_push_back_float(a1,n);
    }


    printf("Daj: ");
    t=scanf("%d", &x);
    if(t!=1)
    {
        array_destroy_struct_float(&a1);
        printf("Incorrect input");
        return 1;
    }
    if(x<=0)
    {
        array_destroy_struct_float(&a1);
        printf("Incorrect input data");
        return 2;
    }
    t=array_create_struct_float(&a2, x);
    if(t!=0)
    {
        array_destroy_struct_float(&a1);
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    for(i=0; i<x; i++)
    {
        t=scanf("%f",&n);
        if(t!=1)
        {
            printf("Incorrect input");
            array_destroy_struct_float(&a1);
            array_destroy_struct_float(&a2);
            return 1;
        }
        array_push_back_float(a2,n);
    }
    wi=add_vectors(a1,a2,&a3);
    if(wi==1)
    {
        t1=1;
        printf("Operation not permitted\n");
    }
    else if(wi==2)
    {
        printf("Failed to allocate memory");
        array_destroy_struct_float(&a1);
        array_destroy_struct_float(&a2);
        return 8;
    }
    else
    {
        array_display_float(a3);
        printf("\n");
    }
    wi=subtract_vectors(a1,a2,&a4);
    if(wi==1)
    {
        t2=1;
        printf("Operation not permitted\n");
    }
    else if(wi==2)
    {
        printf("Failed to allocate memory");
        array_destroy_struct_float(&a1);
        array_destroy_struct_float(&a2);
        array_destroy_struct_float(&a3);
        return 8;
    }
    else
    {
        array_display_float(a4);
        printf("\n");
    }
    wf=dot_product(a1,a2);
    if(wf==-1)
        printf("Operation not permitted\n");
    else
        printf("%.2f\n", wf);

    wf=angle_between_vectors(a1,a2);
    if(wf==-1)
        printf("Operation not permitted\n");
    else
        printf("%.2f\n", wf);

    wf = length(a1);
    if(wf == -1)
        printf("Operation not permitted\n");
    else
        printf("%.2f\n", wf);

    wf = length(a2);
    if( wf == -1)
        printf("Operation not permitted\n");
    else
        printf("%.2f\n", wf);

    wi=normalize_vector(a1,&a5);
    if(wi==1||wi==3)
        printf("Operation not permitted\n");
    else if(wi==2)
    {
        printf("Failed to allocate memory");
        array_destroy_struct_float(&a1);
        array_destroy_struct_float(&a2);
        array_destroy_struct_float(&a3);
        array_destroy_struct_float(&a4);
        return 8;
    }
    else
    {
        array_display_float(a5);
        printf("\n");
    }

    wi=normalize_vector(a2,&a6);
    if(wi==1||wi==3)
        printf("Operation not permitted\n");
    else if(wi==2)
    {
        printf("Failed to allocate memory");
        array_destroy_struct_float(&a1);
        array_destroy_struct_float(&a2);
        array_destroy_struct_float(&a3);
        array_destroy_struct_float(&a4);
        array_destroy_struct_float(&a5);
        return 8;
    }
    else
    {
        array_display_float(a6);
        printf("\n");
    }
    array_destroy_struct_float(&a1);
    array_destroy_struct_float(&a2);
    if(t1==0)
        array_destroy_struct_float(&a3);
    if(t2==0)
        array_destroy_struct_float(&a4);
    array_destroy_struct_float(&a5);
    array_destroy_struct_float(&a6);
    return 0;
}

