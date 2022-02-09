#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w,t,o,i;
    char p[10]= {"\0\0\0\0\0\0\0\0\0\0"};
    char k[]="kobieta\0\0\0";
    char m[]="mezczyzna\0";
    o=0;
    printf("Podaj wiek: ");
    t=scanf("%d",&w);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("podaj plec: ");
    scanf("%10s",&*p);
    for(i=0; i<10; i++)
    {
        if(p[i]==k[i])
        {
            o++;
        }

    }
    if((p[7]!='\0')&&(p[7]!='n'))
    {
        printf("Incorrect input");
        return 1;
    }
    if(o!=10)
    {
        for(i=0; i<10; i++)
        {
            if(p[i]!=m[i])
            {
                printf("Incorrect input");
                return 1;
            }

        }
    }

    if(w<4)
    {
        printf("1300");
        return 0;
    }
    if(w<7)
    {
        printf("1700");
        return 0;
    }
    if(w<10)
    {
        printf("2100");
        return 0;
    }
    if((w<13)&&(p[0]=='m'))
    {
        printf("2600");
        return 0;
    }
    if((w<13)&&(p[0]=='k'))
    {
        printf("2300");
        return 0;
    }
    if((w<16)&&(p[0]=='m'))
    {
        printf("3000-3300");
        return 0;
    }
    if((w<16)&&(p[0]=='k'))
    {
        printf("2600-2800");
        return 0;
    }
    if((w<21)&&(p[0]=='m'))
    {
        printf("3200-3700");
        return 0;
    }
    if((w<21)&&(p[0]=='k'))
    {
        printf("2500-2700");
        return 0;
    }
    if((w<65)&&(p[0]=='m'))
    {
        printf("2800-3200");
        return 0;
    }
    if((w<60)&&(p[0]=='k'))
    {
        printf("2400-2800");
        return 0;
    }
    if((w<76)&&(p[0]=='m'))
    {
        printf("2300");
        return 0;
    }
    if((w<76)&&(p[0]=='k'))
    {
        printf("2200");
        return 0;
    }
    if((w>75)&&(p[0]=='m'))
    {
        printf("2100");
        return 0;
    }
    if((w>75)&&(p[0]=='k'))
    {
        printf("2000");
        return 0;
    }

    return 0;
}
