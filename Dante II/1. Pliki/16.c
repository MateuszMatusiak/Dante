#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    FILE *p;
    char n[31];
    printf("Daj: ");
    scanf("%30[^\n]",n);
    p=fopen(n,"r");
    if(p==NULL)
    {
        p=fopen(n,"w");
        if(p==NULL)
        {
            printf("Couldn't create file");
            return 5;
        }
        else
        {
            printf("file created");
        }
    }
    else
    {
        printf("File already exists!");
    }
    fclose(p);
    return 0;
}

