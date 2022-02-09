#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int ii=5;
    const int kk=5;
    int tab[5][5];
    int i,k,t,mxw,mxk;
    printf("Daj:\n");
    for(i=0; i<ii; i++)
    {
        for(k=0; k<kk; k++)
        {
            t=scanf("%d",&tab[i][k]);
            if(t!=1)
            {
                printf("incorrect input");
                return 1;
            }
        }

    }

    for(i=0;i<ii;i++)
    {
        mxw=tab[i][0];
        for(k=0;k<kk;k++)
        {
            if(mxw<tab[i][k])
            {
                mxw=tab[i][k];
            }
        }
        printf("%d ",mxw);
    }
    for(i=0;i<ii;i++)
    {
        mxk=tab[0][i];
        for(k=0;k<kk;k++)
        {
            if(mxk<tab[k][i])
            {
                mxk=tab[k][i];
            }
        }
        printf("%d ",mxk);
    }
    return 0;
}
