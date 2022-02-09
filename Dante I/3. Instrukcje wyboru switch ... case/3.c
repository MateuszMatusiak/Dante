#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, x1, x2;
    printf("Podaj liczbe: ");
    t=scanf("%d %d",&x1,&x2);
    switch(t)
    {
    case 2:
        break;
    default:
        {
            printf("Incorrect input");
            return 1;
        }
    }
    switch(x1>x2)
    {
    case 1:
        {
            printf("%d\n%d",x1,x2);
            break;
        }
    default:
        {
            printf("%d\n%d",x2,x1);
            break;
        }
    }
    return 0;
}
