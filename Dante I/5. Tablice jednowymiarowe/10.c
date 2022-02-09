#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[100];
    int t=0,i=0,x=0,l=0,mx=0,mn=0,suma=0;
    float sr;
    printf("daj: ");
    for(i=0;i<100;i++)
    {
        t=scanf("%d",&x);
        if(t!=1)
        {
            printf("Incorrect input");
            return 1;
        }
        if(x==-1)
            break;
        tab[i]=x;
        l++;
    }
    suma=tab[0];
    mx=tab[0];
    mn=tab[0];
    for(i=1;i<l;i++)
    {
        suma=suma+tab[i];
        if(mx<tab[i])
            mx=tab[i];
        if(mn>tab[i])
            mn=tab[i];
    }

    sr=(float)suma/l;
    printf("%d\n",l);
    printf("%d\n",mn);
    printf("%d\n",mx);
    printf("%f\n",sr);
    printf("%d\n",suma);
    for(i=0;i<l;i++)
    {
        if(tab[i]==mn)
            printf("%d ",i);
    }
    printf("\n");
    for(i=0;i<l;i++)
    {
        if(tab[i]==mx)
            printf("%d ",i);
    }
    return 0;
}
