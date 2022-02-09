#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,t;
    printf("Podaj liczbe: ");
    t=scanf("%d",&x);
    switch((abs(x)%2)+t)
    {
    case 2:
    {
        printf("%d is odd",x);
        break;
    }
    case 1:
    {
        printf("%d is even",x);
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
