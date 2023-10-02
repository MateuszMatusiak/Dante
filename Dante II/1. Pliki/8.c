#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    int w,t,suma=0,x=0;
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
    fseek(p, 0, SEEK_END);
    w = ftell(p);
    fseek(p, 0 ,SEEK_SET);
    while(w!=ftell(p))
    {
        suma=suma+x;
        t=fscanf(p,"%d",&x);
        if(t==0)
        {
            fclose(p);
            printf("File corrupted");
            return 6;
        }
    }
    fclose(p);
    printf("Suma: %d",suma);
    return 0;
}

