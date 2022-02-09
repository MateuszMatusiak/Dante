#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b;
    int t;
    printf("podaj a: ");
    t=scanf("%f",&a);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("podaj b: ");
    t=scanf("%f",&b);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if((a+b)*(a-b)==(a*a)+(b*b))
    {
        printf("tozsamosc jest prawdziwa");
        return 0;
    }
    else
    {
        printf("tozsamosc nie jest prawdziwa");
        return 0;
    }

}
