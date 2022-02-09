#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"
#include "sort.h"
#include "types_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main()
{
    int tab[50];
    int i,t;
    int d,a;
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
    printf("Daj: " );
    t=scanf("%d",&a);
    if(t!=1)
    {

        printf("incorrect input");
        return 1;
    }
    if((a!=1)&&(a!=2)&&(a!=3))
    {
        printf("Incorrect input data");
        return 2;
    }
    sort(tab, i, d, a);
    display_vector(tab,i);
    return 0;
}

