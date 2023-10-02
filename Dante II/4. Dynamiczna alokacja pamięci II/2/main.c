#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"


int **create_array_2d(int width, int height)
{
    if(width<=0||height<=0)
    {
        return NULL;
    }
    int **tab;
    tab=(malloc(height*sizeof(int*)));
    if(tab==NULL)
    {
        return NULL;
    }
    for(int i=0; i<height; i++)
    {
        *(tab+i)=(malloc(width*sizeof(int)));
        if(*(tab+i)==NULL)
        {
            for(int k=0; k<i; k++)
            {
                free(*(tab+k));
            }
            free(tab);
            return NULL;
        }
    }
    return tab;
}
void display_array_2d(int **ptr, int width, int height)
{
    if(ptr!=NULL&&width>0&&height>0)
    {
        for(int i=0; i<height; i++)
        {
            if(*(ptr+i)==NULL)
            {
                return;
            }
        }
        for(int i=0; i<height; i++)
        {
            for(int k=0; k<width; k++)
            {
                printf("%d ",*(*(ptr+i)+k));
            }
            printf("\n");
        }
    }
}
void destroy_array_2d(int **ptr, int height)
{
    if(ptr!=NULL||height<=0)
    {
        for(int i=0; i<height; i++)
        {
            if(*(ptr+i)!=NULL)
            {
                free(*(ptr+i));
            }
        }
        free(ptr);
    }
}





int main()
{
    int t,x,y,g,i,k;
    int **tab;
    printf("Daj: ");
    t=scanf("%d %d",&x,&y);
    if(t!=2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(x<=0||y<=0)
    {
        printf("Incorrect input data");
        return 2;
    }
    tab=create_array_2d(x,y);
    if(tab==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Daj: ");
    while (getchar () != '\n' );
    for(i=0;i<y;i++)
    {
        for(k=0;k<x;k++)
        {
            t=scanf("%d",&g);
            if(t!=1)
            {
                printf("Incorrect input");
                destroy_array_2d(tab,y);
                return 1;
            }
            *(*(tab+i)+k)=g;

        }
    }
    display_array_2d(tab,x,y);
    destroy_array_2d(tab,y);
    return 0;
}

