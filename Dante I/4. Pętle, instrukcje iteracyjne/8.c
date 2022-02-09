#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,k;
    for(i=0; i<11; i++)
    {
        for(k=0; k<11; k++)
        {
            printf("%d * %d\t= %d\n",i,k,i*k);
        }
        printf("\n");
    }
    return 0;
}
