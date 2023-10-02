#include <stdio.h>
#include <stdlib.h>
#include "circular_buffer.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    struct circular_buffer_t *p;
    int t, n,x=1;
    printf("Daj: ");
    t=scanf("%d",&n);
    if(t!=1)
    {
        printf("Incorrect input\n");
        return 1;
    }
    if(n<=0)
    {
        printf("Incorrect input data\n");
        return 2;
    }
    t=circular_buffer_create_struct(&p,n);
    if(t!=0)
    {
        printf("Failed to allocate memory\n");
        return 8;
    }
    while(x!=0)
    {
        printf("Daj: ");
        t=scanf("%d",&x);
        if(t!=1)
        {
            printf("Incorrect input\n");
            circular_buffer_destroy_struct(&p);
            return 1;
        }
        if(x<0||x>6)
        {
            printf("Incorrect input data\n");
            continue;
        }
        else if(x==1)
        {
            printf("Daj: ");
            t=scanf("%d",&n);
            if(t!=1)
            {
                printf("Incorrect input\n");
                circular_buffer_destroy_struct(&p);
                return 1;
            }
            circular_buffer_push_back(p,n);
        }
        else if(x==2)
        {
            n=circular_buffer_pop_back(p,&t);
            if(t!=0)
            {
                printf("Buffer is empty\n");
            }
            else
                printf("%d\n",n);
        }
        else if(x==3)
        {
            n=circular_buffer_pop_front(p,&t);
            if(t!=0)
            {
                printf("Buffer is empty\n");
            }
            else
                printf("%d\n",n);
        }
        else if(x==4)
        {
            t=circular_buffer_empty(p);
            if(t!=0)
            {
                printf("Buffer is empty");
            }
            else
                circular_buffer_display(p);
            printf("\n");
        }
        else if(x==5)
        {
            t=circular_buffer_empty(p);
            if(t!=0)
            {
                printf("1\n");
            }
            else
                printf("0\n");
        }
        else if(x==6)
        {
            t=circular_buffer_full(p);
            if(t!=0)
            {
                printf("1\n");
            }
            else
                printf("0\n");
        }
    }
    circular_buffer_destroy_struct(&p);
    return 0;
}

