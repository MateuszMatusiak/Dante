#include <stdio.h>
#include <stdlib.h>
#include "image_utils.h"
#include <string.h>
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

int main() {
    char *nz = (char *) calloc(40, sizeof(char));
    if (nz == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    getstr(nz, 39);
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

    int q = 0;
    printf("Daj: ");
    int t = scanf("%d", &q);
    if (t != 1) {
        printf("Incorrect input");
        free(nz);
        destroy_image(&xd);
        return 1;
    }

    if (q < 1) {
        printf("Incorrect input data");
        free(nz);
        destroy_image(&xd);
        return 2;
    }
    while (getchar() != '\n');
    for (int i = 0; i < q; ++i) {
        char *xxd = (char *) calloc(40, sizeof(char));
        if (xxd == NULL) {
            printf("Failed to allocate memory");
            free(nz);
            destroy_image(&xd);
            return 8;
        }

        printf("Daj: ");
        getstr(xxd, 39);

        struct image_t *xd1 = load_image_t(xxd, &err);
        if (xd1 == NULL) {
            switch (err) {
                case 1:
                    printf("Incorrect input\n");
                    break;
                case 2:
                    printf("Couldn't open file\n");
                    break;
                case 3:
                    printf("File corrupted\n");
                    break;
                case 4:
                    printf("Failed to allocate memory\n");
                    free(nz);
                    free(xxd);
                    destroy_image(&xd);
                    return 8;
                default:
                    return 0;
            }
            free(xxd);
            continue;
        }

        int x, y;
        printf("Daj: ");
        t = scanf("%d %d", &x, &y);
        if (t != 2) {
            printf("Incorrect input\n");
            free(xxd);
            destroy_image(&xd1);
            destroy_image(&xd);
            free(nz);
            return 1;
        }
        while (getchar() != '\n');
        t= draw_image(xd,xd1,x,y);
        if(t==1)
        {
            printf("Incorrect input data\n");
        }
        free(xxd);
        destroy_image(&xd1);
    }

    char* n1=realloc(nz,49*sizeof(char));
    if(n1==NULL)
    {
        printf("Failed to allocate memory");
        destroy_image(&xd);
        free(nz);
        return 8;
    }
    nz=n1;

    int l=strlen(nz);
    if(*(nz+l-1)=='m'&&*(nz+l-2)=='g'&&*(nz+l-3)=='p'&&*(nz+l-4)=='.')
    {
        *(nz+l-4)='_';
        *(nz+l-3)='m';
        *(nz+l-2)='o';
        *(nz+l-1)='d';
        *(nz+l)='i';
        *(nz+l+1)='f';
        *(nz+l+2)='i';
        *(nz+l+3)='e';
        *(nz+l+4)='d';
        *(nz+l+5)='.';
        *(nz+l+6)='p';
        *(nz+l+7)='g';
        *(nz+l+8)='m';
        *(nz+l+9)='\0';
    }
    else if(*(nz+l-1)=='t'&&*(nz+l-2)=='x'&&*(nz+l-3)=='t'&&*(nz+l-4)=='.')
    {
        *(nz+l-4)='_';
        *(nz+l-3)='m';
        *(nz+l-2)='o';
        *(nz+l-1)='d';
        *(nz+l)='i';
        *(nz+l+1)='f';
        *(nz+l+2)='i';
        *(nz+l+3)='e';
        *(nz+l+4)='d';
        *(nz+l+5)='.';
        *(nz+l+6)='t';
        *(nz+l+7)='x';
        *(nz+l+8)='t';
        *(nz+l+9)='\0';
    }
    else
    {
        strcat(nz,"_modified");
    }
    t= save_image_t(nz,xd);
    if(t)
    {
        printf("Couldn't create file");
        destroy_image(&xd);
        free(nz);
        return 5;
    }
    printf("File saved");
    destroy_image(&xd);
    free(nz);
    return 0;
}


