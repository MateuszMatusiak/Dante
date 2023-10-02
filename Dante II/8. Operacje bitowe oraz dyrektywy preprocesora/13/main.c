#include <stdio.h>
#include "functions.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    int q;
    printf("Daj: ");
    int t = scanf("%d", &q);
    if (t != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (q == 0) {
        wetam(unsigned int, "%u")
    } else if (q == 1) {
        wetam(unsigned short, "%hu")
    } else if (q == 2) {
        wetam(unsigned long, "%lu")
    } else {
        printf("Incorrect input data");
        return 2;
    }

    return 0;
}

