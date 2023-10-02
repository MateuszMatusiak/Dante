#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct point_t {
    int x;
    int y;
};

int my_printf(char *txt, ...) {
    int i = 0, w = 0;
    va_list ap;
    va_start(ap, txt);
    while (*(txt + i) != '\0') {
        if (*(txt + i) == '%') {
            ++i;
            if (*(txt + i) == 's') {
                char *t = va_arg(ap, char*);
                int k = 0;
                while (*(t + k) != '\0') {
                    putchar(*(t + k));
                    ++k;
                }
                w += k;
            } else if (*(txt + i) == 'd') {
                int t = va_arg(ap, int);
                if (t == 0) {
                    w++;
                    putchar('0');
                    ++i;
                    continue;
                }

                int nb = t;
                int k = 0;
                int p = 0;
                if (nb < 0) {
                    putchar('-');
                    nb *= -1;
                    w++;
                }
                if(nb/10>0)
                {
                    p += nb % 10;
                    nb /= 10;
                    k++;
                    while (nb >= 10) {

                        p *= 10;
                        p += nb % 10;
                        nb /= 10;
                        k++;
                    }
                    w += k;
                }
                w++;
                putchar(nb % 10 + '0');
                for (int o = 0; o < k; ++o) {
                    putchar(p % 10 + '0');
                    p /= 10;
                }

            } else if (*(txt + i) == 'f') {
                double t = va_arg(ap, double);
                int nb = (int) t;
                int y = nb;
                int p = 0;
                int k = 0;
                if (nb < 0) {
                    putchar('-');
                    nb *= -1;
                    w++;
                }
                if (nb != 0) {
                    if(nb/10>0)
                    {
                        p += nb % 10;
                        nb /= 10;
                        k++;
                        while (nb >= 10) {

                            p *= 10;
                            p += nb % 10;
                            nb /= 10;
                            k++;
                        }
                        w += k;
                    }
                    w++;
                    putchar(nb % 10 + '0');
                    for (int o = 0; o < k; ++o) {
                        putchar(p % 10 + '0');
                        p /= 10;
                    }
                } else {
                    putchar('0');
                    w++;
                }
                putchar('.');
                w++;
                t -= (double) y;

                if (t < 0) {
                    t *= -1;
                }
                for(int o=0;o<5;++o)
                {
                    putchar((((int)(t*=10))%10)+'0');
                    w++;
                }




            } else if (*(txt + i) == 'p') {
                struct point_t t = va_arg(ap, struct point_t);
                putchar('(');
                w++;
                int nb = t.x;
                int p = 0;
                int k = 0;
                if (nb < 0) {
                    putchar('-');
                    nb *= -1;
                    w++;
                }
                if (nb != 0) {
                    if(nb/10>0)
                    {
                        p += nb % 10;
                        nb /= 10;
                        k++;
                        while (nb >= 10) {
                            p *= 10;
                            p += nb % 10;
                            nb /= 10;
                            k++;
                        }
                        w += k;
                    }
                    w++;
                    putchar(nb % 10 + '0');
                    for (int o = 0; o < k; ++o) {
                        putchar(p % 10 + '0');
                        p /= 10;
                    }
                } else {
                    putchar('0');
                    w++;
                }

                putchar(' ');
                w++;
                nb = t.y;
                if (nb != 0) {
                    p = 0;
                    k = 0;
                    if (nb < 0) {
                        putchar('-');
                        nb *= -1;
                        w++;
                    }
                    if(nb/10>0)
                    {
                        p += nb % 10;
                        nb /= 10;
                        k++;
                        while (nb >= 10) {

                            p *= 10;
                            p += nb % 10;
                            nb /= 10;
                            k++;
                        }
                        w += k;
                    }
                    w++;
                    putchar(nb % 10 + '0');
                    for (int o = 0; o < k; ++o) {
                        putchar(p % 10 + '0');
                        p /= 10;
                    }
                } else {
                    putchar('0');
                    w++;
                }
                w++;
                putchar(')');
            } else {
                putchar(*(txt + i));
                w++;
            }
        } else {
            putchar(*(txt + i));
            w++;
        }
        ++i;
    }
    va_end(ap);
    return w;
}

int my_scanf(char *txt, ...) {
    int i=0,w=0;
    va_list ap;
    va_start(ap, txt);
    int f=1;
    char ch;
    while(*(txt+i)!='\0')
    {
        if(f)
            ch=getchar();
        if(*(txt+i)=='%')
        {
            ++i;
            if(*(txt+i)=='d')
            {
                f=1;
                int *t= va_arg(ap,int*);
                int m=0;
                int x=0;
                int k=0;
                while(isdigit(ch)||ch=='-')
                {
                    if(ch=='-') {
                        if(k!=0)
                            return w;
                        m = 1;
                        ch=getchar();
                        continue;
                    }
                    x+=ch-'0';
                    ++k;
                    ch=getchar();
                    if(!isdigit(ch)) {
                        f=0;
                        break;
                    }
                    x*=10;
                }
                if(k==0)
                    return w;
                if(m)
                    x*=-1;
                *t=x;
                w++;
            }
            else if(*(txt+i)=='f')
            {
                f=1;
                double *t= va_arg(ap,double*);
                int m=0;
                double x=0;
                int k=0;
                while(isdigit(ch)||ch=='-')
                {
                    if(ch=='-') {
                        if(k!=0)
                            return w;
                        m = 1;
                        ch=getchar();
                        continue;
                    }
                    x+=ch-'0';
                    ++k;
                    ch=getchar();
                    if(!isdigit(ch))
                        break;
                    x*=10;
                }
                if(k==0)
                    return w;

                if(ch=='.')
                {
                    k=10;
                    ch=getchar();
                    if(!isdigit(ch))
                        return w;
                    while(isdigit(ch))
                    {
                        x+=(double)((double)(ch-'0')/(double)k);
                        k*=10;
                        ch=getchar();
                    }
                    f=0;
                }

                if(m)
                    x*=-1;
                *t=x;
                w++;
            }
            else if(*(txt+i)=='p')
            {
                f=1;
                struct point_t* t = va_arg(ap, struct point_t*);
                int m=0;
                int x=0;
                int k=0;
                if(ch!='(')
                    return w;
                ch=getchar();
                while(isdigit(ch)||ch=='-')
                {
                    if(ch=='-') {
                        if(k!=0)
                            return w;
                        m = 1;
                        ch=getchar();
                        continue;
                    }
                    x+=ch-'0';
                    ++k;
                    ch=getchar();
                    if(!isdigit(ch))
                        break;
                    x*=10;
                }
                if(k==0)
                    return w;
                if(m)
                    x*=-1;
                t->x=x;
                m=0;
                x=0;
                k=0;


                if(ch!=' ')
                    return w;
                ch=getchar();
                while(isdigit(ch)||ch=='-')
                {
                    if(ch=='-') {
                        if(k!=0)
                            return w;
                        m = 1;
                        ch=getchar();
                        continue;
                    }
                    x+=ch-'0';
                    ++k;
                    ch=getchar();
                    if(!isdigit(ch))
                        break;
                    x*=10;
                }
                if(k==0)
                    return w;
                if(m)
                    x*=-1;
                t->y=x;

                if(ch!=')')
                    return w;
                w+=2;
            }
        }
        else{
            f=1;
            if(ch!=*(txt+i))
                return w;
        }
        ++i;
    }
    va_end(ap);
    return w;
}

int main() {
    return 0;
}

