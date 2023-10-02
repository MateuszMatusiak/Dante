#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    int t,s,i,x;
    int *tab;
    p *funcs;
    funcs=(p*)calloc(4,sizeof(p));
    if(funcs==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    *funcs=comp_int;
    *(funcs+1)=comp_int_abs;
    *(funcs+2)=comp_int_length;
    *(funcs+3)=comp_int_digits_sum;
    printf("Daj: ");
    t=scanf("%d",&s);
    if(t!=1)
    {
        free(funcs);
        printf("Incorrect input");
        return 1;
    }
    if(s<=0)
    {
        free(funcs);
        printf("Incorrect input data");
        return 2;
    }
    tab=(int*)calloc(s,sizeof(int));
    if(tab==NULL)
    {
        free(funcs);
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    for(i=0; i<s; i++)
    {
        t=scanf("%d",&x);
        if(t!=1)
        {
            free(funcs);
            free(tab);
            printf("Incorrect input");
            return 1;
        }
        *(tab+i)=x;
    }
    printf("Daj: ");
    t=scanf("%d",&x);
    if(t!=1)
    {
        free(funcs);
        free(tab);
        printf("Incorrect input");
        return 1;
    }
    if(x<0||x>3)
    {
        free(funcs);
        free(tab);
        printf("Incorrect input data");
        return 2;
    }
    sort_int(tab, s,*(funcs+x));
    for(i=0; i<s; i++)
        printf("%d ",*(tab+i));
    free(funcs);
    free(tab);
    return 0;
}

