#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "ctype.h"
#include "tested_declarations.h"
#include "rdebug.h"



void getstr(char *nz, int n) {
    char ch = getchar();
    int i = 0;
    while (i < n && ch != '\n') {
        *(nz + i) = ch;
        ch = getchar();
        ++i;
    }
    *(nz + i) = '\0';
    if (i == n && ch != '\n')
        while (getchar() != '\n');
}

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
    double x;
    printf("Daj: ");

    char ch='0';
    while(ch!='\n')
    {
        x=0;
        ch = getchar();
        if (isdigit(ch)) {
            x=ch-'0';
            while(isdigit(ch))
            {
                ch=getchar();
                if(isdigit(ch))
                {
                    x*=10;
                    x+=ch-'0';
                }
            }
            t= stack_push(xd,x);
            if(t!=0)
            {
                stack_destroy(&xd);
                printf("Failed to allocate memory");
                return 8;
            }
        }
        else if (ch == '+') {
            int err;
        double a= stack_pop(xd,&err);
        if(err!=0)
        {
            printf("Incorrect expression");
            stack_destroy(&xd);
            return 2;
        }
        double b= stack_pop(xd,&err);
        if(err!=0)
        {
            printf("Incorrect expression");
            stack_destroy(&xd);
            return 2;
        }
        t= stack_push(xd,a+b);
        if(t!=0)
        {
            stack_destroy(&xd);
            printf("Failed to allocate memory");
            return 8;
        }
        } else if (ch == '-') {

            x=0;
            ch = getchar();
            if (isdigit(ch)) {
                x=ch-'0';
                while(isdigit(ch))
                {
                    ch=getchar();
                    if(isdigit(ch))
                    {
                        x*=10;
                        x+=ch-'0';
                    }
                }
                t= stack_push(xd,x*-1);
                if(t!=0)
                {
                    stack_destroy(&xd);
                    printf("Failed to allocate memory");
                    return 8;
                }
                continue;
            }
            else if(ch!=' '&&ch!='\n')
            {
                printf("Incorrect input");
                stack_destroy(&xd);
                return 1;
            }


            int err;
            double a= stack_pop(xd,&err);
            if(err!=0)
            {
                printf("Incorrect expression");
                stack_destroy(&xd);
                return 2;
            }
            double b= stack_pop(xd,&err);
            if(err!=0)
            {
                printf("Incorrect expression");
                stack_destroy(&xd);
                return 2;
            }
            t= stack_push(xd,b-a);
            if(t!=0)
            {
                stack_destroy(&xd);
                printf("Failed to allocate memory");
                return 8;
            }
        } else if (ch == '*') {
            int err;
            double a= stack_pop(xd,&err);
            if(err!=0)
            {
                printf("Incorrect expression");
                stack_destroy(&xd);
                return 2;
            }
            double b= stack_pop(xd,&err);
            if(err!=0)
            {
                printf("Incorrect expression");
                stack_destroy(&xd);
                return 2;
            }
            t= stack_push(xd,a*b);
            if(t!=0)
            {
                stack_destroy(&xd);
                printf("Failed to allocate memory");
                return 8;
            }
        } else if (ch == '/') {
            int err;
            double a= stack_pop(xd,&err);
            if(err!=0)
            {
                printf("Incorrect expression");
                stack_destroy(&xd);
                return 2;
            }
            double b= stack_pop(xd,&err);
            if(err!=0)
            {
                printf("Incorrect expression");
                stack_destroy(&xd);
                return 2;
            }
            t= stack_push(xd,b/a);
            if(t!=0)
            {
                stack_destroy(&xd);
                printf("Failed to allocate memory");
                return 8;
            }
        } else if (ch == ' ') {
            continue;
        }else if (ch == '\n') {
            break;
        } else {
            printf("Incorrect input");
            stack_destroy(&xd);
            return 1;
        }
    }
    if(stack_size(xd)!=1)
    {
        printf("Incorrect expression");
        stack_destroy(&xd);
        return 2;
    }
    stack_display(xd);
    stack_destroy(&xd);
    return 0;
}

