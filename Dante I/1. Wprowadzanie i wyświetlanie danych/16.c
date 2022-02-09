#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c;
    printf("podaj pierwsza wartosc ");
    scanf("%d",&a);
    printf("podaj druga wartosc ");
    scanf("%d",&b);
    printf("podaj trzecia wartosc ");
    scanf("%d",&c);

    printf("%.2f",sqrt((a*a)+(b*b)+(c*c)));

    return 0;
}
