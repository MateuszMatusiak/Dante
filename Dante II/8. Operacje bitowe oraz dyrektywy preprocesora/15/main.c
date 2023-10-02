#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "tested_declarations.h"
#include "rdebug.h"

DEFINE_ARRAY(int)

CREATE_ARRAY(int)

FREE_ARRAY(int)

SAVE_ARRAY(int)

LOAD_ARRAY(int)

SORT_ARRAY(int)

DEFINE_ARRAY(double)

CREATE_ARRAY(double)

FREE_ARRAY(double)

SAVE_ARRAY(double)

LOAD_ARRAY(double)

SORT_ARRAY(double)


void getstr(char *nz, int n) {
    char ch = getchar();
    int i = 0;
    while (i < n && ch != '\n') {
        *(nz + i) = ch;
        ch = getchar();
        ++i;
    }
    *(nz + i) = '\0';
    if (i == n && ch != '\n')
        while (getchar() != '\n');
}

int main() {
    char *nz = (char *) calloc(31, sizeof(char));
    if (nz == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    struct array_int_t *xdi;
    struct array_double_t *xdd;
    int c = 0;
    printf("Daj: ");
    getstr(nz, 30);
    printf("Daj: ");
    int t = scanf("%d", &c);
    if (t != 1) {
        printf("Incorrect input");
        free(nz);
        return 1;
    }
    if (c == 0) {
        t = load_array_int(&xdi, nz);
        if (t == 1) {
            printf("Incorrect input");
            free(nz);
            return 1;

        }
        if (t == 2) {
            printf("Couldn't open file");
            free(nz);
            return 4;
        }
        if (t == 3) {
            printf("File corrupted");
            free(nz);
            return 6;
        }
        if (t == 4) {
            printf("Failed to allocate memory");
            free(nz);
            return 8;
        }
        sort_array_int(xdi);
        t=save_array_int(xdi, nz);
        if (t !=0) {
            printf("Couldn't create file");
            free_array_int(xdi);
            free(nz);
            return 5;

        }
        free_array_int(xdi);
    } else if (c == 1) {
        t = load_array_double(&xdd, nz);
        if (t == 1) {
            printf("Incorrect input");
            free(nz);
            return 1;

        }
        if (t == 2) {
            printf("Couldn't open file");
            free(nz);
            return 4;
        }
        if (t == 3) {
            printf("File corrupted");
            free(nz);
            return 6;
        }
        if (t == 4) {
            printf("Failed to allocate memory");
            free(nz);
            return 8;
        }
        sort_array_double(xdd);
        t=save_array_double(xdd, nz);
        if (t!=0) {
            printf("Couldn't create file");
            free_array_double(xdd);
            free(nz);
            return 5;

        }
        free_array_double(xdd);
    } else {
        free(nz);
        printf("Incorrect input data");
        return 2;
    }
    printf("File saved");
    free(nz);
    return 0;
}

