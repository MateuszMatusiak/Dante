#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b,c,d,e;
    int l;
    l=0;
    printf("Podaj 5 znakow: ");
    scanf("%c%c%c%c%c",&a,&b,&c,&d,&e);
    if((a=='x')||(a=='y')||(a=='z')||(a=='2')||(a=='7'))
        l++;
    if((b=='x')||(b=='y')||(b=='z')||(b=='2')||(b=='7'))
        l++;
    if((c=='x')||(c=='y')||(c=='z')||(c=='2')||(c=='7'))
        l++;
    if((d=='x')||(d=='y')||(d=='z')||(d=='2')||(d=='7'))
        l++;
    if((e=='x')||(e=='y')||(e=='z')||(e=='2')||(e=='7'))
        l++;
    printf("Szukane znaki wystapily %d raz(y)",l);
    return 0;
}
