#include <stdio.h>
#include "vector_utils.h"
#include "sort.h"
#include "tested_declarations.h"
#include "rdebug.h"

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


