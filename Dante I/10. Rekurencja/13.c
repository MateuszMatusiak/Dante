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
int is_divisible_by_3(int number)
{
    if((abs(number)==0)||(abs(number)==3)||(abs(number)==6)||(abs(number)==9))
        return 1;
    else if(abs(number)>11)
    {
        return is_divisible_by_3(sum_of_digits(number));
    }
    else
        return 0;

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
    if(is_divisible_by_3(s)==1)
        printf("YES");
    else
        printf("NO");
    return 0;
}

