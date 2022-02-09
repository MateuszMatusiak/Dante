#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[5][5];
    int t,k,i,x;
    printf("daj: ");
    for(i=0; i<5; i++)
    {
        for(k=0; k<5; k++)
            t=scanf("%d",&tab[i][k]);
        if(t!=1)
        {
            printf("incorrect input");
            return 1;
        }

    }


    for(i=0,k=4; i<5; i++,k--)
    {
        x=tab[i][i];
        tab[i][i]=tab[i][k];
        tab[i][k]=x;
    }
    for(i=0; i<5; i++)
    {
        for(k=0; k<5; k++)
            printf("%d\t",tab[i][k]);
        printf("\n");


    }



    return 0;
}
