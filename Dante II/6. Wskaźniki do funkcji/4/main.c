#include <stdio.h>
#include <stdlib.h>
#include "for_loop.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    p funcs[]= {print_value, print_accumulated, print_square, print_abs};
    float a, b,c;
    int x,t;
    printf("Daj: ");
    t=scanf("%f %f %f",&a, &b, &c);
    if(t!=3)
    {
        printf("Incorrect input");
        return 1;
    }
    if(b==0)
    {
        printf("Incorrect input data");
        return 2;
    }
    if((a>c&&b>0)||(a<c&&b<0))
    {
        printf("Incorrect input data");
        return 2;
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
    for_loop(a,b,c,*(funcs+x));
    return 0;
}

