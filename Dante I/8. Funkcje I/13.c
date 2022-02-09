#include <stdio.h>
#include <stdlib.h>
#include "expected_prototypes.h"

int czy_pierwsza(int a)
{
    int i;
    if(a<=1)
        return 0;
    for(i=2; i<a/2+1; i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}

int goldbach(int x)
{
    int i,o=0;
    if(x%2==0)
        for(i=0; i<x; i++)
        {

            if((czy_pierwsza(i)==1)&&(czy_pierwsza(x-i)==1))
            {
                printf("(%d, %d) ",i,x-i);
                o++;
            }
        }
    if(o>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int x,y,t;
    printf("Daj: ");
    t=scanf("%d",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Daj: ");
    t=scanf("%d",&y);
    if((t!=1)||(y<x))
    {
        printf("Incorrect input");
        return 1;
    }
    for(int i=x; i<=y; i++)
    {
        if(i%2==0)
        {
            printf("%d: ",i);
            goldbach(i);
            printf("\n");
        }
    }


    return 0;
}

