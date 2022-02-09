#include <stdio.h>
#include <stdlib.h>


int main()
{
    int licznik1,licznik2;
    int y,z,t,q=0;
    int liczba;
    printf("Daj: ");
    t=scanf("%d", &liczba);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if((liczba>100000)||(liczba<0))
    {
        printf("Incorrect input");
        return 1;
    }
    for(int i=0; i<liczba; i++)
        for(int j=0; j<liczba; j++)
        {
            z=i;
            y=j;
            licznik1=0;
            licznik2=0;
            if(i+j==liczba)
            {
                while(z>9)
                {
                    z=z/10;
                    licznik1=licznik1+1;
                }
                while(y>9)
                {
                    y=y/10;
                    licznik2=licznik2+1;
                }
                if(licznik1-1==licznik2)
                {
                    printf("%d + %d = %d\n",i,j,i+j);
                    q++;
                }
            }
        }
    if(q==0)
    {
        printf("Nothing to show");
    }
    return 0;
}
