#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    unsigned long long x=1;
    for(x=1,i=1;x<1000000000000000001;printf("%llu ",x),i++)
        if(i==1)
            continue;
        else
            x=x*10;
    return 0;
}
