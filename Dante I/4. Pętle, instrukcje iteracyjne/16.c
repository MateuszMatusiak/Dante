#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,iloczyn=1;
    int t=1;
    do
    {
        printf("daj: ");
        t=scanf("%f",&x);
        if(t!=1)
        {
            printf("incorrect input");
            break;
        }
        iloczyn=iloczyn*x;
        printf("%.2f\n",iloczyn);

    }
    while(t==1);
    return 0;
}
