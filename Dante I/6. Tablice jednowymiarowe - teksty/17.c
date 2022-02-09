#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tekst[1001];
    float stos,mx=0,sam=0,sp=0;
    int i=0,dl=0,k,x=0;
    printf("daj: ");
    scanf("%1000[^\n]",tekst);
    while(tekst[i]!='\0')
    {
        if(((tekst[i]>='a')&&(tekst[i]<='z'))||((tekst[i]>='A')&&(tekst[i]<='Z'))||(tekst[i]==' '))
        {
            i++;
            x++;
        }
        else
        {
            printf("incorrect input");
            return 1;
        }
    }
    i=0;
    while(tekst[i]!='\0')
    {
        if(tekst[i]=='a'||tekst[i]=='A'||tekst[i]=='e'||tekst[i]=='E'||tekst[i]=='i'||tekst[i]=='I'||tekst[i]=='o'||tekst[i]=='O'||tekst[i]=='u'||tekst[i]=='U'||tekst[i]=='y'||tekst[i]=='Y')
        {
            sam++;
        }
        else if(tekst[i]!=' ')
        {
            sp++;
        }
        else
        {
            stos=sam/sp;
            if(mx<stos)
                mx=stos;
            sp=0;
            sam=0;
        }
        i++;

    }
    stos=sam/sp;
    if (mx<stos)
        mx=stos;
    sp=0;
    sam=0;


    for(i=x-1;i>=0;i--)
    {
        if(tekst[i]=='a'||tekst[i]=='A'||tekst[i]=='e'||tekst[i]=='E'||tekst[i]=='i'||tekst[i]=='I'||tekst[i]=='o'||tekst[i]=='O'||tekst[i]=='u'||tekst[i]=='U'||tekst[i]=='y'||tekst[i]=='Y')
        {
            sam++;
            dl++;
        }
        else if(tekst[i]!=' ')
        {
            sp++;
            dl++;
        }
        else
        {
            stos=sam/sp;
            if(mx==stos)
            {
                for(k=i+1; k<i+1+dl; k++)
                {
                    printf("%c",tekst[k]);
                }
                printf("\n");
            }
            sp=0;
            sam=0;
            dl=0;
        }


    }
    stos=sam/sp;
    if(mx==stos)
    {
        for(k=i+1; k<i+1+dl; k++)
        {
            printf("%c",tekst[k]);
        }
        printf("\n");
    }

    return 0;
}
