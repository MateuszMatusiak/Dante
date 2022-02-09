#include <stdio.h>
#include "vector_utils.h"
#include "sort.h"
#include "tested_declarations.h"
#include "rdebug.h"

int selection_sort_asc(int tab[], int size)
{
    if(size<=0)
        return 1;
    int i, k, mn,x;
    for(i=0; i<size-1; i++)
    {
        mn=i;
        for(k=i+1; k<size; k++)
        {
            if(tab[k]<tab[mn])
            {
                mn=k;

            }
        }
        x=tab[i];
        tab[i]=tab[mn];
        tab[mn]=x;

        display_vector(tab,size);
        printf("\n");
    }
    return 0;
}



int selection_sort_desc(int tab[], int size)
{
    if(size<=0)
        return 1;
    int i, k, mn,x;
    for(i=0; i<size-1; i++)
    {
        mn=i;
        for(k=i+1; k<size; k++)
        {
            if(tab[k]>tab[mn])
            {
                mn=k;

            }
        }
        x=tab[i];
        tab[i]=tab[mn];
        tab[mn]=x;

        display_vector(tab,size);
        printf("\n");
    }
    return 0;
}

int selection_sort(int tab[], int size, enum direction dir)
{

    if (dir == 1)
    {
        return selection_sort_asc(tab, size);
    }
    if(dir == 2)
    {
        return selection_sort_desc(tab, size);
    }
    return 1;
}


