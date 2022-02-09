#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y;
    int t;
    printf("Podaj liczbe: ");
    t=scanf("%f",&x);
    getchar();
    if(t!=1)
    {
        printf("incorrect input");
        return 1;
    }
    while(x!=0)
    {
        y=x;
        printf("Podaj liczbe: ");
        t=scanf("%f",&x);
        getchar();
        if(t!=1)
        {
            printf("incorrect input");
            return 1;
        }
        if(x==0)
            break;
        printf("%f\n",x-y);
    }
    return 0;
}
