#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int create_array_int(int **ptr, int N)
{
    if(N<=0)
    {
        return 1;
    }
    if(ptr==NULL)
        return 1;
    *ptr=(int*)calloc(N,sizeof(int));
    if(*ptr==NULL)
        return 2;
    return 0;
}
void destroy_array_int(int **ptr)
{
    if(ptr!=NULL)
    {
        free(*ptr);
        *ptr=NULL;
    }
}
int main()
{
    int i,n,t;
    int *tab;
    printf("Daj: ");
    t=scanf("%d",&n);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    t=create_array_int(&tab,n);
    if(t==1)
    {
        printf("Incorrect input data");
        destroy_array_int(&tab);
        return 2;
    }
    if(t==2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    for(i=0; i<n; i++)
    {
        t=scanf("%d ",(tab+i));
        if(t!=1)
        {
            printf("Incorrect input");
            destroy_array_int(&tab);
            return 1;
        }
    }
    for(i=n-1; i>=0; i--)
    {
        printf("%d ",*(tab+i));
    }
    destroy_array_int(&tab);
    return 0;
}


