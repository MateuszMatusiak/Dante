#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "functions.h"
#include "tested_declarations.h"
#include "rdebug.h"


typedef char*(* f )( const char*);

char **text_modifier(const char *text, int N, ...) {
    if (text == NULL || N <= 0)
        return NULL;
    char **res = (char **) calloc(N + 1, sizeof(char *));
    if (res == NULL)
        return NULL;
    *(res + N) = NULL;
    va_list ap;
    va_start(ap, N);
    for (int i = 0; i < N; ++i) {
        f arg = va_arg(ap, f);
        *(res + i) = arg(text);
            if (*(res + i) == NULL) {
                for(int k=0;k<i;k++)
                    free(*(res+k));
                free(res);
                return NULL;
            }
    }
    va_end(ap);
    return res;
}


int main() {
    char* txt=(char*)calloc(1001,sizeof(char));
    if(txt==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    f* tab=(f*)calloc(4,sizeof(f*));
    if(tab==NULL)
    {
        free(txt);
        printf("Failed to allocate memory");
        return 8;
    }
    int* nb=(int*)calloc(4,sizeof(int));
    if(nb==NULL)
    {
        free(txt);
        free(tab);
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    scanf("%1000[^\n]",txt);
    while (getchar () != '\n');
    printf("Daj: ");
    int w;
    int t=scanf("%d",&w);
    if(t!=1)
    {
        free(txt);
        free(tab);
        free(nb);
        printf("Incorrect input");
        return 1;
    }
    if(w<2||w>4)
    {
        free(txt);
        free(tab);
        free(nb);
        printf("Incorrect input data");
        return 2;
    }
    while (getchar () != '\n');
    printf("Daj: ");
    for(int i=0;i<w;++i)
    {
        t=scanf("%d",(nb+i));
        if(t!=1)
        {
            free(txt);
            free(tab);
            free(nb);
            printf("Incorrect input");
            return 1;
        }
    }

    char** res;
    for(int i=0;i<w;++i)
    {
    if(*(nb+i)==0)
    {
        res=text_modifier(txt,1, lower_to_upper);
        if(res==NULL)
        {
            free(txt);
            free(tab);
            free(nb);
            printf("Failed to allocate memory");
            return 8;
        }
        printf("%s\n",*res);
        free_texts(res);
    }
    else if(*(nb+i)==1)
    {
        res=text_modifier(txt,1, upper_to_lower);
        if(res==NULL)
        {
            free(txt);
            free(tab);
            free(nb);
            printf("Failed to allocate memory");
            return 8;
        }
        printf("%s\n",*res);
        free_texts(res);
    }
    else if(*(nb+i)==2)
    {
        res=text_modifier(txt,1, reverse_letter);
        if(res==NULL)
        {
            free(txt);
            free(tab);
            free(nb);
            printf("Failed to allocate memory");
            return 8;
        }
        printf("%s\n",*res);
        free_texts(res);
    }
    else if(*(nb+i)==3)
    {
        res=text_modifier(txt,1, space_to_dash);
        if(res==NULL)
        {
            free(txt);
            free(tab);
            free(nb);
            printf("Failed to allocate memory");
            return 8;
        }
        printf("%s\n",*res);
        free_texts(res);
    }
    }
    free(txt);
    free(tab);
    free(nb);
    return 0;
}

