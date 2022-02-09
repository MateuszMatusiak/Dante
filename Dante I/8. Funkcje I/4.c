#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int sign(int value)
{
    switch (value)
    {
    case 0:
    {
        return 0;
    }
    default:
    {
        return value/abs(value);
    }
    }
}

int main()
{
    int k,t;
    printf("Daj: ");
    t=scanf("%d",&k);
    switch(t)
    {
    case 1:
    {
        break;
    }
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    }


    switch (sign(k))
    {
    case 1:
    {
        printf("positive");
        break;
    }
    case 0:
    {
        printf("zero");
        break;
    }
    default:
    {
        printf("negative");
    }
    }
    return 0;
}

