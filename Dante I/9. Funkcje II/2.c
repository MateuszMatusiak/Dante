#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


int find_char(const char tab[], char c)
{
    int i=0;
    while(tab[i]!='\0')
    {
        if(tab[i]==c)
            return i;
        i++;
    }
    return -1;
}

int rfind_char(const char tab[], char c)
{
    int i=0,k;
    while(tab[i]!='\0')
    {
        i++;
    }
    for(k=i-1; k>=0; k--)
    {
        if(tab[k]==c)
        {
            return k;
        }
    }
    return -1;
}

int main()
{
    char tab[1001];
    char c;
    printf("Daj: ");
    scanf("%1000[^\n]",tab);
    while(getchar() != '\n');

    printf("Daj: ");
    scanf(" %c",&c);
    printf("%d\n%d",find_char(tab,c),rfind_char(tab,c));

    return 0;
}

