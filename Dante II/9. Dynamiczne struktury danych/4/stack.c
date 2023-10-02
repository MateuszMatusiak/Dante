#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"

int stack_push(struct stack_t **stack, char *value) {
    if (stack == NULL || value == NULL) {
        return 1;
    }
    struct stack_t *xd = (struct stack_t *) calloc(1, sizeof(struct stack_t));
    if (xd == NULL)
        return 2;
    xd->prev = *stack;
    xd->sentence = value;
    *stack = xd;
    return 0;
}

char *stack_pop(struct stack_t **stack, int *err_code) {
    if(err_code!=NULL)
        *err_code=0;
    if (stack == NULL || *stack == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return NULL;
    }
    char *v = (*stack)->sentence;
    struct stack_t *xd = *stack;
    (*stack) = (*stack)->prev;
    free(xd);
    return v;
}

void stack_destroy(struct stack_t **stack) {
    if (stack != NULL) {
        while ((*stack)!=NULL) {
            free((*stack)->sentence);
            free((*stack));
            (*stack)=(*stack)->prev;
        }
        free(*stack);
        *stack = NULL;
    }
}

int stack_load(struct stack_t **stack, const char *filename) {
    if (stack==NULL||filename == NULL||(*stack)!=NULL)
        return 1;
    FILE *f=fopen(filename,"r");
    if(f==NULL)
        return 2;
    fpos_t pos;
    while(!feof(f))
    {
        fgetpos(f,&pos);
        char ch=fgetc(f);
        int c=1;
        while(ch!='.'&&ch!='\0'&&ch!=-1)
        {
            c++;
            ch=fgetc(f);
        }
        if(ch=='\0'||ch==-1)
            break;
        fsetpos(f,&pos);
        char *xd=(char*)calloc(c+1,sizeof(char));
        if(xd==NULL)
        {
            stack_destroy(stack);
            fclose(f);
            return 3;
        }
        ch=fgetc(f);
        c=0;
        while(ch!='.')
        {
            *(xd+c)=ch;
            c++;
            ch=fgetc(f);
        }
        *(xd+c++)=ch;
        *(xd+c)='\0';
        int t=stack_push(stack,xd);
        if(t==1) {
            free(xd);
            stack_destroy(stack);
            fclose(f);
            return 1;
        }
        if(t==2) {
            free(xd);
            stack_destroy(stack);
            fclose(f);
            return 3;
        }
    }
    fclose(f);
    return 0;
}

int stack_save(const struct stack_t *stack, const char *filename) {
    if(stack==NULL||filename==NULL)
        return 1;
    FILE *f=fopen(filename,"w");
    if(f==NULL)
    {
        return 2;
    }
    const struct stack_t *xd= stack;
    while(xd!=NULL)
    {
        fprintf(f,"%s",xd->sentence);
        xd= xd->prev;
    }
    fclose(f);
    return 0;
}

