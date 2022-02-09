#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,l=1;
    float x;
    float mx,mn,sr,suma;
    printf("podaj liczbe: ");
    t=scanf("%f",&x);
    if((t!=1)||(x==-1))
    {
        printf("Incorrect input");
        return 1;

    }
    mx=x;
    mn=x;
    suma=x;
    while(1)
    {
        t=scanf("%f",&x);
        if(t!=1)
        {
            printf("Incorrect input");
            return 1;

        }
        if(x==-1)
        break;
        if(mx<x)
        {
            mx=x;
        }
        if(mn>x)
        {
            mn=x;
        }
        suma=suma+x;
        l++;
    }
    sr=suma/l;
    printf("%.2f\n",mn);
    printf("%.2f\n",mx);
    printf("%.2f\n",sr);

    return 0;
}
