#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    p funcs[]= {comp_min, comp_max, comp_sum};
    int t,c,r,i,k,w,o;
    int **tab;
    printf("Daj: ");
    t=scanf("%d %d",&c,&r);
    if(t!=2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(c<=0||r<=0)
    {
        printf("Incorrect input data");
        return 2;
    }
    tab=(int**)calloc(r,sizeof(int*));
    if(tab==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    for(i=0; i<r; i++)
    {
        *(tab+i)=(int*)calloc(c,sizeof(int));
        if(*(tab+i)==NULL)
        {
            for(o=0; o<i; o++)
            {
                if(*(tab+o)!=NULL)
                {
                    free(*(tab+o));
                }
            }
            free(tab);
            printf("Failed to allocate memory");
            return 8;
        }
    }
    printf("Daj: ");
    for(i=0; i<r; i++)
    {
        for(k=0; k<c; k++)
        {
            t=scanf("%d",(*(tab+i)+k));
            if(t!=1)
            {
                for(o=0; o<r; o++)
                {
                    if(*(tab+o)!=NULL)
                    {
                        free(*(tab+o));
                    }
                }
                free(tab);
                printf("Incorrect input");
                return 1;
            }
        }
    }
    printf("Daj: ");
    t=scanf("%d",&w);
    if(t!=1)
    {
        for(o=0; o<r; o++)
        {
            if(*(tab+o)!=NULL)
            {
                free(*(tab+o));
            }
        }
        free(tab);
        printf("Incorrect input");
        return 1;
    }
    if(w<0||w>2)
    {
        for(o=0; o<r; o++)
        {
            if(*(tab+o)!=NULL)
            {
                free(*(tab+o));
            }
        }
        free(tab);
        printf("Incorrect input data");
        return 2;
    }
    sort_rows(tab,c,r,*(funcs+w));
    for(i=0; i<r; i++)
    {
        for(k=0; k<c; k++)
        {
            printf("%d ",*(*(tab+i)+k));
        }
        printf("\n");
    }
    for(o=0; o<r; o++)
    {
        if(*(tab+o)!=NULL)
        {
            free(*(tab+o));
        }
    }
    free(tab);
    return 0;
}

