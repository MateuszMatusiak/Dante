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
    case 2:
    case 3:
    case 4:
    case 5:
    {
        printf("Dzien roboczy");
        break;
    }
    case 6:
    case 7:
        {
            printf("Weekend");
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
