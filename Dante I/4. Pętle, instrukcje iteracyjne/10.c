#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,suma=0;
    int t,i;
    for(i=0;i<10;i++)
    {
        printf("Podaj liczbe: ");
        t=scanf("%f",&x);
        if(t!=1)
        {
            printf("Incorrect input");
            return 1;
        }
        suma=suma+x;
    }
    printf("%f",suma);
    return 0;
}
