#include <stdio.h>
#include <stdlib.h>
#include "big_numbers.h"
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"



int create(struct big_numbers_t *bn, int capacity) {
    if (bn == NULL || capacity <= 0)
        return 1;
    bn->big_number = (char **) calloc(capacity, sizeof(char *));
    if (bn->big_number == NULL)
        return 2;
    bn->size = 0;
    bn->capacity = capacity;
    return 0;
}

int create_big_numbers(struct big_numbers_t **bn, int capacity) {
    if (bn == NULL || capacity <= 0)
        return 1;
    *bn = (struct big_numbers_t *) calloc(1, sizeof(struct big_numbers_t));
    if (*bn == NULL)
        return 2;
    int t = create(*bn, capacity);
    if (t != 0) {
        free(*bn);
        *bn = NULL;
    }
    return t;

}

void destroy(struct big_numbers_t *bn) {
    if (!(bn == NULL || bn->big_number == NULL || bn->capacity <= 0 || bn->size < 0 || bn->size > bn->capacity)) {
        while (bn->size > 0) {
            free(*(bn->big_number + bn->size - 1));
            --bn->size;
        }
        free(bn->big_number);
    }
}

void destroy_big_numbers(struct big_numbers_t **bn) {
    if (!(bn == NULL || *bn == NULL || (*bn)->big_number == NULL || (*bn)->capacity <= 0 ||
          (*bn)->size<0 || (*bn)->size>(*bn)->capacity)) {
        destroy(*bn);
        free(*bn);
        *bn = NULL;
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

int add_big_number(struct big_numbers_t *bn, const char *big_number) {
    if (bn == NULL || big_number == NULL || bn->big_number == NULL || bn->capacity <= 0 || bn->size < 0 ||
        bn->size > bn->capacity || validate(big_number) != 0)
        return 1;
    if (bn->size == bn->capacity)
        return 3;

    int l = strlen(big_number);
    *(bn->big_number + bn->size) = (char *) calloc(l + 1, sizeof(char));
    if (*(bn->big_number + bn->size) == NULL)
        return 2;
    for (int i = 0; i < l; ++i) {
        *(*(bn->big_number + bn->size) + i) = *(big_number + i);
    }
    bn->size++;
    return 0;
}

void display(const struct big_numbers_t *bn) {
    if (!(bn == NULL || bn->big_number == NULL || bn->capacity <= 0 || bn->size < 0 || bn->size > bn->capacity)) {
        for (int i = 0; i < bn->size; ++i) {
            printf("%s\n", *(bn->big_number + i));
        }
    }
}

int save_big_numbers_b(const struct big_numbers_t *bn, const char *filename) {
    if (bn == NULL || bn->big_number == NULL || bn->size < 0 || bn->capacity <= 0 || bn->size > bn->capacity ||
        filename == NULL)
        return 1;
    FILE *f = fopen(filename, "wb");
    if (f == NULL)
        return 2;
    fwrite(&(bn->size), sizeof(int), 1, f);
    int l;
    for (int i = 0; i < bn->size; ++i) {
        l = strlen(*(bn->big_number + i));
        fwrite(&l, sizeof(int), 1, f);
        fwrite(*(bn->big_number + i), sizeof(char), l, f);
    }
    fclose(f);
    return 0;
}

int load_big_numbers_b(struct big_numbers_t **bn, const char *filename) {
    if (bn == NULL || filename == NULL)
        return 1;
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
        return 3;
    int s;
    fread(&s, sizeof(int), 1, f);
    if (s <= 0) {
        fclose(f);
        return 4;
    }
    int t = create_big_numbers(bn, s);
    if (t != 0) {
        fclose(f);
        return 2;
    }
    int l;
    for (int i = 0; i < s; ++i) {
        fread(&l, sizeof(int), 1, f);
        if (l <= 0) {
            fclose(f);
            destroy_big_numbers(bn);
            return 4;
        }
        *((*bn)->big_number + i) = (char *) calloc(l + 1, sizeof(char));
        if (*((*bn)->big_number + i) == NULL) {
            fclose(f);
            destroy_big_numbers(bn);
            return 2;
        }
        (*bn)->size++;
        int xd=fread(*((*bn)->big_number + i), sizeof(char), l, f);
        *(*((*bn)->big_number + i) + l) = '\0';
        if (validate(*((*bn)->big_number + i))) {
            fclose(f);
            destroy_big_numbers(bn);
            return 4;
        }
        if(xd!=l)
        {
            fclose(f);
            destroy_big_numbers(bn);
            return 4;
        }
    }
    fclose(f);
    return 0;
}


int sort_big_numbers_asc(struct big_numbers_t *bn) {
    if (bn == NULL || bn->big_number == NULL || bn->size < 0 || bn->capacity <= 0 || bn->size > bn->capacity) {
        return 1;
    }
    for(int i=0;i<bn->size;++i)
    {
        if(validate(*(bn->big_number+i))!=0)
            return 1;
    }
    for(int i=1;i<bn->size;++i)
    {
        for(int k=1;k<bn->size;++k)
        {
            if(compare(*(bn->big_number+k-1),*(bn->big_number+k))==1)
            {
                char* x=*(bn->big_number+k-1);
                *(bn->big_number+k-1)=*(bn->big_number+k);
                *(bn->big_number+k)=x;

            }
        }
    }

    return 0;
}

char *total_sum_big_numbers(const struct big_numbers_t *bn, int *err_code) {
    if (bn == NULL || bn->big_number == NULL || bn->size < 0 || bn->capacity <= 0 || bn->size > bn->capacity) {
        if (err_code != NULL) {
            *err_code = 1;
        }
        return NULL;
    }
    if (err_code != NULL)
        *err_code = 0;
    int t;
    for (int i = 0; i < bn->size; ++i) {
        t = validate(*(bn->big_number + i));
        if (t != 0) {
            if (err_code != NULL) {
                *err_code = 2;
            }
            return NULL;
        }
    }


    char *n1;
    if (bn->size == 1) {
        n1=strdup(*(bn->big_number));
        if(n1==NULL)
        {
            if (err_code != NULL)
                *err_code = 3;
            return NULL;
        }
        return n1;
    }

    t=add(*(bn->big_number),*(bn->big_number + 1),&n1);
    if (t == 1) {
        if (err_code != NULL)
            *err_code = 1;
        free(n1);
        return NULL;
    }
    if (t == 2) {
        if (err_code != NULL)
            *err_code = 2;
        free(n1);
        return NULL;
    }
    if (t == 3) {
        if (err_code != NULL)
            *err_code = 3;
        free(n1);
        return NULL;
    }

    char *n2;
    int f=1;
    for (int i = 2; i < bn->size; ++i) {
        if(f==1) {
            t = add(n1, *(bn->big_number + i), &n2);
            free(n1);
            f=0;
        }
        else {
            t = add(n2, *(bn->big_number + i), &n1);
            free(n2);
            f = 1;
        }
        if (t == 1) {
            if (err_code != NULL)
                *err_code = 1;
            free(n1);
            return NULL;
        }
        if (t == 2) {
            if (err_code != NULL)
                *err_code = 2;
            free(n1);

            return NULL;
        }
        if (t == 3) {
            if (err_code != NULL)
                *err_code = 3;
            free(n1);
            return NULL;
        }
    }
    if(f==0)
        return n2;
    else
        return n1;
}

int comp(const char *number1, const char *number2) {
    int l1 = strlen(number1);
    l1--;
    int l2 = strlen(number2);
    l2--;


    if (l1 == l2) {
        if (*number1 == '-' && *number2 != '-')
            return -1;
        if (*number2 == '-' && *number1 != '-')
            return 1;
    }
    if (l1 > l2) {
        if (l1 == l2 + 1) {
            if (*number1 != '-') {
                return 1;
            }
        } else
            return 1;

    }
    if (l2 > l1) {
        if (l2 == l1 + 1) {
            if (*number2 != '-') {
                return -1;
            }
        } else
            return -1;

    }
    int sz = l1 > l2 ? l1 : l2;
    int x1 = 0, x2 = 0;
    if (*number1 == '-')
        x1++;
    if (*number2 == '-')
        x2++;
    for (int i = 0; i < sz + 1; ++i) {
        if (ctoi(*(number1 + x1)) > ctoi(*(number2 + x2))) {
            return 1;
        } else if (ctoi(*(number1 + x1)) < ctoi(*(number2 + x2))) {
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

    if (*number1 != '-' && *number2 == '-')
        return 1;
    else if (*number1 == '-' && *number2 != '-')
        return -1;
    else if (*number1 == '-' && *number2 == '-') {
        int l1= strlen(number1);
        int l2= strlen(number2);
        if(l1>l2)
            return -1;
        else if(l1<l2)
            return 1;
        else
        {
            for(int i=1;i<l1;++i)
            {
                if(ctoi(*(number1+i))>ctoi(*(number2+i)))
                    return -1;
                else if(ctoi(*(number1+i))<ctoi(*(number2+i)))
                    return 1;
            }
            return 0;
        }
    } else {
        int l1= strlen(number1);
        int l2= strlen(number2);
        if(l1>l2)
            return 1;
        else if(l1<l2)
            return -1;
        else
        {
            for(int i=0;i<l1;++i)
            {
                if(ctoi(*(number1+i))>ctoi(*(number2+i)))
                    return 1;
                else if(ctoi(*(number1+i))<ctoi(*(number2+i)))
                    return -1;
            }
            return 0;
        }
    }
    return 0;
}

void reduktor(char **result) {
    if (strlen(*result) == 1)
        return;
    int i = 0;
    int m = 0;
    if (**result == '-')
        m = 1;
    while (*(*result + i) == '0' || *(*result + i) == '-') {
        i++;
    }
    int sz = (int) strlen(*result) - i;
    int k = 0;
    if (m == 1) {
        *(*result + k) = '-';
        ++k;
        ++sz;
    }
    for (; k < sz; ++k) {

        *(*result + k) = *(*result + i);
        ++i;
    }
    *(*result + sz) = '\0';

}

void wm(char *xd) {
    int i = 0;
    while (*(xd + i) == '-') {
        i++;
    }
    int sz = (int) strlen(xd) - i;
    int k = 0;
    for (; k < sz; ++k) {

        *(xd + k) = *(xd + i);
        ++i;
    }
    *(xd + sz) = '\0';
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
        *result = (char *) calloc((sz + 1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result, '0', sz);
        *(*result + sz) = '\0';
        l1--;
        l2--;
        int x = 0, d = 0;
        sz--;
        for (; sz >= 0; --sz) {
            x = 0;
            if (d == 1) {
                d = 0;
                x = 1;
            }
            if (l1 >= 0) {
                x += ctoi(*(number1 + l1));
            }
            if (l2 >= 0) {
                x += ctoi(*(number2 + l2));
            }
            if (x >= 10) {
                d = 1;
                x -= 10;
            }
            *(*result + sz) = x + '0';
            --l1;
            --l2;
        }
        if (d == 1) {
            *(*result + sz) = '1';
        }

    } else if (*number1 == '-' && *number2 != '-') {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        *result = (char *) calloc((sz + 1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result, '0', sz);
        *(*result + sz) = '\0';
        l1--;
        l2--;
        int x = 0, d = 0;
        sz--;

        if (comp(number1, number2) == 1) {
            for (; sz >= 0; --sz) {
                x = 0;
                if (d == 1) {
                    x--;
                    d = 0;
                }
                if (l1 >= 0) {
                    x += ctoi(*(number1 + l1));
                }
                if (l2 >= 0) {
                    x -= ctoi(*(number2 + l2));
                }
                if (x < 0) {
                    d = 1;
                    x += 10;
                }
                *(*result + sz) = x + '0';
                --l1;
                --l2;

            }
            *(*result) = '-';
        } else if (comp(number1, number2) == -1) {
            for (; sz >= 0; --sz) {
                x = 0;
                if (d == 1) {
                    x--;
                    d = 0;
                }
                if (l1 >= 0) {
                    x -= ctoi(*(number1 + l1));
                }
                if (l2 >= 0) {
                    x += ctoi(*(number2 + l2));
                }
                if (x < 0) {
                    d = 1;
                    x += 10;
                }
                *(*result + sz) = x + '0';
                --l1;
                --l2;

            }
        } else {
            *(*result) = '0';
            *(*result + 1) = '\0';
            return 0;
        }

    } else if (*number1 != '-' && *number2 == '-') {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        sz++;
        *result = (char *) calloc((sz + 1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result, '0', sz);
        *(*result + sz) = '\0';
        l1--;
        l2--;
        int x = 0, d = 0;
        sz--;

        if (comp(number1, number2) == 1) {
            for (; sz >= 0; --sz) {
                x = 0;
                if (d == 1) {
                    x--;
                    d = 0;
                }
                if (l1 >= 0) {
                    x += ctoi(*(number1 + l1));
                }
                if (l2 >= 0) {
                    x -= ctoi(*(number2 + l2));
                }
                if (x < 0) {
                    d = 1;
                    x += 10;
                }
                *(*result + sz) = x + '0';
                --l1;
                --l2;

            }

        } else if (comp(number1, number2) == -1) {
            for (; sz >= 0; --sz) {
                x = 0;
                if (d == 1) {
                    x--;
                    d = 0;
                }
                if (l2 >= 0) {
                    x += ctoi(*(number2 + l2));
                }
                if (l1 >= 0) {
                    x -= ctoi(*(number1 + l1));
                }

                if (x < 0) {
                    d = 1;
                    x += 10;
                }
                *(*result + sz) = x + '0';
                --l1;
                --l2;

            }
            *(*result) = '-';
        } else {
            *(*result) = '0';
            *(*result + 1) = '\0';
            return 0;
        }

    } else if (*number1 == '-' && *number2 == '-') {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        sz++;
        *result = (char *) calloc((sz + 1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result, '0', sz);
        *(*result + sz) = '\0';
        l1--;
        l2--;
        int x = 0, d = 0;
        sz--;
        for (; sz >= 0; --sz) {
            x = 0;
            if (d == 1) {
                d = 0;
                x = 1;
            }
            if (l1 >= 0) {
                x += ctoi(*(number1 + l1));
            }
            if (l2 >= 0) {
                x += ctoi(*(number2 + l2));
            }
            if (x >= 10) {
                d = 1;
                x -= 10;
            }
            *(*result + sz) = x + '0';
            --l1;
            --l2;
        }
        if (d == 1) {
            *(*result + sz) = '1';
        }
        **result = '-';

    }
    reduktor(result);
    return 0;
}

int subtract(const char *number1, const char *number2, char **result) {
    if (number1 == NULL || number2 == NULL || result == NULL)
        return 1;
    if (validate(number1) != 0 || validate(number2) != 0)
        return 2;
    if (*number1 != '-' && *number2 != '-') {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        sz++;
        *result = (char *) calloc((sz + 1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result, '0', sz);
        *(*result + sz) = '\0';
        l1--;
        l2--;
        int x = 0, d = 0;
        sz--;

        if (comp(number1, number2) == 1) {
            for (; sz >= 0; --sz) {
                x = 0;
                if (d == 1) {
                    x--;
                    d = 0;
                }
                if (l1 >= 0) {
                    x += ctoi(*(number1 + l1));
                }
                if (l2 >= 0) {
                    x -= ctoi(*(number2 + l2));
                }
                if (x < 0) {
                    d = 1;
                    x += 10;
                }
                *(*result + sz) = x + '0';
                --l1;
                --l2;

            }

        } else if (comp(number1, number2) == -1) {
            for (; sz >= 0; --sz) {
                x = 0;
                if (d == 1) {
                    x--;
                    d = 0;
                }
                if (l2 >= 0) {
                    x += ctoi(*(number2 + l2));
                }
                if (l1 >= 0) {
                    x -= ctoi(*(number1 + l1));
                }

                if (x < 0) {
                    d = 1;
                    x += 10;
                }
                *(*result + sz) = x + '0';
                --l1;
                --l2;

            }
            *(*result) = '-';
        } else {
            *(*result) = '0';
            *(*result + 1) = '\0';
            return 0;
        }

    } else if (*number1 == '-' && *number2 == '-') {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        *result = (char *) calloc((sz + 1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result, '0', sz);
        *(*result + sz) = '\0';
        l1--;
        l2--;
        int x = 0, d = 0;
        sz--;

        if (comp(number1, number2) == 1) {
            for (; sz >= 0; --sz) {
                x = 0;
                if (d == 1) {
                    x--;
                    d = 0;
                }
                if (l1 >= 0) {
                    x += ctoi(*(number1 + l1));
                }
                if (l2 >= 0) {
                    x -= ctoi(*(number2 + l2));
                }
                if (x < 0) {
                    d = 1;
                    x += 10;
                }
                *(*result + sz) = x + '0';
                --l1;
                --l2;

            }
            *(*result) = '-';
        } else if (comp(number1, number2) == -1) {
            for (; sz >= 0; --sz) {
                x = 0;
                if (d == 1) {
                    x--;
                    d = 0;
                }
                if (l1 >= 0) {
                    x -= ctoi(*(number1 + l1));
                }
                if (l2 >= 0) {
                    x += ctoi(*(number2 + l2));
                }
                if (x < 0) {
                    d = 1;
                    x += 10;
                }
                *(*result + sz) = x + '0';
                --l1;
                --l2;

            }
        } else {
            *(*result) = '0';
            *(*result + 1) = '\0';
            return 0;
        }

    } else if (*number1 == '-' && *number2 != '-') {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        sz++;
        sz++;
        *result = (char *) calloc((sz + 1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result, '0', sz);
        *(*result + sz) = '\0';
        l1--;
        l2--;
        int x = 0, d = 0;
        sz--;
        for (; sz >= 0; --sz) {
            x = 0;
            if (d == 1) {
                d = 0;
                x = 1;
            }
            if (l1 >= 0) {
                x += ctoi(*(number1 + l1));
            }
            if (l2 >= 0) {
                x += ctoi(*(number2 + l2));
            }
            if (x >= 10) {
                d = 1;
                x -= 10;
            }
            *(*result + sz) = x + '0';
            --l1;
            --l2;
        }
        if (d == 1) {
            *(*result + sz) = '1';
        }
        **result = '-';


    } else if (*number1 != '-' && *number2 == '-') {
        int l1 = strlen(number1);
        int l2 = strlen(number2);
        int sz = l1 > l2 ? l1 : l2;
        sz++;
        *result = (char *) calloc((sz + 1), sizeof(char));
        if (*result == NULL) {
            return 3;
        }
        memset(*result, '0', sz);
        *(*result + sz) = '\0';
        l1--;
        l2--;
        int x = 0, d = 0;
        sz--;
        for (; sz >= 0; --sz) {
            x = 0;
            if (d == 1) {
                d = 0;
                x = 1;
            }
            if (l1 >= 0) {
                x += ctoi(*(number1 + l1));
            }
            if (l2 >= 0) {
                x += ctoi(*(number2 + l2));
            }
            if (x >= 10) {
                d = 1;
                x -= 10;
            }
            *(*result + sz) = x + '0';
            --l1;
            --l2;
        }
        if (d == 1) {
            *(*result + sz) = '1';
        }

    }
    reduktor(result);
    return 0;
}

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
