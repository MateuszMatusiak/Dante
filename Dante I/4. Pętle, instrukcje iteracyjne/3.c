#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,t;
    float x;
    printf("ile pln: ");
    t=scanf("%f",&x);
    if((t!=1)||(x<0))
    {
        printf("incorrect input");
        return 1;
    }
    printf("ile mies: ");
    t=scanf("%d",&n);
    if((t!=1)||(n<0))
    {
        printf("incorrect input");
        return 1;
    }
    for (i=0;i<n;i++)
    {
     x=x*1.01;
    }
    printf("%.2f",x);

    return 0;
}
