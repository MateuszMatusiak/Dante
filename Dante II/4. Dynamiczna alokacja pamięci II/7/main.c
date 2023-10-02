#include <stdio.h>
#include <stdlib.h>
#include "image_utils.h"
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

void getstr(char* nz,int n)
{
    char ch=getchar();
    int i=0;
    while(i<n&&ch!='\n')
    {
        *(nz+i)=ch;
        ch=getchar();
        ++i;
    }
    *(nz+i)='\0';
}

int main() {
    char *nz = (char *) calloc(40, sizeof(char));
    if (nz == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    getstr(nz,39);
    int err;
    struct image_t *xd = load_image_t(nz, &err);
    if (xd == NULL) {
        switch (err) {
            case 1:
                printf("Incorrect input");
                free(nz);
                return 1;
            case 2:
                printf("Couldn't open file");
                free(nz);
                return 4;
            case 3:
                printf("File corrupted");
                free(nz);
                return 6;
            case 4:
                printf("Failed to allocate memory");
                free(nz);
                return 8;
            default:
                return 0;
        }
    }
    struct image_t *xd1 = image_flip_vertical(xd);
    if (xd1 == NULL) {
        printf("Failed to allocate memory");
        free(nz);
        destroy_image(&xd);
        return 8;
    }
    struct image_t *xd2 = image_flip_horizontal(xd);
    if (xd2 == NULL) {
        printf("Failed to allocate memory");
        free(nz);
        destroy_image(&xd);
        destroy_image(&xd1);
        return 8;
    }
    struct image_t *xd3 = image_negate(xd);
    if (xd3 == NULL) {
        printf("Failed to allocate memory");
        free(nz);
        destroy_image(&xd);
        destroy_image(&xd1);
        destroy_image(&xd2);
        return 8;
    }
    char*n1=realloc(nz,49*sizeof(char));
    if(n1==NULL)
    {
        printf("Failed to allocate memory");
        free(nz);
        destroy_image(&xd);
        destroy_image(&xd1);
        destroy_image(&xd2);
        return 8;
    }
    nz=n1;

    for(int i=49;i>=0;--i)
    {
        *(nz+i)=*(nz+i-9);
    }
    *nz='m';
    *(nz+1)='i';
    *(nz+2)='r';
    *(nz+3)='r';
    *(nz+4)='o';
    *(nz+5)='r';
    *(nz+6)='_';
    *(nz+7)='h';
    *(nz+8)='_';
    int t= save_image_t(nz,xd2);
    if(t==1)
    {
        printf("Couldn't create file\n");
    }
    else if(t==2)
    {
        printf("Couldn't create file\n");
    }
    else if(t==3)
    {
        printf("Couldn't create file\n");
    }
    else
    {
        printf("File saved\n");
    }

    *(nz+7)='v';
    t= save_image_t(nz,xd1);
    if(t==1)
    {
        printf("Couldn't create file\n");
    }
    else if(t==2)
    {
        printf("Couldn't create file\n");
    }
    else if(t==3)
    {
        printf("Couldn't create file\n");
    }
    else
    {
        printf("File saved\n");
    }

    *nz='i';
    *(nz+1)='n';
    *(nz+2)='v';
    *(nz+3)='e';
    *(nz+4)='r';
    *(nz+5)='t';
    *(nz+6)='_';
    for(int i=0;i<40;++i)
    {
        *(nz+i+7)=*(nz+i+9);
    }
    t= save_image_t(nz,xd3);
    if(t==1)
    {
        printf("Couldn't create file\n");
    }
    else if(t==2)
    {
        printf("Couldn't create file\n");
    }
    else if(t==3)
    {
        printf("Couldn't create file\n");
    }
    else
    {
        printf("File saved\n");
    }
    destroy_image(&xd);
    destroy_image(&xd1);
    destroy_image(&xd2);
    destroy_image(&xd3);
    free(nz);
    return 0;
}



