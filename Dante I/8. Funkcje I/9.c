#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

float poly(float x)
{
    return(5*x*x+12.55*x+0.75);
}

int main()
{
    float x;
    int t;
   printf("Daj: ");
    t=scanf("%f",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("wynik %f",poly(x));
    return 0;
}

