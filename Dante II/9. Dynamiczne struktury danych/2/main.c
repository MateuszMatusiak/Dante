#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main() {
    struct stack_t *xd;
    int t= stack_init(&xd);
    if(t==1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(t==2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    int c=1;
    while(c!=0)
    {
        printf("Daj: ");
        t= scanf("%d",&c);
        if(t!=1)
        {
            printf("Incorrect input");
            stack_destroy(&xd);
            return 1;
        }
        if(c==0)
        {
            break;
        }
        else if(c==1)
        {
            int x;
            printf("Daj: ");
            t=scanf("%d",&x);
            if(t!=1)
            {
                printf("Incorrect input");
                stack_destroy(&xd);
                return 1;
            }
            t= stack_push(xd,x);
            if(t==2)
            {
                printf("Failed to allocate memory");
                stack_destroy(&xd);
                return 8;
            }
        }
        else if(c==2)
        {
            int err;
            t= stack_pop(xd,&err);
            if(err==1)
            {
                printf("Stack is empty\n");
            }
            else
                printf("%d\n",t);
        }
        else if(c==3)
        {
            printf("%d\n",stack_empty(xd));
        }
        else if(c==4)
        {
            if(xd->head==NULL)
                printf("Stack is empty");
            else
                stack_display(xd);
            printf("\n");
        }
        else {
            printf("Incorrect input data\n");
        }
    }
    stack_destroy(&xd);
    return 0;
}

