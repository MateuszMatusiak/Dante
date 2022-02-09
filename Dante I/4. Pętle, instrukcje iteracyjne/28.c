#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x;
    srand(time(NULL));
    while(1)
    {
       x=((rand()%2000)-1000);
       if((x>=100)&&(x<=200))
       {
           break;
       }
       printf("%d\n",x);
    }

    return 0;
}
