#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "tested_declarations.h"
#include "rdebug.h"
//44
struct point_t
{
    int x;
    int y;
};
struct point_t* set(struct point_t* p, int x, int y)
{
    if(p!=NULL)
    {
        p->x=x;
        p->y=y;
        return p;
    }
    return NULL;
}
void show(const struct point_t* p)
{
    if(p!=NULL)
    {
        printf("x= %d ",p->x);
        printf("y= %d\n",p->y);
    }
}

int save_point_t(const char *filename, const struct point_t* p)
{
    if(p==NULL)
    {
        return 1;
    }
    if(filename==NULL)
    {
        return 1;
    }
    FILE *f;
    int i=0,t;
    while(*(filename+i)!='\0')
        i++;
    f=fopen(filename,"w");
    if(f==NULL)
    {
        return 2;
    }
    t=fprintf(f,"x= %d ",p->x);
    if(t<0)
    {
        fclose(f);
        return 3;
    }
    t=fprintf(f,"y= %d\n",p->y);
    if(t<0)
    {
        fclose(f);
        return 3;
    }
    fclose(f);
    return 0;
}
int load_point_t(const char *filename, struct point_t* p)
{
    if(p==NULL)
    {
        return 1;
    }
    if(filename==NULL)
    {
        return 1;
    }
    FILE *f;
    char c;
    int i=0,t,x,y;
    while(*(filename+i)!='\0')
        i++;
    f=fopen(filename,"r");
    if(f==NULL)
    {
        return 2;
    }
    c=fgetc(f);
    while(!(c>='0'&&c<='9'||c=='-'))
    {
        c=fgetc(f);
        if(c==EOF)
        {
            fclose(f);
            return 3;
        }
    }
    fseek(f, -1,SEEK_CUR);
    t=fscanf(f,"%d",&x);
    if(t<0)
    {
        fclose(f);
        return 3;
    }
    c=fgetc(f);
    if(c==EOF)
    {
        fclose(f);
        return 3;
    }
    while(!(c>='0'&&c<='9'||c=='-'))
    {
        c=fgetc(f);
        if(c==EOF)
        {
            fclose(f);
            return 3;
        }
    }
    fseek(f, -1,SEEK_CUR);
    t=fscanf(f,"%d",&y);
    if(t<0)
    {
        fclose(f);
        return 3;
    }

    p->x=x;
    p->y=y;
    fclose(f);
    if((*(filename+i-4)=='.'&&*(filename+i-3)=='b'&&*(filename+i-2)=='i'&&*(filename+i-1)=='n')&&(t==0))
    {
        return 3;
    }
    return 0;
}
int save_point_b(const char *filename, const struct point_t* p)
{
    if(p==NULL)
    {
        return 1;
    }
    if(filename==NULL)
    {
        return 1;
    }
    FILE *f;
    int i=0,t;
    while(*(filename+i)!='\0')
        i++;
    f=fopen(filename,"wb");
    if(f==NULL)
    {
        return 2;
    }
    t=fwrite(&(p->x),sizeof(int),1,f);
    if(t<0)
    {
        fclose(f);
        return 3;
    }
    t=fwrite(&(p->y),sizeof(int),1,f);
    if(t<0)
    {
        fclose(f);
        return 3;
    }
    fclose(f);
    return 0;
}
int load_point_b(const char *filename, struct point_t* p)
{
    if(p==NULL)
    {
        return 1;
    }
    if(filename==NULL)
    {
        return 1;
    }
    FILE *f;
    int i=0,t,x,y;
    while(*(filename+i)!='\0')
        i++;
    f=fopen(filename,"rb");
    if(f==NULL)
    {
        return 2;
    }

    t=fread(&x,sizeof(int),1,f);
    if(t<0)
    {
        fclose(f);
        return 3;
    }
    t=fread(&y,sizeof(int),1,f);
    if(t<=0)
    {
        fclose(f);
        return 3;
    }
    p->x=x;
    p->y=y;
    fclose(f);

    return 0;
}

int main()
{

    srand(time(NULL));
    struct point_t p1,p2;
    int i=0,t;
    char filename[31];
    char c;
    p1.x=rand()%10;
    p1.y=rand()%10;
    show(&p1);
    printf("Daj: ");
    scanf("%30[^\n]",filename);
    while(*(filename+i)!='\0')
        i++;
    if((*(filename+i-4)=='.'&&*(filename+i-3)=='b'&&*(filename+i-2)=='i'&&*(filename+i-1)=='n'))
    {
        t=save_point_b(filename,&p1);
        if(t==2)
        {
            printf("Couldn't create file");
            return 5;
        }
        if(t==3)
        {
            printf("Incorrect input");
            return 1;
        }
        printf("File saved\n");
    }
    else if((*(filename+i-4)=='.'&&*(filename+i-3)=='t'&&*(filename+i-2)=='x'&&*(filename+i-1)=='t'))
    {
        t=save_point_t(filename,&p1);
        if(t==2)
        {
            printf("Couldn't create file");
            return 5;
        }
        if(t==3)
        {
            printf("Incorrect input");
            return 1;
        }
        printf("File saved\n");
    }
    else
    {
        printf("Unsupported file format");
        return 7;
    }
    while (getchar () != '\n' );
    printf("Chcesz?\n");
    t=scanf("%c",&c);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(c!='y'&&c!='Y'&&c!='n'&&c!='N')
    {
        printf("Incorrect input");
        return 1;
    }
    if(c=='y'||c=='Y')
    {
        if((*(filename+i-4)=='.'&&*(filename+i-3)=='b'&&*(filename+i-2)=='i'&&*(filename+i-1)=='n'))
        {
            t=load_point_b(filename,&p2);
            if(t==2)
            {
                printf("Couldn't open file");
                return 4;
            }
            if(t==3)
            {
                printf("File corrupted");
                return 6;
            }

            printf("x= %d ",p2.x);
            printf("y= %d ",p2.y);
        }
        else if((*(filename+i-4)=='.'&&*(filename+i-3)=='t'&&*(filename+i-2)=='x'&&*(filename+i-1)=='t'))
        {
            t=load_point_t(filename,&p2);
            if(t==2)
            {
                printf("Couldn't open file");
                return 4;
            }
            if(t==3)
            {
                printf("File corrupted");
                return 6;
            }

            printf("x= %d ",p2.x);
            printf("y= %d ",p2.y);
        }
        else
        {
            printf("Unsupported file format");
            return 7;
        }
    }
    return 0;
}


