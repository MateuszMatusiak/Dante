#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

long power_rec(int a, int n)
{
    long x=(long)n;
    if(x<0)
    return 0;
    else if(x==0)
        return 1;
    else
    {
        return power_rec(a,x-1)*a;
    }
}
int main()
{
    int a,n,t;
    printf("Daj: ");
    t=scanf("%d",&a);
    if(t!=1)
   {
       printf("Incorrect input");
       return 1;
   }
   printf("Daj: ");
    t=scanf("%d",&n);
    if(t!=1)
   {
       printf("Incorrect input");
       return 1;
   }
   if(n<0)
   {
       printf("Incorrect input data");
       return 2;
   }
    printf("%li",power_rec(a,n));
    return 0;
}

