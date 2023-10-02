#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"
#include "tested_declarations.h"
#include "rdebug.h"

int sort(void *tab, int size, int sizeofelement, p function)
{
    if(tab==NULL||size<=0||sizeofelement<=0||function==NULL)
    {
        return 1;
    }
    int i,k,t,o;
    unsigned char x, *tb,*tb1;
    for(i=0; i<size-1; i++)
    {
        for(k=0; k<size-1; k++)
        {
            tb=(unsigned char*)(tab);
            tb=tb+(k*sizeofelement);
            tb1=(unsigned char*)(tab);
            tb1=tb1+((k+1)*sizeofelement);
            t=function(tb,tb1);
            if(t>0)
            {
                for(o=0; o<sizeofelement; o++)
                {
                    x=*(tb+o);
                    *(tb+o)=*(tb1+o);
                    *(tb1+o)=x;
                }
            }
        }
    }
    return 0;
}
int comp_int(const void *ptr1, const void *ptr2)
{
    if(ptr1==NULL||ptr2==NULL)
    {
        return 0;
    }
    int a,b;
    a=*(int*)ptr1;
    b=*(int*)ptr2;
    if(a>b)
        return 1;
    else if(a==b)
        return 0;
    else if(a<b)
        return -1;
    return -1;
}
int comp_double(const void *ptr1, const void *ptr2)
{
    if(ptr1==NULL||ptr2==NULL)
    {
        return 0;
    }
    double a,b;
    a=*(double*)ptr1;
    b=*(double*)ptr2;
    if(a>b)
        return 1;
    else if(a==b)
        return 0;
    else if(a<b)
        return -1;
    return -1;
}
int comp_point(const void *ptr1, const void *ptr2)
{
    if(ptr1==NULL||ptr2==NULL)
    {
        return 0;
    }
    struct point_t a,b;
    a=*(struct point_t*)ptr1;
    b=*(struct point_t*)ptr2;
    if(a.x>b.x)
        return 1;
    else if(a.x<b.x)
        return -1;
    else if(a.y>b.y)
        return 1;
    else if(a.y<b.y)
        return -1;
    else
        return 0;
    return 0;
}

