#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"


char *lower_to_upper(const char *in) {
    if (in == NULL)
        return NULL;
    char *xd = (char *) calloc(strlen(in) + 1, sizeof(char));
    if (xd == NULL)
        return NULL;
    strcpy(xd, in);
    int i = 0;
    while (*(in + i) != '\0') {
        if (islower(*(in + i))) {
            *(xd + i) = toupper(*(xd + i));
        }
        i++;
    }
    return xd;
}

char *upper_to_lower(const char *in) {
    if (in == NULL)
        return NULL;
    char *xd = (char *) calloc(strlen(in) + 1, sizeof(char));
    if (xd == NULL)
        return NULL;
    strcpy(xd, in);
    int i = 0;
    while (*(in + i) != '\0') {
        if (!islower(*(in + i))) {
            *(xd + i) = tolower(*(xd + i));
        }
        i++;
    }
    return xd;
}

char *space_to_dash(const char *in) {
    if (in == NULL)
        return NULL;
    char *xd = (char *) calloc(strlen(in) + 1, sizeof(char));
    if (xd == NULL)
        return NULL;
    strcpy(xd, in);
    int i = 0;
    while (*(in + i) != '\0') {
        if (*(in + i) == ' ') {
            *(xd + i) = '_';
        }
        i++;
    }
    return xd;
}

char *reverse_letter(const char *in) {
    if (in == NULL)
        return NULL;
    char *xd = (char *) calloc(strlen(in) + 1, sizeof(char));
    if (xd == NULL)
        return NULL;
    strcpy(xd, in);
    int i = 0;
    while (*(in + i) != '\0') {

        if (isupper(*(in + i))) {
            *(xd + i) = 'Z' - ((*(in + i)) - 'A');
        }
        if (islower(*(in + i))) {
            *(xd + i) = 'z' - ((*(in + i)) - 'a');
        }
        i++;
    }
    return xd;
}

void free_texts(char **text) {
    if (text != NULL) {
        int i = 0;
        while (*(text + i) != NULL) {
            free(*(text + i));
            ++i;
        }
        free(text);
    }
}

