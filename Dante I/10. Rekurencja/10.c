#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int sum_of_digits(long long number)
{
    int suma=0;
    if(number==0)
        return 0;
    else
        return suma+sum_of_digits(number/10)+abs(number%10);
}
int main()
{
    int t;
    long long s;
    printf("Daj: ");
    t=scanf("%lli",&s);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%d",sum_of_digits(s));
    return 0;
}

