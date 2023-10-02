#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "big_numbers.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    struct big_numbers_t *bn;
    int t = create_big_numbers(&bn, 10);
    if (t != 0) {
        printf("Failed to allocate memory\n");
        return 8;
    }
    char *x = (char *) calloc(201, sizeof(char));
    if (x == NULL) {
        destroy_big_numbers(&bn);
        printf("Failed to allocate memory\n");
        return 8;
    }
    printf("Daj:");
    while (1) {
        memset(x,'\0',200);
        scanf("%200[^\n]", x);
        if (*x == '\0'||*x=='\n'||strlen(x)<1)
            break;
        if (validate(x) != 0) {
            printf("Incorrect input\n");
            while (getchar () != '\n' );
            continue;
        }
        t = add_big_number(bn, x);
        if (t == 1) {
            printf("Incorrect input\n");
            while (getchar () != '\n' );
            continue;
        }
        if (t == 2) {
            printf("Failed to allocate memory\n");
            break;
        }
        if (t == 3) {
            printf("Buffer is full\n");
            break;
        }
        while (getchar () != '\n' );
    }
    if (bn->size == 0) {
        printf("Buffer is empty\n");
        destroy_big_numbers(&bn);
        free(x);
        return 0;
    }
    display(bn);
    destroy_big_numbers(&bn);
    free(x);
    return 0;
}

