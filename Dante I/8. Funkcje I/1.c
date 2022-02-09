#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int test1(int a)
{
   return a;
}


int main()
{
    int k,t;
    printf("Daj: ");
    t=scanf("%d",&k);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%d",test1(k));
    return 0;
}

