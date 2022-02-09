#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p;
    float x;
    printf("podaj liczbe ");
    scanf("%f",&x);
    printf("podaj dokl ");
    scanf("%d",&p);
    printf("%.*f",p,x);
    return 0;
}
