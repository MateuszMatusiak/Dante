#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,l;
    printf("podaj liczbe: ");
    t=scanf("%d",&l);
    if(t)
    {
        if(l)
        {
            printf("Not equal to zero");
            return 0;
        }
        else
        {
            printf("Equal to zero");
            return 0;
        }
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }

}
