#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

int concatenate(char *res, int s, int n, ...) {
    if (res == NULL || s <= 0 || n <= 1)
        return 1;

    char *txt;
    int sz = 0;
    va_list ap;
    va_start(ap, n);

    txt = va_arg(ap, char*);
    sz += strlen(txt);
    if (sz + n - 1 > s) {
        va_end(ap);
        return 2;
    }
    strcpy(res, txt);
    strcat(res, " ");


    for (int i = 1; i < n - 1; ++i) {
        txt = va_arg(ap, char*);
        sz += strlen(txt);
        if (sz + n - 1 > s) {
            va_end(ap);
            return 2;
        }
        strcat(res, txt);
        strcat(res, " ");
    }
    txt = va_arg(ap, char*);
    sz += strlen(txt);
    if (sz + n > s) {
        va_end(ap);
        return 2;
    }
    strcat(res, txt);
    va_end(ap);
    return 0;
}


int main() {
    int t, n;
    char *res;
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

    res = (char *) calloc(4004, sizeof(char));
    if (res == NULL) {
        for (int k = 0; k < 4; ++k)
            free(*(xd + k));
        free(xd);
        printf("Failed to allocate memory");
        return 8;
    }


    printf("Daj:");
    t = scanf("%d", &n);
    if (t != 1) {
        for (int k = 0; k < 4; ++k)
            free(*(xd + k));
        free(xd);
        free(res);
        printf("Incorrect input");
        return 1;
    }
    if (n < 2 || n > 4) {
        for (int k = 0; k < 4; ++k)
            free(*(xd + k));
        free(xd);
        free(res);
        printf("Incorrect input data");
        return 2;
    }
    printf("Daj:");
    for (int i = 0; i < n; ++i) {

        while(getchar()!='\n');
        scanf("%1000[^\n]", *(xd + i));
    }
    char *xd1=*xd;
    char *xd2=*(xd + 1);
    char *xd3=*(xd + 2);
    char *xd4=*(xd + 3);

    t = concatenate(res, 4004, n, xd1, xd2, xd3, xd4);
    if (t == 1) {
        free(res);
        for (int i = 0; i < 4; ++i)
            free(*(xd + i));
        free(xd);
        printf("Incorrect input");
        return 1;
    }
    if (t == 2) {
        free(res);
        for (int i = 0; i < 4; ++i)
            free(*(xd + i));
        free(xd);
        printf("Failed to allocate memory");
        return 8;
    }
    printf("%s", res);
    for (int i = 0; i < 4; ++i)
        free(*(xd + i));
    free(xd);
    free(res);

    return 0;
}


