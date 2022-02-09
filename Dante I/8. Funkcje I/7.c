#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

float add(float x, float y)
{
    return x+y;
}
float subtract(float x, float y)
{
    return x-y;
}
float multiply(float x, float y)
{
    return x*y;
}
float divide(float x,float y)
{
    if(y==0)
        return -1;
    else
        return x/y;
}

int main()
{
    float x,y;
    int t;
    printf("Daj: ");
    t=scanf("%f",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Daj: ");
    t=scanf("%f",&y);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Suma %f\n",add(x,y));
    printf("Roznica %f\n",subtract(x,y));
    printf("Iloczyn %f\n",multiply(x,y));
    if(y==0)
    {
        printf("operation not permitted");
        return 0;
    }
    else
        printf("Iloraz %f",divide(x,y));
    return 0;
}

