#include <stdio.h>
#include <stdlib.h>
#include "dante.h"
#include "tested_declarations.h"
#include "rdebug.h"

int create_array_2d_2(int ***ptr, int width, int height)
{
    if(ptr==NULL||width<=0||height<=0)
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
    *ptr=tab;
    return 0;
}
void destroy_array_2d(int ***ptr, int height)
{
if(ptr!=NULL&&height>0)
{
    int **tab=*ptr;
    for(int k=0;k<height;++k)
    {
        if(*(tab+k)!=NULL)
            free(*(tab+k));
    }
    free(tab);
    *ptr=NULL;
    ptr=NULL;
}
}
void display_array_2d(int **ptr, int width, int height)
{
if(ptr!=NULL&&width>0&&height>0)
{
    for(int i=0;i<height;++i)
    {
        if(*(ptr+i)==NULL)
            return;
    }
    for(int i=0;i<height;++i)
    {
        for(int k=0;k<width;++k)
        {

                printf("%d ",*(*(ptr+i)+k));
        }
        printf("\n");
    }
}
}

int sum_row(int *ptr, int width)
{
if(ptr==NULL||width<=0)
    return -1;
int sum=0;

for(int i=0;i<width;++i)
{
    sum+=*(ptr+i);
}
return sum;
}


int sum_array_2d(int **ptr, int width, int height)
{
if(ptr==NULL||width<=0||height<=0)
{
    return -1;
}
int sum=0,x;
for(int i=0;i<height;++i)
{
    if(*(ptr+i)==NULL)
        return -1;
    x=sum_row(*(ptr+i),width);
    sum+=x;
}
return sum;
}





int main() {
    int t,w,h,x;
    int **tab;
    printf("Daj: ");
    t=scanf("%d %d",&w, &h);
    if(t!=2)
    {
    return r1();
    }
    if(w<=0||h<=0)
        return r2();

    t=create_array_2d_2(&tab,w,h);
    if(t!=0)
        return r8();
    pd();
    for (int i = 0; i < h; ++i) {
        for (int k = 0; k < w; ++k) {
        t=scanf("%d",&x);
        if(t!=1) {
            destroy_array_2d(&tab,h);
            return r1();
        }
        *(*(tab+i)+k)=x;
        }
    }
    display_array_2d(tab,w,h);
    for (int i = 0; i < h; ++i) {
        printf("%d\n", sum_row(*(tab+i),w));
    }
    printf("%d",sum_array_2d(tab,w,h));
    destroy_array_2d(&tab,h);
    return 0;
}

