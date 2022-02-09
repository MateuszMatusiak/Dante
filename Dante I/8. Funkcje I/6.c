#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

float add(float x, float y)
{
    return x+y;
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
    printf("%f",add(x,y));
    return 0;
}

