#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[10];
    int i,t,suma,mx,mn;
    float sr;
    printf("daj: ");
    for(i=0; i<10; i=i+2)
    {
        t=scanf("%d %d",&tab[i],&tab[i+1]);
        if(t!=2)
        {
            printf("Input data type error");
            return 1;
        }

    }
    mx=tab[0];
    mn=tab[0];
    suma=tab[0];
    for(i=1; i<10; i++)
    {
      if(tab[i]>mx)
            mx=tab[i];
      if(tab[i]<mn)
        mn=tab[i];
      suma=suma+tab[i];
    }
    sr=suma/10.0;
    printf("%.4f\n%d\n%d\n",sr,mx,mn);
    return 0;
}
