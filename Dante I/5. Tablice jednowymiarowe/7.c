#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[10];
    int i,t,k,n;
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
    for(i=0; i<10; i++)
    {
        if((tab[i]!=0)&&(tab[i]!=1)&&(tab[i]>0))
        {
            n=tab[i]/2+1;
            for(k=2; k<n; k++)
            {
                if(tab[i]%k==0)
                {
                    printf("%d composite\n",tab[i]);
                    break;
                }
            }
            if(k==n)
                printf("%d prime\n",tab[i]);
        }
        else
        {
            printf("%d other\n",tab[i]);
        }
    }
    return 0;
}
