#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

float* create_array(int N)
{
    float *tab;
    tab=(float*)calloc(N,sizeof(float));
    if(tab==NULL)
        return NULL;
    if(N<=0)
    {
        free(tab);
        return NULL;
    }
    return tab;
}

int main()
{
    int n,x;
    float* tab;
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
    tab=create_array(n);
    if(tab==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj:");
    for(int i=0; i<n; i++)
    {
        x=scanf("%f",(tab+i));
        if(x!=1)
        {
            printf("Incorrect input");
            free(tab);
            return 1;
        }
    }
    for(int i=n-1; i>=0; i--)
    {
        printf("%f ",*(tab+i));
    }
    free(tab);
    return 0;
}

