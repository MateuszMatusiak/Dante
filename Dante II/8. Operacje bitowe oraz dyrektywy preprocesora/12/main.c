#include <stdio.h>
#include "functions.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    int x;
    printf("Daj: ");
    int t = scanf("%d", &x);
    if (t != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (x == 0) {
        int x1, x2;
        printf("Daj: ");
        t = scanf("%d %d", &x1, &x2);
        if (t != 2) {
            printf("Incorrect input");
            return 1;
        }

        printf("%d\n%d\n%d\n%d",SQR(x1), SQR(x2), MAX(x1, x2), MIN(x1, x2));
        return 0;
    } else if (x == 1) {
        float x1, x2;
        printf("Daj: ");
        t = scanf("%f %f", &x1, &x2);
        if (t != 2) {
            printf("Incorrect input");
            return 1;
        }
        printf("%f\n%f\n%f\n%f",SQR(x1), SQR(x2), MAX(x1, x2), MIN(x1, x2));
        return 0;
    } else {
        printf("Incorrect input data");
        return 2;
    }
    return 0;
}

