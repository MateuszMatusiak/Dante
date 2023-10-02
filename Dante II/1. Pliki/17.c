#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    char n[51];
    int i=0,k,w=0;
    FILE *p;
    FILE *cp;
    printf("Daj: ");
    scanf("%30[^\n]",n);
    while(*(n+w)!='\0')
        w++;
    if(!((*(n+w-4)=='.')&&(*(n+w-3)=='b')&&(*(n+w-2)=='m')&&(*(n+w-1)=='p')))
    {
        printf("Unsupported File Format");
        return 7;
    }
    p=fopen(n,"r");
    if(p==NULL)
    {
        printf("Couldn't open file");
        return 4;
    }
    for(k=w;k>=0;k--)
    {
        *(n+k+5)=*(n+k);
    }
    *(n+k+5)='_';
    *(n+k+4)='y';
    *(n+k+3)='p';
    *(n+k+2)='o';
    *(n+k+1)='c';

    cp=fopen(n,"w");
    if(cp==NULL)
    {
        fclose(p);
        printf("Couldn't create file");
        return 5;
    }
    fseek(p, 0, SEEK_END);
    w = ftell(p);
    fseek(p, 0 ,SEEK_SET);
    for(i=0;i<w;i++)
    {
    fputc(fgetc(p),cp);
    }
    printf("File saved");
    fclose(p);
    fclose(cp);
    return 0;
}

