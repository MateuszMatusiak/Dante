#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, t;
    printf("Podaj wartosc: ");
    t=scanf("%d",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(x<0)
    {
        printf("ujemna");
        return 0;
    }
    if(x>0)
    {
        printf("dodatnia");
        return 0;
    }
    if(x==0)
    {
        printf("zerowa");
        return 0;
    }

}
