#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

float distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
float perimeter(float a, float b, float c)
{
    if((a<=0)||(b<=0)||(c<=0)||(a+b<c)||(a+c<b)||(b+c<a))
        return -1;
    return a+b+c;
}
float area(float a, float b, float c)
{
    float p,x;
    if((a<=0)||(b<=0)||(c<=0)||(a+b<c)||(a+c<b)||(b+c<a))
        return -1;
    p=(perimeter(a,b,c))/2;
    x=sqrt(p*(p-a)*(p-b)*(p-c));
    return x;
}

int main()
{
    float a,b,c;
    int x1,x2,x3,y1,y2,y3,t;
    printf("Daj wsp pierwsze: ");
    t=scanf("(%d, %d)",&x1,&y1);
    getchar();
    if(t!=2)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Daj wsp drugie: ");
    t=scanf("(%d, %d)",&x2,&y2);
    getchar();
    if(t!=2)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Daj wsp trzecie: ");
    t=scanf("(%d, %d)",&x3,&y3);
    if(t!=2)
    {
        printf("Incorrect input");
        return 1;
    }
    if((x1==x2)&&(x2==x3)||(y1==y2)&&(y2==y3))
    {
        printf("Incorrect input");
        return 1;
    }
    a=distance(x1,y1,x2,y2);
    b=distance(x2,y2,x3,y3);
    c=distance(x1,y1,x3,y3);

    if((area(a,b,c)!=-1)&&(perimeter(a,b,c))!=-1)
        printf("%f",area(a,b,c));
    else
    {
        printf("Incorrect input");
        return 1;
    }

    return 0;
}

