#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x,i,z;
    srand(time(NULL));
    x=rand()%101;
    for(i=0;i<10;i++)
    {
        printf("daj: ");
        scanf("%d",&z);
        if(z==x)
        {
            printf("wygrales");
            return 0;
        }
        if(z<x)
            printf("za malo\n");
        if(z>x)
            printf("za duzo\n");
    }
    printf("przegrales");
    return 0;
}
