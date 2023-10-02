#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tested_declarations.h"
#include "rdebug.h"


int main()
{
    FILE *p;
    int x,n,t,i,nn,k,y,j,d;
    char q[10]="0";
    srand(time(NULL));
    printf("Daj: ");
    t=scanf("%d",&n);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(n<=0||n>1000)
    {
        printf("Incorrect input data");
        return 2;
    }
    nn=n/10;
    for(i=0;i<nn;i++)
    {
        d=0;
        y=i;
        do
        {
            d++;
            y=y/10;
        } while(y!=0);
        y=i;
        j=0;
        do
        {
        *(q+d-j-1)=(y%10)+'0';
        j++;
        y=y/10;
        } while(y!=0);
        *(q+j)='.';
        *(q+j+1)='t';
        *(q+j+2)='x';
        *(q+j+3)='t';
        p=fopen(q,"w");
        if(p==NULL)
        {
            printf("couldn't create file");
            return 5;
        }
        printf("%s\n",q);
        for(k=0;k<10;k++)
        {
            x=rand()%1001;
            fprintf(p, "%d\n",x);
        }
    fclose(p);
    }
    if(n%10!=0)
    {
       d=0;
        y=i;
        do
        {
            d++;
            y=y/10;
        } while(y!=0);
        y=i;
        j=0;
        do
        {
        *(q+d-j-1)=(y%10)+'0';
        j++;
        y=y/10;
        } while(y!=0);
        *(q+j)='.';
        *(q+j+1)='t';
        *(q+j+2)='x';
        *(q+j+3)='t';

        p=fopen(q,"w");
        if(p==NULL)
        {
            printf("couldn't create file");
            return 5;
        }
        printf("%s\n",q);
        for(k=0;k<n%10;k++)
        {
            x=rand()%1001;
            fprintf(p, "%d\n",x);
        }
    fclose(p);
    }
    return 0;
}



