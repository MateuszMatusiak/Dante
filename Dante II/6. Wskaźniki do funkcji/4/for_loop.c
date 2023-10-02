#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "for_loop.h"
#include "tested_declarations.h"
#include "rdebug.h"

void for_loop(double beg, double a, double end, p function)
{
    if(!(function==NULL||a==0))
    {
        if(beg<end&&a>0)
        {
          if(beg>=end)
            return;
        else
        {
            function(beg);
            beg=beg+a;
            for_loop(beg,a,end,function);
        }
        }
        else if(beg>end&&a<0)
        {
          if(beg<=end)
            return;
        else
        {
            function(beg);
            beg=beg+a;
            for_loop(beg,a,end,function);
        }
        }

    }
}
void print_value(double a)
{
    printf("%f ",a);
}
void print_accumulated(double a)
{
    static double i=0;
    i=i+a;
    printf("%f ",i);
}
void print_square(double a)
{
    printf("%f ",a*a);

}
void print_abs(double a)
{
    double b=fabs(a);
    printf("%f ",b);
}

