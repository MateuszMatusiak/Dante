#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[10];
    int i,t;
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
        if(tab[i]%2==0)
            printf("%d even\n",tab[i]);
        else
            printf("%d odd\n",tab[i]);
    }
    return 0;
}
