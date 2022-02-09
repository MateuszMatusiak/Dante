#include <stdio.h>
#include <stdlib.h>

int main()
{
    char op;
    int a,b,t;
    float c;
    printf("Podaj liczby: ");
    t=scanf("%d %d",&a,&b);
    switch(t)
    {
    case 2:
    {
        break;
    }
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    }
    printf("Podaj operator: ");
    scanf("%c",&op);
    scanf("%c",&op);
    switch(b)
    {
    case 0:
    {
        printf("Illegal operation");
        return 2;
    }
    default:
    {
        break;
    }
    }
    switch (op)
    {
    case '+':
    {
        printf("%d",a+b);
        break;
    }
    case '-':
    {
        printf("%d",a-b);
        break;
    }
    case '*':
    {
        printf("%d",a*b);
        break;
    }
    case '/':
    {
        c=(float)a/b;
        printf("%.2f",c);
        break;
    }
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    }
    return 0;
}
