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

int endsWith(const char* txt, const char* src)
{
    int l= strlen(txt);
    int l1= strlen(src);

    if(l<l1)
        return 0;
    int k=0;
    for(int i=l-l1;i<l;++i)
    {
        if(*(txt+i)!=*(src+k))
        {
            return 0;
        }
        ++k;
    }

    return 1;
}

int main() {
    char* nz=(char*) calloc(20,sizeof(char));
    if(nz==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    getstr(nz,19);

    if(!endsWith(nz,".bin")&&!endsWith(nz,".txt"))
    {
        free(nz);
        printf("Unsupported file format");
        return 7;
    }
    int err;
    struct matrix_t* xd1;
    struct matrix_t* xd2;
    if(endsWith(nz,".bin"))
    {
        xd1= matrix_load_b(nz,&err);
        if(xd1==NULL)
        {
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
    }
    if(endsWith(nz,".txt"))
    {
        xd1= matrix_load_t(nz,&err);
        if(xd1==NULL)
        {
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
    }

    printf("Daj: ");
    getstr(nz,19);

    if(!endsWith(nz,".bin")&&!endsWith(nz,".txt"))
    {
        free(nz);
        matrix_destroy_struct(&xd1);
        printf("Unsupported file format");
        return 7;
    }

    if(endsWith(nz,".bin"))
    {
        xd2= matrix_load_b(nz,&err);
        if(xd2==NULL)
        {
            switch (err) {
                case 1:
                    printf("Incorrect input");
                    matrix_destroy_struct(&xd1);
                    free(nz);
                    return 1;
                    case 2:
                        printf("Couldn't open file");
                        matrix_destroy_struct(&xd1);
                        free(nz);
                        return 4;
                        case 3:
                            printf("File corrupted");
                            matrix_destroy_struct(&xd1);
                            free(nz);
                            return 6;
                            case 4:
                                printf("Failed to allocate memory");
                                matrix_destroy_struct(&xd1);
                                free(nz);
                                return 8;
                                default:
                                    return 0;
            }
        }
    }
    if(endsWith(nz,".txt"))
    {
        xd2= matrix_load_t(nz,&err);
        if(xd2==NULL)
        {
            switch (err) {
                case 1:
                    printf("Incorrect input");
                    matrix_destroy_struct(&xd1);
                    free(nz);
                    return 1;
                    case 2:
                        printf("Couldn't open file");
                        matrix_destroy_struct(&xd1);
                        free(nz);
                        return 4;
                        case 3:
                            printf("File corrupted");
                            matrix_destroy_struct(&xd1);
                            free(nz);
                            return 6;
                            case 4:
                                printf("Failed to allocate memory");
                                matrix_destroy_struct(&xd1);
                                free(nz);
                                return 8;
                                default:
                                    return 0;
            }
        }
    }

    struct matrix_t *xd3= matrix_add(xd1,xd2);
    if(xd3==NULL)
    {
        printf("Error\n");
    }
    else
    {
        matrix_display(xd3);
    }
    matrix_destroy_struct(&xd3);
    xd3= matrix_subtract(xd1,xd2);
    if(xd3==NULL)
    {
        printf("Error\n");
    }
    else
    {
        matrix_display(xd3);
    }
    matrix_destroy_struct(&xd3);
    xd3= matrix_multiply(xd1,xd2);
    if(xd3==NULL)
    {
        printf("Error\n");
    }
    else
    {
        matrix_display(xd3);
    }
    matrix_destroy_struct(&xd1);
    matrix_destroy_struct(&xd2);
    matrix_destroy_struct(&xd3);
    free(nz);
    return 0;
}

