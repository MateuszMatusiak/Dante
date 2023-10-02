#include <stdio.h>
#include "dante.h"
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    int i,k;
    int **t=(int**)calloc(10,sizeof(int*));
    if(t==NULL)
        return fa();
    for(i=0;i<10;i++)
    {
        *(t+i)=(int*)calloc(10,sizeof(int));
        if(*(t+i)==NULL) {
            for (k = 0; k < i; k++)
                free(*(t + k));
            free(t);
            return fa();
        }
    }

    for(i=0;i<10;i++)
    {
         for(k=0;k<10;k++)
         {
             *(*(t+i)+k)=(i+1)*(k+1);
         }
    }
    for(i=0;i<10;i++)
    {
         for(k=0;k<10;k++)
         {
             printf("%3d ",*(*(t+i)+k));
         }
         printf("\n");
    }
    for (k = 0; k < 10; k++)
        free(*(t + k));
    free(t);
    return 0;
}

