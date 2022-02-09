#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,i=1;
    printf("Daj: ");
    t=scanf("%d",&n);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    while(n%i==0)
    {
        n++;
        i++;
    }
    printf("%d",i-1);
    return 0;
}
