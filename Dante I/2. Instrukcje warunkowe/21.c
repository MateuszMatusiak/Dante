#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,t;
    char s;
    printf("Podaj pierwsza liczbe: ");
    t=scanf("%d",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj druga liczbe: ");
    t=scanf("%d",&y);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj symbol operacji: ");
    scanf("%c",&s);
    scanf("%c",&s);
    if((s!='+')&&(s!='-')&&(s!='*')&&(s!='/'))
    {
        printf("Incorrect input");
        return 1;
    }
    if((s=='/')&&(y==0))
    {
        printf("Operation not permitted");
        return 2;
    }
    if(s=='+')
    {
        printf("%d",x+y);

    }
    if(s=='-')
    {
        printf("%d",x-y);

    }
    if(s=='*')
    {
        printf("%d",x*y);

    }
    if(s=='/')
    {
        float d = (float)x / (float)y;
        printf("%.2f",d);

    }
    return 0;
}
