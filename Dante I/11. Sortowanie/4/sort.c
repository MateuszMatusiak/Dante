#include <stdio.h>
#include "vector_utils.h"
#include "sort.h"
#include "tested_declarations.h"
#include "rdebug.h"


int insertion_sort_asc(int tab[], int size)
{
    if(size<=0)
        return 1;
    int i,k,x;
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
        display_vector(tab,size);
        printf("\n");
    }

    return 0;
}

int insertion_sort_desc(int tab[], int size)
{
    if(size<=0)
        return 1;
    int i,k,x;
    for(i=1; i<size; i++)
    {

        x=tab[i];
        k=i-1;
        while((k>=0)&&(tab[k]<x))
        {
            tab[k+1]=tab[k];
            k=k-1;
        }

        tab[k+1]=x;
        display_vector(tab,size);
        printf("\n");
    }

    return 0;
}
int insertion_sort(int tab[], int size, enum direction dir)
{

    if (dir == 1)
    {
        return insertion_sort_asc(tab, size);
    }
    if(dir == 2)
    {
        return insertion_sort_desc(tab, size);
    }
    return 1;
}






