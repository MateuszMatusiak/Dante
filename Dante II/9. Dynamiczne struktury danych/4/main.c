#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Not enough arguments");
        return 9;
    }
    struct stack_t *xd;
    for (int i = 1; i < argc; ++i) {
        int t = stack_load(&xd, *(argv + i));
        if (t == 1) {
            printf("Incorrect input\n");
            continue;
        } else if (t == 2) {
            printf("Couldn't open file %s\n", *(argv + i));
            continue;
        } else if (t == 3) {
            printf("Failed to allocate memory");
            return 8;
        }
        t = stack_save(xd, *(argv + i));
        if (t == 1) {
            printf("Incorrect input\n");
            stack_destroy(&xd);
            continue;
        } else if (t == 2) {
            printf("Couldn't create file\n");
            stack_destroy(&xd);
            return 5;
        } else {
            printf("File %s saved\n", *(argv + i));
            stack_destroy(&xd);
        }
    }
    return 0;
}


