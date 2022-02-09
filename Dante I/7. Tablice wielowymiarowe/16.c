#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int ii=5;
    const int kk=5;
    int tab[5][5];
    int t,i,k,mx,s=0;
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
    s=0;
        for(k=0; k<kk; k++)
        {
            s=s+tab[k][0];

        }
            mx=s;
    for(i=1; i<ii; i++)
    {
        s=0;
        for(k=0; k<kk; k++)
        {
            s=s+tab[k][i];

        }
        if(mx<s)
            mx=s;
    }


    for(i=0; i<ii; i++)
    {
        s=0;
        for(k=0; k<kk; k++)
        {
            s=s+tab[k][i];

        }
        if(mx==s)
        {
            for(k=0; k<kk; k++)
            {
                printf("%d ",tab[k][i]);
            }
            printf("\n");
        }
    }
    return 0;
}
