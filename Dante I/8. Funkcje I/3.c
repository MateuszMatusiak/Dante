#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"


float circumference(float b)
{
    if(b<=0)
        return -1;
    else
    return M_PI*b;
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
    if(circumference(k)==-1)
    {
       printf("Incorrect input");
       return 1;
    }
    else
    printf("obwod= %f",circumference(k));
    return 0;
}

