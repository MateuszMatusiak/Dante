#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,l=0;
    char tekst[1001];
    printf("daj: ");
    scanf("%1000[^\n]",tekst);
    while(tekst[i]!='\0')
    {
        if(((tekst[i]>='a')&&(tekst[i]<='z'))||((tekst[i]>='A')&&(tekst[i]<='Z')))
        {
            if(i==0)
            {
                l++;
                i++;
                continue;
            }
            i++;
            continue;
        }
        else if(((tekst[i+1]>='a')&&(tekst[i+1]<='z'))||((tekst[i+1]>='A')&&(tekst[i+1]<='Z')))
            l++;
    i++;

    }
    printf("%d",l);
    return 0;
}
