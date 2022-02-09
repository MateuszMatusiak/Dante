#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

float quadratic_equation(float a, float b, float c, float x)
{
    return (a*x*x+b*x+c);
}
int main()
{
    float x,a,b,c;
    int t;
    printf("Daj rownianie: ");
    t=scanf("%fx^2%fx%f",&a,&b,&c);
    if(t!=3)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Daj x: ");
    t=scanf("%f",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%f",quadratic_equation(a,b,c,x));
    return 0;
}

