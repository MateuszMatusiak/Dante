#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

int sort_by_dividers(int tab[],int size)
{
    if(size<=0)
        return 1;
    int x;
    int licznik1,licznik2;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size-1; j++)
        {
            licznik1=0;
            licznik2=0;
            for(int m=1; m<=abs(tab[j]); m++)
                if(tab[j]%m==0)
                    licznik1=licznik1+1;
            for(int m=1; m<=abs(tab[j+1]); m++)
                if(tab[j+1]%m==0)
                    licznik2=licznik2+1;
            if(licznik2<licznik1)
            {
                x=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=x;
            }

            if(licznik2==licznik1)
                if(tab[j]>tab[j+1])
                {
                    x=tab[j];
                    tab[j]=tab[j+1];
                    tab[j+1]=x;
                }
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

    sort_by_dividers(tab,t);
    display_vector(tab,t);
    return 0;
}

