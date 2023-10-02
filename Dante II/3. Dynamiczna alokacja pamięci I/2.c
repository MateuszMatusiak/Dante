#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    float *x;
    x=(float*)calloc(1,sizeof(float));
    if(x==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    *x=M_PI;
    printf("%f %p",*x, (void*)x);
    free(x);
    return 0;
}

