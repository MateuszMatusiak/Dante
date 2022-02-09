#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,n;
    unsigned long long s=1;
    printf("podaj silnie: ");
    t=scanf("%d",&n);
    if((t!=1)||(n>20)||(n<0))
    {
        printf("Incorrect input");
        return 1;
    }
    for(i=1;i<=n;i++)
    {
        s=s*i;
    }
    printf("%llu",s);
    return 0;
}
