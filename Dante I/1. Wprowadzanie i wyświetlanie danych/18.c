#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x1, x2, x3, x4, x5;
    printf("podaj liczbe 1 ");
    scanf("%f",&x1);
    printf("podaj liczbe 2 ");
    scanf("%f",&x2);
    printf("podaj liczbe 3 ");
    scanf("%f",&x3);
    printf("podaj liczbe 4 ");
    scanf("%f",&x4);
    printf("podaj liczbe 5 ");
    scanf("%f",&x5);
    printf("%.4f",(x1+x2+x3+x4+x5)/5.0);

    return 0;
}
