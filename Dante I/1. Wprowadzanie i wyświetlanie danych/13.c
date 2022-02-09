#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, x2;
    printf("Podaj pierwsza liczbe ");
    scanf("%d", &x1);
    printf("Podaj druga liczbe ");
    scanf("%d", &x2);
    printf("%i",x1+x2);
    printf("\n%i",x1-x2);
    printf("\n%i",x1*x2);
    printf("\n%i",x1/x2);

    return 0;
}
