#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int sort_lowercase(char tab[])
{
    int i, k, l=0,size=0;
    char x;
    while(tab[size]!='\0')
    {
        if((tab[size]<'a')||(tab[size]>'z'))
            return 1;
        size++;
    }
    if(size==0)
        return 1;
    for (i = 0; i<size-1; i++)
    {

        l=0;
        for (k=0; k<size-1; k++)
        {
            if (tab[k] < tab[k+1])
            {
                x = tab[k+1];
                tab[k+1] = tab[k];
                tab[k] = x;
                l++;
            }
        }
        if(l==0)
            break;
    }
    size=0;
    while(tab[size]!='\0')
    {

        if(tab[size]=='0')
            break;
        size++;
    }


    for (i = 0; i<=size-1; i++)
    {
        l=0;
        for (k=0; k<size-1; k++)
        {
            if (tab[k] > tab[k+1])
            {
                x = tab[k+1];
                tab[k+1] = tab[k];
                tab[k] = x;
                l++;
            }

        }
        if(l==0)
            break;
    }
    i=0;
while(tab[i]!='\0')
{
    if(tab[i]=='0')
        tab[i]='\0';
    i++;
}

    return 0;
}
int main()
{
    char cyferki[31];
    printf("Daj: ");
    scanf("%30[^\n]",cyferki);
    int i=0;
    sort_lowercase(cyferki);
    while(cyferki[i]!='\0')
    {
        if((cyferki[i]<'a')||(cyferki[i]>'z'))
        {
            printf("incorrect input data");
            return 2;
        }
        i++;
    }
    i=0;
    while(cyferki[i]!='\0')
    {
        printf("%c",cyferki[i]);
        i++;
    }
    if(i==0)
    {
        printf("nothing to show");
    }

    return 0;
}


