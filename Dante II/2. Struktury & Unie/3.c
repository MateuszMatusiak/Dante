#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"


struct point_t
{
    int x;
    int y;
};

int save_points_b(const char *filename, const struct point_t* p, unsigned int N)
{
    if(p==NULL)
    {
        return 1;
    }
    if(filename==NULL)
    {
        return 1;
    }
    if(N==0)
    {
        return 1;
    }
    int t;
    struct point_t q;
    FILE *f;
    f=fopen(filename,"wb");
    if(f==NULL)
    {
        return 2;
    }
    for(int i=0; i<(int)N; i++)
    {
        q=*(p+i);
        t=fwrite(&q,sizeof(struct point_t),1,f);
        if(t==0)
        {
            fclose(f);
            return 3;
        }
    }
    fclose(f);
    return 0;
}
struct point_t* read(struct point_t* p)
{
    if(p==NULL)
    {
        printf("Incorrect input");
        return NULL;
    }
    int x,y,t;
    t=scanf("%d %d",&x,&y);
    if(t!=2)
    {
        printf("Incorrect input");
        return NULL;
    }
    p->x=x;
    p->y=y;
    return p;
}
int main()
{
    struct point_t *tt,pt[100];
    char n[30];
    int i,t;
    printf("Daj: ");
    t=scanf("%d",&i);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(i<=0)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("Daj: ");
    for(int k=0; k<i; k++)
    {
        tt=read((pt+k));
        if(tt==NULL)
        {
            return 1;
        }
        if(k==99)
            break;
    }
    while (getchar () != '\n' );
    printf("Daj: ");
    scanf("%30[^\n]",n);
    if(i>100)
        t=save_points_b(n,pt,100);
    else
        t=save_points_b(n,pt,(unsigned int)i);
    if(t==1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(t==2)
    {
        printf("couldn't create file");
        return 5;
    }
    if(t==3)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("File saved");
    return 0;
}

