#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i1,i2,i3;
    printf("podaj date ");
    scanf("%2d-%2d-%4d",&i1,&i2,&i3);
    printf("%-10s%02d\n%-10s%02d\n%-8s%04d","Day:",i1,"Month:",i2,"Year:",i3);
    return 0;
}
