#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[15][15];
    int tab2[30];
    int tab3[15][15];
    int i,k,t,x;
    printf("daj: ");
    for(i=0;i<30;i++)
        tab2[i]=0;
    for(i=0; i<15; i++)
    {
        for(k=0; k<15; k++)
        {
            t=scanf("%d",&x);
            if(t!=1)
            {
                printf("Incorrect input");
                return 1;
            }
            if((x>=30)||(x<0))
            {
                printf("value out of range");
                return 2;
            }
            tab[i][k]=x;
        }
    }
    for(i=0;i<15;i++)
    {
        for(k=0;k<15;k++)
        {
            tab2[tab[i][k]]++;
        }
    }
    for(i=0;i<15;i++)
    {
        for(k=0;k<15;k++)
        {
         tab3[i][k]=tab2[tab[i][k]];
         printf("%d\t",tab3[i][k]);
        }
        printf("\n");
    }
    return 0;
}
