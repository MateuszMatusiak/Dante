#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r,u,t;
    char z;
    printf("Podaj zespolona d+/-id: ");
    t=scanf("%d%ci%d",&r,&z,&u);
    if((t!=3)||(u<0)||((z!='+')&&(z!='-')))
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Czesc rzeczywista: %d\n",r);
    if(z=='-')
    {
        printf("Czesc urojona: %c%d",z,u);
    }
    else
    {
        printf("Czesc urojona: %d",u);
    }
    return 0;
}
