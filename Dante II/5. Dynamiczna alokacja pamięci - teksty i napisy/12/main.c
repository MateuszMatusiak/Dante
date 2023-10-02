#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"


int countWords(const char *text)
{
    if(text==NULL)
        return -1;
    if(*(text)=='\0')
        return 0;
    int i=0;
    int l=0;
    while(*(text+i)!='\0')
    {
        if((!isalpha(*(text+i+1)))&&(isalpha(*(text+i))))
            ++l;
        if(!isalpha(*(text+i))) {
            while (!isalpha(*(text + i))) {
                if(*(text+i)=='\0')
                    return l;
                ++i;
            }
        }
        else
            ++i;

    }
    return l;

}

int wrdlen(const char* word)
{
    int i=0;
    while(isalpha(*(word+i)))
    {
        ++i;
    }
    return i;
}

char **split_words(const char *text) {
    int sp= countWords(text);
    if(sp<=0)
        return NULL;

    int i=0,x=0,k=0;
    char** xd=(char**)calloc(sp+1,sizeof(char*));
    if(xd==NULL)
        return NULL;


    *(xd+sp)=NULL;

    while(1)
    {
        if(i==sp)
            break;
        k+=x;
        x= wrdlen(text+k);
        if(x==0)
        {
            x++;
            continue;
        }
        *(xd+i)=(char*)calloc(x+1,sizeof(char));
        if(*(xd+i)==NULL)
        {
            for(int o=0;o<i;++o)
            {
                free(*(xd+o));
            }
            free(xd);
            return NULL;
        }
        strncpy(*(xd+i),text+k,x);
        x++;
        ++i;
    }

    return xd;
}

int sort_words(char **words) {
    if (words == NULL)
        return 1;

    int l = 0;
    while (*(words + l) != NULL)
        ++l;

    for(int k=0;k<l-1;++k) {
        for(int i=0;i<l-1;++i)
        {
            if(!islower(**(words+i+1))&& islower(**(words+i)))
            {
                char *xd = *(words+i);
                *(words+i)=*(words+i+1);
                *(words+i+1)=xd;
            }
            else if(strcmp(*(words+i+1),*(words+i))<0)
            {
                char *xd = *(words+i);
                *(words+i)=*(words+i+1);
                *(words+i+1)=xd;
            }
        }
    }

    return 0;
}

void destroy(char **words) {
    if (words != NULL) {
        int i = 0;
        while (*(words + i) != NULL) {
            free(*(words + i));
            i++;
        }
        free(words);
    }
}


int main() {

    char* xd=(char*)calloc(1000,sizeof(char));
    if(xd==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Daj: ");
    scanf("%999[^\n]", xd);
    if(countWords(xd)==0)
    {
        free(xd);
        printf("Nothing to show");
        return 0;
    }
    char **res= split_words(xd);
    if(res==NULL)
    {
        free(xd);
        printf("Failed to allocate memory");
        return 8;
    }
    if(*res==NULL)
    {
        free(xd);
        printf("Nothing to show");
        return 0;
    }
    int t = sort_words(res);
    if(t==1)
    {
        free(xd);
        destroy(res);
        printf("Incorrect input");
        return 1;
    }
    int i=0;
    while(*(res+i)!=NULL)
    {
        printf("%s\n",*(res+i));
        ++i;
    }
    destroy(res);
    free(xd);
    return 0;
}


