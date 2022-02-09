#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[10][10];
    int i,k,sumap=0,sumanp=0,t;
    printf("Daj: ");
    for(i=0;i<10;i++)
    {
        for(k=0;k<10;k++)
        {
            t=scanf("%d",&tab[i][k]);
            if(t!=1)
            {
                printf("incorrect input");
                return 1;
            }
        }
    }
    for(i=0;i<10;i++)
    {
        for(k=0;k<10;k++)
        {
            if((i+k)%2==0)
                sumap=sumap+tab[i][k];
            else
                sumanp=sumanp+tab[i][k];
        }
    }
    printf("%d",sumap-sumanp);

    return 0;
}
