#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long x;
    int t=0,o=0,p=0;
    printf("Podaj liczbe: ");
    t=scanf("%llu",&x);
    if(t!=1)
    {
        printf("incorrect input");
        return 1;
    }
    o=x%10;
    while(x>0)
    {
        if(x/10==0)
        {
            p=x;
            break;
        }
        x=x/10;
    }
    printf("pierwsza %d\nostatnia %d",p,o);
    return 0;
}
