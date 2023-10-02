#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"


int read_file(const char *filename)
{
    char n[31];
    FILE *p;
    int s=1,x,i,l;
    if(filename==NULL)
        return -1;
    p=fopen(filename, "r");
    if(p == NULL)
        return 0;

    while(!feof(p))
    {
        for(i=0;i<30;i++)
        {
            l=fgetc(p);
            *(n+i)=l;
            if(*(n+i)=='\n')
            {
                *(n+i)='\0';
                break;
            }
        }
        i=0;
        while(*(n+i)!='\0')
        {
            if(*(n+i)>40&&*(n+i)<126)
            printf("%c",*(n+i));
            i++;
        }
        if(*(n+1)>40&&*(n+1)<126)
        printf("\n");
        x=read_file(n);
        if(x==-1)
        {
            s=-1;
            break;
        }
        s=s+x;
    }

    fclose(p);
    return s;
}


int main()
{
    FILE *p;
    char n[31];
    int f;
    printf("Daj: ");
    scanf("%30[^\n]",n);
    p=fopen(n,"r");
    if(p==NULL)
    {
        printf("Couldn't open file");
        return 4;
    }
    f=read_file(n);
    printf("%d", f);
    fclose(p);
    return 0;
}


