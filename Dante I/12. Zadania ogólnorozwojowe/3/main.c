#include <stdio.h>
#include <math.h>


int main()
{
    long long dal, dal2, wynik, licznik, licznik2, y, z, licznik3;
    licznik=1;
    licznik2=1;
    licznik3=1;
    int tab[100];
    printf("Daj ");
    scanf("%lli", &dal);
    printf("Daj ");
    scanf("%lli", &dal2);
    y=dal2;
    wynik=dal*dal2;
    z=dal;
    while(wynik>9)
    {
        wynik=wynik/10;
        licznik=licznik+1;
    }
    while(y>9)
    {
        y=y/10;
        licznik2=licznik2+1;
    }
    while(z>9)
    {
        z=z/10;
        licznik3=licznik3+1;
    }

    y=dal2;
    for(int i=0; i<licznik2; i++)
    {
        tab[i]=y%10;
        y=y/10;

    }
    for (int i=0; i<=licznik-licznik3-1; i++)
        printf(" ");
    printf("%lli",dal);
    printf("\n");
    for (int i=0; i<licznik-licznik2; i++)
        printf(" ");
    printf("%lli\n",dal2);
    for(int i=0; i<licznik; i++)
        printf("-");
    printf("\n");

    for(int i=0; i<licznik2; i++)
    {
        licznik3=1;
        z= tab[i]*dal;
        while(z>9)
        {
            z=z/10;
            licznik3=licznik3+1;
        }
        for(int f=0; f<licznik-licznik3-i; f++)
            printf(" ");
        printf("%lli \n",tab[i]*dal);
    }




    for(int i=0; i<licznik; i++)
        printf("-");
    printf("\n%lli",dal*dal2);



    return 0;
}
