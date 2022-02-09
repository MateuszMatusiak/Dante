#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x,suma=0;
    int t,i;
    printf("daj 10: ");
    for(i=0;i<10;i++)
    {
        t=scanf("%f",&x);
        if(t!=1)
    {
        printf("incorrect input");
        return 1;
    }
        suma=suma+fabs(x);
    }
    printf("%.2f",suma);
    return 0;
}
