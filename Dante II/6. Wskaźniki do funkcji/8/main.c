#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    p funcs[]= {comp_int, comp_double, comp_point};
    int t,w,s,i;
    int *tabi;
    double *tabd;
    struct point_t *tabs;
    printf("Daj: ");
    t=scanf("%d",&w);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(w<0||w>2)
    {
        printf("Incorrect input data");
        return 2;
    }
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
    if(w==0)
    {
        tabi=(int*)calloc(s,sizeof(int));
        if(tabi==NULL)
        {
            printf("Failed to allocate memory");
            return 8;
        }
        printf("Daj: ");
        for(i=0; i<s; i++)
        {
            t=scanf("%d",tabi+i);
            if(t!=1)
            {
                free(tabi);
                printf("Incorrect input");
                return 1;
            }
        }
        sort(tabi,s,sizeof(int),*(funcs+w));
        for(i=0; i<s; i++)
        {
            printf("%d ",*(tabi+i));
        }
        free(tabi);

    }
    else if(w==1)
    {
        tabd=(double*)calloc(s,sizeof(double));
        if(tabd==NULL)
        {
            printf("Failed to allocate memory");
            return 8;
        }
        printf("Daj: ");
        for(i=0; i<s; i++)
        {
            t=scanf("%lf",tabd+i);
            if(t!=1)
            {
                free(tabd);
                printf("Incorrect input");
                return 1;
            }
        }
        sort(tabd,s,sizeof(double),*(funcs+w));
        for(i=0; i<s; i++)
        {
            printf("%lf ",*(tabd+i));
        }
        free(tabd);

    }
    else if(w==2)
    {
        tabs=(struct point_t*)calloc(s,sizeof(struct point_t));
        if(tabs==NULL)
        {
            printf("Failed to allocate memory");
            return 8;
        }
        printf("Daj: ");
        for(i=0; i<s; i++)
        {
            t=scanf("%lf %lf",&((tabs+i)->x), &((tabs+i)->y));
            if(t!=2)
            {
                free(tabs);
                printf("Incorrect input");
                return 1;
            }
        }
        sort(tabs,s,sizeof(struct point_t),*(funcs+w));
        for(i=0; i<s; i++)
        {
            printf("%lf %lf\n",(tabs+i)->x, (tabs+i)->y);
        }
        free(tabs);

    }

    return 0;
}

