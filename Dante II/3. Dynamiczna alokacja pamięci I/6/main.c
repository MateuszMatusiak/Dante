#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    int s, x,t;
    struct array_t a;

    printf("Daj: ");
    t=scanf("%d", &s);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(s<= 0)
    {
        printf("Incorrect input data");
        return 2;
    }
    t=array_create(&a, s);
    if(t==1||t==2)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Daj:");
    do
    {
        t=scanf("%d", &x);
        if(t!=1)
        {
            printf("Incorrect input");
            array_destroy(&a);
            return 1;
        }

        if(x!=0)
            array_push_back(&a, x);
    }
    while(x!=0);

    if(a.size == a.capacity)
        printf( "Buffer is full\n");

    if(a.size == 0)
        printf( "Buffer is empty");
    else
        array_display(&a);

    array_destroy(&a);
    return 0;
}

