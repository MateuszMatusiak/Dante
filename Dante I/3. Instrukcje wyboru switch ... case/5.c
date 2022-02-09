#include <stdio.h>
#include <stdlib.h>

int main()
{
    char l;
    int t,k;
    printf("podaj literke: ");
    t=scanf("%c",&l);
    switch(t)
    {
    case 1:
    {
        break;
    }
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    }
    k=((l>='a')+(l<='z')+(l>='A')+(l<='Z'));
    switch(k)
    {
    case 3:
        break;
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    }
    switch(l)
    {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
    case 'y':
    case 'Y':
    {
        printf("vowel");
        break;
    }
    default:
    {
        printf("consonant");
        break;
    }
    }
    return 0;
}
