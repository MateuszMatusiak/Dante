#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,mx,mn,i;
    printf("Daj min: ");
    t=scanf("%d",&mn);
    if(t!=1)
    {
        printf("incorrect input");
        return 1;
    }
    printf("Daj max: ");
    t=scanf("%d",&mx);
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
    for(i=mn;i<=mx;i++)
        printf("%d ",i);
    return 0;
}
