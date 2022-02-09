#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, pkt;
    printf("Podaj ilosc punktow: ");
    t=scanf("%d",&pkt);
    if((t!=1)||(pkt<0)||(pkt>20))
    {
        printf("Incorrect input");
        return 1;
    }
    if(pkt<=10)
    {
        printf("ocena 2");
        return 0;
    }
    if(pkt<=13)
    {
        printf("ocena 3");
        return 0;
    }
    if(pkt<=16)
    {
        printf("ocena 4");
        return 0;
    }
    if(pkt<=20)
    {
        printf("ocena 5");
        return 0;
    }

}
