#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i1,i2,i3,i4;
    printf("podaj numer ");
    scanf("%3d-%2d-%2d",&i1,&i2,&i3);
    printf("podaj kierunkowy ");
    scanf("%2d",&i4);
    printf("(%02d) %03d-%02d-%02d",i4,i1,i2,i3);
    return 0;
}
