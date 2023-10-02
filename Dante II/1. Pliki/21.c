#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"


int main()
{
    FILE *p;
    FILE *o;
    FILE *r;
    char n[31];
    int s,t,w,x,z,i;
    printf("Daj: ");
    scanf("%30[^\n]",n);
    p=fopen(n,"r");
    if(p==NULL)
    {
        printf("Couldn't open file");
        return 4;
    }
    o=fopen(n,"r");
    r=fopen("w","w");

    s=0;
    while(!feof(p) && fgetc(p)!='\n')
        s++;

    fseek(p, 0, SEEK_END);
    w=ftell(p);
    fseek(p, 0, SEEK_SET);
    t=1;
    while(t)
    {
        t=fscanf(o,"%d", &x);
        if((t==0 && ftell(o)<s) || x>w || x<=s)
        {
            printf("File corrupted");
            fclose(p);
            fclose(o);
            fclose(r);
            return 6;
        }

        if(fseek(p, x, SEEK_SET)!=0)
        {
            fclose(r);
            fclose(o);
            fclose(p);
            printf("File corrupted");
            return 6;
        }
        z=fgetc(p);
        if(z== '\n')
        {
            fclose(o);
            fclose(p);
            fclose(r);
            printf("File corrupted");
            return 6;
        }
        fprintf(r,"%c",z);

    }

    fclose(r);
    r=fopen("w","r");
    if(r==NULL)
    {
        printf("Couldn't open file");
        return 4;
    }
    i=0;
    while(1)
    {
        z=fgetc(r);
        i++;
        if(z==EOF)
            break;
    }
    fseek(r, 0, SEEK_SET);
    x=0;
    while(x<i-2)
    {
        z=fgetc(r);
        x++;
        if(z==EOF)
            break;
        putchar(z);
    }
    fclose(r);
    fclose(o);
    fclose(p);
    return 0;
}


