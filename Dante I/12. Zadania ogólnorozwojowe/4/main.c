#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,k,o,x;
    char tab[1001];
    printf("Daj: ");
    t=scanf("%1000[^\n]",tab);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if((tab[0]>='a')&&(tab[0]<='z'))
    {
        tab[0]=tab[0]-32;

    }
    i=0;
    while(tab[i]!='\0')
    {
        if(((tab[i]<'a')||(tab[i]>'z'))&&((tab[i]<'A')||(tab[i]>'Z')))
        {
            if(((tab[i+1]>='a')&&(tab[i+1]<='z'))||((tab[i+1]>='A')&&(tab[i+1]<='Z')))
            {
                if((tab[i+1]>='a')&&(tab[i+1]<='z'))
                {
                    tab[i+1]=tab[i+1]-32;

                }
            }
        }
        if(((tab[i]>='a')&&(tab[i]<='z'))||((tab[i]>='A')&&(tab[i]<='Z')))
            if(((tab[i+1]>='a')&&(tab[i+1]<='z'))||((tab[i+1]>='A')&&(tab[i+1]<='Z')))
            {
                if((tab[i+1]>='A')&&(tab[i+1]<='Z'))
                {
                    tab[i+1]=tab[i+1]+32;

                }

            }
        i++;
    }

    for(k=i; k>=0; k--)
    {
        for(o=0; o<k; o++)
        {

            if(((tab[o]<'a')||(tab[o]>'z'))&&((tab[o]<'A')||(tab[o]>'Z')))
            {
            x=tab[o+1];
            tab[o+1]=tab[o];
            tab[o]=x;
            }
        }
    }
    i=0;
    while(tab[i]!='\0')
    {
        printf("%c",tab[i]);
        i++;
    }
    if(i==0)
    {
        printf("NothingToShow");
    }
    return 0;
}



