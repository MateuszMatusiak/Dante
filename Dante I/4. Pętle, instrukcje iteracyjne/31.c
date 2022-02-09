#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n=1,s=0,x;
    int l=-1;
    x=1/(n*(n+1));
    while(x>=0.0001)
    {
    x=1/(n*(n+1));
    s=s+x;
    n++;
    l++;
    }
    printf("licz: %d suma: %.3f",l,s);
    return 0;
}
