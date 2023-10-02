#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

int load_words(char ***words, const char *filename) {
    if (words == NULL || filename == NULL) {
        return 1;
    }
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        *words = NULL;
        return 2;
    }
    int l, t, s = 0;
    char **xd;
    char *w;
    while (!feof(f)) {
        t = fread(&l, sizeof(int), 1, f);
        if (l <= 0) {
            fclose(f);
            *words = NULL;
            return 3;
        }
        if (t == 0)
            break;
        w = (char *) calloc(l, sizeof(char));
        if (w == NULL) {
            fclose(f);
            *words = NULL;
            return 4;
        }
        t = fread(w, sizeof(char), l, f);
        {
            if (t != l) {
                *words = NULL;
                free(w);
                fclose(f);
                return 3;
            }
        }
        free(w);
        ++s;
    }
    if (s == 0) {
        fclose(f);
        *words = NULL;
        return 3;
    }
    xd = (char **) calloc(s + 1, sizeof(char *));
    if (xd == NULL) {
        fclose(f);
        *words = NULL;
        return 4;
    }
    *(xd + s) = NULL;
    fseek(f, SEEK_SET, 0);
    ///////////////////////
    for (int i = 0; i < s; ++i) {
        t = fread(&l, sizeof(int), 1, f);
        if (l <= 0 || t < 0) {
            fclose(f);
            *words = NULL;
            return 3;
        }
        *(xd + i) = (char *) calloc(l + 1, sizeof(char));
        if (*(xd + i) == NULL) {
            for (int k = 0; k < i; ++k)
                free(*(xd + k));
            *words = NULL;
            free(xd);
            fclose(f);
            return 4;
        }
        t = fread(*(xd + i), sizeof(char), l, f);
        strcat(*(xd + i), "\0");
        {
            if (t != l) {
                for (int k = 0; k < i; ++k)
                    free(*(xd + k));
                *words = NULL;
                free(xd);
                fclose(f);
                return 3;
            }
        }
    }
    ///////////////////////////
    *words = xd;
    fclose(f);
    return 0;
}

void destroy(char **words) {
    if (words != NULL) {
        int s = 0;
        while (*(words + s) != NULL) {
            free((*(words + s)));
            s++;
        }
        free(words);
    }
}

int validate(const char *x) {
    int i = 0;
    while (*(x + i) != '\0') {
        if (!(*(x + i) >= 'A' && *(x + i) <= 'Z'))
            return 1;
        i++;
    }
    return 0;
}

int pbs(char *x1, char *x2) {
    int l1 = 0, l2 = 0;
    while (*(x1 + l1) == ' ')
        l1++;
    while (*(x2 + l2) == ' ')
        l2++;
    return strcmp((x1 + l1), (x2 + l2));
}

int create_crossword(char ***crossword, char **words, const char *word) {
    if (crossword == NULL)
        return 1;
    if (words == NULL || word == NULL) {
        *crossword = NULL;
        return 1;
    }
    int sw = 0;
    while (*(words + sw) != NULL) {
        if (validate(*(words + sw)) != 0) {
            *crossword = NULL;
            return 1;
        }
        ++sw;
    }
    if (validate(word) != 0) {
        *crossword = NULL;
        return 1;
    }
    int s = strlen(word);
    if (s == 0) {
        *crossword = NULL;
        return 1;
    }
    char **xd = (char **) calloc(s + 1, sizeof(char *));
    if (xd == NULL) {
        *crossword = NULL;
        return 4;
    }
    *(xd + s) = NULL;
    int k, f = 0, o;
    for (int i = 0; i < s; ++i) {
        for (k = 0; k < sw; ++k) {
            f = 0;
            if (strchr(*(words + k), *(word + i)) != NULL) {
                for (o = 0; o < i; ++o) {
                    int j = strcmp(*(words + k), *(xd + o));
                    if (j == 0) {
                        f = 1;
                    }
                }
                if (f == 1)
                    continue;
                *(xd + i) = (char *) calloc(strlen(*(words + k)) + 1, sizeof(char));
                if (*(xd + i) == NULL) {
                    for (o = 0; o < i; ++o)
                        free(*(xd + o));
                    free(xd);
                    *crossword = NULL;
                    return 4;
                }
                strcat(*(xd + i), *(words + k));
                strcat(*(xd + i), "\0");
                break;
            }
        }
        if (k == sw) {
            for (o = 0; o < i; ++o)
                free(*(xd + o));
            free(xd);
            *crossword = NULL;
            return 2;
        }
    }
    int mx = 0, x;
    for (int i = 0; i < s; ++i) {
        x = strchr(*(xd + i), *(word + i)) - (*(xd + i));
        if (x > mx)
            mx = x;
    }

    for (int i = 0; i < s; ++i)
        free(*(xd + i));


    for (int i = 0; i < s; ++i) {
        for (k = 0; k < sw; ++k) {
            f = 0;
            if (strchr(*(words + k), *(word + i)) != NULL) {
                for (o = 0; o < i; ++o) {
                    if (pbs(*(words + k), *(xd + o)) == 0) {
                        f = 1;
                        break;
                    }
                }
                if (f == 1)
                    continue;


                x = strchr(*(words + k), *(word + i)) - *(words + k);
                int il = mx - x;
                *(xd + i) = (char *) calloc(strlen(*(words + k)) + 1 + il, sizeof(char));
                if (*(xd + i) == NULL) {
                    for (o = 0; o < i; ++o)
                        free(*(xd + o));
                    free(xd);
                    *crossword = NULL;
                    return 4;
                }
                for (o = 0; o < il; ++o) {
                    strcat(*(xd + i), " ");
                }
                strcat(*(xd + i), *(words + k));
                strcat(*(xd + i), "\0");
                break;
            }
        }
        if (k == sw) {
            for (o = 0; o < i; ++o)
                free(*(xd + o));
            free(xd);
            *crossword = NULL;
            return 2;
        }
    }
    *crossword = xd;
    return 0;
}


int main() {

    char *nz = (char *) calloc(40, sizeof(char));
    if (nz == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj:");
    scanf("%39s", nz);
    while (getchar() != '\n');


    char **words;
    int t = load_words(&words, nz);
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

    char *pwd = (char *) calloc(11, sizeof(char));
    if (pwd == NULL) {
        printf("Failed to allocate memory");
        free(nz);
        return 8;
    }

    printf("Daj:");
    scanf("%10s", pwd);
    char **crossword;
    t = create_crossword(&crossword, words, pwd);
    if (t == 1) {
        printf("Incorrect input");
        destroy(words);
        free(nz);
        free(pwd);
        return 1;
    }
    if (t == 2) {
        printf("Couldn't create crossword");
        free(nz);
        free(pwd);
        destroy(words);
        return 0;
    }
    if (t == 4) {
        printf("Failed to allocate memory");
        free(nz);
        free(pwd);
        destroy(words);
        return 8;
    }
    int i = 0, k = 0;
    while (*(crossword + i) != NULL) {
        k = 0;
        if (*(*(crossword + i) + k) == *(pwd + i)) {
            printf("|%c|", *(*(crossword + i) + k));
            k++;
            while (*(*(crossword + i) + k) != '\0') {
                printf("%c", *(*(crossword + i) + k));
                k++;
            }
        } else {
            while (*(*(crossword + i) + k) != *(pwd + i)) {
                printf("%c", *(*(crossword + i) + k));
                k++;
            }
            printf("|%c|", *(*(crossword + i) + k));
            k++;
            while (*(*(crossword + i) + k) != '\0') {
                printf("%c", *(*(crossword + i) + k));
                k++;
            }
        }
        printf("\n");
        i++;
    }

    free(nz);
    free(pwd);
    destroy(words);
    destroy(crossword);
    return 0;
}



