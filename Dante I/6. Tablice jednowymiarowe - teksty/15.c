#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,l=0;
    char tekst[1001];
    int tab2[500];
    printf("daj: ");
    scanf("%1000[^\n]",tekst);
    for(int o=0;o<500;o++)
    {
        tab2[o]=0;
    }
    while(tekst[i]!='\0')
    {
        if(((tekst[i]>='a')&&(tekst[i]<='z'))||((tekst[i]>='A')&&(tekst[i]<='Z')))
        {
            l++;
        }
        else
            {
                tab2[l]++;
                l=0;
            }
    i++;

    }
    tab2[l]++;
    for(int o=1;o<500;o++)
    {
        if(tab2[o]!=0)
            printf("%d - %d\n",o,tab2[o]);
    }
    return 0;
}
