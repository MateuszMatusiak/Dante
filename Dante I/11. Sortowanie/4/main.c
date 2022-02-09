#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#include "sort.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main()
{
    int tab[50];
    int i,t;
    int d;
    i=read_vector(tab,50,0);
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
    while(getchar()!='\n');
    printf("Daj: " );
    t=scanf("%d",&d);
    if(t!=1)
    {

        printf("incorrect input");
        return 1;
    }
    if((d!=1)&&(d!=2))
    {
        printf("Incorrect input data");
        return 2;
    }

    insertion_sort(tab,i,d);
    display_vector(tab,i);
    printf("\n");
    return 0;
}

