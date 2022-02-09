#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,x,suma=0;
    srand(time(NULL));
    for(i=0; i<100; i++)
    {
        x=((rand()%11)+10);
        suma=suma+x;
    }
    printf("%d",suma);
    return 0;
}
