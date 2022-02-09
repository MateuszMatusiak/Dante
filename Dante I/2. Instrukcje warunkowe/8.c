#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x;
    int y,t;
    printf("Podaj pole szachownicy: ");
    t=scanf("%c%d",&x,&y);
    if((t!=2)||(y>8)||(y<=0)||(x!='a'&&x!='b'&&x!='c'&&x!='d'&&x!='e'&&x!='f'&&x!='g'&&x!='h'))
    {
        printf("Incorrect input");
        return 1;
    }
    if((((x=='a')||(x=='c')||(x=='e')||(x=='g'))&&(y%2==0))||(((x=='b')||(x=='d')||(x=='f')||(x=='h'))&&(y%2==1)))
        printf("white");
    if((((x=='a')||(x=='c')||(x=='e')||(x=='g'))&&(y%2==1))||(((x=='b')||(x=='d')||(x=='f')||(x=='h'))&&(y%2==0)))
        printf("black");
    return 0;
}
