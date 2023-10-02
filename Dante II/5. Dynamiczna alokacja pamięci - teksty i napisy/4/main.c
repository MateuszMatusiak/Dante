#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

int ctoi(char x) {
    switch (x) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case '-':
            return 0;
        default:
            return 10;
    }
}
int isdigitx(char x) {
    switch (x) {
        case '0':
            return 1;
        case '1':
            return 1;
        case '2':
            return 1;
        case '3':
            return 1;
        case '4':
            return 1;
        case '5':
            return 1;
        case '6':
            return 1;
        case '7':
            return 1;
        case '8':
            return 1;
        case '9':
            return 1;
        default:
            return 0;
    }
}
int validate(const char *number) {
    int i = 0, c = 0;
    if (number == NULL)
        return -1;
    if (strlen(number) == 0)
        return 2;
    if (*number == '0' && (strlen(number) < 2)) {
        return 0;
    }

    if (*(number + strlen(number) - 1) == '\n')
        return 2;
    if (strlen(number) < 5)
        if (atol(number) == 0)
            return 2;

    if (*number == '-' && strlen(number) > 1)
        ++i;
    while (*(number + i) != '\0') {
        if (c == 1)
            return 2;
        if (!isdigitx(*(number + i))) {
            return 2;
        }
        if (i == 0 && *number == '0')
            c = 1;
        i++;
    }
    return 0;
}
int comp(const char *number1, const char *number2)
{
    int l1= strlen(number1);
    l1--;
    int l2= strlen(number2);
    l2--;


    if(l1==l2)
    {
        if(*number1=='-'&&*number2!='-')
            return -1;
        if(*number2=='-'&&*number1!='-')
            return 1;
    }
    if(l1>l2) {
        if(l1==l2+1) {
            if (*number1 != '-') {
                return 1;
            }
        }
        else
            return 1;

    }
    if(l2>l1) {
        if(l2==l1+1) {
            if (*number2 != '-') {
                return -1;
            }
        }
        else
            return -1;

    }
    int sz=l1>l2?l1:l2;
    int x1=0, x2=0;
    if(*number1=='-')
        x1++;
    if(*number2=='-')
        x2++;
    for(int i=0;i<sz+1;++i)
    {
        if(ctoi(*(number1+x1))>ctoi(*(number2+x2)))
        {
            return 1;
        }
        else if(ctoi(*(number1+x1))<ctoi(*(number2+x2)))
        {
            return -1;
        }
        x1++;
        x2++;
    }
    return 0;
}
int compare(const char *number1, const char *number2) {
    if (number1 == NULL || number2 == NULL)
        return 2;
    if (validate(number1) || validate(number2))
        return 3;

    if(*number1!='-'&&*number2=='-')
        return 1;
    else if(*number1=='-'&&*number2!='-')
        return -1;
    else if(*number1=='-'&&*number2=='-') {
        int a = comp(number1, number2);
        if(a==1)
            return -1;
        else if(a==-1)
            return 1;
        else
            return 0;
    }
    else return comp(number1, number2);
    return 0;
}
void reduktor(char** result)
{
    if(strlen(*result)==1)
        return;
    int i=0;
    int m=0;
    if(**result=='-')
        m=1;
    while(*(*result+i)=='0'||*(*result+i)=='-')
    {
        i++;
    }
    int sz= (int)strlen(*result)-i;
    int k=0;
    if(m==1)
    {
        *(*result+k)='-';
        ++k;
        ++sz;
    }
    for(;k< sz;++k){

        *(*result+k)=*(*result+i);
        ++i;
    }
    *(*result+sz)='\0';

}
void wm(char* xd)
{
    int i=0;
    while(*(xd+i)=='-')
    {
        i++;
    }
    int sz= (int)strlen(xd)-i;
    int k=0;
    for(;k< sz;++k){

        *(xd+k)=*(xd+i);
        ++i;
    }
    *(xd+sz)='\0';
}
int add(const char *number1, const char *number2, char **result) {
    if (number1 == NULL || number2 == NULL || result == NULL)
        return 1;
    if (validate(number1) != 0 || validate(number2) != 0)
        return 2;
    if (*number1 != '-' && *number2 != '-') {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        sz++;
        *result = (char *) calloc((sz+1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result,'0',sz);
        *(*result+sz)='\0';
        l1--;
        l2--;
        int x=0,d=0;
        sz--;
        for (; sz >= 0; --sz) {
            x = 0;
            if (d == 1)
            {
                d=0;
                x=1;
            }
            if (l1 >= 0) {
                x+=ctoi(*(number1+l1));
            }
            if (l2 >= 0) {
                x+=ctoi(*(number2+l2));
            }
            if(x>=10)
            {
                d=1;
                x-=10;
            }
            *(*result+sz)=x+'0';
            --l1;
            --l2;
        }
        if(d==1)
        {
            *(*result+sz)='1';
        }

    }
    else if (*number1 == '-' && *number2 != '-') {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        *result = (char *) calloc((sz+1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result,'0',sz);
        *(*result+sz)='\0';
        l1--;
        l2--;
        int x=0,d=0;
        sz--;

        if(comp(number1,number2)==1)
        {
            for(;sz>=0;--sz)
            {
                x=0;
                if(d==1)
                {
                    x--;
                    d=0;
                }
                if(l1>=0)
                {
                    x+=ctoi(*(number1+l1));
                }
                if(l2>=0)
                {
                    x-=ctoi(*(number2+l2));
                }
                if(x<0) {
                    d = 1;
                    x+=10;
                }
                *(*result+sz)=x+'0';
                --l1;
                --l2;

            }
            *(*result)='-';
        }
        else if(comp(number1,number2)==-1)
        {
            for(;sz>=0;--sz)
            {
                x=0;
                if(d==1)
                {
                    x--;
                    d=0;
                }
                if(l1>=0)
                {
                    x-=ctoi(*(number1+l1));
                }
                if(l2>=0)
                {
                    x+=ctoi(*(number2+l2));
                }
                if(x<0) {
                    d = 1;
                    x+=10;
                }
                *(*result+sz)=x+'0';
                --l1;
                --l2;

            }
        }
        else {
            *(*result)='0';
            *(*result+1)='\0';
            return 0;
        }

    }
    else if (*number1 != '-' && *number2 == '-') {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        sz++;
        *result = (char *) calloc((sz+1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result,'0',sz);
        *(*result+sz)='\0';
        l1--;
        l2--;
        int x=0,d=0;
        sz--;

        if(comp(number1,number2)==1)
        {
            for(;sz>=0;--sz)
            {
                x=0;
                if(d==1)
                {
                    x--;
                    d=0;
                }
                if(l1>=0)
                {
                    x+=ctoi(*(number1+l1));
                }
                if(l2>=0)
                {
                    x-=ctoi(*(number2+l2));
                }
                if(x<0) {
                    d = 1;
                    x+=10;
                }
                *(*result+sz)=x+'0';
                --l1;
                --l2;

            }

        }
        else if(comp(number1,number2)==-1)
        {
            for(;sz>=0;--sz)
            {
                x=0;
                if(d==1)
                {
                    x--;
                    d=0;
                }
                if(l2>=0)
                {
                    x+=ctoi(*(number2+l2));
                }
                if(l1>=0)
                {
                    x-=ctoi(*(number1+l1));
                }

                if(x<0) {
                    d = 1;
                    x+=10;
                }
                *(*result+sz)=x+'0';
                --l1;
                --l2;

            }
            *(*result)='-';
        }
        else {
            *(*result)='0';
            *(*result+1)='\0';
            return 0;
        }

    }
    else if (*number1 == '-' && *number2 == '-') {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        sz++;
        *result = (char *) calloc((sz+1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result,'0',sz);
        *(*result+sz)='\0';
        l1--;
        l2--;
        int x=0,d=0;
        sz--;
        for (; sz >= 0; --sz) {
            x = 0;
            if (d == 1)
            {
                d=0;
                x=1;
            }
            if (l1 >= 0) {
                x+=ctoi(*(number1+l1));
            }
            if (l2 >= 0) {
                x+=ctoi(*(number2+l2));
            }
            if(x>=10)
            {
                d=1;
                x-=10;
            }
            *(*result+sz)=x+'0';
            --l1;
            --l2;
        }
        if(d==1)
        {
            *(*result+sz)='1';
        }
        **result='-';

    }
    reduktor(result);
    return 0;
}
int subtract(const char *number1, const char *number2, char **result) {
    if (number1 == NULL || number2 == NULL || result == NULL)
        return 1;
    if (validate(number1) != 0 || validate(number2) != 0)
        return 2;
    if(*number1!='-'&&*number2!='-')
    {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        sz++;
        *result = (char *) calloc((sz+1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result,'0',sz);
        *(*result+sz)='\0';
        l1--;
        l2--;
        int x=0,d=0;
        sz--;

        if(comp(number1,number2)==1)
        {
            for(;sz>=0;--sz)
            {
                x=0;
                if(d==1)
                {
                    x--;
                    d=0;
                }
                if(l1>=0)
                {
                    x+=ctoi(*(number1+l1));
                }
                if(l2>=0)
                {
                    x-=ctoi(*(number2+l2));
                }
                if(x<0) {
                    d = 1;
                    x+=10;
                }
                *(*result+sz)=x+'0';
                --l1;
                --l2;

            }

        }
        else if(comp(number1,number2)==-1)
        {
            for(;sz>=0;--sz)
            {
                x=0;
                if(d==1)
                {
                    x--;
                    d=0;
                }
                if(l2>=0)
                {
                    x+=ctoi(*(number2+l2));
                }
                if(l1>=0)
                {
                    x-=ctoi(*(number1+l1));
                }

                if(x<0) {
                    d = 1;
                    x+=10;
                }
                *(*result+sz)=x+'0';
                --l1;
                --l2;

            }
            *(*result)='-';
        }
        else{
            *(*result)='0';
            *(*result+1)='\0';
            return 0;
        }

    }
    else if(*number1=='-'&&*number2=='-')
    {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        *result = (char *) calloc((sz+1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result,'0',sz);
        *(*result+sz)='\0';
        l1--;
        l2--;
        int x=0,d=0;
        sz--;

        if(comp(number1,number2)==1)
        {
            for(;sz>=0;--sz)
            {
                x=0;
                if(d==1)
                {
                    x--;
                    d=0;
                }
                if(l1>=0)
                {
                    x+=ctoi(*(number1+l1));
                }
                if(l2>=0)
                {
                    x-=ctoi(*(number2+l2));
                }
                if(x<0) {
                    d = 1;
                    x+=10;
                }
                *(*result+sz)=x+'0';
                --l1;
                --l2;

            }
            *(*result)='-';
        }
        else if(comp(number1,number2)==-1)
        {
            for(;sz>=0;--sz)
            {
                x=0;
                if(d==1)
                {
                    x--;
                    d=0;
                }
                if(l1>=0)
                {
                    x-=ctoi(*(number1+l1));
                }
                if(l2>=0)
                {
                    x+=ctoi(*(number2+l2));
                }
                if(x<0) {
                    d = 1;
                    x+=10;
                }
                *(*result+sz)=x+'0';
                --l1;
                --l2;

            }
        }
        else {
            *(*result)='0';
            *(*result+1)='\0';
            return 0;
        }

    }
    else if(*number1=='-'&&*number2!='-')
    {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        sz++;
        sz++;
        *result = (char *) calloc((sz+1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result,'0',sz);
        *(*result+sz)='\0';
        l1--;
        l2--;
        int x=0,d=0;
        sz--;
        for (; sz >= 0; --sz) {
            x = 0;
            if (d == 1)
            {
                d=0;
                x=1;
            }
            if (l1 >= 0) {
                x+=ctoi(*(number1+l1));
            }
            if (l2 >= 0) {
                x+=ctoi(*(number2+l2));
            }
            if(x>=10)
            {
                d=1;
                x-=10;
            }
            *(*result+sz)=x+'0';
            --l1;
            --l2;
        }
        if(d==1)
        {
            *(*result+sz)='1';
        }
        **result='-';


    }
    else if(*number1!='-'&&*number2=='-')
    {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        sz++;
        *result = (char *) calloc((sz+1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result,'0',sz);
        *(*result+sz)='\0';
        l1--;
        l2--;
        int x=0,d=0;
        sz--;
        for (; sz >= 0; --sz) {
            x = 0;
            if (d == 1)
            {
                d=0;
                x=1;
            }
            if (l1 >= 0) {
                x+=ctoi(*(number1+l1));
            }
            if (l2 >= 0) {
                x+=ctoi(*(number2+l2));
            }
            if(x>=10)
            {
                d=1;
                x-=10;
            }
            *(*result+sz)=x+'0';
            --l1;
            --l2;
        }
        if(d==1)
        {
            *(*result+sz)='1';
        }

    }
    reduktor(result);
    return 0;
}

int main() {
    char* number1=(char*) calloc(201,sizeof(char));
    if(number1== NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    char* number2=(char*) calloc(201,sizeof(char));
    if(number2== NULL)
    {
        free(number1);
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj:");
    scanf("%200[^\n]",number1);
    while (getchar () != '\n' );
    printf("Daj:");
    scanf("%200[^\n]",number2);

    char* res;
    char* res2;
    int t=add(number1,number2,&res);
    if(t==1||t==2)
    {
        printf("Incorrect input");
        free(number1);
        free(number2);
        return 1;
    }
    if(t==3)
    {
        printf("Failed to allocate memory");
        free(number1);
        free(number2);
        return 8;
    }

    t=subtract(number1,number2,&res2);
    if(t==1||t==2)
    {
        printf("Incorrect input");
        free(number1);
        free(number2);
        free(res);
        return 1;
    }
    if(t==3)
    {
        printf("Failed to allocate memory");
        free(number1);
        free(number2);
        free(res);
        return 8;
    }
    printf("%s\n",res);
    printf("%s",res2);
    free(number1);
    free(number2);
    free(res);
    free(res2);
    return 0;
}


