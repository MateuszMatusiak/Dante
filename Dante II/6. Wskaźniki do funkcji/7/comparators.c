#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"
#include "tested_declarations.h"
#include "rdebug.h"

int sort_rows(int **tab, int column, int row, p function)
{
    if(tab==NULL||column<=0||row<=0||function==NULL)
    {
        return 1;
    }
    int i,k,t;
    int *x;
    for(i=0; i<row-1; i++)
    {
        for(k=0; k<row-1; k++)
        {
            t=function(*(tab+k),*(tab+k+1),column);
            if(t==1)
            {
                x=*(tab+k);
                *(tab+k)=*(tab+k+1);
                *(tab+k+1)=x;
            }
        }
    }
    return 0;
}
int comp_min(const int *ptr1, const int *ptr2, int width)
{
    if(ptr1==NULL||ptr2==NULL||width<=0)
        return 2;
    int i, m1=*ptr1, m2=*ptr2;
    for(i=1; i<width; i++)
    {
        if(*(ptr1+i)<m1)
        {
            m1=*(ptr1+i);
        }
        if(*(ptr2+i)<m2)
        {
            m2=*(ptr2+i);
        }
    }
    if(m1>m2)
        return 1;
    else if(m1==m2)
        return 0;
    else if(m1<m2)
        return -1;
    return -1;
}
int comp_max(const int *ptr1, const int *ptr2, int width)
{
    if(ptr1==NULL||ptr2==NULL||width<=0)
        return 2;
    int i, m1=*ptr1, m2=*ptr2;
    for(i=1; i<width; i++)
    {
        if(*(ptr1+i)>m1)
        {
            m1=*(ptr1+i);
        }
        if(*(ptr2+i)>m2)
        {
            m2=*(ptr2+i);
        }
    }
    if(m1>m2)
        return 1;
    else if(m1==m2)
        return 0;
    else if(m1<m2)
        return -1;
    return -1;
}
int comp_sum(const int *ptr1, const int *ptr2, int width)
{
    if(ptr1==NULL||ptr2==NULL||width<=0)
        return 2;
    int i, m1=*ptr1, m2=*ptr2;
    for(i=1; i<width; i++)
    {
        m1+=*(ptr1+i);
        m2+=*(ptr2+i);
    }
    if(m1>m2)
        return 1;
    else if(m1==m2)
        return 0;
    else if(m1<m2)
        return -1;
    return -1;
}

