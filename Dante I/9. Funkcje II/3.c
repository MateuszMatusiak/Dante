#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


int find_string(const char tab[], const char tab2[])
{
    if((tab[0]=='\n')&&(tab2[0]=='\n'))
        return 0;

    int l=0,i=0,o=0,z=0;
    while(tab2[l]!='\0')
    {
        l++;
    }
    while(tab[i]!='\0')
    {
        if(tab[i]==tab2[0])
        {
            z=i;
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
            return z;
        i++;
    }
    return -1;
}

int rfind_string(const char tab[], const char tab2[])
{
    int i=0,l1,l2,k,z;
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
        z=0;
        for(k=l2-1; k>=0; k--)
        {
            if(tab[i]==tab2[k]){
                i--;
                z++;
            }
        }
        if(z==l2)
            return i+1;
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
    printf("%d\n%d",find_string(tab,tab2),rfind_string(tab,tab2));

    return 0;
}

