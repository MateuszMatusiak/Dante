#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "format_type.h"
#include "tested_declarations.h"
#include "rdebug.h"

struct statistic_t
{
    int min;
    int max;
    float avg;
    float standard_deviation;
    int range;
};

int statistics(int **ptr, struct statistic_t **stats)
{
    if(stats==NULL||ptr==NULL)
        return 1;
    *stats=(struct statistic_t *)malloc(sizeof(struct statistic_t));
    if(*stats==NULL)
        return 2;
    int i=0,k=0,s=0;
    if(*ptr!=NULL)
    {
        (*stats)->min=**ptr;
        (*stats)->max=**ptr;
        (*stats)->avg=0;
        (*stats)->standard_deviation=0;
    }
    while(*(ptr+i)!=NULL)
    {
        k=0;
        while(*(*(ptr+i)+k)!=-1)
        {
            (*stats)->avg=(*stats)->avg+(*(*(ptr+i)+k));
            (*stats)->standard_deviation=(*stats)->standard_deviation+pow((*(*(ptr+i)+k)),2);
            if((*stats)->min>*(*(ptr+i)+k))
                (*stats)->min=*(*(ptr+i)+k);
            if((*stats)->max<*(*(ptr+i)+k))
                (*stats)->max=*(*(ptr+i)+k);
            k++;
            s++;
        }
        i++;
    }
    if(s==0)
    {
        free(*stats);
        return 3;
    }
    (*stats)->avg=((*stats)->avg)/s;
    (*stats)->standard_deviation=((*stats)->standard_deviation)/(float)s;
    (*stats)->standard_deviation=((*stats)->standard_deviation)-pow((*stats)->avg,2);
    (*stats)->standard_deviation=sqrt((*stats)->standard_deviation);
    (*stats)->range=(*stats)->max-(*stats)->min;
    return 0;
}
void display(int **ptr)
{
    if(ptr!=NULL)
    {
        int i=0,k=0;
        while(*(ptr+i)!=NULL)
        {
            k=0;
            while(1)
            {
                if(*(*(ptr+i)+k)==-1)
                    break;
                printf("%d ",*(*(ptr+i)+k));
                k++;
            }
            printf("\n");
            i++;
        }
    }
}
int save(const char *filename, int **ptr, enum save_format_t format)
{
    if((ptr==NULL)||(filename==NULL))
        return 1;
    int i=0,k=0;
    FILE *f;
    if(format==fmt_text)
    {
        f=fopen(filename, "w");
        if(f==NULL)
            return 2;
        i=0;
        while(*(ptr+i)!=NULL)
        {
            k=0;
            do
            {
                fprintf(f,"%d ",*(*(ptr+i)+k));

            }
            while((*(*(ptr+i)+k++))!=-1);
            fprintf(f,"\n");
            i++;
        }

    }
    else if(format==fmt_binary)
    {
        f=fopen(filename, "wb");
        if(f==NULL)
            return 2;
        i=0;
        while(*(ptr+i)!=NULL)
        {
            k=0;
            do
            {
                fwrite(*(ptr+i)+k,sizeof(int),1,f);

            }
            while(*(*(ptr+i)+k++)!=-1);
            i++;
        }
    }
    else
        return 1;

    fclose(f);
    return 0;
}
int main()
{
    int A[] = {10, 20, 30, 40, 50, 60, 70, -1};
    int B[] = {100, 200, 300, 400, 500, 600, 700, 800, -1};
    int C[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, -1};
    int* D[] = {A, B, C, NULL};
    struct statistic_t *p;
    char *n, *n1, *n2;
    int l,i,t;

    display(D);

    n=(char*)(malloc(40*sizeof(char)));
    if(n==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    scanf("%39[^\n]",n);
    l=strlen(n);
    *(n+l)='\0';
    n1=(char *)malloc(44*sizeof(char));
    if(n1==NULL)
    {
        printf("Failed to allocate memory");
        free(n);
        return 8;
    }
    n2=(char *)malloc(44*sizeof(char));
    if(n2==NULL)
    {
        printf("Failed to allocate memory");
        free(n);
        free(n1);
        return 8;
    }
    i=0;
    while(*(n+i)!='\0')
    {
        *(n1+i)=*(n+i);
        *(n2+i)=*(n+i);
        i++;
    }
    *(n1+i)='.';
    *(n1+i+1)='t';
    *(n1+i+2)='x';
    *(n1+i+3)='t';
    *(n1+i+4)='\0';
    *(n2+i)='.';
    *(n2+i+1)='b';
    *(n2+i+2)='i';
    *(n2+i+3)='n';
    *(n2+i+4)='\0';
    t=save(n1,D,fmt_text);
    if(t!=0)
    {
        printf("Couldn't create file\n");
    }
    else
    {
        printf("File saved\n");
    }
    t=save(n2,D,fmt_binary);
    if(t!=0)
    {
        printf("Couldn't create file\n");
    }
    else
    {
        printf("File saved\n");
    }
    t=statistics(D,&p);
    if(t!=0)
    {
        printf("Failed to allocate memory");
        free(n);
        free(n1);
        free(n2);
        return 8;
    }
    printf("%d\n", p->min);
    printf("%d\n", p->max);
    printf("%d\n", p->range);
    printf("%f\n", p->avg);
    printf("%f", p->standard_deviation);
    free(n);
    free(n1);
    free(n2);
    free(p);
    return 0;
}

