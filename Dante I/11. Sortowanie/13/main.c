#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"


int sort_negative_asc_positive_desc(int tab[], int size)
{
    if(size<=0)
        return 1;
    int i,k,x,o;
    for(i=1; i<size; i++)
    {

        x=tab[i];
        k=i-1;
        while((k>=0)&&(tab[k]>x))
        {
            tab[k+1]=tab[k];
            k=k-1;
        }

        tab[k+1]=x;
    }
    o=0;
    while((tab[o]<0)&&(o<size))
    {
      o++;
    }
    for(i=o; i<size; i++)
    {

        x=tab[i];
        k=i-1;
        while((k>=o)&&(tab[k]<x))
        {
            tab[k+1]=tab[k];
            k=k-1;
        }

        tab[k+1]=x;

    }
    return 0;
}



int main()
{
    int tab[150];
    int t;
    t=read_vector(tab,150,0);
    if(t==-1)
    {
        printf("not enough data available");
        return 3;
    }
    if(t==-2)
    {
        printf("incorrect input");
        return 1;
    }
    sort_negative_asc_positive_desc(tab,t);
    for(int i=0;i<t;i++)
        printf("%d ",tab[i]);
    return 0;
}

