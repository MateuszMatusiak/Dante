#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main() {
    struct doubly_linked_list_t *xd;
    xd = dll_create();
    if (xd == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    int c;
    while (1) {
        printf("Daj: ");
        int t = scanf("%d", &c);
        if (t != 1) {
            printf("Incorrect input");
            dll_clear(xd);
            free(xd);
            return 1;
        }
        if (c == 0)
            break;
        else if (c == 1) {
            printf("Daj: ");
            int x;
            t = scanf("%d", &x);
            if (t != 1) {
                printf("Incorrect input");
                dll_clear(xd);
                free(xd);
                return 1;
            }
            t = dll_push_back(xd, x);
            if (t != 0) {
                printf("Failed to allocate memory");
                dll_clear(xd);
                free(xd);
                return 8;
            }
        } else if (c == 2) {
            int err;
            int x = dll_pop_back(xd, &err);
            if (err != 0) {
                printf("List is empty\n");
            } else
                printf("%d\n", x);
        } else if (c == 3) {
            printf("Daj: ");
            int x;
            t = scanf("%d", &x);
            if (t != 1) {
                printf("Incorrect input");
                dll_clear(xd);
                free(xd);
                return 1;
            }
            t = dll_push_front(xd, x);
            if (t != 0) {
                printf("Failed to allocate memory");
                dll_clear(xd);
                free(xd);
                return 8;
            }
        } else if (c == 4) {
            int err;
            int x = dll_pop_front(xd, &err);
            if (err != 0) {
                printf("List is empty\n");
            } else
                printf("%d\n", x);
        } else if (c == 5) {
            printf("Daj: ");
            int x;
            t = scanf("%d", &x);
            if (t != 1) {
                printf("Incorrect input");
                dll_clear(xd);
                free(xd);
                return 1;
            }
            printf("Daj: ");
            unsigned int n;
            t = scanf("%u", &n);
            if (t != 1) {
                printf("Incorrect input");
                dll_clear(xd);
                free(xd);
                return 1;
            }
            t = dll_insert(xd, n, x);
            if (t == 1) {
                printf("Index out of range\n");
            }
            if (t == 2) {
                printf("Failed to allocate memory");
                dll_clear(xd);
                free(xd);
                return 8;
            }

        } else if (c == 6) {
            if (dll_is_empty(xd) == 1)
                printf("List is empty\n");
            else {
                printf("Daj: ");
                unsigned int n;
                t = scanf("%u", &n);
                if (t != 1) {
                    printf("Incorrect input");
                    dll_clear(xd);
                    free(xd);
                    return 1;
                }
                int err;
                int x = dll_remove(xd, n, &err);
                if (err != 0) {
                    printf("Index out of range\n");
                } else {
                    printf("%d\n", x);
                }
            }
        } else if (c == 7) {
            int err;
            int x = dll_back(xd, &err);
            if (err != 0) {
                printf("List is empty\n");
            } else {
                printf("%d\n", x);
            }

        } else if (c == 8) {
            int err;
            int x = dll_front(xd, &err);
            if (err != 0) {
                printf("List is empty\n");
            } else {
                printf("%d\n", x);
            }

        } else if (c == 9) {
            if (dll_is_empty(xd) == 1)
                printf("1\n");
            else
                printf("0\n");
        } else if (c == 10) {
            printf("%d\n", dll_size(xd));
        } else if (c == 11) {
            dll_clear(xd);
        } else if (c == 12) {
            if (dll_is_empty(xd) == 1)
                printf("List is empty\n");
            else {
                printf("Daj: ");
                unsigned int n;
                t = scanf("%u", &n);
                if (t != 1) {
                    printf("Incorrect input");
                    dll_clear(xd);
                    free(xd);
                    return 1;
                }
                int x = dll_at(xd, n, NULL);
                printf("%d\n", x);
            }
        } else if (c == 13) {
            if (dll_is_empty(xd) == 1)
                printf("List is empty\n");
            else {
                dll_display(xd);
                printf("\n");
            }
        } else if (c == 14) {
            if (dll_is_empty(xd) == 1)
                printf("List is empty\n");
            else{
                dll_display_reverse(xd);
                printf("\n");
            }
        }
        else
        {
            printf("Incorrect input data\n");
        }

    }
    dll_clear(xd);
    free(xd);
    return 0;
}


