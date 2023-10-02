#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {

    struct stack_t *xd;
    int t=stack_init(&xd);
    if(t!=0)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    unsigned long long x;
    printf("Daj:");
    t= scanf("%llu",&x);
    if(t!=1)
    {
        stack_destroy(&xd);

        printf("Incorrect input");
        return 1;
    }
    if(x==0)
    {
        printf("0");
        stack_destroy(&xd);
        return 0;
    }
    while (x>0)
    {
        t= stack_push(xd,(int)(x%2));
        if(t!=0)
        {
            printf("Failed to allocate memory");
            stack_destroy(&xd);

            return 8;
        }
        x/=2;
    }
    stack_display(xd);
    stack_destroy(&xd);

    return 0;
}

