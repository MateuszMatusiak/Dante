#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"
#include "tested_declarations.h"
#include "rdebug.h"

int sort_int(int *array, int size, p function)
{
    if(array==NULL||size<=0||function==NULL)
    {
        return 1;
    }
    int i,k,t,x;
    for(i=0; i<size-1; i++)
    {
        for(k=0; k<size-1; k++)
        {
            t=function(*(array+k),*(array+k+1));
            if(t==1)
            {
                x=*(array+k);
                *(array+k)=*(array+k+1);
                *(array+k+1)=x;
            }
        }
    }
    return 0;
}
int comp_int(int a, int b)
{
    if(a==b)
        return 0;
    if(a>b)
        return 1;
    return -1;
}
int comp_int_abs(int a, int b)
{
    a=abs(a);
    b=abs(b);

    if(a==b)
        return 0;
    else if(a>b)
        return 1;
    else if(b<a)
        return -1;
    return -1;
}
int comp_int_length(int a, int b)
{
    int la=0, lb=0;
    a=abs(a);
    b=abs(b);
    while(a>0)
    {
        la++;
        a=a/10;
    }
    while(b>0)
    {
        lb++;
        b=b/10;
    }
    if(la==lb)
    {
        return 0;
    }
    else if(la>lb)
    {
        return 1;
    }
    else if(la<lb)
    {
        return -1;
    }
    return -1;
}
int comp_int_digits_sum(int a, int b)
{
    int la=0, lb=0;
    a=abs(a);
    b=abs(b);
    while(a>0)
    {
        la=la+a%10;
        a=a/10;
    }
    while(b>0)
    {
        lb=lb+b%10;
        b=b/10;
    }
    if(la==lb)
    {
        return 0;
    }
    else if(la>lb)
    {
        return 1;
    }
    else if(la<lb)
    {
        return -1;
    }
    return 0;
}

