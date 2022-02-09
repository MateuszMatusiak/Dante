#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned long sum_rec(int n)
{
    if(n==1)
        return 1;
    if(n>1)
        return sum_rec(n-1)+n;
    else
        return 0;
}
int main()
{
    int n,t;
    printf("Daj: ");
    t=scanf("%d",&n);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(n<=0)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("%lu",sum_rec(n));
    return 0;
}

