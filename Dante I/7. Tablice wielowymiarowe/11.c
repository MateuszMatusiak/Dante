#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int tab[10][10];
    float mx,mn,najb,wmx=0,kmx=0,wmn=0,kmn=0,wsr=0,ksr=0,lx=0,ln=0,lb=0,srednia=0,w,wm,a,b,c;
    int t,i,k;
    printf("Daj: ");
    for(i=0; i<10; i++)
    {
        for(k=0; k<10; k++)
        {
            t=scanf("%d",&tab[i][k]);
            if(t!=1)
            {
                printf("incorrect input");
                return 1;
            }
        }
    }
    mn=tab[0][0];
    mx=tab[0][0];

    for(i=0; i<10; i++)
    {
        for(k=0; k<10; k++)
        {
            srednia=srednia+tab[i][k];
            if(mx<tab[i][k])
            {
                mx=tab[i][k];
                wmx=i;
                kmx=k;
            }

            if(mn>tab[i][k])
            {
                mn=tab[i][k];
                wmn=i;
                kmn=k;
            }
        }
    }
    srednia=srednia/100.0;

    wm=fabs(srednia-tab[0][0]);
    najb=tab[0][0];
    for(i=0; i<10; i++)
    {
        for(k=0; k<10; k++)
        {
            w=fabs(srednia-tab[i][k]);
            if(w<wm)
            {
                wm=w;
                najb=tab[i][k];
                wsr=i;
                ksr=k;
            }
        }
    }

    for(i=0; i<10; i++)
    {
        for(k=0; k<10; k++)
        {
            if(tab[i][k]==mx)
                lx++;
            if(tab[i][k]==mn)
                ln++;
            if(tab[i][k]==najb)
                lb++;
        }
    }
    if((lx>1)||(ln>1)||(lb>1))
    {
        printf("error");
        return 2;
    }
    a=sqrt(((wmx-wmn)*(wmx-wmn))+((kmx-kmn)*(kmx-kmn)));
    b=sqrt(((wsr-wmn)*(wsr-wmn))+((ksr-kmn)*(ksr-kmn)));
    c=sqrt(((wsr-wmx)*(wsr-wmx))+((ksr-kmx)*(ksr-kmx)));

    printf("%.2f %.2f %.2f",a,b,c);
        return 0;
}
