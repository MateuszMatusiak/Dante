#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,t;
    printf("Podaj liczbe 0-10: ");
    t=scanf("%d",&x);
    switch(t)
    {
    case 1:
    {
        break;
    }
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    }
    switch(x)
    {
    case 0:
    {
        printf("zero");
        break;
    }
    case 1:
    {
        printf("jeden");
        break;
    }
    case 2:
    {
        printf("dwa");
        break;
    }
    case 3:
    {
        printf("trzy");
        break;
    }
    case 4:
    {
        printf("cztery");
        break;
    }
    case 5:
    {
        printf("piec");
        break;
    }
    case 6:
    {
        printf("szesc");
        break;
    }
    case 7:
    {
        printf("siedem");
        break;
    }
    case 8:
    {
        printf("osiem");
        break;
    }
    case 9:
    {
        printf("dziewiec");
        break;
    }
    case 10:
    {
        printf("dziesiec");
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
