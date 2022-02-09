#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[1000];
    int i,l=0,x,t,suma=0,sumaw=0,sumam=0;
    float sr;
    printf("daj: ");
    for(i=0;i<1000;i++)
    {
        t=scanf("%d",&x);
        if(t!=1)
        {
            printf("incorrect input");
            return 1;
        }
        if(x==0)
            break;
        tab[l]=x;
        l++;
    }
    if(l==0)
    {
        printf("Brak danych");
        return 0;
    }

    for(i=0;i<l;i++)
    {
      suma=suma+tab[i];
    }
    sr=(float)suma/l;
    printf("%.2f\n",sr);
    for(i=0;i<l;i++)
    {
        if(tab[i]>sr)
        {
            sumaw=sumaw+tab[i];
        }
        if(tab[i]<sr)
        {
            sumam=sumam+tab[i];
        }
    }
    printf("%d\n%d",sumaw,sumam);
    return 0;
}
