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
    if (!(bn == NULL || *bn == NULL || (*bn)->big_number == NULL || (*bn)->capacity <= 0 || (*bn)->size<0 || (*bn)->size>(*bn)->capacity)) {
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
    if(bn == NULL || big_number == NULL || bn->big_number == NULL || bn->capacity <=  0 || bn->size < 0 || bn->size > bn->capacity || validate( big_number)!=0)
        return 1;
    if(bn->size==bn->capacity)
        return 3;

    int l=strlen(big_number);
    *(bn->big_number+bn->size)=(char*)calloc(l+1,sizeof(char));
    if(*(bn->big_number+bn->size)==NULL)
        return 2;
    for(int i=0;i<l;++i)
    {
        *(*(bn->big_number+bn->size)+i)=*(big_number+i);
    }
    bn->size++;
    return 0;
}

void display(const struct big_numbers_t *bn) {
    if(!(bn == NULL || bn->big_number == NULL || bn->capacity <=  0 || bn->size < 0 || bn->size > bn->capacity))
    {
        for(int i=0;i<bn->size;++i)
        {
            printf("%s\n",*(bn->big_number+i));
        }
    }
}
