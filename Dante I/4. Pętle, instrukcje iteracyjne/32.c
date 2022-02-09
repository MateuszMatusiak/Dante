#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int i,l=0,x;
    srand(time(NULL));
    for(i=0;i<100;i++)
    {
        x=(rand()%2001)-1000;
        if(fabs(x)<=100)
        {
            l++;
        }
    }
    printf("%d\n",l);
    return 0;
}
