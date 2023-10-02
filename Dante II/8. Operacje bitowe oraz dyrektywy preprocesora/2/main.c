#include <stdio.h>
#include <stdlib.h>
#include "bit.h"
#include "tested_declarations.h"
#include "rdebug.h"

int toggle_bit(uint32_t* pvalue, int b)
{
    if(pvalue==NULL||b<0||b>31)
        return -1;
    int x;
    x=1<<b;
    *pvalue=*pvalue^x;
    return 0;
}
int set_bit(uint32_t* pvalue, int b)
{
    if(pvalue==NULL||b<0||b>31)
        return -1;
    int x;
    x=1<<b;
    *pvalue=*pvalue|x;
    return 0;
}
int clear_bit(uint32_t* pvalue, int b)
{
    if(pvalue==NULL||b<0||b>31)
        return -1;
    int x;
    x=1<<b;
    x=~x;
    *pvalue=*pvalue&x;
    return 0;
}

int isset_bit(const uint32_t* pvalue, int b)
{
    if(pvalue==NULL||b<0||b>31)
        return -1;
    int x,w;
    x=1<<b;
    w=*pvalue&x;
    if(w)
        return 1;
    return 0;
}

int main()
{
    uint32_t value;
    int t,w,b,y;
    printf("Daj: ");
    t=scanf("%u",&value);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Daj: ");
    t=scanf("%d",&b);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(b<0||b>31)
    {
        printf("Invalid bit index");
        return 1;
    }
    printf("Daj: ");
    t=scanf("%d",&w);
       if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(w<0||w>3)
    {
        printf("Invalid operation");
        return 1;
    }
    if(w==0)
    {
      toggle_bit(&value,b);
    }
    else if(w==1)
    {
       set_bit(&value,b);
    }
    else if(w==2)
    {
        clear_bit(&value,b);
    }
    else if(w==3)
    {
        y=isset_bit(&value,b);
        printf("%d",y);
    }
    printf("%.8x",value);
    return 0;
}

