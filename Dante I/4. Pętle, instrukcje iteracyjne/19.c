#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t, i, x;
    printf("Podaj: ");
    t=scanf("%d",&x);
    if(t!=1)
    {
        printf("incorrect input");
        return 1;
    }
    if(x==0)
    {
        printf("NO");
        return 0;
    }
    if((x==1)||(x<0))
    {
        printf("NO");
        return 0;
    }
    for(i=2; i<fabs(x/2)+1; i++)
    {
        if(x%i==0)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
