#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x1, x2;
    printf("Podaj pierwsza liczbe ");
    scanf("%f", &x1);
    printf("Podaj druga liczbe ");
    scanf("%f", &x2);
    printf("%f",x1+x2);
    printf("\n%f",x1-x2);
    printf("\n%f",x1*x2);
    printf("\n%f",x1/x2);

    return 0;
}
