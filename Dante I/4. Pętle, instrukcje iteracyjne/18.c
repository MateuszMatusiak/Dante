#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sumap=0,sumanp=0,x,t;
    printf("daj: ");
    while(1)
    {
        t=scanf("%d",&x);
        if(t!=1)
        {
            printf("incorrect input");
            return 1;
        }
        if(x==-1)
            break;
        if(x%2==0)
            sumap=sumap+x;
        else
            sumanp=sumanp+x;
    }
    printf("Suma parz: %d\nSuma nieparz: %d",sumap,sumanp);
    return 0;
}
