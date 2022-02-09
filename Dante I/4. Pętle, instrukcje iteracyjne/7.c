#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    double x=0.1;
    for(i=1;i<=20;i++)
    printf("10 do potegi% 3d = % 21.0f\n",i-1,x=x*10);
    return 0;
}
