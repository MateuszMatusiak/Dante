#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


int find_any(const char tab[], const char tab2[])
{
    int i=0,k=0;
    while(tab[i]!='\0')
    {
        k=0;
        while(tab2[k]!='\0')
        {
            if(tab[i]==tab2[k])
            {
                return i;
            }
            k++;
        }
        i++;
    }
    return -1;
}

int rfind_any(const char tab[], const char tab2[])
{
    int i=0,l1,l2,k;
    while(tab[i]!='\0')
    {
        i++;
    }
    l1=i;
    i=0;
    while(tab2[i]!='\0')
    {
        i++;
    }
    l2=i;
    for(i=l1-1; i>=0; i--)
    {
        for(k=l2-1; k>=0; k--)
        {
            if(tab[i]==tab2[k])
            {
                return i;
            }
        }

    }
    return -1;
}
int main()
{
    char tab[1001];
    char tab2[1001];
    printf("Daj: ");
    scanf("%1000[^\n]",tab);
    while(getchar() != '\n');
    printf("Daj: ");
    scanf("%1000[^\n]",tab2);
    printf("%d\n%d",find_any(tab,tab2),rfind_any(tab,tab2));
    return 0;
}

