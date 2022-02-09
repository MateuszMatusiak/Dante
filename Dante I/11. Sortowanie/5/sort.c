#include <stdio.h>
#include "vector_utils.h"
#include "sort.h"
#include "types_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"


int sort(int tab[], int size, enum direction dir, enum algorithm alg)
{
    if(alg==1)
        return bubble_sort(tab, size, dir);
    if(alg==2)
        return selection_sort(tab, size, dir);
    if(alg==3)
        return insertion_sort(tab, size, dir);
    return 1;
}

int bubble_sort_asc(int tab[], int size)
{
    if(size<=0)
        return 1;
    int i, k, x,l=0;
    for (i = 0; i<size-1; i++)
    {
        l=0;
        for (k=0; k<size-1; k++)
        {
            if (tab[k] > tab[k+1])
            {
                x = tab[k+1];
                tab[k+1] = tab[k];
                tab[k] = x;
                l++;
            }


        }
        if(l==0)
            break;
        display_vector(tab,size);
        printf("\n");


    }

    return 0;
}
int bubble_sort_desc(int tab[], int size)
{
    if(size<=0)
        return 1;
    int i, k, x,l=1;
    for (i = 0; i<size-1; i++)
    {

        l=0;
        for (k=0; k<size-1; k++)
        {
            if (tab[k] < tab[k+1])
            {
                x = tab[k+1];
                tab[k+1] = tab[k];
                tab[k] = x;
                l++;
            }
        }
        if(l==0)
            break;

        display_vector(tab,size);
        printf("\n");
    }

    return 0;
}
int bubble_sort(int tab[], int size, enum direction dir)
{

    if (dir == 1)
    {
        return bubble_sort_asc(tab, size);
    }
    if(dir == 2)
    {
        return bubble_sort_desc(tab, size);
    }
    return 1;
}


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


