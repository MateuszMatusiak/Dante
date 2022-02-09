#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tekst[1001];
    int l=0,licz=0;
    int tab[12];
    printf("daj: ");
    scanf("%1000[^\n]",tekst);
    for(int i=0;i<12;i++)
        tab[i]=0;
    while(tekst[l]!='\0')
    {

        if((tekst[l]=='a')&&(tab[0]==0))
        {
            tab[0]=1;
            licz++;
            l++;
        }
        else if((tekst[l]=='A')&&(tab[1]==0))
        {
            tab[1]=1;
            licz++;
            l++;
        }
        else if((tekst[l]=='e')&&(tab[2]==0))
        {
            tab[2]=1;
            licz++;
            l++;
        }
        else if((tekst[l]=='E')&&(tab[3]==0))
        {
            tab[3]=1;
            licz++;
            l++;
        }
        else if((tekst[l]=='i')&&(tab[4]==0))
        {
            tab[4]=1;
            licz++;
            l++;
        }
        else if((tekst[l]=='I')&&(tab[5]==0))
        {
            tab[5]=1;
            licz++;
            l++;
        }
        else if((tekst[l]=='o')&&(tab[6]==0))
        {
            tab[6]=1;
            licz++;
            l++;

        }
        else if((tekst[l]=='O')&&(tab[7]==0))
        {
            tab[7]=1;
            licz++;
            l++;
        }
        else if((tekst[l]=='u')&&(tab[8]==0))
        {
            tab[8]=1;
            licz++;
            l++;
        }
        else if((tekst[l]=='U')&&(tab[9]==0))
        {
            tab[9]=1;
            licz++;
            l++;
        }
        else if((tekst[l]=='y')&&(tab[10]==0))
        {
            tab[10]=1;
            licz++;
            l++;
        }
        else if((tekst[l]=='Y')&&(tab[11]==0))
        {
            tab[11]=1;
            licz++;
            l++;
        }
        else
            l++;
    }
    printf("Wynik: %d",licz);
    return 0;
}














