#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int add(int x, int y)
{
    return x+y;
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
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%d",add(x,y));
    return 0;
}

