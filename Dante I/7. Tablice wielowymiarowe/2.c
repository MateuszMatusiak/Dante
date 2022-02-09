#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double tab[201][2];
    int i,k;
    tab[0][0]=0;
    tab[0][1]=sin(tab[0][0]);
    for(i=1;i<201;i++)
    {
        tab[i][0]=(tab[i-1][0]+((M_PI)/100));
        tab[i][1]=sin(tab[i][0]);
    }
    for(i=0; i<201; i++)
    {
        for(k=0; k<2; k++)
            printf("%.4f\t",tab[i][k]);
        printf("\n");
    }
    return 0;
}
