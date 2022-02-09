#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char imie[11];
    i=0;
    printf("daj: ");
    scanf("%10[^\n]",imie);
    while(imie[i]!='\0')
    {
        i++;
    }
    if(i>0)
    if(imie[i-1]=='a')
    {
        printf("Imie zenskie");

    }
    else
        printf("Imie meskie");
    return 0;
}
