#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    int i;
    int *tab;
    tab=(int*)calloc(100,sizeof(int));
    if(tab==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    for(i=0;i<100;i++)
        *(tab+i)=i;
    for(i=0;i<100;i++)
        printf("%d ",*(tab+i));
    free(tab);
    return 0;
}

