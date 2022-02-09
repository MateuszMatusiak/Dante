#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=5,k=2;
    float l = (float)i/(float)k;
    printf("%i %i",i, k);
    printf("\n%i",i*k);
    printf("\n%.2f",l);
    printf("\n%i",i+k);
    printf("\n%i",i-k);
    return 0;
}
