#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"


int stack_init(struct stack_t **stack) {
    if (stack == NULL)
        return 1;
    struct stack_t *xd = (struct stack_t *) calloc(1, sizeof(struct stack_t));
    if (xd == NULL) {
        return 2;
    }
    xd->head = NULL;
    *stack = xd;
    return 0;
}

int stack_push(struct stack_t *stack, double value) {
    if (stack == NULL)
        return 1;
    struct node_t *q;
    q = (struct node_t *) calloc(1, sizeof(struct node_t));
    if (q == NULL) {
        return 2;
    }
    q->data = value;
    q->next = stack->head;
    stack->head = q;
    return 0;
}

void stack_display(const struct stack_t *stack) {
    if (stack != NULL) {
        struct node_t *q = stack->head;
        while (q != NULL) {
            printf("%f ", q->data);
            q = q->next;
        }
    }
}

double stack_pop(struct stack_t *stack, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (stack == NULL || stack->head == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }
    double x = stack->head->data;
    struct node_t *q = stack->head->next;
    free(stack->head);
    stack->head = q;
    return x;
}

void stack_destroy(struct stack_t **stack) {
    if (stack != NULL && *stack != NULL) {
        struct stack_t *xd = *stack;
        struct node_t *q;
        while (xd->head != NULL) {
            q = xd->head->next;
            free(xd->head);
            xd->head = q;
        }
        free(xd);
        *stack = NULL;
    }
}

int stack_empty(const struct stack_t *stack) {
    if (stack == NULL) { return 2; }
    if (stack->head != NULL)
        return 0;
    return 1;
}

int stack_size(const struct stack_t *stack) {
    if (stack == NULL)
        return -1;
    struct node_t *q = stack->head;
    int c=0;
    while (q != NULL) {
        c++;
        q = q->next;
    }
    return c;

}
