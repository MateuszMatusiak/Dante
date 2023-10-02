#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    int t,suma=0,x=0,lc=0,l=0;
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
    t=fscanf(p,"%d",&l);
    if(l<0||t!=1)
    {
        printf("File corrupted");
        fclose(p);
        return 6;
    }
    while(!feof(p))
    {
    t=fscanf(p,"%d",&x);
    if(t!=1)
    {
        printf("File corrupted");
        fclose(p);
        return 6;
    }
    suma=suma+x;
    lc++;
    if(lc==l)
        break;
    }
    if(l>lc)
        {
        printf("File corrupted");
        fclose(p);
        return 6;
    }
    fclose(p);
    printf("%d\n%f",suma,(double)suma/lc);
    return 0;
}



