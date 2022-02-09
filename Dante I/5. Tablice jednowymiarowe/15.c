#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[1000];
    float tab2[1000];
    int i,t,l=0, x;
    printf("daj: ");
    for(i=0; i<1000; i++)
    {
        t=scanf("%d",&x);
        if(t!=1)
        {
            printf("incorrect input");
            return 1;
        }
        if(x==0)
            break;
        tab[i]=x;
        l++;
    }
    if(l<2)
    {
        printf("not enough data available");
        return 2;
    }

    for(i=1;i<l;i++)
    {
        tab2[i-1]=(tab[i-1]+tab[i])/2.0;
    }


  for(i=0; i<l-1; i++)
        printf("%.2f ",tab2[i]);

    return 0;
}
