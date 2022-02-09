#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[11][11];
    int i,k;
    for(i=0; i<11; i++)
    {
        for(k=0; k<11; k++)
            tab[i][k]=i*k;

    }

    for(i=0; i<11; i++)
    {
        for(k=0; k<11; k++)
            printf("%d\t",tab[i][k]);
        printf("\n");
    }
    return 0;
}
