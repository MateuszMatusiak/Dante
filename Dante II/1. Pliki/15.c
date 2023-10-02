#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    int i=0;
    char l;
    FILE *p;
    char n[31];
    printf("Daj: ");
    scanf("%30[^\n]",n);
    p=fopen(n,"r");
    if(p==NULL)
    {
        printf("Couldn't open file");
        return 4;
    }
    fgetc(p);
    if(feof(p))
    {
        printf("0");
        fclose(p);
        return 0;
    }
    fseek(p, 0 ,SEEK_SET);
    while(!feof(p))
    {
        i++;
        printf("%d. ",i);
        l=fgetc(p);
        while(l!='\n'&&!feof(p))
        {
            putchar(l);
            l=fgetc(p);
        }
        printf("\n");
    }
    printf("%d",i);
    fclose(p);
    return 0;
}

