#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

int bubble_sort(int tab[], int size)
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
int main()
{
    int tab[150];
    int i;
    i=read_vector(tab,150,0);
    if(i==-1)
    {
        printf("not enough data available");
        return 3;
    }
    if(i==-2)
    {
        printf("incorrect input");
        return 1;
    }

    bubble_sort(tab,i);
    display_vector(tab,i);
    return 0;
}

