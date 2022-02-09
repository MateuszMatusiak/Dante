#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned long factorial_rec(int n)
{
    if(n<0)
        return 0;
    if(n>=1)
        return factorial_rec(n-1)*n;
    else
    {
      return 1;
    }


}

int main()
{
   int n,t;
   printf("Daj: ");
   t=scanf("%d",&n);
   if(t!=1)
   {
       printf("Incorrect input");
       return 1;
   }
   if((n<0)||(n>20))
   {
       printf("Incorrect input data");
       return 2;
   }
   printf("%lu",factorial_rec(n));
    return 0;
}

