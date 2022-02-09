#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    float pln;
    char w;
    printf("podaj ilosc pln: ");
    t=scanf("%f",&pln);
    switch(t)
    {
    case 1:
        break;
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    }
    switch(pln>0)
    {
    case 1:
        break;
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    }
    printf("podaj symbol operacji: e/f/d: ");
    scanf("%c",&w);
    t=scanf("%c",&w);
    switch(t)
    {
    case 1:
        break;
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    }
    switch(w)
    {
    case 'e':
    {
        printf("%.2f",pln/4.2074);
        break;
    }
    case 'f':
    {
        printf("%.2f",pln/4.7073);
        break;
    }
    case 'd':
    {
        printf("%.2f",pln/3.5382);
        break;
    }
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    }

    return 0;
}
