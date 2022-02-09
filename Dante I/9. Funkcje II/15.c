#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"


int horner(const char binary[])
{
    int b[17],licz=0;
    int suma=0,i=0;

    licz=0;
    while(binary[licz]!='\0')
   {
       if(binary[licz]=='1')
       {
           b[licz]=1;
       }
       else if(binary[licz]=='0')
       {
           b[licz]=0;
       }
       else
        return -1;
       licz++;
   }


    i=0;
    if(binary[i]=='\0')
        return -1;
    if(binary[i+1]=='\0')
        return b[i];

    suma=b[i];
    while(binary[i+1]!='\0')
    {
        suma=suma*2+b[i+1];
        i++;
    }
    return suma;
}

int main()
{
    int i=0;
    char tab[17];
    printf("Daj: ");
    scanf("%16[^\n]",tab);
    while(tab[i]!='\0')
    {
        if(tab[i]=='1')
            i++;
        else if(tab[i]=='0')
            i++;
        else
        {
            printf("Incorrect input");
            return 1;
        }

    }
    printf("%d",horner(tab));
    return 0;
}

