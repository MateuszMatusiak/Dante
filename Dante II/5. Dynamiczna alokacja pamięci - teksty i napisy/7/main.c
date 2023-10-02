#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "big_numbers.h"
#include "tested_declarations.h"
#include "rdebug.h"

int multiply(const char *number1, const char *number2, char **result) {
    if (number1 == NULL || number2 == NULL || result == NULL) {
        return 1;
    }
    if(validate(number1)!=0|| validate(number2)!=0) {
        return 2;
    }
    int l1=strlen(number1);
    int l2=strlen(number2);
    int l3=l1+l2+2;
    int l4=l3;
    char* xd=(char*)calloc(l3,sizeof(char));
    if(xd==NULL)
    {
        return 3;
    }
    char* xd1=(char*)calloc(l4,sizeof(char));
    if(xd1==NULL)
    {
        free(xd);
        return 3;
    }
    char* xd2=(char*)calloc(l4,sizeof(char));
    if(xd2==NULL)
    {
        free(xd);
        free(xd1);
        return 3;
    }
    memset(xd,'0',sizeof(char)*l3);
    memset(xd1,'0',sizeof(char)*l4);
    memset(xd2,'0',sizeof(char)*l4);
    l3--;
    l4--;
    *(xd+l3)='\0';
    *(xd1+l4)='\0';
    *(xd2+l4)='\0';
    l3--;
    l4--;

    l1--;
    l2--;
    int ml=l1<l2?l1:l2;
    int s3=l3;

    int d=0;

    if(l1>l2)
    {
        for(int k=l1;k>=0;--k)
        {
            int n1=(ctoi(*(number1+k)));
            int n2=(ctoi(*(number2+ml)));
            int x=(n2 * n1)+d;
            if(x>=10)
            {
                d=x/10;
                x=x%10;
            }
            else
            {
                d=0;
            }
            *(xd+l3)=x+'0';
            l3--;
        }
        if(d>0)
        {
            *(xd+l3)=d+'0';
            d=0;
        }
    }
    else
    {
        for(int k=l2;k>=0;--k)
        {
            int n1=(ctoi(*(number2+k)));
            int n2=(ctoi(*(number1+ml)));
            int x=(n2 * n1)+d;
            if(x>=10)
            {
                d=x/10;
                x=x%10;
            }
            else
                d=0;
            *(xd+l3)=x+'0';
            l3--;
        }
        if(d>0)
        {
            *(xd+l3)=d+'0';
            d=0;
        }
    }
    l3=--s3;



    for(int i=ml-1;i>=0;--i)
    {
        if(l1>l2)
        {
            for(int k=l1;k>=0;--k)
            {
                int n1=(ctoi(*(number1+k)));
                int n2=(ctoi(*(number2+i)));
                int x=(n2 * n1)+d;
                if(x>=10)
                {
                    d=x/10;
                    x=x%10;
                }
                else
                    d=0;
                *(xd1+l3)=x+'0';
                l3--;
            }
            if(d>0)
            {
                *(xd1+l3)=d+'0';
                d=0;
            }

        }
        else
        {
            for(int k=l2;k>=0;--k)
            {
                int n1=(ctoi(*(number1+i)));
                int n2=(ctoi(*(number2+k)));
                int x=(n2 * n1)+d;
                if(x>=10)
                {
                    d=x/10;
                    x=x%10;
                }
                else
                    d=0;
                *(xd1+l3)=x+'0';
                l3--;
            }
            if(d>0)
            {
                *(xd1+l3)=d+'0';
                d=0;
            }

        }
        strcpy(xd2,xd);
        free(xd);
        reduktor(&xd1);
        reduktor(&xd2);
        if(*xd1=='0'|| strcmp(xd1, "")==0)
        {
            xd=(char*)calloc(strlen(xd2)+1,sizeof(char));
            if(xd==NULL)
            {
                free(xd1);
                free(xd2);
                return 3;
            }
            strcpy(xd,xd2);
        }
        else if(*xd2=='0' || strcmp(xd2, "")==0)
        {
            xd=(char*)calloc(strlen(xd1)+1,sizeof(char));
            if(xd==NULL)
            {
                free(xd1);
                free(xd2);
                return 3;
            }
            strcpy(xd,xd1);
        }
        else{
            int t= add(xd1,xd2,&xd);
            if(t==1)
            {
                free(xd1);
                free(xd2);
                return 1;
            }
            if(t==2)
            {
                free(xd1);
                free(xd2);
                return 2;
            }
            if(t==3)
            {
                free(xd1);
                free(xd2);
                return 3;
            }
        }
        memset(xd1,'0',sizeof(char)*(l4+1));
        memset(xd2,'0',sizeof(char)*(l4+1));
        *(xd1+l4+1)='\0';
        *(xd2+l4+1)='\0';
        l3=--s3;
    }

    reduktor(&xd);
    if(strcmp(xd, "")==0)
    {
        free(xd);
        free(xd1);
        free(xd2);
        xd=(char*)calloc(2,sizeof(char));
        if(xd==NULL)
        {
            return 3;
        }
        strcpy(xd,"0\0");
        *result=xd;
        return 0;
    }

    if((*number1=='-'&&*number2!='-')||(*number1!='-'&&*number2=='-')) {
        strcpy(xd1,xd);
        reduktor(&xd1);
        free(xd);
        xd=(char*)calloc(strlen(xd1)+2,sizeof(char));
        if(xd==NULL)
        {
            free(xd1);
            free(xd2);
            return 3;
        }
        *xd = '-';
        strcat(xd,xd1);
        strcat(xd,"\0");
    }

    free(xd1);
    free(xd2);
    *result=xd;
    return 0;
}

int validate_expression(const char *expr) {
    if(expr==NULL)
        return 2;
    int i=0,k=0;
    if(*expr=='-')
        ++i;
    int x=strlen(expr);
    while(*(expr+i)!='\0')
    {
        while ((*(expr + i) != '+') && (*(expr + i) != '-') && (*(expr + i) != '*') && (*(expr + i) != '\0')) {
            ++i;
        }
        if(i==k)
        {
            ++i;
            while ((*(expr + i) != '+') && (*(expr + i) != '-') && (*(expr + i) != '*') && (*(expr + i) != '\0')) {
                ++i;
            }
        }
        char *xd = (char *) calloc(i-k + 1, sizeof(char));
        if (xd == NULL) {
            return 1;
        }
        if (strncpy(xd, expr+k, i-k) == NULL) {
            free(xd);
            return 1;
        }
        strcat(xd, "\0");
        if (validate(xd) != 0) {
            free(xd);
            return 1;
        }
        free(xd);

        if(x==i)
            break;
        i++;
        k=i;
    }
    if(validate(expr+x-1)!=0)
    {
        return 1;
    }
return 0;
}

int calculate(const char *expr, char **result) {
    if(expr==NULL||result==NULL)
        return 1;
    *result = (char *) calloc(2, sizeof(char));
    if (*result == NULL) {
        return 3;
    }
    free(*result);
    if(validate_expression(expr)!=0)
        return 2;

    int i=0,k=0;
    if(*expr=='-')
        ++i;
    int x=strlen(expr);

    while ((*(expr + i) != '+') && (*(expr + i) != '-') && (*(expr + i) != '*') && (*(expr + i) != '\0')) {
        ++i;
    }
    if(i==k)
    {
        ++i;
        while ((*(expr + i) != '+') && (*(expr + i) != '-') && (*(expr + i) != '*') && (*(expr + i) != '\0')) {
            ++i;
        }
    }
    *result = (char *) calloc(i-k + 1, sizeof(char));
    if (*result == NULL) {
        return 3;
    }
    if (strncpy(*result, expr+k, i-k) == NULL) {
        free(*result);
        return 1;
    }
    strcat(*result, "\0");
    char op=*(expr+i);
    i++;
    k=i;



    while(*(expr+i)!='\0')
    {
        while ((*(expr + i) != '+') && (*(expr + i) != '-') && (*(expr + i) != '*') && (*(expr + i) != '\0')) {
            ++i;
        }
        if(i==k)
        {
            ++i;
            while ((*(expr + i) != '+') && (*(expr + i) != '-') && (*(expr + i) != '*') && (*(expr + i) != '\0')) {
                ++i;
            }
        }
        char *xd = (char *) calloc(i-k + 1, sizeof(char));
        if (xd == NULL) {
            free(*result);
            return 3;
        }
        if (strncpy(xd, expr+k, i-k) == NULL) {
            free(xd);
            free(*result);
            return 1;
        }
        strcat(xd, "\0");

        char* n=(char*)calloc(strlen(*result)+1,sizeof(char));
        if(n==NULL)
        {
            free(xd);
            free(*result);
            return 3;
        }
        strcpy(n,*result);
        strcat(n,"\0");
        free(*result);
        if(op=='+')
        {
            int t=add(n,xd,result);
            if(t==1)
            {
                free(n);
                free(xd);
                return 1;
            }
            if(t==2)
            {
                free(n);
                free(xd);
                return 2;
            }
            if(t==3)
            {
                free(n);
                free(xd);
                return 3;
            }
        }
        else if(op=='-')
        {
            int t=subtract(n,xd,result);
            if(t==1)
            {
                free(n);
                free(xd);
                return 1;
            }
            if(t==2)
            {
                free(n);
                free(xd);
                return 2;
            }
            if(t==3)
            {
                free(n);
                free(xd);
                return 3;
            }
        }
        else
        {
            int t=multiply(n,xd,result);
            if(t==1)
            {
                free(n);
                free(xd);
                return 1;
            }
            if(t==2)
            {
                free(n);
                free(xd);
                return 2;
            }
            if(t==3)
            {
                free(n);
                free(xd);
                return 3;
            }
        }
        op=*(expr+i);
        free(xd);
        free(n);
        if(x==i)
            break;
        i++;
        k=i;
    }
    return 0;
}

int main() {
    char* xd=(char*)calloc(500,sizeof(char));
    if(xd==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj:");
    scanf("%499s",xd);
    char* res;
    int t= calculate(xd,&res);
    if(t==1)
    {
        printf("Incorrect input");
        free(xd);
        return 1;
    }
    if(t==2)
    {
        printf("Incorrect input");
        free(xd);
        return 1;
    }
    if(t==3)
    {
        printf("Failed to allocate memory");
        free(xd);
        return 8;
    }
    free(xd);
    printf("%s",res);
    free(res);
    return 0;
}

