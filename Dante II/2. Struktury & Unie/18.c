#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct point_t
{
    int x;
    int y;
};

struct circle_t
{
    struct point_t c;
    float r;
};


struct rectangle_t
{
    struct point_t p;
    int width;
    int height;
};

struct triangle_t
{
    struct point_t p1;
    struct point_t p2;
    struct point_t p3;
};

enum figure_types
{
    TRIANGLE = 1,
    RECTANGLE,
    CIRCLE
};

struct figure_t
{
    union
    {
        struct rectangle_t rect;
        struct triangle_t triangle;
        struct circle_t circ;
    };
    enum figure_types type;
};
int eqp(struct point_t p1, struct point_t p2)
{
    if(p1.x==p2.x&&p1.y==p2.y)
        return 1;
    return 0;
}

float area_triangle(const struct triangle_t *t)
{
    if(t==NULL)
        return -1;
    if(eqp(t->p1,t->p2)==1||eqp(t->p2,t->p3)==1||eqp(t->p1,t->p3)==1)
        return -1;
    float p,a,b,c,x;
    a=sqrt(pow((t->p1.x-t->p2.x),2)+pow((t->p1.y-t->p2.y),2));
    b=sqrt(pow((t->p2.x-t->p3.x),2)+pow((t->p2.y-t->p3.y),2));
    c=sqrt(pow((t->p3.x-t->p1.x),2)+pow((t->p3.y-t->p1.y),2));
    p=(a+b+c)/2.0;
    x=sqrt(p*(p-a)*(p-b)*(p-c));
    if(x<=0)
        return -1;
    return x;
}
float area_rectangle(const struct rectangle_t *r)
{
    if(r==NULL)
        return -1;
    float a,b,x;
    a=r->height;
    b=r->width;
    x=a*b;
    if(x<=0||a<0||b<0)
        return -1;
    return x;
}
float area_circle(const struct circle_t *c)
{
    if(c==NULL||c->r<=0)
        return -1;
    float r,x;
    r=c->r;
    x=M_PI*r*r;
    if(x<=0)
        return -1;
    return x;
}
float area_figure(const struct figure_t *f)
{
    if(f==NULL)
        return -1;
    float x;
    if(f->type==TRIANGLE)
    {
        x=area_triangle(&f->triangle);
    }
    else if(f->type==RECTANGLE)
    {
        x=area_rectangle(&f->rect);
    }
    else if(f->type==CIRCLE)
    {
        x=area_circle(&f->circ);
    }
    else
        return -1;
    if(x<=0)
        return -1;
    return x;
}

void display_rectangle(const struct rectangle_t *rect)
{
    if(rect!=NULL)
    {
        printf("Rectangle (%d, %d), width = %d, height = %d",rect->p.x, rect->p.y, rect->width, rect->height);
    }
}
void display_triangle(const struct triangle_t *t)
{
    if(t!=NULL)
    {
        printf("Triangle p1(%d, %d), p2(%d, %d), p3(%d, %d)",t->p1.x, t->p1.y, t->p2.x, t->p2.y, t->p3.x, t->p3.y);
    }
}
void display_circle(const struct circle_t *circ)
{
    printf("Circle (%d, %d), radius = %f",circ->c.x, circ->c.y, circ->r);
}
void display_figure(struct figure_t *f)
{
    if(f!=NULL)
    {
        if(f->type==TRIANGLE)
        {
            display_triangle(&f->triangle);
        }
        if(f->type==RECTANGLE)
        {
            display_rectangle(&f->rect);
        }
        if(f->type==CIRCLE)
        {
            display_circle(&f->circ);
        }
    }
}
int sort_by_area(struct figure_t **figures, int size)
{
    if(figures==NULL||size<=0)
        return 1;
    int i,k;
    float x1,x2;
    struct figure_t *p;
    for(i=0; i<size; i++)
    {
        if(*(figures+i)==NULL)
            return 1;
    }
    for(i=0; i<size-1; i++)
    {
        for(k=0; k<size-i-1; k++)
        {
            x1=area_figure(*(figures+k));
            x2=area_figure(*(figures+k+1));
            if(x1==-1||x2==-1)
                return 1;
            if(x1<x2)
            {
                p=*(figures+k);
                *(figures+k)=*(figures+k+1);
                *(figures+k+1)=p;
            }
        }
    }
    return 0;
}
int main()
{
    struct figure_t *f[50];
    struct figure_t fw[50];
    struct figure_t f1;
    int t,w,s=0;
    while(s<50)
    {
        printf("Daj: ");
        t=scanf("%d",&w);
        if(t!=1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(w==1)
        {
            f1.type=1;
            printf("Daj: ");
            t=scanf("%d %d %d %d %d %d", &f1.triangle.p1.x, &f1.triangle.p1.y, &f1.triangle.p2.x, &f1.triangle.p2.y, &f1.triangle.p3.x, &f1.triangle.p3.y);
            if(t!=6)
            {
                printf("Incorrect input");
                return 1;
            }
        while(getchar()!='\n');

        }
        else if(w==2)
        {
            f1.type=2;
            printf("Daj: ");
            t=scanf("%d %d %d %d", &f1.rect.p.x, &f1.rect.p.y, &f1.rect.width, &f1.rect.height);
            if(t!=4)
            {
                printf("Incorrect input");
                return 1;
            }
            while(getchar()!='\n');

        }
        else if(w==3)
        {
            f1.type=3;
            printf("Daj: ");
            t=scanf("%d %d %f", &f1.circ.c.x, &f1.circ.c.y, &f1.circ.r);
            if(t!=3)
            {
                printf("Incorrect input");
                return 1;
            }
            while(getchar()!='\n');

        }
        else if(w==0)
        {
            break;
        }
        else
        {
            printf("Incorrect input data");
            return 2;
        }
        *(fw+s)=f1;
        *(f+s)=(fw+s);
        s++;
    }

    t=sort_by_area(f,s);
    {
        if(t==1)
        {
            printf("Incorrect input data");
            return 2;
        }
    }
    for(int i=0;i<s;i++)
    {
        display_figure(*(f+i));
        printf("\n");
    }
        return 0;
}

