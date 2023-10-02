#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

char *ltoa(unsigned long long number) {
    int l = 0;
    unsigned long long x = number;
    while (x > 0) {
        x /= 10;
        l++;
    }
    x = number;
    if (l == 0)
        ++l;
    char *xd = (char *) calloc(l + 1, sizeof(char));
    if (xd == NULL) {
        return NULL;
    }
    memset(xd, '0', sizeof(char) * l);
    *(xd + l) = '\0';
    for (int i = l - 1; i >= 0; --i) {
        *(xd + i) = (x % 10) + '0';
        x /= 10;
    }

    return xd;
}


char *my_strcat(char **dest, const char *src) {
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    char* t;
    int l, o = 1;
    if (*dest == NULL) {
        o = 0;
        l = strlen(src);
    } else {
        o = strlen(*dest);
        l = (strlen(src) + strlen(*dest));
    }
    if(*dest==NULL)
    {
        *dest=(char*)calloc(l+1,sizeof(char));
        if(*dest==NULL)
            return NULL;
    }
    else {
        t = realloc(*dest, sizeof(char) * (l + 1));
        if (t == NULL)
            return NULL;
        *dest = t;
    }
    int i, k = 0;
    for (i = o; i < l; ++i) {
        (*(*dest + i)) = *(src + k);
        k++;
    }
    (*(*dest + i)) = '\0';
    return *dest;
}

int mmmsetunie(char **text, char *number, int l) {
    if (l > 3)
        l = 3;
    int ln = strlen(number);
    if (ln < l)
        l = ln;
    if ((*number == '0') && (*(number + 1) == '0') && (*(number + 2) == '0'))
        return 2;
    int x = l == 3 ? 1 : 0;
    char *t;
    if (l == 3) {
        switch (*number) {
            case '1':
                t = my_strcat(text, "One Hundred");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '2':
                t = my_strcat(text, "Two Hundred");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '3':
                t = my_strcat(text, "Three Hundred");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '4':
                t = my_strcat(text, "Four Hundred");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '5':
                t = my_strcat(text, "Five Hundred");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '6':
                t = my_strcat(text, "Six Hundred");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '7':
                t = my_strcat(text, "Seven Hundred");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '8':
                t = my_strcat(text, "Eight Hundred");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '9':
                t = my_strcat(text, "Nine Hundred");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '0':
                break;
            default:
                return 1;
        }
    }
    if (l > 1) {
        if (l == 3) {
            if (!(((*(number + 1)) == '0') && (*(number + 2) == '0')) && (*number != '0')) {
                t = my_strcat(text, " ");
                if (t == NULL) {
                    return 1;
                }
            }
            x = 1;
        } else
            x = 0;
        switch (*(number + x)) {
            case '1': {
                switch (*(number + x + 1)) {
                    case '0':
                        t = my_strcat(text, "Ten");
                        if (t == NULL) {
                            return 1;
                        }
                        break;
                    case '1':
                        t = my_strcat(text, "Eleven");
                        if (t == NULL) {
                            return 1;
                        }
                        break;
                    case '2':
                        t = my_strcat(text, "Twelve");
                        if (t == NULL) {
                            return 1;
                        }
                        break;
                    case '3':
                        t = my_strcat(text, "Thirteen");
                        if (t == NULL) {
                            return 1;
                        }
                        break;
                    case '4':
                        t = my_strcat(text, "Fourteen");
                        if (t == NULL) {
                            return 1;
                        }
                        break;
                    case '5':
                        t = my_strcat(text, "Fifteen");
                        if (t == NULL) {
                            return 1;
                        }
                        break;
                    case '6':
                        t = my_strcat(text, "Sixteen");
                        if (t == NULL) {
                            return 1;
                        }
                        break;
                    case '7':
                        t = my_strcat(text, "Seventeen");
                        if (t == NULL) {
                            return 1;
                        }
                        break;
                    case '8':
                        t = my_strcat(text, "Eighteen");
                        if (t == NULL) {
                            return 1;
                        }
                        break;
                    case '9':
                        t = my_strcat(text, "Nineteen");
                        if (t == NULL) {
                            return 1;
                        }
                        break;
                    default:
                        return 1;
                }
                return 0;
            }
            case '2':
                t = my_strcat(text, "Twenty");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '3':
                t = my_strcat(text, "Thirty");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '4':
                t = my_strcat(text, "Forty");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '5':
                t = my_strcat(text, "Fifty");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '6':
                t = my_strcat(text, "Sixty");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '7':
                t = my_strcat(text, "Seventy");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '8':
                t = my_strcat(text, "Eighty");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '9':
                t = my_strcat(text, "Ninety");
                if (t == NULL) {
                    return 1;
                }
                break;
            case '0':
                break;
            default:
                return 1;
        }
    }

    if (l == 3) {
        if (!(((*(number + 1)) == '0') || (*(number + 2) == '0'))) {
            t = my_strcat(text, " ");
            if (t == NULL) {
                return 1;
            }
        }
        x = 1;
    } else if (l == 2) {
        if ((*(number + 1)) != '0') {
            t = my_strcat(text, " ");
            if (t == NULL) {
                return 1;
            }
        }
        x = 0;
    } else
        x = -1;


    switch (*(number + x + 1)) {
        case '1':
            t = my_strcat(text, "One");
            if (t == NULL) {
                return 1;
            }
            break;
        case '2':
            t = my_strcat(text, "Two");
            if (t == NULL) {
                return 1;
            }
            break;
        case '3':
            t = my_strcat(text, "Three");
            if (t == NULL) {
                return 1;
            }
            break;
        case '4':
            t = my_strcat(text, "Four");
            if (t == NULL) {
                return 1;
            }
            break;
        case '5':
            t = my_strcat(text, "Five");
            if (t == NULL) {
                return 1;
            }
            break;
        case '6':
            t = my_strcat(text, "Six");
            if (t == NULL) {
                return 1;
            }
            break;
        case '7':
            t = my_strcat(text, "Seven");
            if (t == NULL) {
                return 1;
            }
            break;
        case '8':
            t = my_strcat(text, "Eight");
            if (t == NULL) {
                return 1;
            }
            break;
        case '9':
            t = my_strcat(text, "Nine");
            if (t == NULL) {
                return 1;
            }
            break;
        case '0':
            break;
        default:
            return 1;
    }
    return 0;
}

int number_2_words(char **text, unsigned long long number) {

    if(text==NULL)
        return 1;

    char *nb = ltoa(number);
    if (nb == NULL) {
        *text=NULL;
        return 2;
    }
    int t;
    int l = strlen(nb);
    int p = 0;

    char *xd = NULL;
    my_strcat(&xd, "");
    if (xd == NULL) {
        free(nb);
        *text=NULL;
        return 2;
    }

    if (number == 0) {
        my_strcat(&xd, "Zero");
        free(nb);
        if (xd == NULL) {
            text = NULL;
            return 2;
        }
        *text = xd;
        return 0;
    }



    if (l > 18) {

        t = mmmsetunie(&xd, nb, l - 18);
        if (t == 1) {
            free(nb);
            text = NULL;
            return 2;
        }
        p += l-18;
        if (t != 2)
            my_strcat(&xd, " Quintillion ");
    }
    if (l > 15) {

        t = mmmsetunie(&xd, nb + p, l - 15);
        if (t == 1) {
            free(nb);
            if (xd != NULL)
                free(xd);
            text = NULL;
            return 2;
        }
        if(l>18)
            p += 3;
        else
            p+=l-15;
        if (t != 2)
            my_strcat(&xd, " Quadrillion ");
    }
    if (l > 12) {
        t = mmmsetunie(&xd, nb + p, l - 12);
        if (t == 1) {
            free(nb);
            if (xd != NULL)
                free(xd);
            text = NULL;
            return 2;
        }
        if(l>15)
            p += 3;
        else
            p+=l-12;
        if(t!=2)
            my_strcat(&xd, " Trillion ");
    }
    if (l > 9) {
        t = mmmsetunie(&xd, nb + p, l - 9);
        if (t == 1) {
            free(nb);
            if (xd != NULL)
                free(xd);
            text = NULL;
            return 2;
        }
        if(l>12)
            p += 3;
        else
            p+=l-9;
        if (t != 2)
            my_strcat(&xd, " Billion ");
    }
    if (l > 6) {
        t = mmmsetunie(&xd, nb + p, l - 6);
        if (t == 1) {
            free(nb);
            if (xd != NULL)
                free(xd);
            text = NULL;
            return 2;
        }
        if(l>9)
            p += 3;
        else
            p+=l-6;

        if (t != 2)
            my_strcat(&xd, " Million ");
    }
    if (l > 3) {
        t = mmmsetunie(&xd, nb + p, l - 3);
        if (t == 1) {
            free(nb);
            if (xd != NULL)
                free(xd);
            text = NULL;
            return 2;
        }
        if(l>6)
            p += 3;
        else
            p+=l-3;
        if (t != 2)
            my_strcat(&xd, " Thousand ");
    }
    t = mmmsetunie(&xd, nb + p, l);
    if (t == 1) {
        free(nb);
        if (xd != NULL)
            free(xd);
        text = NULL;
        return 2;
    }
    free(nb);
    if (xd == NULL) {
        text = NULL;
        return 2;
    }
    *text = xd;
    return 0;
}


int main() {
    unsigned long long nb;
    printf("Daj");
    int t= scanf("%llu",&nb);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    char* txt;
    t= number_2_words(&txt,nb);
    if(t==1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(t==2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("%s",txt);
    free(txt);
    return 0;
}






