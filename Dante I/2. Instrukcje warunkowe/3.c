#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d,m,r,t;
    printf("Podaj date (w formacie dd-mm-yyyy): ");
    t=scanf("%2d-%2d-%4d",&d,&m,&r);
    if(t!=3)
    {
        printf("Incorrect input");
        return 1;
    }
    if(m>12||m<1||d<1)
    {
        printf("Incorrect");
        return 0;
    }

    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
        if(d>31)
        {
            printf("Incorrect");
            return 0;
        }
    }


    if((m==2&&r%400==0)||(m==2&&r%100!=0&&r%4==0))
    {
        if(d>29)
        {
            printf("Incorrect");
            return 0;
        }
    }

    if((m==2&&r%100!=0&&r%4!=0)||(m==2&&r%100==0&&r%400!=0))
    {
        if(d>28)
        {
            printf("Incorrect");
            return 0;
        }
    }
    if(m==4||m==6||m==9||m==11)
    {
        if(d>30)
        {
            printf("Incorrect");
            return 0;
        }
    }

    printf("Correct");
    return 0;
}
