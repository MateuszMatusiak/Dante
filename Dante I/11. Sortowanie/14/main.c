#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

int sort_negative_asc_positive_desc(int tab[], int size)
{
   if(size<=0)
        return 1;
    int i, k, mn,x;
    for(i=0; i<size-1; i++)
    {
        while(tab[i]>=0)
            i++;
        if(i>=size-1)
            break;
        mn=i;
        for(k=i+1; k<size; k++)
        {
            if((tab[k]<tab[mn])&&(tab[k]<0))
            {
                mn=k;

            }
        }
        x=tab[i];
        tab[i]=tab[mn];
        tab[mn]=x;

    }

    for(i=0; i<size-1; i++)
    {
        while(tab[i]<0)
            i++;
        if(i>=size-1)
            break;
        mn=i;
        for(k=i+1; k<size; k++)
        {
            if((tab[k]>tab[mn])&&(tab[k]>=0))
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
    sort_negative_asc_positive_desc(tab,t);
    display_vector(tab,t);
    return 0;
}

