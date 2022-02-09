#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a,b,c;
    printf("podaj a ");
    scanf("%f", &a);
    printf("podaj b ");
    scanf("%f", &b);
    c=sqrt((a*a)+(b*b));
    printf("przeciwprostokatna: %.2f",c);
    printf("\nkat 1: %.2f",asin(a/c)*(180/M_PI));
    printf("\nkat 2: %.2f",asin(b/c)*(180/M_PI));


    return 0;
}
