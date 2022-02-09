#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int compare(int x, int y, int z)
{
    if(x==y)
    {
        if(y==z)
        {
            if(z==x)
            {
                return 1;
            }

            else
                return 0;

        }
        else
            return 0;
    }
    else
        return 0;
}

int main()
{
    int x,y,z,t;
    printf("Daj: ");
    t=scanf("%d-%d-%d",&x,&y,&z);
    if(t!=3)
    {
        printf("Incorrect input");
        return 1;
    }
    if(compare(x,y,z)==1)
        printf("EQUAL");
    else
        printf("NOT EQUAL");
    return 0;
}

