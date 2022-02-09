#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tab[26];
    int i;
    for(i=0;i<=25;i++)
    {
        tab[i]=i+65;
    }
    for(i=0;i<=25;i++)
    printf("%d %c %c\n",tab[i], tab[i], tab[i]+32);
    return 0;
    }
