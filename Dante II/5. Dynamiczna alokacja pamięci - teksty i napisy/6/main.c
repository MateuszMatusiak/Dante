#include <stdio.h>
#include "stdlib.h"
#include "big_numbers.h"
#include "string.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    char* nz=(char*)calloc(31,sizeof(char));
    if(nz==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    struct big_numbers_t *bn;
    printf("Daj: ");
    scanf("%20s",nz);
    int t= load_big_numbers_b(&bn,nz);
    if(t==1)
    {
        printf("Incorrect input");
        free(nz);
        return 1;
    }
    if(t==2)
    {
        printf("Failed to allocate memory");
        free(nz);
        return 8;
    }
    if(t==3)
    {
        printf("Couldn't open file");
        free(nz);
        return 4;
    }
    if(t==4)
    {
        printf("File corrupted");
        free(nz);
        return 7;
    }
    t=sort_big_numbers_asc(bn);
    if(t==1)
    {
        printf("Incorrect input");
        free(nz);
        return 1;
    }
    char* nz2=(char*) calloc(38,sizeof(char));
    if(nz2==NULL)
    {
        printf("Failed to allocate memory");
        free(nz);
        return 8;
    }
    char* z=(strrchr(nz, '.' ));
    int x;
    if(z!=NULL) {
        x = (z - nz);
        strncpy(nz2, nz, x);
    }
    else
        strcpy(nz2,nz);
    strcat(nz2,"_sorted");
    if(z!=NULL)
        strcat(nz2,strrchr(nz, '.' ));
    strcat(nz2,"\0");
    t= save_big_numbers_b(bn,nz2);
    if(t==1)
    {
        printf("Incorrect input");
        free(nz);
        free(nz2);
        return 1;
    }
    if(t==2)
    {
        printf("Couldn't create file\n");
    }
    else {
        printf("File saved\n");
    }
    int err;
    char* xd= total_sum_big_numbers(bn,&err);
    if(xd==NULL)
    {
        printf("Error");
    }
    else
        printf("%s",xd);

    free(nz);
    free(nz2);
    free(xd);
    destroy_big_numbers(&bn);
    return 0;
}


