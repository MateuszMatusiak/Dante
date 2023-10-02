#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct bit
{
    unsigned char a0:1;
    unsigned char a1:1;
    unsigned char a2:1;
    unsigned char a3:1;
    unsigned char a4:1;
    unsigned char a5:1;
    unsigned char a6:1;
    unsigned char a7:1;
    unsigned char a8:1;
    unsigned char a9:1;
    unsigned char a10:1;
    unsigned char a11:1;
    unsigned char a12:1;
    unsigned char a13:1;
    unsigned char a14:1;
    unsigned char a15:1;
    unsigned char a16:1;
    unsigned char a17:1;
    unsigned char a18:1;
    unsigned char a19:1;
    unsigned char a20:1;
    unsigned char a21:1;
    unsigned char a22:1;
    unsigned char a23:1;
    unsigned char a24:1;
    unsigned char a25:1;
    unsigned char a26:1;
    unsigned char a27:1;
    unsigned char a28:1;
    unsigned char a29:1;
    unsigned char a30:1;
    unsigned char a31:1;

};

union bit_set
{
    uint32_t x;
    struct bit b;
};

int toggle_bit(uint32_t* pvalue, int b)
{
    if(pvalue==NULL)
        return -1;
    union bit_set p;
    p.x=*pvalue;
    if(b==0)
    {
        if(p.b.a0==0)
        {
            p.b.a0=1;
        }
        else
        {
            p.b.a0=0;
        }
        *pvalue=p.x;
    }
    else if(b==1)
    {
        if(p.b.a1==0)
        {
            p.b.a1=1;
        }
        else
        {
            p.b.a1=0;
        }
        *pvalue=p.x;
    }
    else if(b==2)
    {
        if(p.b.a2==0)
        {
            p.b.a2=1;
        }
        else
        {
            p.b.a2=0;
        }
        *pvalue=p.x;
    }
    else if(b==3)
    {
        if(p.b.a3==0)
        {
            p.b.a3=1;
        }
        else
        {
            p.b.a3=0;
        }
        *pvalue=p.x;
    }
    else if(b==4)
    {
        if(p.b.a4==0)
        {
            p.b.a4=1;
        }
        else
        {
            p.b.a4=0;
        }
        *pvalue=p.x;
    }
    else if(b==5)
    {
        if(p.b.a5==0)
        {
            p.b.a5=1;
        }
        else
        {
            p.b.a5=0;
        }
        *pvalue=p.x;
    }
    else if(b==6)
    {
        if(p.b.a6==0)
        {
            p.b.a6=1;
        }
        else
        {
            p.b.a6=0;
        }
        *pvalue=p.x;
    }
    else if(b==7)
    {
        if(p.b.a7==0)
        {
            p.b.a7=1;
        }
        else
        {
            p.b.a7=0;
        }
        *pvalue=p.x;
    }
    else if(b==8)
    {
        if(p.b.a8==0)
        {
            p.b.a8=1;
        }
        else
        {
            p.b.a8=0;
        }
        *pvalue=p.x;
    }
    else if(b==9)
    {
        if(p.b.a9==0)
        {
            p.b.a9=1;
        }
        else
        {
            p.b.a9=0;
        }
        *pvalue=p.x;
    }
    else if(b==10)
    {
        if(p.b.a10==0)
        {
            p.b.a10=1;
        }
        else
        {
            p.b.a10=0;
        }
        *pvalue=p.x;
    }
    else if(b==11)
    {
        if(p.b.a11==0)
        {
            p.b.a11=1;
        }
        else
        {
            p.b.a11=0;
        }
        *pvalue=p.x;
    }
    else if(b==12)
    {
        if(p.b.a12==0)
        {
            p.b.a12=1;
        }
        else
        {
            p.b.a12=0;
        }
        *pvalue=p.x;
    }
    else if(b==13)
    {
        if(p.b.a13==0)
        {
            p.b.a13=1;
        }
        else
        {
            p.b.a13=0;
        }
        *pvalue=p.x;
    }
    else if(b==14)
    {
        if(p.b.a14==0)
        {
            p.b.a14=1;
        }
        else
        {
            p.b.a14=0;
        }
        *pvalue=p.x;
    }
    else if(b==15)
    {
        if(p.b.a15==0)
        {
            p.b.a15=1;
        }
        else
        {
            p.b.a15=0;
        }
        *pvalue=p.x;
    }
    else if(b==16)
    {
        if(p.b.a16==0)
        {
            p.b.a16=1;
        }
        else
        {
            p.b.a16=0;
        }
        *pvalue=p.x;
    }
    else if(b==17)
    {
        if(p.b.a17==0)
        {
            p.b.a17=1;
        }
        else
        {
            p.b.a17=0;
        }
        *pvalue=p.x;
    }
    else if(b==18)
    {
        if(p.b.a18==0)
        {
            p.b.a18=1;
        }
        else
        {
            p.b.a18=0;
        }
        *pvalue=p.x;
    }
    else if(b==19)
    {
        if(p.b.a19==0)
        {
            p.b.a19=1;
        }
        else
        {
            p.b.a19=0;
        }
        *pvalue=p.x;
    }
    else if(b==20)
    {
        if(p.b.a20==0)
        {
            p.b.a20=1;
        }
        else
        {
            p.b.a20=0;
        }
        *pvalue=p.x;
    }
    else if(b==21)
    {
        if(p.b.a21==0)
        {
            p.b.a21=1;
        }
        else
        {
            p.b.a21=0;
        }
        *pvalue=p.x;
    }
    else if(b==22)
    {
        if(p.b.a22==0)
        {
            p.b.a22=1;
        }
        else
        {
            p.b.a22=0;
        }
        *pvalue=p.x;
    }
    else if(b==23)
    {
        if(p.b.a23==0)
        {
            p.b.a23=1;
        }
        else
        {
            p.b.a23=0;
        }
        *pvalue=p.x;
    }
    else if(b==24)
    {
        if(p.b.a24==0)
        {
            p.b.a24=1;
        }
        else
        {
            p.b.a24=0;
        }
        *pvalue=p.x;
    }
    else if(b==25)
    {
        if(p.b.a25==0)
        {
            p.b.a25=1;
        }
        else
        {
            p.b.a25=0;
        }
        *pvalue=p.x;
    }
    else if(b==26)
    {
        if(p.b.a26==0)
        {
            p.b.a26=1;
        }
        else
        {
            p.b.a26=0;
        }
        *pvalue=p.x;
    }
    else if(b==27)
    {
        if(p.b.a27==0)
        {
            p.b.a27=1;
        }
        else
        {
            p.b.a27=0;
        }
        *pvalue=p.x;
    }
    else if(b==28)
    {
        if(p.b.a28==0)
        {
            p.b.a28=1;
        }
        else
        {
            p.b.a28=0;
        }
        *pvalue=p.x;
    }
    else if(b==29)
    {
        if(p.b.a29==0)
        {
            p.b.a29=1;
        }
        else
        {
            p.b.a29=0;
        }
        *pvalue=p.x;
    }
    else if(b==30)
    {
        if(p.b.a30==0)
        {
            p.b.a30=1;
        }
        else
        {
            p.b.a30=0;
        }
        *pvalue=p.x;
    }
    else if(b==31)
    {
        if(p.b.a31==0)
        {
            p.b.a31=1;
        }
        else
        {
            p.b.a31=0;
        }
        *pvalue=p.x;
    }

    else
        return -1;
    return 0;
}
int set_bit(uint32_t* pvalue, int b)
{
    if(pvalue==NULL)
        return -1;
    union bit_set p;
    p.x=*pvalue;
    if(b==0)
    {
        p.b.a0=1;
        *pvalue=p.x;
    }
    else if(b==1)
    {
        p.b.a1=1;
        *pvalue=p.x;
    }
    else if(b==2)
    {
        p.b.a2=1;
        *pvalue=p.x;
    }
    else if(b==3)
    {
        p.b.a3=1;
        *pvalue=p.x;
    }
    else if(b==4)
    {
        p.b.a4=1;
        *pvalue=p.x;
    }
    else if(b==5)
    {
        p.b.a5=1;
        *pvalue=p.x;
    }
    else if(b==6)
    {
        p.b.a6=1;
        *pvalue=p.x;
    }
    else if(b==7)
    {
        p.b.a7=1;
        *pvalue=p.x;
    }
    else if(b==8)
    {
        p.b.a8=1;
        *pvalue=p.x;
    }
    else if(b==9)
    {
        p.b.a9=1;
        *pvalue=p.x;
    }
    else if(b==10)
    {
        p.b.a10=1;
        *pvalue=p.x;
    }
    else if(b==11)
    {
        p.b.a11=1;
        *pvalue=p.x;
    }
    else if(b==12)
    {
        p.b.a12=1;
        *pvalue=p.x;
    }
    else if(b==13)
    {
        p.b.a13=1;
        *pvalue=p.x;
    }
    else if(b==14)
    {
        p.b.a14=1;
        *pvalue=p.x;
    }
    else if(b==15)
    {
        p.b.a15=1;
        *pvalue=p.x;
    }
    else if(b==16)
    {
        p.b.a16=1;
        *pvalue=p.x;
    }
    else if(b==17)
    {
        p.b.a17=1;
        *pvalue=p.x;
    }
    else if(b==18)
    {
        p.b.a18=1;
        *pvalue=p.x;
    }
    else if(b==19)
    {
        p.b.a19=1;
        *pvalue=p.x;
    }
    else if(b==20)
    {
        p.b.a20=1;
        *pvalue=p.x;
    }
    else if(b==21)
    {
        p.b.a21=1;
        *pvalue=p.x;
    }
    else if(b==22)
    {
        p.b.a22=1;
        *pvalue=p.x;
    }
    else if(b==23)
    {
        p.b.a23=1;
        *pvalue=p.x;
    }
    else if(b==24)
    {
        p.b.a24=1;
        *pvalue=p.x;
    }
    else if(b==25)
    {
        p.b.a25=1;
        *pvalue=p.x;
    }
    else if(b==26)
    {
        p.b.a26=1;
        *pvalue=p.x;
    }
    else if(b==27)
    {
        p.b.a27=1;
        *pvalue=p.x;
    }
    else if(b==28)
    {
        p.b.a28=1;
        *pvalue=p.x;
    }
    else if(b==29)
    {
        p.b.a29=1;
        *pvalue=p.x;
    }
    else if(b==30)
    {
        p.b.a30=1;
        *pvalue=p.x;
    }
    else if(b==31)
    {
        p.b.a31=1;
        *pvalue=p.x;
    }
    else
        return -1;
    return 0;
}
int clear_bit(uint32_t* pvalue, int b)
{

    if(pvalue==NULL)
        return -1;
    union bit_set p;
    p.x=*pvalue;
    if(b==0)
    {
        p.b.a0=0;
        *pvalue=p.x;
    }
    else if(b==1)
    {
        p.b.a1=0;
        *pvalue=p.x;
    }
    else if(b==2)
    {
        p.b.a2=0;
        *pvalue=p.x;
    }
    else if(b==3)
    {
        p.b.a3=0;
        *pvalue=p.x;
    }
    else if(b==4)
    {
        p.b.a4=0;
        *pvalue=p.x;
    }
    else if(b==5)
    {
        p.b.a5=0;
        *pvalue=p.x;
    }
    else if(b==6)
    {
        p.b.a6=0;
        *pvalue=p.x;
    }
    else if(b==7)
    {
        p.b.a7=0;
        *pvalue=p.x;
    }
    else if(b==8)
    {
        p.b.a8=0;
        *pvalue=p.x;
    }
    else if(b==9)
    {
        p.b.a9=0;
        *pvalue=p.x;
    }
    else if(b==10)
    {
        p.b.a10=0;
        *pvalue=p.x;
    }
    else if(b==11)
    {
        p.b.a11=0;
        *pvalue=p.x;
    }
    else if(b==12)
    {
        p.b.a12=0;
        *pvalue=p.x;
    }
    else if(b==13)
    {
        p.b.a13=0;
        *pvalue=p.x;
    }
    else if(b==14)
    {
        p.b.a14=0;
        *pvalue=p.x;
    }
    else if(b==15)
    {
        p.b.a15=0;
        *pvalue=p.x;
    }
    else if(b==16)
    {
        p.b.a16=0;
        *pvalue=p.x;
    }
    else if(b==17)
    {
        p.b.a17=0;
        *pvalue=p.x;
    }
    else if(b==18)
    {
        p.b.a18=0;
        *pvalue=p.x;
    }
    else if(b==19)
    {
        p.b.a19=0;
        *pvalue=p.x;
    }
    else if(b==20)
    {
        p.b.a20=0;
        *pvalue=p.x;
    }
    else if(b==21)
    {
        p.b.a21=0;
        *pvalue=p.x;
    }
    else if(b==22)
    {
        p.b.a22=0;
        *pvalue=p.x;
    }
    else if(b==23)
    {
        p.b.a23=0;
        *pvalue=p.x;
    }
    else if(b==24)
    {
        p.b.a24=0;
        *pvalue=p.x;
    }
    else if(b==25)
    {
        p.b.a25=0;
        *pvalue=p.x;
    }
    else if(b==26)
    {
        p.b.a26=0;
        *pvalue=p.x;
    }
    else if(b==27)
    {
        p.b.a27=0;
        *pvalue=p.x;
    }
    else if(b==28)
    {
        p.b.a28=0;
        *pvalue=p.x;
    }
    else if(b==29)
    {
        p.b.a29=0;
        *pvalue=p.x;
    }
    else if(b==30)
    {
        p.b.a30=0;
        *pvalue=p.x;
    }
    else if(b==31)
    {
        p.b.a31=0;
        *pvalue=p.x;
    }
    else
        return -1;
    return 0;
}
int isset_bit(const uint32_t* pvalue, int b)
{

    if(pvalue==NULL)
        return -1;
    union bit_set p;
    p.x=*pvalue;
    if(b==0)
    {
        return p.b.a0;
    }
    else if(b==1)
    {
        return p.b.a1;
    }
    else if(b==2)
    {
        return p.b.a2;
    }
    else if(b==3)
    {
        return p.b.a3;
    }
    else if(b==4)
    {
        return p.b.a4;
    }
    else if(b==5)
    {
        return p.b.a5;
    }
    else if(b==6)
    {
        return p.b.a6;
    }
    else if(b==7)
    {
        return p.b.a7;
    }
    else if(b==8)
    {
        return p.b.a8;
    }
    else if(b==9)
    {
        return p.b.a9;
    }
    else if(b==10)
    {
        return p.b.a10;
    }
    else if(b==11)
    {
        return p.b.a11;
    }
    else if(b==12)
    {
        return p.b.a12;
    }
    else if(b==13)
    {
        return p.b.a13;
    }
    else if(b==14)
    {
        return p.b.a14;
    }
    else if(b==15)
    {
        return p.b.a15;
    }
    else if(b==16)
    {
        return p.b.a16;
    }
    else if(b==17)
    {
        return p.b.a17;
    }
    else if(b==18)
    {
        return p.b.a18;
    }
    else if(b==19)
    {
        return p.b.a19;
    }
    else if(b==20)
    {
        return p.b.a20;
    }
    else if(b==21)
    {
        return p.b.a21;;
    }
    else if(b==22)
    {
        return p.b.a22;
    }
    else if(b==23)
    {
        return p.b.a23;
    }
    else if(b==24)
    {
        return p.b.a24;
    }
    else if(b==25)
    {
        return p.b.a25;
    }
    else if(b==26)
    {
        return p.b.a26;
    }
    else if(b==27)
    {
        return p.b.a27;
    }
    else if(b==28)
    {
        return p.b.a28;
    }
    else if(b==29)
    {
       return p.b.a29;
    }
    else if(b==30)
    {
        return p.b.a30;
    }
    else if(b==31)
    {
        return p.b.a31;
    }
    else
        return -1;
    return 0;
}
int main()
{
    uint32_t a;
    int b,w,t,u;
    printf("Daj: ");
    t=scanf("%u",&a);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Daj: ");
    t=scanf("%d",&b);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(b<0||b>31)
    {
        printf("Invalid bit index");
        return 2;
    }
    printf("Daj: ");
    t=scanf("%d",&w);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(w<0||w>3)
    {
        printf("Invalid operation");
        return 2;
    }
    if(w==0)
    {
        toggle_bit(&a,b);
        printf("%x",a);
    }
    if(w==1)
    {
        set_bit(&a,b);
        printf("%x",a);
    }
    if(w==2)
    {
        clear_bit(&a,b);
        printf("%x",a);
    }
    if(w==3)
    {
        u=isset_bit(&a,b);
        printf("%d",u);
    }
    return 0;
}

