#include <stdio.h>
#include <stdlib.h>
#include "int_operations.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    int a, b, x, w, t;
    printf("Daj: ");
    t=scanf("%d %d",&a, &b);
    if(t!=2)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Daj: ");
    t=scanf("%d",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(x<0||x>3)
    {
       printf("Incorrect input data");
       return 2;
    }
    w=get_function(x)(a, b);
    printf("%d",w);

    return 0;
}

