#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,t;
    printf("Podaj liczbe 0-10: ");
    t=scanf("%d",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if((x<0)||(x>10))
    {
        printf("blad");
        return 0;
    }
    if(x==0)
    {
        printf("zero");
        return 0;
    }
    if(x==1)
    {
        printf("jeden");
        return 0;
    }
    if(x==2)
    {
        printf("dwa");
        return 0;
    }
    if(x==3)
    {
        printf("trzy");
        return 0;
    }
    if(x==4)
    {
        printf("cztery");
        return 0;
    }
    if(x==5)
    {
        printf("piec");
        return 0;
    }
    if(x==6)
    {
        printf("szesc");
        return 0;
    }
    if(x==7)
    {
        printf("siedem");
        return 0;
    }
    if(x==8)
    {
        printf("osiem");
        return 0;
    }
    if(x==9)
    {
        printf("dziewiec");
        return 0;
    }
    if(x==10)
    {
        printf("dziesiec");
        return 0;
    }
}
