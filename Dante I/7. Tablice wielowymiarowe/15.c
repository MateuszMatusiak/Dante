#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int ii=5;
    const int kk=5;
    int tab[5][5];
    int t,i,k,s1=0,s2=0;
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
        s1=s1+tab[i][i];
    }
    for(i=0;i<ii;i++)
    {
        s2=s2+tab[i][4-i];
    }
    printf("%d %d",s1,s2);
    return 0;
}
