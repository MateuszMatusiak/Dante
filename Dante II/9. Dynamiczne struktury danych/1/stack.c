#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"

int stack_init(struct stack_t **stack, int N) {
    if (stack == NULL || N < 1) {
        return 1;
    }
    *stack = (struct stack_t *) calloc(1, sizeof(struct stack_t));
    if (*stack == NULL)
        return 2;
    (*stack)->data = (int *) calloc(N, sizeof(int));
    if ((*stack)->data == NULL) {
        free(*stack);
        *stack = NULL;
        return 2;
    }
    (*stack)->head = 0;
    (*stack)->capacity = N;
    return 0;
}

int stack_push(struct stack_t *stack, int value) {
    if (stack == NULL || stack->data == NULL || stack->capacity <= 0 || stack->head < 0||stack->head>stack->capacity)
        return 1;
    if(stack->head==stack->capacity)
    {
        int * q= realloc(stack->data,sizeof(int)*stack->capacity*2);
        if(q==NULL)
        {
            return 2;
        }
        stack->capacity*=2;
        stack->data=q;
    }
    *(stack->data+stack->head)=value;
    stack->head++;

    return 0;
}

int stack_pop(struct stack_t *stack, int *err_code) {
    if(err_code!=NULL)
        *err_code=0;

    if (stack == NULL || stack->data == NULL || stack->capacity <= 0 || stack->head < 0||stack->head>stack->capacity)
    {
        if(err_code!=NULL)
            *err_code=1;
        return 1;
    }
    if(stack->head == 0)
    {
        if(err_code!=NULL)
            *err_code=2;
        return 2;
    }
    stack->head--;
    int xd=*(stack->data+stack->head);
    return xd;
}

void stack_display(const struct stack_t *stack) {
    if (!(stack == NULL || stack->data == NULL || stack->capacity <= 0 || stack->head <= 0||stack->head>stack->capacity)) {
        for(int i=stack->head-1;i>=0;--i)
        {
            printf("%d ",*(stack->data+i));
        }
    }
}

void stack_free(struct stack_t *stack) {
    if(stack!=NULL)
    {
        if(stack->data!=NULL)
            free(stack->data);
        free(stack);
    }
}

