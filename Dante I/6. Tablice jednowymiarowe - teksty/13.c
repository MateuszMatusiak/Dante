#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,k;
    char tekst[1001];
    int tab2['z'-'a'+1][2];
    printf("daj: ");
    scanf("%1000[^\n]",tekst);
    for(k='a'; k<='z'; k++)
    {
        tab2[k-'a'][0]=k;
        tab2[k-'a'][1]=0;
    }
    while(tekst[i]!='\0')
    {
        if((tekst[i]>='a')&&(tekst[i]<='z'))
            tab2[tekst[i]-'a'][1]++;
        if((tekst[i]>='A')&&(tekst[i]<='Z'))
            tab2[tekst[i]-'A'][1]++;
        i++;
    }

    for(k=0; k<('z'-'a'+1); k++)
    {

        printf("%c %d\n",tab2[k][0],tab2[k][1]);

    }
    return 0;
}
