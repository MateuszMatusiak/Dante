#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

int validate(const char *word) {
    int i = 0;
    while (*(word + i) != '\0') {
        if (!(*(word + i) >= 'A' && *(word + i) <= 'Z'))
            return 1;
        ++i;
    }

    return 0;
}

int create_leading_word_cross(const char *first, const char *second, char ***result) {
    if (result == NULL)
        return -1;
    if (first == NULL || second == NULL) {
        *result = NULL;
        result = NULL;
        return -1;
    }

    if (validate(first) != 0 || validate(second) != 0) {
        *result = NULL;
        result = NULL;
        return -1;
    }
    int l1 = strlen(first);
    int l2 = strlen(second);
    int x2 = strcspn(second, first);
    if (x2 == l2) {
        *result = NULL;
        return -2;
    }
    int x1 = first - strchr(first, *(second + x2));
    x1 *= -1;
    int p;
    char **xd = (char **) calloc(l1 + 1, sizeof(char *));
    if (xd == NULL) {
        *result = NULL;
        result = NULL;
        return -3;
    }
    int i, k;
    for (i = 0; i < l1; ++i) {
        p = (i != x1) ? x2 + 1 : l2;
        *(xd + i) = (char *) calloc(p + 1, sizeof(char));
        if (*(xd + i) == NULL) {
            for (k = 0; k < i; ++k) {
                free(*(xd + k));
            }
            free(xd);
            *result = NULL;
            result = NULL;
            return -3;
        }
    }
    *(xd + l1) = NULL;

    for (i = 0; i < l1; ++i) {
        if (i != x1) {
            p = x2 + 1;
            for (k = 0; k < p - 1; ++k) {
                *(*(xd + i) + k) = ' ';
            }
            *(*(xd + i) + k) = *(first + i);
            *(*(xd + i) + k + 1) = '\0';
        } else {
            p = l2;
            for (k = 0; k < p; ++k) {
                *(*(xd + i) + k) = *(second + k);
            }
            *(*(xd + i) + k) = '\0';
        }
    }
    *result = xd;
    return x1;
}

void destroy(char **words) {
    if (words != NULL) {
        int i = 0;
        while (*(words + i) != NULL) {
            free(*(words + i));
            ++i;
        }
        free(words);
    }
}
void print(char **words) {
    if (words != NULL) {
        int i = 0;
        while (*(words + i) != NULL) {
            printf("%s\n",*(words + i));
            ++i;
        }
    }
}


int create_double_leading_word_cross(const char *first, const char *second, const char *third, const char *fourth,
                                     char ***result, char ***first_cross, char ***second_cross) {
    if (result == NULL)
        return 1;
    int x1 = 0, x2 = 0;
    x1 = create_leading_word_cross(second, first,  first_cross);
    if (x1 < 0) {
        *result=NULL;
        result=NULL;
        return x1 * (-1);
    }
    x2 = create_leading_word_cross(fourth, third, second_cross);
    if (x2 < 0) {
        *result=NULL;
        result=NULL;
        destroy(*first_cross);
        return x2 * (-1);
    }
    char **f1 = *first_cross;
    char **f2 = *second_cross;
    int w1 = 0, w2 = 0;

    while(*(f1+w1)!=NULL)
        w1++;
    while(*(f2+w2)!=NULL)
        w2++;
    int x = x1 > x2 ? x1 - x2 : x2 - x1;
    int w = x1 > x2 ? x1:x2;
    w+=strlen(second)-x1> strlen(fourth)-x2?(int)strlen(second)-x1:(int)strlen(fourth)-x2;

    int dok2=0;
    char **xd = (char **) calloc(w + 1, sizeof(char *));
    if (xd == NULL) {
        destroy(f1);
        destroy(f2);
        *result=NULL;
        result=NULL;
        return 3;
    }
    *(xd + w) = NULL;
    int dl=strlen(*(f1+x1));
    int k;
    if (x1 > x2) {
        for (k = 0; k < x1 - x2; ++k) {
            *(xd + k) = (char *) calloc(strlen(*(f1 + k))+1, sizeof(char));
            if (*(xd + k) == NULL) {
                for (int o = 0; o < k; ++o) {
                    free(*(xd + o));
                }
                destroy(f1);
                destroy(f2);
                free(xd);
                *result=NULL;
                result=NULL;
                return 3;
            }
        }
        for(;k<w;++k)
        {
            int l2;
            if(k-x>=w2) {
                l2 = -3;
                dl= strlen(*(f1+k));
            }
            else
                l2=strlen(*(f2 + k-x));
            *(xd + k) = (char *) calloc(dl+l2+4, sizeof(char));
            if (*(xd + k) == NULL) {
                for (int o = 0; o < k; ++o) {
                    free(*(xd + o));
                }
                destroy(f1);
                destroy(f2);
                free(xd);
                *result=NULL;
                result=NULL;
                return 3;
            }
        }
    } else if (x2 > x1) {
        for(k=0;k<x2-x1;++k)
        {
            int l2;
            if(k>=w2) {
                l2 = -3;
                dl= strlen(*(f1+k));
            }
            else
                l2=strlen(*(f2 + k));
            *(xd+k)=(char*)calloc(dl+l2+4,sizeof(char));
            if (*(xd + k) == NULL) {
                for (int o = 0; o < k; ++o) {
                    free(*(xd + o));
                }
                destroy(f1);
                destroy(f2);
                free(xd);
                *result=NULL;
                result=NULL;
                return 3;
            }

        }
        for(;k<w;++k)
        {
            int l2;
            if(k>=w2) {
                l2 = -3;
                dl= strlen(*(f1+k-x));
            }
            else
                l2=strlen(*(f2 + k));

            *(xd + k) = (char *) calloc(dl+l2+4, sizeof(char));
            if (*(xd + k) == NULL) {
                for (int o = 0; o < k; ++o) {
                    free(*(xd + o));
                }
                destroy(f1);
                destroy(f2);
                free(xd);
                *result=NULL;
                result=NULL;
                return 3;
            }
        }
    } else {
        for(k=0;k<w;++k)
        {
            int l2;
            if(k>=w2) {
                l2 = -3;
                dl= strlen(*(f1+k));
            }
            else
                l2=strlen(*(f2 + k));


            *(xd + k) = (char *) calloc(dl+l2+4, sizeof(char));
            if (*(xd + k) == NULL) {
                for (int o = 0; o < k; ++o) {
                    free(*(xd + o));
                }
                destroy(f1);
                destroy(f2);
                free(xd);
                *result=NULL;
                result=NULL;
                return 3;
            }
        }
    }
    ////////

    dl= strlen(*(f1+x1));
    if (x1 > x2) {
        for (k = 0; k < x1 - x2; ++k) {
            strcat(*(xd+k),*(f1+k));
        }
        for(;k<w;++k)
        {
            if(*(f1+k)==NULL)
            {
                dok2=1;
                break;
            }
            strcat(*(xd+k),*(f1+k));
            if(k-x>=w2)
                continue;
            for(int o=strlen(*(f1+k));o<dl;++o)
            {
                strcat(*(xd+k)," ");
            }
            strcat(*(xd+k),"   ");
            strcat(*(xd+k),*(f2+k-x));
        }
    } else if (x2 > x1) {
        for(k=0;k<x2-x1;++k)
        {
            for(int o=0;o<dl;++o)
            {
                strcat(*(xd+k)," ");
            }
            strcat(*(xd+k),"   ");
            strcat(*(xd+k),*(f2+k));
        }
        for(;k<w;++k)
        {
            if(*(f1+k-x)==NULL)
            {
                dok2=1;
                break;
            }
            strcat(*(xd+k),*(f1+k-x));
            if(k>=w2)
                continue;
            for(int o=strlen(*(f1+k-x));o<dl;++o)
            {
                strcat(*(xd+k)," ");
            }
            strcat(*(xd+k),"   ");
            strcat(*(xd+k),*(f2+k));
        }
    } else {
        for(k=0;k<w;++k)
        {
            if(*(f1+k)==NULL)
            {
                dok2=1;
                break;
            }
            strcat(*(xd+k),*(f1+k));

            if(k>=w2)
            {
                continue;
            }
            for(int o=strlen(*(f1+k));o<dl;++o)
            {
                strcat(*(xd+k)," ");
            }
            strcat(*(xd+k),"   ");
            strcat(*(xd+k),*(f2+k));
        }
    }

    if(dok2==1)
    {
        for(;k<w;++k)
        {
            for (int o = 0; o < dl; ++o) {
                strcat(*(xd + k), " ");
            }
            strcat(*(xd + k), "   ");
            if(!(x1>x2))
                x=0;
            strcat(*(xd + k), *(f2 + k-x));
        }
    }

    *result=xd;

    return 0;
}


int main() {
    char* f1=(char*)calloc(11,sizeof(char));
    if(f1==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    char* f2=(char*)calloc(11,sizeof(char));
    if(f2==NULL)
    {
        printf("Failed to allocate memory");
        free(f1);
        return 8;
    }
    char* f3=(char*)calloc(11,sizeof(char));
    if(f3==NULL)
    {
        printf("Failed to allocate memory");
        free(f1);
        free(f2);
        return 8;
    }
    char* f4=(char*)calloc(11,sizeof(char));
    if(f4==NULL)
    {
        printf("Failed to allocate memory");
        free(f1);
        free(f2);
        free(f3);
        return 8;
    }
    printf("Daj: ");
    int t=scanf("%10s %10s %10s %10s",f1,f2,f3,f4);
    if(t==0){
        printf("Incorrect input");
        free(f1);
        free(f2);
        free(f3);
        free(f4);
        return 1;
    }
    char** res,**r1,**r2;
    t= create_double_leading_word_cross(f1,f2,f3,f4,&res,&r1,&r2);
    if(t==1) {
        printf("Incorrect input");
        free(f1);
        free(f2);
        free(f3);
        free(f4);
        return 1;
    }
    if(t==3) {
        printf("Failed to allocate memory");
        free(f1);
        free(f2);
        free(f3);
        free(f4);
        return 8;
    }
    if(t==2) {
        printf("Unable to make two crosses");
        free(f1);
        free(f2);
        free(f3);
        free(f4);
        return 0;
    }

    print(r1);
    printf("\n");
    print(r2);
    printf("\n");
    print(res);
    destroy(r1);
    destroy(r2);
    destroy(res);
    free(f1);
    free(f2);
    free(f3);
    free(f4);
    return 0;
}




