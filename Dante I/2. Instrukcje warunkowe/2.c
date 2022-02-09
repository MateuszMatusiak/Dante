#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i1, i2, i3, i4, t;
    printf("Podaj numer w formacie (dd) ddd-dd-dd: ");
    t=scanf("(%2d) %3d-%2d-%2d",&i1,&i2,&i3,&i4);
    if(t!=4)
    {
        printf("Incorrect input");
        return 1;
    }
    else
    {
        printf("Numer kierunkowy: %02d\nNumer telefonu: %03d-%02d-%02d",i1,i2,i3,i4);
    }
    return 0;
}
