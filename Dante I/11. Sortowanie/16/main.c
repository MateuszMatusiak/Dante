#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

int sort_odd_asc_even_desc(int tab[],int size)
{
    int x;
    if(size<=0)
        return 1;
    for(int i=0; i<size+1000; i++)
        for (int j=0; j<size-1; j++)
        {
            if(tab[j]%2==0)
            {
                if(tab[j+1]%2==0)
                {
                    if(tab[j]<tab[j+1])
                    {
                        x=tab[j];
                        tab[j]=tab[j+1];
                        tab[j+1]=x;
                    }
                }
                else
                {
                    x=tab[j];
                    tab[j]=tab[j+1];
                    tab[j+1]=x;
                }
            }
            else if(tab[j+1]%2!=0)
                if(tab[j]>tab[j+1])
                {
                    x=tab[j];
                    tab[j]=tab[j+1];
                    tab[j+1]=x;
                }
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

    sort_odd_asc_even_desc(tab,t);
    display_vector(tab,t);
    return 0;
}

