#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    int s, x,t,c,l=0;
    struct array_t *a;

    printf("Daj wielkosc: ");
    t=scanf("%d", &s);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(s<=0)
    {
        printf("Incorrect input data");
        return 2;
    }
    t=array_create_struct(&a, s);
    if(t==1||t==2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    while(1)
    {
        while(getchar()!='\n');
        printf("Daj wybor:");
        t=scanf("%d",&c);
        if(t!=1)
        {
            printf("incorrect input");
            array_destroy_struct(&a);
            return 1;
        }
        if(c==1)
        {
            printf("Daj add:");
            l=0;
            do
            {
                t=scanf("%d", &x);
                if(t!=1)
                {
                    printf("Incorrect input");
                    array_destroy_struct(&a);
                    return 1;
                }
                if(l >= a->capacity)
                    printf( "Buffer is full\n");
                if(x==0||l==a->capacity)
                    break;
                if(x!=0)
                {
                    t=array_push_back(a, x);
                    if(t!=0)
                    {
                        printf("Incorrect input");
                        array_destroy_struct(&a);
                        return 1;
                    }
                    l++;
                }
            }
            while(1);



            if(a->size == 0)
                printf( "Buffer is empty\n");
            else
            {
                array_display(a);
                printf("\n");

            }
        }
        else if(c==2)
        {
            l=0;
            printf("Daj del: ");
            do
            {
                t=scanf("%d", &x);
                if(t!=1)
                {
                    printf("Incorrect input");
                    array_destroy_struct(&a);
                    return 1;
                }
                l++;
                if(x==0)
                    break;
                array_remove_item(a,x);


            }
            while(1);
            if(a->size == 0)
                printf( "Buffer is empty\n");
            else
            {

                array_display(a);
                printf("\n");

            }
        }
        else if (c==0)
        {
            break;
        }
        else
        {
            printf("Incorrect input data\n");
        }
    }

    array_destroy_struct(&a);

    return 0;
}

