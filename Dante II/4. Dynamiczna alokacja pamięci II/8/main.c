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
    if(i==n&&ch!='\n')
        while (getchar () != '\n' );


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

    int x,y,w,h,sz;

    printf("Daj: ");
    int t= scanf("%d %d %d %d",&x, &y, &w, &h);
    if(t!=4)
    {
        printf("Incorrect input");
        free(nz);
        destroy_image(&xd);
        return 1;
    }
//    if(w<=0||w>xd->width||h<=0||h>xd->height)
//    {
//        printf("Incorrect input data");
//        free(nz);
//        destroy_image(&xd);
//        return 2;
//    }
//    if(x<0||x>=xd->width-w||y<0||y>=xd->height-h)
//    {
//        printf("Incorrect input data");
//        free(nz);
//        destroy_image(&xd);
//        return 2;
//    }
    printf("Daj: ");
    t=scanf("%d",&sz);
    if(t!=1)
    {
        printf("Incorrect input");
        free(nz);
        destroy_image(&xd);
        return 1;
    }
//    if(sz<0||sz>255)
//    {
//        printf("Incorrect input data");
//        free(nz);
//        destroy_image(&xd);
//        return 2;
//    }
    struct rectangle_t rect;
    rect.height=h;
    rect.width=w;
    rect.p.x=x;
    rect.p.y=y;
    t= image_draw_rectangle(xd,&rect,sz);
    if(t==1)
    {
        printf("Incorrect input data");
        free(nz);
        destroy_image(&xd);
        return 2;
    }
    t= save_image_t(nz,xd);
    if(t==1)
    {
        printf("Couldn't create file\n");
        destroy_image(&xd);
        free(nz);
        return 5;
    }
    else if(t==2)
    {
        printf("Couldn't create file\n");
        destroy_image(&xd);
        free(nz);
        return 5;
    }
    else if(t==3)
    {
        printf("Couldn't create file\n");
        destroy_image(&xd);
        free(nz);
        return 5;
    }
    else
    {
        printf("File saved\n");
    }
    destroy_image(&xd);
    free(nz);
    return 0;
}


