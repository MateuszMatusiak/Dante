#include <stdio.h>
#include <stdlib.h>
#include "int_operations.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    p funcs[]={add_int, sub_int, div_int, mul_int};
    int a, b, x, w, t;
    printf("Daj: ");
    t=scanf("%d %d",&a, &b);
    if(t!=2)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Daj: ");
    t=scanf("%d",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(x<0||x>3)
    {
       printf("Incorrect input data");
       return 2;
    }
    w=calculate(a,b,*(funcs+x));
    printf("%d",w);

    return 0;
}

