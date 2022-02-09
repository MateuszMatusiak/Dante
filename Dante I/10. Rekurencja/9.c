#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

long long binary_exponentiation(long long a, unsigned int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return a;
    if(n%2==0)
    {
        return binary_exponentiation(a*a, n/2);
    }
    else
        return a*binary_exponentiation(a*a, (n-1)/2);
    return -1;
}
int main()
{
    int t;
    long long x;
    unsigned int n;
    printf("Daj: ");
    t=scanf("%lli",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Daj: ");
    t=scanf("%u",&n);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("%lli",binary_exponentiation(x, n));
    return 0;
}

