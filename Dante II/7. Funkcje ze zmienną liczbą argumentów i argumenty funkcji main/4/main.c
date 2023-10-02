#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

char* concatenate(int n,...)
{
    if(n<=1)
        return NULL;

    char* txt;
    int sz=0;
    va_list ap,ap2;
    va_start(ap,n);
    va_copy(ap2,ap);
    for(int i=0;i<n;++i) {
        txt = va_arg(ap2, char*);
        sz += strlen(txt);
        sz++;
    }

    char *res=(char*)calloc(sz,sizeof(char));
    if(res==NULL)
    {
        va_end(ap);
        va_end(ap2);
        return NULL;
    }


    for(int i=0;i<n-1;++i)
    {
        txt = va_arg(ap,char*);
        strcat(res, txt);
        strcat(res, " ");
    }
    txt = va_arg(ap,char*);
    strcat(res, txt);
    va_end(ap);
    va_end(ap2);
    return res;
}

//main do zrobienia, f gotowa
int main() {
    int n;
    char **xd = (char **) calloc(4, sizeof(char *));
    if (xd == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    for (int i = 0; i < 4; ++i) {
        *(xd + i) = (char *) calloc(1001, sizeof(char));
        if (*(xd + i) == NULL) {
            for (int k = 0; k < i; ++k)
                free(*(xd + k));
            free(xd);
            printf("Failed to allocate memory");
            return 8;
        }
    }

    int t;
    printf("Daj:");
    t=scanf("%d",&n);
    if(t!=1)
    {
        for (int k = 0; k < 4; ++k)
            free(*(xd + k));
        free(xd);
        printf("Incorrect input");
        return 1;
    }
    if(n<2||n>4)
    {
        for (int k = 0; k < 4; ++k)
            free(*(xd + k));
        free(xd);
        printf("Incorrect input data");
        return 2;
    }

    printf("Daj: ");
    for(int i=0;i<n;++i)
    {
        while (getchar () != '\n' );
        scanf("%1000[^\n]",*(xd+i));
    }
    char *res= concatenate(n,*(xd),*(xd+1),*(xd+2),*(xd+3));
    if(res==NULL)
    {
        free(res);
        for(int i=0;i<4;++i)
            free(*(xd+i));
        free(xd);
        printf("Failed to allocate memory");
        return 8;
    }

    printf("%s",res);
    for(int i=0;i<4;++i)
        free(*(xd+i));
    free(xd);
    free(res);
    return 0;
}
