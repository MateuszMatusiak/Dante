#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int even_odd(int s, int n)
{
    if(n<0)
        return -1;
    int x;
    if(n==0)
        return s;
    else
    {
        x=even_odd(s, n-1);
        if(x%2==0)
            return (x/2);

        else if((x%2==1)||(x%2==-1))
            return (3*x+1);

    }
    return 0;
}
int main()
{
    int n,t,s;
    printf("Daj: ");
    t=scanf("%d",&s);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Daj: ");
    t=scanf("%d",&n);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(n<0)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("%d",even_odd(s,n));
    return 0;
}

