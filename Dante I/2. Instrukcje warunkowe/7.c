#include <stdio.h>
#include <stdlib.h>

int main()
{
    float en,x,y,z,w;
    int t;
    w=0;
    printf("Podaj ilosc zuzytej energii(kWh): ");
    t=scanf("%f",&en);
    if((t!=1)||(en<0))
    {
        printf("Incorrect input");
        return 1;
    }
    if(en==0)
    {
        printf("0");
        return 0;
    }
    if(en<=50)
    {
        printf("%.2f",en*0.50*1.22);
        return 0;
    }
    if(en>50)
    {
        x=en-50;
        w=w+(50*0.5*1.22);
        if(x<=100)
        {
            printf("%.2f",(x*0.75*1.22)+w);
            return 0;
        }
        if(x>100)
        {
            y=x-100;
            w=w+(0.75*1.22*100);
            if(y<=100)
            {
                printf("%.2f",(y*1.20*1.22)+w);
                return 0;
            }
            if(y>100)
            {
            z=y-100;
            w=w+(1.20*1.22*100);
            if(en>250)
            {
                w=w+(z*1.22*1.50);
            }
            }
        }
    }
    printf("%.2f",w);
    return 0;
}
