#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[11];
    int i,x,t;
    printf("daj: ");
    for(i=0;i<11;i++)
        tab[i]=0;
    do
    {
        t=scanf("%d",&x);
        if(t!=1)
        {
            printf("Incorrect input");
            return 1;
        }
        if((x>=0)&&(x<=10))
        {
            tab[x]++;
        }
    }
    while (x!=-1);
    for(i=0;i<11;i++)
        printf("%d - %d\n",i,tab[i]);
    return 0;
}
