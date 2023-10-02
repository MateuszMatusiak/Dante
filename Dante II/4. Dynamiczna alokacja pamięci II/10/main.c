#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"


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

int endsWith(const char *txt, const char *src) {
    int l = strlen(txt);
    int l1 = strlen(src);

    if (l < l1)
        return 0;
    int k = 0;
    for (int i = l - l1; i < l; ++i) {
        if (*(txt + i) != *(src + k)) {
            return 0;
        }
        ++k;
    }

    return 1;
}

int main() {
    char *nz = (char *) calloc(501, sizeof(char));
    if (nz == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    getstr(nz, 500);

    int j = 0;
    int i = 0;
    int k;
    char ch;
    int err;
    int s = 0;
    char *xxd1, *xxd2;
    struct matrix_t *xd1;
    struct matrix_t *xd2;
    struct matrix_t *xd3;

    while (*(nz + i) != '+' && *(nz + i) != '-' && *(nz + i) != '*') {
        ++i;
    }
    j = i;
    ch = *(nz + i);
    if (i == (int) strlen(nz)) {
        printf("Incorrect input");
        free(nz);
        return 1;
    }
    xxd1 = (char *) calloc(500, sizeof(char));
    if (xxd1 == NULL) {
        printf("Failed to allocate memory");
        free(nz);
        return 8;
    }
    strncpy(xxd1, nz, i);
    *(xxd1+i)='\0';

    ++i;
    j++;

    if (endsWith(xxd1, ".bin")) {
        xd1 = matrix_load_b(xxd1, &err);
        if (xd1 == NULL) {
            switch (err) {
                case 1:
                    printf("Incorrect input");
                    free(nz);
                    free(xxd1);
                    return 1;
                case 2:
                    printf("Couldn't open file");
                    free(nz);
                    free(xxd1);
                    return 4;
                case 3:
                    printf("File corrupted");
                    free(nz);
                    free(xxd1);
                    return 6;
                case 4:
                    printf("Failed to allocate memory");
                    free(nz);
                    free(xxd1);
                    return 8;
                default:
                    return 0;
            }
        }
    } else if (endsWith(xxd1, ".txt")) {
        xd1 = matrix_load_t(xxd1, &err);
        if (xd1 == NULL) {
            switch (err) {
                case 1:
                    printf("Incorrect input");
                    free(nz);
                    free(xxd1);
                    return 1;
                case 2:
                    printf("Couldn't open file");
                    free(nz);
                    free(xxd1);
                    return 4;
                case 3:
                    printf("File corrupted");
                    free(nz);
                    free(xxd1);
                    return 6;
                case 4:
                    printf("Failed to allocate memory");
                    free(nz);
                    free(xxd1);
                    return 8;
                default:
                    return 0;
            }
        }
    } else {
        free(nz);
        free(xxd1);
        printf("Unsupported file format");
        return 7;
    }

    k = i;
    while (*(nz + k) != '+' && *(nz + k) != '-' && *(nz + k) != '*' && *(nz + k) != '\0') {
        ++k;
    }
    j = k;


    xxd2 = (char *) calloc(500, sizeof(char));
    if (xxd2 == NULL) {
        printf("Failed to allocate memory");
        free(xxd1);
        free(nz);
        return 8;
    }
    strncpy(xxd2, nz + i, k - i);
    *(xxd2+k-i)='\0';


    if (endsWith(xxd2, ".bin")) {
        xd2 = matrix_load_b(xxd2, &err);
        if (xd2 == NULL) {
            switch (err) {
                case 1:
                    printf("Incorrect input");
                    matrix_destroy_struct(&xd1);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    return 1;
                case 2:
                    printf("Couldn't open file");
                    matrix_destroy_struct(&xd1);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    return 4;
                case 3:
                    printf("File corrupted");
                    matrix_destroy_struct(&xd1);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    return 6;
                case 4:
                    printf("Failed to allocate memory");
                    matrix_destroy_struct(&xd1);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    return 8;
                default:
                    return 0;
            }
        }
    } else if (endsWith(xxd2, ".txt")) {
        xd2 = matrix_load_t(xxd2, &err);
        if (xd2 == NULL) {
            switch (err) {
                case 1:
                    printf("Incorrect input");
                    matrix_destroy_struct(&xd1);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    return 1;
                case 2:
                    printf("Couldn't open file");
                    matrix_destroy_struct(&xd1);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    return 4;
                case 3:
                    printf("File corrupted");
                    matrix_destroy_struct(&xd1);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    return 6;
                case 4:
                    printf("Failed to allocate memory");
                    matrix_destroy_struct(&xd1);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    return 8;
                default:
                    return 0;
            }
        }
    } else {
        free(xxd1);
        free(xxd2);
        free(nz);
        matrix_destroy_struct(&xd1);
        printf("Unsupported file format");
        return 7;
    }


    switch (ch) {
        case '+':
            if (xd1->height != xd2->height || xd1->width != xd2->width) {
                matrix_destroy_struct(&xd1);
                matrix_destroy_struct(&xd2);
                free(nz);
                free(xxd1);
                free(xxd2);
                printf("Illegal operation");
                return 1;
            }
            xd3 = matrix_add(xd1, xd2);
            if (xd3 == NULL) {
                matrix_destroy_struct(&xd1);
                matrix_destroy_struct(&xd2);
                free(nz);
                free(xxd1);
                free(xxd2);
                printf("Failed to allocate memory");
                return 8;
            }
            break;
        case '-':
            if (xd1->height != xd2->height || xd1->width != xd2->width) {
                matrix_destroy_struct(&xd1);
                matrix_destroy_struct(&xd2);
                free(nz);
                free(xxd1);
                free(xxd2);
                printf("Illegal operation");
                return 1;
            }
            xd3 = matrix_subtract(xd1, xd2);
            if (xd3 == NULL) {
                matrix_destroy_struct(&xd1);
                matrix_destroy_struct(&xd2);
                free(nz);
                free(xxd1);
                free(xxd2);
                printf("Failed to allocate memory");
                return 8;
            }
            break;
        case '*':
            if (xd1->height != xd2->width) {
                matrix_destroy_struct(&xd1);
                matrix_destroy_struct(&xd2);
                free(nz);
                free(xxd1);
                free(xxd2);
                printf("Illegal operation");
                return 1;
            }
            xd3 = matrix_multiply(xd1, xd2);
            if (xd3 == NULL) {
                matrix_destroy_struct(&xd1);
                matrix_destroy_struct(&xd2);
                free(nz);
                free(xxd1);
                free(xxd2);
                printf("Failed to allocate memory");
                return 8;
            }
            break;
        default:
            break;
    }


    while (*(nz + j) != '\0') {
        matrix_destroy_struct(&xd1);
        matrix_destroy_struct(&xd2);
        s = 12;
        ch = *(nz + j);
        if (ch == '\0')
            break;
        j++;
        k = j;
        while (*(nz + k) != '+' && *(nz + k) != '-' && *(nz + k) != '*' && *(nz + k) != '\0') {
            ++k;
        }
        strncpy(xxd1, nz + j, k - j);
        *(xxd1+k-j)='\0';
        j = k;
        if (endsWith(xxd1, ".bin")) {
            xd1 = matrix_load_b(xxd1, &err);
            if (xd1 == NULL) {
                switch (err) {
                    case 1:
                        printf("Incorrect input");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd3);
                        return 1;
                    case 2:
                        printf("Couldn't open file");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd3);
                        return 4;
                    case 3:
                        printf("File corrupted");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd3);
                        return 6;
                    case 4:
                        printf("Failed to allocate memory");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd3);
                        return 8;
                    default:
                        return 0;
                }
            }
        } else if (endsWith(xxd1, ".txt")) {
            xd1 = matrix_load_t(xxd1, &err);
            if (xd1 == NULL) {
                switch (err) {
                    case 1:
                        printf("Incorrect input");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd3);
                        return 1;
                    case 2:
                        printf("Couldn't open file");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd3);
                        return 4;
                    case 3:
                        printf("File corrupted");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd3);
                        return 6;
                    case 4:
                        printf("Failed to allocate memory");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd3);
                        return 8;
                    default:
                        return 0;
                }
            }
        } else {
            free(nz);
            free(xxd1);
            free(xxd2);
            matrix_destroy_struct(&xd3);
            printf("Unsupported file format");
            return 7;
        }

        switch (ch) {
            case '+':
                if (xd3->height != xd1->height || xd3->width != xd1->width) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd3);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Illegal operation");
                    return 1;
                }
                xd2 = matrix_add(xd3, xd1);
                if (xd2 == NULL) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd3);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Failed to allocate memory");
                    return 8;
                }
                break;

            case '-':
                if (xd3->height != xd1->height || xd3->width != xd1->width) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd3);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Illegal operation");
                    return 1;
                }
                xd2 = matrix_subtract(xd3, xd1);
                if (xd2 == NULL) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd3);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Failed to allocate memory");
                    return 8;
                }
                break;
            case '*':
                if (xd3->height != xd1->width) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd3);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Illegal operation");
                    return 1;
                }
                xd2 = matrix_multiply(xd3, xd1);
                if (xd2 == NULL) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd3);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Failed to allocate memory");
                    return 8;
                }
                break;
            default:
                break;
        }
        matrix_destroy_struct(&xd1);
        matrix_destroy_struct(&xd3);
        s = 13;
        ch = *(nz + j);
        if (ch == '\0')
            break;
        j++;
        k = j;
        while (*(nz + k) != '+' && *(nz + k) != '-' && *(nz + k) != '*' && *(nz + k) != '\0') {
            ++k;
        }
        strncpy(xxd1, nz + j, k - j);
        *(xxd1+k-j)='\0';
        j = k;
        if (endsWith(xxd1, ".bin")) {
            xd1 = matrix_load_b(xxd1, &err);
            if (xd1 == NULL) {
                switch (err) {
                    case 1:
                        printf("Incorrect input");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd2);
                        return 1;
                    case 2:
                        printf("Couldn't open file");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd2);
                        return 4;
                    case 3:
                        printf("File corrupted");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd2);
                        return 6;
                    case 4:
                        printf("Failed to allocate memory");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd2);
                        return 8;
                    default:
                        return 0;
                }
            }
        } else if (endsWith(xxd1, ".txt")) {
            xd1 = matrix_load_t(xxd1, &err);
            if (xd1 == NULL) {
                switch (err) {
                    case 1:
                        printf("Incorrect input");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd2);
                        return 1;
                    case 2:
                        printf("Couldn't open file");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd2);
                        return 4;
                    case 3:
                        printf("File corrupted");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd2);
                        return 6;
                    case 4:
                        printf("Failed to allocate memory");
                        free(nz);
                        free(xxd1);
                        free(xxd2);
                        matrix_destroy_struct(&xd2);
                        return 8;
                    default:
                        return 0;
                }
            }
        } else {
            free(nz);
            free(xxd1);
            free(xxd2);
            matrix_destroy_struct(&xd2);
            printf("Unsupported file format");
            return 7;
        }

        switch (ch) {
            case '+':
                if (xd1->height != xd2->height || xd1->width != xd2->width) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd2);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Illegal operation");
                    return 1;
                }
                xd3 = matrix_add(xd2, xd1);
                if (xd3 == NULL) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd2);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Failed to allocate memory");
                    return 8;
                }
                break;
            case '-':
                if (xd1->height != xd2->height || xd1->width != xd2->width) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd2);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Illegal operation");
                    return 1;
                }
                xd3 = matrix_subtract(xd2, xd1);
                if (xd3 == NULL) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd2);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Failed to allocate memory");
                    return 8;
                }
                break;
            case '*':
                if (xd1->height != xd2->width) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd2);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Illegal operation");
                    return 1;
                }
                xd3 = matrix_multiply(xd2, xd1);
                if (xd3 == NULL) {
                    matrix_destroy_struct(&xd1);
                    matrix_destroy_struct(&xd2);
                    free(nz);
                    free(xxd1);
                    free(xxd2);
                    printf("Failed to allocate memory");
                    return 8;
                }
                break;
            default:
                break;
        }
    }

    if (s == 12) {
        matrix_display(xd3);
        matrix_destroy_struct(&xd3);
    } else if (s == 13) {
        matrix_display(xd2);
        matrix_destroy_struct(&xd2);
    } else {
        matrix_display(xd3);
        matrix_destroy_struct(&xd1);
        matrix_destroy_struct(&xd2);
        matrix_destroy_struct(&xd3);
    }
    free(xxd1);
    free(xxd2);
    free(nz);

    return 0;
}

