#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s;
    char x[1001]= {'\x0'};
    int l=0;
    printf("daj: ");
    scanf ("%1000[^\n]",x);
    printf("daj szyfer: ");
    scanf ("%d",&s);
    while (x[l]!='\0')
    {
        if(((x[l]>='A')&&(x[l]<='Z'))||((x[l]>='a')&&(x[l]<='z')))
        {

            if ((x[l]>='A')&&(x[l]<='Z'))
            {
                if(x[l]+s>'Z')
                    x[l]=x[l]-('Z'-'A'+1)+s;
                else
                    x[l]=x[l]+s;
            }
            if((x[l]>='a')&&(x[l]<='z'))
            {
                if(x[l]+s>'z')
                    x[l]=x[l]-('z'-'a'+1)+s;
                else
                    x[l]=x[l]+s;
            }

        }
        l++;
    }
    l=0;
    while (x[l]!='\0')
    {
        printf("%c",x[l]);
        l++;
    }

}
