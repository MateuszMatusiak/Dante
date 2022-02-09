#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

long int fibonacci(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n>1)
        return fibonacci(n-1)+fibonacci(n-2);
    return -1;
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
    if(n<0)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("%li",fibonacci(n));
    return 0;
}

