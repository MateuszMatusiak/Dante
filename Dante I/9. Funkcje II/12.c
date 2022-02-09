#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int starts_with(const char tab[], const char tab2[])
{
    int i=0,l2=0,l1=0;
    while(tab[l1]!='\0')
    {
        l1++;
    }
    while(tab2[l2]!='\0')
    {
        l2++;
    }
    if(l2>l1)
        return 0;
    while(tab[i]!='\0')
    {
        if(tab[i]==tab2[i])
        {
        }
        else if(i==l2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        i++;

    }
    return 1;

}
int ends_with(const char tab[], const char tab2[])
{
    int l1=0,l2=0,i,k;
    while(tab[l1]!='\0')
    {
        l1++;
    }
    while(tab2[l2]!='\0')
    {
        l2++;
    }
    if(l2>l1)
        return 1;
    if((l1==l2)&&(l1==1)&&(tab[0]==tab2[0]))
    {
        return 1;
    }
    k=l2-1;
    for(i=l1-1; i>=0; i--)
    {
        if(k<0)
            return 1;
        if(tab[i]!=tab2[k])
            return 0;
        k--;
        if(k<0)
            return 1;
    }
    return 0;
}

int main()
{
    char tab[101];
    char tab2[101];
    printf("Daj: ");
    scanf("%100[^\n]",tab);
    while(getchar() != '\n');
    printf("Daj: ");
    scanf("%100[^\n]",tab2);
    printf("%d\n%d",starts_with(tab,tab2),ends_with(tab,tab2));
    return 0;
}

