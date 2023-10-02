#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_negative(int value) {
    if (value & 1 << 31)
        return 1;
    return 0;

}
int is_equal(int a, int b) {

    int x=a^b;
    if(x)
        return 0;
    return 1;
}




int main() {
    int x, y;
    printf("Daj: ");
    int t = scanf("%d %d", &x, &y);
    if (!t) {
        printf("Incorrect input");
        return 1;
    }
    printf("%s\n", is_equal(x, y) ? "rowne" : "nierowne");
    printf("%s %s", is_negative(x) ? "ujemna" : "nieujemna", is_negative(y) ? "ujemna" : "nieujemna");

    return 0;
}

