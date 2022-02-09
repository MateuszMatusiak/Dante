#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int t,n,i,k,p,r,l,q,a,b;
    char tab[1000];
    printf("Daj: ");
    t=scanf("%d", &n);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if((n<1)||(n>6))
    {
        printf("Incorrect input data");
        return 2;
    }
    p=pow(3,n-1);
    for(k=0; k<p; k++)
    {
        tab[k]='_';
        printf("%c",tab[k]);
    }
    printf("\n");


    for(i=1; i<n; i++)
    {
        l=0;
        a=0;
        while(tab[l]=='_')
        {
            l++;
        }
        for(b=0; b<pow(3,i); b++)
        {
            if(tab[a]=='_')
            {

                for(k=0; k<l/3; k++)
                {
                    a++;
                }
                for(r=k; r<k+(l/3); r++)
                {

                    tab[a]=' ';
                    a++;


                }
                for(q=r; q<r+(l/3); q++)
                {
                    a++;
                }
            }
            else
            {
                while(tab[a]==' ')
                    a++;
            }
        }
        for(k=0; k<p; k++)
        {
            printf("%c",tab[k]);
        }
        printf("\n");
    }

    return 0;
}

