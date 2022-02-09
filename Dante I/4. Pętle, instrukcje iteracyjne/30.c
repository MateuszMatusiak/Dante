#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n,i,t;
    float x,suma=0;
    srand(time(NULL));
    printf("daj n: ");
    t=scanf("%d",&n);
    if((t!=1)||(n>10)||(n<=0))
    {
        printf("Improper input data");
        return 1;
    }
    for(i=0;i<n;i++)
    {
        x=(rand()%10)-5;
        printf("%.6f ",x);
        suma=suma+x;
    }
    printf("%.4f",suma);

    return 0;
}
