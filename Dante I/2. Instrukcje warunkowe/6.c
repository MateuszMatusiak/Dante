#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1,x2,t;
    printf("Podaj pierwsza liczbe: ");
    t=scanf("%d",&x1);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj druga liczbe: ");
    t=scanf("%d",&x2);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(x2==0)
    {
        printf("Operation not permitted");
        return 1;
    }
    if(x1%x2==0)
    {
        printf("%d is divisible by %d",x1,x2);
    }
    if(x1%x2!=0)
    {
        printf("%d is not divisible by %d",x1,x2);
    }
    return 0;
}
