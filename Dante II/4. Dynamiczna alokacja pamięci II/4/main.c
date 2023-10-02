#include <stdio.h>
#include <stdlib.h>
#include "dante.h"
#include "tested_declarations.h"
#include "rdebug.h"

struct matrix_t{
    int **ptr;
    int width;
    int height;
};

int matrix_create(struct matrix_t *m, int width, int height)
{
    if(m==NULL||width<=0||height<=0)
    {
        return 1;
    }
    int** tab;
    int i,k;
    tab=(int**)calloc(height,sizeof(int*));
    if(tab==NULL)
        return 2;
    for(i=0; i<height;++i)
    {
        *(tab+i)=(int*)calloc(width,sizeof(int));
        if(*(tab+i)==NULL)
        {
            for(k=0;k<i;++k)
            {
                free(*(tab+k));
            }
            free(tab);
            return 2;
        }
    }
    m->ptr=tab;
    m->width=width;
    m->height=height;
    return 0;
}
void matrix_destroy(struct matrix_t *m)
{
    if(m!=NULL&&m->height>0)
    {

        int **tab=m->ptr;
        for(int k=0;k<m->height;++k)
        {
            if(*(tab+k)!=NULL)
                free(*(tab+k));
        }
        free(tab);
    }
}
int matrix_read(struct matrix_t *m)
{
if(m==NULL||m->height<=0||m->width<=0||m->ptr==NULL)
    return 1;
int h=m->height;
int w=m->width;
int t,x;
int** tab= m->ptr;
    for (int i = 0; i < h; ++i) {
        for (int k = 0; k < w; ++k) {
            t=scanf("%d",&x);
            if(t!=1) {
                matrix_destroy(m);
                return 2;
            }
            *(*(tab+i)+k)=x;
        }
    }
    return 0;
}
void matrix_display(const struct matrix_t *m)
{
    if(!(m==NULL||m->height<=0||m->width<=0||m->ptr==NULL))
    {

        for(int i=0;i<m->height;++i)
        {
            if(*(m->ptr+i)==NULL)
                return;
        }
        for(int i=0;i<m->height;++i)
        {
            for(int k=0;k<m->width;++k)
            {

                printf("%d ",*(*(m->ptr+i)+k));
            }
            printf("\n");
        }
    }
}


int main() {
    int t,w,h;
    struct matrix_t m;
    pd();
    t=scanf("%d %d",&w,&h);
    if(t!=2)
        return r1();
    if(w<=0||h<=0)
        return r2();
    t=matrix_create(&m,w,h);
    if(t!=0)
        return r8();
    pd();
    t=matrix_read(&m);
    if(t!=0) {
//        matrix_destroy(&m);
        return r1(); }
    matrix_display(&m);
    matrix_destroy(&m);
    return 0;
}

