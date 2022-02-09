#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "types_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"


int quicksort_asc(int l, int r, int tab[], int tabSize)
{
    if ((tabSize<=0)||(l<0)||(r<0)||(l>r)||(r>tabSize))
        return 1;
    int i, k, x, o;
    if(l<r)
    {
        x=l;
        i=l;
        k=r;

        while(i<k)
        {
            while(tab[i]<=tab[x]&&i<r)
                i++;
            while(tab[k]>tab[x])
                k--;
            if(i<k)
            {
                o=tab[i];
                tab[i]=tab[k];
                tab[k]=o;
            }
        }

        o=tab[x];
        tab[x]=tab[k];
        tab[k]=o;
        if(l<k)
            quicksort_asc(l,k-1,tab,tabSize);
        if(i<r)
            quicksort_asc(k+1,r,tab,tabSize);

    }
    return 0;
}
int quicksort_desc(int l, int r, int tab[], int tabSize)
{
     if ((tabSize<=0)||(l<0)||(r<0)||(l>r)||(r>tabSize))
        return 1;
    int i, k, x, o;
    if(l<r)
    {
        x=l;
        i=l;
        k=r;

        while(i<k)
        {
            while(tab[i]>=tab[x]&&i<r)
                i++;
            while(tab[k]<tab[x])
                k--;
            if(i<k)
            {
                o=tab[i];
                tab[i]=tab[k];
                tab[k]=o;
            }
        }

        o=tab[x];
        tab[x]=tab[k];
        tab[k]=o;
        if(l<k)
            quicksort_desc(l,k-1,tab,tabSize);
        if(i<r)
            quicksort_desc(k+1,r,tab,tabSize);

    }
    return 0;
}
int quicksort(int tab[], int size, enum direction dir)
{

    if (dir == 1)
    {
        return quicksort_asc(0,size-1,tab, size);
    }
    if(dir == 2)
    {
        return quicksort_desc(0,size-1,tab, size);
    }
    return 1;
}

