#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, x2, t;
    printf("Podaj dwie liczby calkowite oddzielone spacja: ");
    t=scanf("%d %d",&x1,&x2);
    if(t!=2)
    {
        printf("Incorrect input");
        return 1;
    }
    else
    {
        printf("%d",x1+x2);
    }
    return 0;
}
