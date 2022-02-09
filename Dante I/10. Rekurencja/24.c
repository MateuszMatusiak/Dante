#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

void gwiazd(int n)
{
    printf("* ");
    if(n==1)
        return;
    gwiazd(n-1);
}

void rectangular_triangle(int n)
{
    if(n<=0)
        return;
    if(n>1)
    {
        rectangular_triangle(n-1);
        printf("\n");
    }
    gwiazd(n);

    return;
}


int main()
{
    int n,t;
    printf("Daj: ");
    t=scanf("%d", &n);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(n<1)
    {
        printf("Incorrect input data");
        return 2;
    }
    rectangular_triangle(n);
    return 0;
}


