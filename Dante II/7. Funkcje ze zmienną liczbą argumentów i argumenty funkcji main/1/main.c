#include <stdio.h>
#include <stdarg.h>
#include "tested_declarations.h"
#include "rdebug.h"

int stats(int *sum, float *avg, int num,...)
{
    if(sum==NULL||avg==NULL||num<=0)
        return 1;
    *sum=0;
    *avg=0;
    va_list ap;
    va_start(ap,num);
    for(int i=0;i<num;++i)
        *sum+= va_arg(ap,int);
    *avg=(float)(*sum)/(float)num;
    va_end(ap);
    return 0;
}

int main() {
    int t,n,x[3]={0,0,0};
    int sum;
    float avg;
    printf("Daj:");
    t= scanf("%d",&n);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(n<1||n>3)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("Daj:");
    for(int i=0;i<n;++i) {
        t = scanf("%d ", x+i);
        if (t != 1) {
            printf("Incorrect input");
            return 1;
        }
    }

    t= stats(&sum,&avg,n,*x,*(x+1),*(x+2));
    if(t!=0) {
        printf("Incorrect input");
        return 1;
    }
    printf("%d, %f",sum,avg);
    return 0;
}

