#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"


int file_size_from_path(const char *path)
{
    if(path==NULL)
        return -2;
    FILE *p;
    int w;
    p=fopen(path, "r");
    if(p==NULL)
        return -1;
    w=file_size_from_file(p);
    fclose(p);
    return w;
}
int file_size_from_file(FILE *f)
{
    if(f==NULL)
        return -2;
    int i,k;
    k=ftell(f);
    fseek(f,0,SEEK_END);
    i=ftell(f);
    fseek(f,k,0);
    return i;

}

int main()
{
    char path[31];
    FILE *p;
    int s1=0,s2=0;
    printf("Daj: ");
    scanf("%30[^\n]",path);
    p=fopen(path,"r");

    if(p==NULL)
    {
        printf("Couldn't open file");
        return 4;
    }
    s1=file_size_from_path(path);
    s2=file_size_from_file(p);
    fclose(p);
    if(s1==-1||s2==-1)
    {
        printf("Couldn't open file");
        return 4;
    }
    if(s1==-2||s2==-2)
    {
        printf("error");
        return 0;
    }
    else
    {
        printf("Rozmiar: %d", s1);
    }

    return 0;
}

