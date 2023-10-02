#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    int t,s,i;
    p *funct;
    printf("Daj: ");
    t=scanf("%d",&s);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(s<=0)
    {
        printf("Incorrect input data");
        return 2;
    }
    funct=easter(s, print_chicken, print_egg, print_rabbit);
    if(funct==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    for(i=0;i<s;i++)
    {
        (*(funct+i))();
        printf("\n");
    }
    free(funct);
    return 0;
}

