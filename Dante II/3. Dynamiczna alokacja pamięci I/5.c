#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int* create_array_int(int N)
{
    int *tab;
    if(N<=0)
    {
        return NULL;
    }
    tab=(int*)calloc(N,sizeof(int));
    if(tab==NULL)
        return NULL;
    return tab;
}
int* copy_array_int(const int* ptr, int N)
{
    if(ptr==NULL)
        return NULL;
    int *tab2;
    if(N<=0)
    {
        return NULL;
    }
    tab2=(int*)calloc(N,sizeof(int));
    if(tab2==NULL)
        return NULL;
    for(int i=0; i<N; i++)
    {
        *(tab2+i)=*(ptr+i);
    }

    return tab2;
}
void display_array_int(const int* ptr, int N)
{
    if(ptr!=NULL&&N>0)
        for(int i=0; i<N; i++)
        {
            printf("%d ",*(ptr+i));
        }
}
int main()
{
    int n,x;
    int* tab;
    int* tab2;
    printf("Daj:");
    x=scanf("%d",&n);
    if(x!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(n<=0)
    {
        printf("Incorrect input data");
        return 2;
    }
    tab=create_array_int(n);
    if(tab==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj:");
    for(int i=0; i<n; i++)
    {
        x=scanf("%d",(tab+i));
        if(x!=1)
        {
            printf("Incorrect input");
            free(tab);
            return 1;
        }
    }
    tab2=copy_array_int(tab,n);
    if(tab2==NULL)
    {
        printf("Failed to allocate memory");
        free(tab);
        return 8;
    }
    display_array_int(tab,n);
    printf("\n");
    display_array_int(tab,n);
    free(tab);
    free(tab2);
    return 0;
}

