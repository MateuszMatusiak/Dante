#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_sort(const int vec[],int i, int size)
{
    if(i==size-1)
        return 0;
    if((vec[i])<=(vec[i+1]))
        return is_sort(vec,i+1,size);
    return 1;
}

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
    while(getchar()!='\n');
    return n;
}

int binary_search(const int arr[], int l, int r, int x)
{
    if(arr[l]==x)
        return l;
    int srodek=((l+r)/2);
    if(l<r)
        if (arr[srodek]<x)
        {
            l=srodek+1;
            return binary_search(arr, l, r, x);
        }
        else
        {
            r=srodek;
            return binary_search(arr, l, r, x);
        }
    return -1;
}


int main()
{
    int vec[150];
    int t,r,x;
    r=read_vector(vec,150,0);
    if(r==-2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(r==-1)
    {
        printf("Not enough data available");
        return 3;
    }
    printf("Daj: ");
    t=scanf("%d",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(is_sort(vec,0,r)==1)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("%d",binary_search(vec,0,r,x));
    return 0;
}

