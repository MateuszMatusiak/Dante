#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned int swap_bits(unsigned int * pvalue, int b1, int b2)
{
    if(b1>31||b2>31||pvalue==NULL||b1<0||b2<0)
        return 1;
    if(!((*pvalue)&1<<b1)&&((*pvalue)&1<<b2))
    {
        (*pvalue)|=1<<b1;
        (*pvalue)&=~(1<<b2);
    }else if(((*pvalue)&1<<b1)&&!((*pvalue)&1<<b2))
    {
        (*pvalue)|=1<<b2;
        (*pvalue)&=~(1<<b1);
    }
    return 0;
}

int main() {
    unsigned int x;
    printf("Daj: ");
    int t= scanf("%u",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }

    int x1,x2;
    printf("Daj: ");
    t= scanf("%d",&x1);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if((int)x1<0)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Daj: ");
    t= scanf("%d",&x2);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if((int)x2<0)
    {
        printf("Incorrect input");
        return 1;
    }
    swap_bits(&x,x1,x2);
    printf("%u",x);
    return 0;
}

