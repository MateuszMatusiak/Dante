#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"


int main()
{
    char p1[31];
    char p2[31];
    FILE *p;
    FILE *r;
    int x=0,i=0;
    printf("Daj wejscie: ");
    scanf("%30[^\n]",p1);
    p=fopen(p1,"r");

    if(p==NULL)
    {
        printf("Couldn't open file");
        return 4;
    }
    while(getchar()!='\n');
    printf("Daj wyjscie: ");
    scanf("%30[^\n]",p2);
    r=fopen(p2,"w");

    if(r==NULL)
    {
        fclose(p);
        printf("couldn't create file");
        return 5;
    }
    fseek(p,0,SEEK_END);
    for(i=ftell(p)-1;i>=0;i--)
    {
        fseek(p,i,SEEK_SET);
        x=fgetc(p);

        if(x==EOF)
            break;
        putc(x,r);
    }
    fclose(p);
    fclose(r);
    printf("File copied");
    return 0;
}

