#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[10][10];
    int i,k,mxp=1,t,o,sumak=0,sumaw=0;
    printf("Daj: ");
    for(i=0;i<10;i++)
    {
        for(k=0;k<10;k++)
        {
            t=scanf("%d",&tab[i][k]);
            if(t!=1)
            {
                printf("incorrect input");
                return 1;
            }
            if(tab[i][k]%2==0)
                mxp=tab[i][k];
        }
    }
    if(mxp==1)
    {
        printf("Nothing to show");
        return 0;
    }
    for(i=0;i<10;i++)
    {
        for(k=0;k<10;k++)
        {
            if((tab[i][k]%2==0)&&(mxp<tab[i][k]))
                mxp=tab[i][k];
        }
    }
    for(i=0;i<10;i++)
    {
        for(k=0;k<10;k++)
        {
            if(tab[i][k]==mxp)
            {
                for(o=0;o<10;o++)
                {
                    sumaw=sumaw+tab[i][o];
                    sumak=sumak+tab[o][k];
                }
                printf("%d %d %d\n",k,i,sumaw-sumak);
                sumaw=0;
                sumak=0;

            }
        }
    }
    return 0;
}
