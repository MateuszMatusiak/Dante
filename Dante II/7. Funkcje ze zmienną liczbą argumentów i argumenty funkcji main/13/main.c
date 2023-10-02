#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include "tested_declarations.h"
#include "rdebug.h"

int *count_words(const char *filename, int *err_code, int N, ...) {
    if (err_code != NULL) {
        *err_code = 0;
    }
    if (filename == NULL || N <= 0) {
        if (err_code != NULL) {
            *err_code = 1;
        }
        return NULL;
    }
    FILE *f;
    f = fopen(filename, "r");
    if (f == NULL) {
        if (err_code != NULL) {
            *err_code = 2;
        }
        return NULL;
    }


    int *res = (int *) calloc(N, sizeof(int));
    if (res == NULL) {
        if (err_code != NULL) {
            *err_code = 3;
        }
        fclose(f);
        return NULL;
    }

    va_list ap;
    va_start(ap, N);
    for (int i = 0; i < N; ++i) {
        fseek(f, SEEK_SET, 0);
        char *txt = va_arg(ap, char*);
        while (!feof(f)) {
            fpos_t pos;
            fgetpos(f, &pos);
            char x;
            int c = 0;
            do {
                x = fgetc(f);
                ++c;
            } while (isalpha(x));
            if (c == 1)
                continue;
            c--;
            if ((int) strlen(txt) != c)
                continue;
            fsetpos(f, &pos);
            int k = 0, ch = 1;
            while (*(txt + k) != '\0') {
                x = fgetc(f);
                if (*(txt + k) != x)
                    ch = 0;
                ++k;
            }
            if (ch == 1 && !isalpha(fgetc(f))) {
                (*(res + i))++;
            }
        }
    }

    fclose(f);
    va_end(ap);
    return res;
}

int main(int argc, char *argv[]) {
    if(argc<3)
    {
        printf("Not enough arguments");
        return 9;
    }
    int err=1;
    for(int i=0;i<argc-2;++i) {
        int *r = count_words(*(argv + 1), &err, 1, *(argv + 2 + i));
        if(err==1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(err==2)
        {
            printf("Couldn't open file");
            return 4;
        }
        if(err==3)
        {
            printf("Failed to allocate memory");
            return 8;
        }
        printf("%d\n",*r);
        free(r);
    }
    return 0;
}

