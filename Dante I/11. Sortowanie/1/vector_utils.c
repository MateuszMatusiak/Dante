#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"
int read_vector(int vec[], int size, int stop_value)
{
    if (size<=0)
    {
        return -1;
    }

    int i,t,n=0;
    printf("Daj: ");
    for(i=0; i<size; i++)
        vec[i]=0;
    for(i=0; i<size; i++)
    {

        t=scanf(" %d",&vec[i]);
        if(t!=1)
        {
            return -2;
        }
        if((i==0) && (vec[i]==stop_value))
        {
            return -1;
        }
        if(vec[i]==stop_value)
        {
            return n;
        }
        n++;
    }
    return n;
}
void display_vector(const int vec[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ",vec[i]);
    }
}


