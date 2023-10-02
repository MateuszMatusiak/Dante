#include <stdio.h>
#include "int_operations.h"
#include "tested_declarations.h"
#include "rdebug.h"

int add_int(int a, int b)
{
    return a + b;
}
int sub_int(int a, int b)
{
    return a - b;
}
int div_int(int a, int b)
{
    if(b==0)
        return 0;
    return a / b;
}
int mul_int(int a, int b)
{
    return a * b;
}
p get_function(enum operations_t x)
{
    p funcs[]={add_int, sub_int, div_int, mul_int};
    if(x<0||x>3)
    {
       printf("Incorrect input data");
       return NULL;
    }
    return *(funcs+x);
}

