#include <stdio.h>
#include <stdlib.h>

int main()
{
    float tab[10];
    int i,t;
    printf("daj: ");
    for(i=0;i<10;i=i+2)
    {
        t=scanf("%f %f",&tab[i],&tab[i+1]);
        if(t!=2)
        {
            printf("Input data type error");
            return 1;
        }

    }
    for(i=0;i<10;i++)
        printf("%d %f\n",i,tab[i]);
    return 0;
}
