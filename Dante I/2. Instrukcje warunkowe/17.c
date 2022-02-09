#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    float x;
    printf("Podaj wartosc: ");
    t=scanf("%f",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if((x>=-5)&&(x<=5))
    {
        printf("%f",2*x*x+3*x-1);
        return 0;
    }
    if(x<-5)
    {
        printf("%f",(x+5)*(x+5)-10);
        return 0;
    }
    if(x>5)
    {
        printf("%f",((x/2)-2)*(2-(3*x/4)));
        return 0;
    }
    return 0;
}
