#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"



struct file_t
{
    FILE *f;
    int size;
};


int open_file(struct file_t* f, const char *filename)
{
    if(f==NULL||filename==NULL)
        return 1;
    FILE *p;
    p=fopen(filename,"a");
    if(p==NULL)
    {
        return 2;
    }
    f->f=p;
    fseek(p,0L,SEEK_END);
    f->size=ftell(p);
    return 0;
}


struct file_t* find_min(const struct file_t* files, int size)
{
    if(files==NULL||size<=0)
        return NULL;
    int i,min;
    min=0;
    for(i=1; i<size; i++)
    {
        if((files+i)->size<(files+min)->size)
        {
            min=i;
        }
    }
    return (struct file_t*)(files+min);
}


void close_file(struct file_t* f)
{
    if(f!=NULL&&f->f!=NULL)
    {
        fclose(f->f);
    }
}



int main()
{
    struct file_t files[5];
    struct file_t *file_min;
    FILE *te;
    char nz[1000];
    memset(nz, '\0', 1000);
    int ilosc=0,k=0,t;

    printf("Daj: ");
    do {

        scanf("%100[^\n]", nz);
        if(*nz=='\0')
            break;
        te = fopen(nz, "r");
        if (te == NULL)
        {
            while (getchar () != '\n' );
            memset(nz, '\0', 1000);
            continue;
        }
        fclose(te);
        t=open_file(files+ilosc,nz);
        if(t!=0)
        {
            continue;
        }
        ilosc++;
        while (getchar () != '\n' );
        memset(nz, '\0', 1000);
    }
    while(1);
    if(ilosc==0)
    {
        printf("Couldn't open file\n");
        for(k=0; k<ilosc; k++)
            close_file(files+k);
        return 4;
    }


    printf("Daj: ");
    do {
        file_min = find_min(files, ilosc);
        if (file_min == NULL) {
            for (k = 0; k < ilosc; k++)
                close_file(files + k);
            printf("Couldn't open file");
            return 4;
        }
        while (getchar () != '\n' );
        memset(nz, '\0', 1000);
        scanf("%1000[^\n]", nz);

        if (*nz == '\0')
        {
            break;
        }
        fseek(file_min->f,0,SEEK_END);
        fprintf(file_min->f,"%s\n",nz);
        fseek(file_min->f,0,SEEK_END);
        file_min->size=ftell(file_min->f);
    }
    while(1);


    for(k=0; k<ilosc; k++)
        close_file(files+k);
    printf("Files saved");
    return 0;
}
