#include <stdio.h>
#include <stdlib.h>
#include "image_utils.h"
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"


struct image_t *load_image_t(const char *filename, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (filename == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return NULL;
    }
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        if (err_code != NULL)
            *err_code = 2;
        return NULL;
    }
    struct image_t *xd = calloc(1, sizeof(struct image_t));
    if (xd == NULL) {
        if (err_code != NULL)
            *err_code = 4;
        fclose(f);
        return NULL;
    }
    if (fgets(xd->type, 3, f) == NULL) {
        if (err_code != NULL)
            *err_code = 3;
        fclose(f);
        free(xd);
        return NULL;
    }
    if (strcmp(xd->type, "P2") != 0) {
        if (err_code != NULL)
            *err_code = 3;
        fclose(f);
        free(xd);
        return NULL;
    }
    int t = fscanf(f, "%d %d", &(xd->width), &(xd->height));
    if (t != 2) {
        if (err_code != NULL)
            *err_code = 3;
        free(xd);
        fclose(f);
        return NULL;
    }
    if (xd->width <= 0 || xd->height <= 0) {
        if (err_code != NULL)
            *err_code = 3;
        free(xd);
        fclose(f);
        return NULL;
    }
    int sz;
    t = fscanf(f, "%d", &sz);
    if (t != 1) {
        if (err_code != NULL)
            *err_code = 3;
        free(xd);
        fclose(f);
        return NULL;
    }
    if (sz != 255) {
        if (err_code != NULL)
            *err_code = 3;
        free(xd);
        fclose(f);
        return NULL;
    }
    xd->ptr = (int **) calloc(xd->height, sizeof(int *));
    if (xd->ptr == NULL) {
        if (err_code != NULL)
            *err_code = 4;
        fclose(f);
        free(xd);
        return NULL;
    }
    for (int i = 0; i < xd->height; ++i) {
        *(xd->ptr + i) = (int *) calloc(xd->width, sizeof(int));
        if (*(xd->ptr + i) == NULL) {
            for (int k = 0; k < i; ++k)
                free(*(xd->ptr + k));
            free((xd->ptr));
            free(xd);
            fclose(f);
            if (err_code != NULL)
                *err_code = 4;
            return NULL;
        }
    }
    for (int i = 0; i < xd->height; ++i) {
        for (int k = 0; k < xd->width; ++k) {
            t = fscanf(f, "%d", (*(xd->ptr + i) + k));
            if (t != 1||*(*(xd->ptr + i) + k)<0) {
                for (int o = 0; o < xd->height; ++o)
                    free(*(xd->ptr + o));
                free((xd->ptr));
                free(xd);
                fclose(f);
                if (err_code != NULL)
                    *err_code = 3;
                return NULL;
            }
        }
    }
    fclose(f);
    return xd;
}

int save_image_t(const char *filename, const struct image_t *m1) {
    if (filename == NULL || m1 == NULL || m1->height <= 0 || m1->width <= 0 || m1->ptr == NULL ||
        strcmp(m1->type, "P2") != 0) {
        return 1;
    }
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        return 2;
    }
    int t = fprintf(f, "%s\n", m1->type);
    if (t < 0) {
        fclose(f);
        return 3;
    }
    t = fprintf(f, "%d %d\n", m1->width, m1->height);
    if (t < 0) {
        fclose(f);
        return 3;
    }
    t = fprintf(f, "%d\n", 255);
    if (t < 0) {
        fclose(f);
        return 3;
    }
    for (int i = 0; i < m1->height; ++i) {
        for (int k = 0; k < m1->width; ++k) {
            t = fprintf(f, "%d ", *(*(m1->ptr + i) + k));
            if (t < 0) {
                fclose(f);
                return 3;
            }
        }
        t = fprintf(f, "\n");
        if (t < 0) {
            fclose(f);
            return 3;
        }
    }
    fclose(f);
    return 0;
}

void destroy_image(struct image_t **m) {
    if (m != NULL) {
        struct image_t *m1 = *m;
        if ((m1)->ptr != NULL) {
            for (int i = 0; i < (m1->height); i++) {
                if ((m1->ptr + i) != NULL)
                    free(*((*m)->ptr + i));
            }
            free(m1->ptr);
            free(*m);
            *m = NULL;
            m = NULL;
        }
    }
}

struct image_t *image_flip_horizontal(const struct image_t *m1) {
    if (m1 == NULL)
        return NULL;

    if (m1->height <= 0 || m1->width <= 0 || m1->ptr == NULL)
        return NULL;

    struct image_t *xd = (struct image_t *) calloc(1, sizeof(struct image_t));
    if (xd == NULL)
        return NULL;
    xd->height = m1->height;
    xd->width = m1->width;
    strcpy(xd->type, m1->type);


    xd->ptr = (int **) calloc(xd->height, sizeof(int *));
    if (xd->ptr == NULL) {
        free(xd);
        return NULL;
    }

    for (int i = 0; i < m1->height; ++i) {
        *(xd->ptr + i) = (int *) calloc(xd->width, sizeof(int));
        if (*(xd->ptr + i) == NULL) {
            for (int k = 0; k < i; ++k)
                free(*(xd->ptr + k));
            free((xd->ptr));
            free(xd);
            return NULL;
        }
    }

    int p = xd->height - 1;
    for (int i = 0; i < xd->height; ++i) {
        for (int k = 0; k < xd->width; ++k) {
            *(*(xd->ptr + i) + k) = (*(*(m1->ptr + p) + k));
        }
        p--;
    }

    return xd;
}

struct image_t *image_flip_vertical(const struct image_t *m1) {
    if (m1 == NULL)
        return NULL;

    if (m1->height <= 0 || m1->width <= 0 || m1->ptr == NULL)
        return NULL;

    struct image_t *xd = (struct image_t *) calloc(1, sizeof(struct image_t));
    if (xd == NULL)
        return NULL;
    xd->height = m1->height;
    xd->width = m1->width;
    strcpy(xd->type, m1->type);


    xd->ptr = (int **) calloc(xd->height, sizeof(int *));
    if (xd->ptr == NULL) {
        free(xd);
        return NULL;
    }

    for (int i = 0; i < m1->height; ++i) {
        *(xd->ptr + i) = (int *) calloc(xd->width, sizeof(int));
        if (*(xd->ptr + i) == NULL) {
            for (int k = 0; k < i; ++k)
                free(*(xd->ptr + k));
            free((xd->ptr));
            free(xd);
            return NULL;
        }
    }

    int p;
    for (int i = 0; i < xd->height; ++i) {
        p = xd->width - 1;
        for (int k = 0; k < xd->width; ++k) {
            *(*(xd->ptr + i) + k) = (*(*(m1->ptr + i) + p));
            p--;
        }
    }

    return xd;
}

struct image_t *image_negate(const struct image_t *m1) {
    if (m1 == NULL)
        return NULL;

    if (m1->height <= 0 || m1->width <= 0 || m1->ptr == NULL)
        return NULL;

    struct image_t *xd = (struct image_t *) calloc(1, sizeof(struct image_t));
    if (xd == NULL)
        return NULL;
    xd->height = m1->height;
    xd->width = m1->width;
    strcpy(xd->type, m1->type);


    xd->ptr = (int **) calloc(xd->height, sizeof(int *));
    if (xd->ptr == NULL) {
        free(xd);
        return NULL;
    }

    for (int i = 0; i < m1->height; ++i) {
        *(xd->ptr + i) = (int *) calloc(xd->width, sizeof(int));
        if (*(xd->ptr + i) == NULL) {
            for (int k = 0; k < i; ++k)
                free(*(xd->ptr + k));
            free((xd->ptr));
            free(xd);
            return NULL;
        }
    }


    for (int i = 0; i < xd->height; ++i) {
        for (int k = 0; k < xd->width; ++k) {
            *(*(xd->ptr + i) + k) = 255 - (*(*(m1->ptr + i) + k));
        }
    }

    return xd;
}

const int *image_get_pixel(const struct image_t *img, int x, int y) {
    if (img == NULL || img->height <= 0 || img->width <= 0 || img->ptr == NULL || strcmp(img->type, "P2") != 0||x<0||y<0||x>=img->width||y>=img->height) {
        return NULL;
    }
    return (*(img->ptr+y)+x);
}

int *image_set_pixel(struct image_t *img, int x, int y) {
    if (img == NULL || img->height <= 0 || img->width <= 0 || img->ptr == NULL || strcmp(img->type, "P2") != 0||x<0||y<0||x>=img->width||y>=img->height) {
        return NULL;
    }
    *(*(img->ptr+y)+x)=0;
    return (*(img->ptr+y)+x);
}

int image_draw_rectangle(struct image_t *img, const struct rectangle_t *rect, int value) {
    if(rect==NULL)
        return 1;
    if (img == NULL || img->height <= 0 || img->width <= 0 || img->ptr == NULL || strcmp(img->type, "P2") != 0||rect->p.x<0||rect->p.y<0||rect->p.x>img->width-rect->width||rect->p.y>img->height-rect->height||rect->width<=0||rect->height<=0||value<0||value>255) {
        return 1;
    }

    for(int k=rect->p.x;k<rect->p.x+rect->width;++k)
    {
        *(*(img->ptr+rect->p.y)+k)=value;
        *(*(img->ptr+rect->p.y+rect->height-1)+k)=value;
    }

    for(int i=rect->p.y;i<(rect->p.y)+rect->height-1;++i)
    {
        *(*(img->ptr+i)+rect->p.x)=value;
        *(*(img->ptr+i)+rect->p.x+rect->width-1)=value;
    }

return 0;
}
