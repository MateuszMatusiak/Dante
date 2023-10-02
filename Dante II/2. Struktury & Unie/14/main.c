#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bit_set.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    union bit_set p;
    uint8_t *bmp;
    bmp=(uint8_t*)calloc(40,sizeof(uint8_t));
    if(bmp==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    int i,t;
    char *nz;
    FILE *f;
    nz=(char*)calloc(30,sizeof(char));
    if(nz==NULL)
    {
        free(bmp);
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    for(i=0; i<40; i++)
    {
        t=scanf("%hhX",(bmp+i));
        if(t!=1)
        {
            free(bmp);
            free(nz);
            printf("Incorrect input");
            return 1;
        }
    }
    while(getchar()!='\n');
    printf("Daj: ");
    scanf("%30[^\n]",nz);
    for(i=0; i<40; i++)
    {

        if(i!=0&&i%5==0)
            printf("\n");
        p.x=*(bmp+i);
        if(p.b.a8)
            printf("#");
        else
            printf(" ");
        if(p.b.a7)
            printf("#");
        else
            printf(" ");
        if(p.b.a6)
            printf("#");
        else
            printf(" ");
        if(p.b.a5)
            printf("#");
        else
            printf(" ");
        if(p.b.a4)
            printf("#");
        else
            printf(" ");
        if(p.b.a3)
            printf("#");
        else
            printf(" ");
        if(p.b.a2)
            printf("#");
        else
            printf(" ");
        if(p.b.a1)
            printf("#");
        else
            printf(" ");
    }
    f=fopen(nz,"w");
    if(f==NULL)
    {
        free(bmp);
        free(nz);
        printf("\nCouldn't create file\n");
        return 5;
    }
    for(i=0; i<40; i++)
    {

        if(i!=0&&i%5==0)
            fprintf(f,"\n");
        p.x=*(bmp+i);
        if(p.b.a8)
            fprintf(f,"#");
        else
            fprintf(f," ");
        if(p.b.a7)
            fprintf(f,"#");
        else
            fprintf(f," ");
        if(p.b.a6)
            fprintf(f,"#");
        else
            fprintf(f," ");
        if(p.b.a5)
            fprintf(f,"#");
        else
            fprintf(f," ");
        if(p.b.a4)
            fprintf(f,"#");
        else
            fprintf(f," ");
        if(p.b.a3)
            fprintf(f,"#");
        else
            fprintf(f," ");
        if(p.b.a2)
            fprintf(f,"#");
        else
            fprintf(f," ");
        if(p.b.a1)
            fprintf(f,"#");
        else
            fprintf(f," ");
    }
    printf("\nFile saved");
    free(bmp);
    free(nz);
    fclose(f);
    return 0;
}

