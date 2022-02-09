#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b,c,d,e;
    printf("Podaj 5 liter: ");
    scanf("%c%c%c%c%c",&a,&b,&c,&d,&e);
    if((a<='z')&&(a>='a'))
        a=a-32;
    if((b<='z')&&(b>='a'))
        b=b-32;
    if((c<='z')&&(c>='a'))
        c=c-32;
    if((d<='z')&&(d>='a'))
        d=d-32;
    if((e<='z')&&(e>='a'))
        e=e-32;
    printf("%c%c%c%c%c",a,b,c,d,e);
    return 0;
}
