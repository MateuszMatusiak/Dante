#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Podaj liczbe 1-7: ");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
    {
        printf("poniedzialek");
        break;
    }
    case 2:
    {
        printf("wtorek");
        break;
    }
    case 3:
    {
        printf("sroda");
        break;
    }
    case 4:
    {
        printf("czwartek");
        break;
    }
    case 5:
    {
        printf("piatek");
        break;
    }
    case 6:
    {
        printf("sobota");
        break;
    }
    case 7:
    {
        printf("niedziela");
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
