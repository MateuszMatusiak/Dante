#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{

    struct array_t src,odd,even;
    int n,t,i,x=1,tt=0;
    printf("Daj: ");
    t=scanf("%d",&n);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(n<=0)
    {
        printf("incorrect input data");
        return 2;
    }
    t=array_create(&src,n);
    if(t!=0)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    i=0;
    printf("Daj: ");
    while(x!=0)
    {

        t=scanf("%d",&x);
        if(t!=1)
        {
            array_destroy(&src);
            printf("Incorrect input");
            return 1;
        }
        if(i==0&&x==0)
        {
            array_destroy(&src);
            printf("Not enough data available");
            return 3;
        }
        if(src.size==src.capacity/2)
        {
            t=array_create(&odd,n);
            if(t!=0)
            {
                array_destroy(&src);
                printf("Failed to allocate memory");
                return 8;
            }
            else
            {
                array_destroy(&odd);
            }
        }
        if(src.size>n)
        {
            printf("Buffer is full\n");
        }
        t=array_push_back(&src,x);
        if(t==1)
        {
            array_destroy(&src);
            printf("Incorrect input");
            return 1;
        }
        if(t==2)
        {
          tt++;
        }
        if(src.size>n||tt==2)
        {
            printf("Buffer is full\n");
        }
        i++;
    }


    t=array_separate(&src,&odd,&even);
    if(t==-1||t==0)
    {
        array_destroy(&src);
        printf("Failed to allocate memory");
        return 8;
    }
    else if(t==1)
    {
        for(i=0; i<odd.size; i++)
            printf("%d ",*(odd.ptr+i));
        printf("\nBuffer is empty");
        array_destroy(&src);
        array_destroy(&odd);
    }
    else if(t==2)
    {
        printf("Buffer is empty\n");
        for(i=0; i<even.size; i++)
            printf("%d ",*(even.ptr+i));
        array_destroy(&src);
        array_destroy(&even);
    }
    else
    {
        for(i=0; i<odd.size; i++)
            printf("%d ",*(odd.ptr+i));
        printf("\n");
        for(i=0; i<even.size; i++)
            printf("%d ",*(even.ptr+i));
        array_destroy(&src);
        array_destroy(&even);
        array_destroy(&odd);
    }

    return 0;
}

