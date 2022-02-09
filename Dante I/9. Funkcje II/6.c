#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int count(const char tab[], char c)
{
    int i=0,l=0;
    while(tab[i]!='\0')
    {
        if(tab[i]==c)
            l++;
        i++;
    }
    return l;
}


int count_string(const char tab[], const char tab2[])
{
    int l=0,i=0,o=0,licz=0;
    while(tab2[l]!='\0')
    {
        l++;
    }
    while(tab[i]!='\0')
    {
        o=0;
        if(tab[i]==tab2[0])
        {
            for(o=0; o<l; o++)
            {
                if(tab[i]==tab2[o])
                {
                    i++;
                }
                else
                    break;
            }
        }
        if(o==l)
            licz++;
        i++;
    }
    return licz;
}

int count_all_of(const char tab[], const char tab2[])
{
    int i=0,k=0,l=0,o,b=0;

    while(tab[i]!='\0')
    {
        k=0;
        while(tab2[k]!='\0')
        {
            for(o=0; o<k; o++)
            {
                if(tab2[o]==tab2[k])
                    b++;
            }
            if(b==0)
            {
                if(tab2[k]==tab[i])
                    l++;
            }
            k++;
            b=0;
        }
        i++;

    }

    return l;
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
    printf("%d\n%d\n%d\n",count(tab,tab2[0]),count_string(tab,tab2),count_all_of(tab,tab2));
    return 0;
}

