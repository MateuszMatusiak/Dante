#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    char nz[31];
    FILE *p;
    int i;
    printf("Daj: ");
    scanf("%30[^\n]",nz);
    p=fopen(nz,"w");

    if(p==NULL)
    {
        printf("couldn't create file");
        return 5;
    }
    for(i=0;i<101;i++)
    {
        fprintf(p, "%d\n", i);
    }
    fclose(p);
    printf( "File saved");
    return 0;
}

