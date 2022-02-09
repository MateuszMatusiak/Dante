#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int ii=5;
    const int kk=5;
    int tab[5][5];
    int t,i,k,s=0;
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
    s=s+tab[i][0];
    s=s+tab[0][i];
    s=s+tab[i][4];
    s=s+tab[4][i];
    }
    s=s-tab[0][0]-tab[4][4]-tab[0][4]-tab[4][0];
    printf("%d",s);
    return 0;
}
