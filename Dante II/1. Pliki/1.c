#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    char nz[31];
    FILE *p;
    int i=0,x=0;
    printf("Daj: ");
    scanf("%30[^\n]",nz);
    p=fopen(nz,"r");
    if(p==NULL)
    {
        printf("Couldn't open file");
        return 4;
    }
    while(x!=EOF)
    {
        x=fgetc(p);
        if(x==EOF&&i==0)
        {
            printf( "Nothing to show");
            break;
        }
        if(x==EOF)
            break;
        putchar(x);
        i++;
    }
    fclose(p);
    return 0;
}

