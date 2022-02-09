#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[5][10];
    int tab2[10][5];
    int i,k,t;
    printf("Daj: ");
    for(i=0; i<5; i++)
    {
        for(k=0; k<10; k++)
        {
            t=scanf("%d",&tab[i][k]);
            if(t!=1)
            {
                printf("incorrect input");
                return 1;
            }
        }
    }
    for(i=0; i<5; i++)
        for(k=0; k<10; k++)
            tab2[k][i]=tab[i][k];

    for(i=0; i<10; i++)
    {
        for(k=0; k<5; k++)
        {
            printf("%d ",tab2[i][k]);
        }
        printf("\n");
    }
    return 0;
}
