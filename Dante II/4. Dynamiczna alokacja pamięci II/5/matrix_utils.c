#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"


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


struct matrix_t* matrix_create_struct(int width, int height)
{
    if(width<=0||height<=0)
        return NULL;
    struct matrix_t *m=(struct matrix_t*)malloc(sizeof(struct matrix_t));
    if(m==NULL)
    {
        return NULL;
    }
    int t=matrix_create(m,width,height);
    if(t!=0)
    {
        free(m);
        return NULL;
    }
    return m;
}

void matrix_destroy_struct(struct matrix_t **m)
{
    if(m!=NULL)
    {
        matrix_destroy(*m);
        free(*m);
    }
    *m=NULL;
}

struct matrix_t* matrix_transpose(const struct matrix_t *m)
{
    if(m==NULL||m->ptr==NULL||m->width<=0||m->height<=0)
        return NULL;
    struct matrix_t *p=matrix_create_struct(m->height,m->width);
    if(p==NULL)
    {
        return NULL;
    }
    for (int i = 0; i < m->height; ++i) {
        for (int k = 0; k < m->width; ++k) {
            *(*(p->ptr+k)+i)=*(*(m->ptr+i)+k);
        }
    }
    return p;
}

int matrix_save_b(const struct matrix_t *m, const char *filename)
{
    if(m==NULL||m->ptr==NULL||m->width<=0||m->height<=0||filename==NULL)
        return 1;
    FILE *f;
    int t;
    f=fopen(filename,"wb");
    if(f==NULL)
        return 2;
    t=fwrite(&m->width,sizeof(int),1,f);
    if(t!=1)
    {
        fclose(f);
        return 3;
    }
    t=fwrite(&m->height,sizeof(int),1,f);
    if(t!=1)
    {
        fclose(f);
        return 3;
    }
    for (int i = 0; i < m->height; ++i) {
        for (int k = 0; k < m->width; ++k) {
            t=fwrite((*(m->ptr+i)+k),sizeof(int),1,f);
            if(t!=1)
            {
                fclose(f);
                return 3;
            }
        }
    }
    fclose(f);
    return 0;

}
int matrix_save_t(const struct matrix_t *m, const char *filename)
{
    if(m==NULL||m->ptr==NULL||m->width<=0||m->height<=0||filename==NULL)
        return 1;
    FILE *f;
    int t;
    f=fopen(filename,"w");
    if(f==NULL)
        return 2;
    t=fprintf(f,"%d %d\n",m->width,m->height);
    if(t<=0)
    {
        fclose(f);
        return 3;
    }
    for (int i = 0; i < m->height; ++i) {
        for (int k = 0; k < m->width; ++k) {
            t=fprintf(f,"%d ",*(*(m->ptr+i)+k));
            if(t<=0)
            {
                fclose(f);
                return 3;
            }
        }
        fprintf(f,"\n");
    }
    fclose(f);
    return 0;
}



