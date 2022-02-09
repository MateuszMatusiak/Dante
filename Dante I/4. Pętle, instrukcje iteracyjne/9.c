#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=-10,b=-10;
    for(a=-10;a<=10;a++)
    {
        for(b=-10;b<=10;b++)
        {
            if(((a+b)*(a-b))==((a*a)+(b*b)))
            {
              printf("%d %d\n",a,b);
            }
        }
    }
    return 0;
}
