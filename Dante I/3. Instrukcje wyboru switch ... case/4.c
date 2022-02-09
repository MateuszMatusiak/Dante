#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,k,t;
    printf("Podaj liczbe: ");
    t=scanf("%d",&x);
    k=(((x==0)*2+(x>0)*4+(x<0)*6)+t);
    switch(k)
    {
    case 3:
    {
        printf("%d is equal to 0",x);
        break;
    }
    case 5:
    {
        printf("%d is positive",x);
        break;
    }
    case 7:
    {
        printf("%d is negative",x);
        break;
    }
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    }
    return 0;
}
