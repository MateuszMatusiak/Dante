#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    for(i=0;i<=100;i++)
    {
        if(((i>=10)&&(i<15))||((i>=40)&&(i<=60))||((i>70)&&(i<80)))
        {
            printf("*");
        }
        printf("%d\n",i);
    }
    return 0;
}
