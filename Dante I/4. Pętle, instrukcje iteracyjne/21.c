#include <stdio.h>
#include <stdlib.h>

int main()
{
    float mx,mn,i;
    int t;
    printf("Daj min: ");
    t=scanf("%f",&mn);
    if(t!=1)
    {
        printf("incorrect input");
        return 1;
    }
    printf("Daj max: ");
    t=scanf("%f",&mx);
    if(t!=1)
    {
        printf("incorrect input");
        return 1;
    }
    if(mx<mn)
    {
        printf("incorrect range");
        return 2;
    }
    for(i=mn;i<=mx;i=i+0.25)
        printf("%f ",i);
    return 0;
}
