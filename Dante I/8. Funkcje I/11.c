#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_prime(int a)
{
    int i;
    if(a==0)
        return 0;
    if(a==1)
        return 0;
    if(a<0)
        return 0;
    for(i=2; i<a/2+1; i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int x,y,t,o=0;
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
        if(is_prime(i)==1)
        {
            printf("%d ",i);
            o++;
        }
    }
    if(o==0)
        printf("Nothing to show");

    return 0;
}

