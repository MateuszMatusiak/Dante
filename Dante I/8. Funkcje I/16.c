#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

double mySin(double x, int n)
{
    double sinx=0,g=1,o,k;
    if(n<0)
        return -1;
    for(k=0; k<=n; k++)
    {
        g=1;
        for(o=2*k+1; o>=1; o--)
            g=o*g;
        sinx=sinx+((pow(-1,k)/g)*(pow(x,(2*k+1))));
    }
    return sinx;
}
double myCos(double x, int n)
{
    if(n<0)
        return -1;
    double cosx=0,g=1,o,k,q,w;
    for(k=0; k<=n; k++)
    {
        g=1;
        for(o=2*k; o>1; o--)
            g=o*g;
        q=pow(-1,k);
        w=pow(x,2*k);
        cosx=cosx+q/g*w;
    }
    return cosx;
}

int main()
{
    int n,t;
    double x;
    printf("Daj kat: ");
    t=scanf("%lf",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    getchar();
    printf("Daj ile wyrazow: ");
    t=scanf("%d",&n);
    if((t!=1)||(n<0))
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%lf %lf",mySin(x,n),myCos(x,n));
    return 0;
}

