#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[1001]={'\x0'};
    int l=0;
    printf("daj: ");
    scanf ("%1000[^\n]",x);
    while (x[l]!='\0')
        l++;
    printf("%d",l);
    return 0;
}
