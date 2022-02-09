#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t;
    float r;
    do
    {
        printf("Podaj liczbe: ");
        t=scanf("%f",&r);
        getchar();
        if((r<=0)||(t!=1))
        {
            printf("Incorrect input\n");
        }
    }
    while((r<=0)||(t!=1));
    printf("obwod %.3f\n",(2*M_PI*r));
    printf("pole %.3f",(M_PI*r*r));
    return 0;
}
