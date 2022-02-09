#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"


int sort_even_asc(int tab[], int size)
{
    if(size<=0)
        return 1;
    int i, k, mn,x;
    for(i=0; i<size-1; i=i+2)
    {
        mn=i;
        for(k=i; k<size; k=k+2)
        {
            if(tab[k]<tab[mn])
            {
                mn=k;

            }
        }
        x=tab[i];
        tab[i]=tab[mn];
        tab[mn]=x;

    }

    return 0;
}


int sort_odd_desc(int tab[], int size)
{
    if(size<=0)
        return 1;
    int i, k, mn,x;
    for(i=1; i<size-1; i=i+2)
    {
        mn=i;
        for(k=i; k<size; k=k+2)
        {
            if(tab[k]>tab[mn])
            {
                mn=k;

            }
        }
        x=tab[i];
        tab[i]=tab[mn];
        tab[mn]=x;



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
    sort_odd_desc(tab,t);
    sort_even_asc(tab,t);
    display_vector(tab,t);
    return 0;
}

