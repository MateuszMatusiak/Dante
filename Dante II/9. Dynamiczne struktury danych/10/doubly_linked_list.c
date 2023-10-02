#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "tested_declarations.h"
#include "rdebug.h"

struct doubly_linked_list_t *dll_create() {
    struct doubly_linked_list_t *xd = (struct doubly_linked_list_t *) calloc(1, sizeof(struct doubly_linked_list_t));
    if (xd == NULL)
        return NULL;
    xd->head = NULL;
    xd->tail = NULL;
    return xd;
}

int dll_push_back(struct doubly_linked_list_t *dll, int value) {
    if (dll == NULL)
        return 1;
    struct node_t *x = (struct node_t *) calloc(1, sizeof(struct node_t));
    if (x == NULL)
        return 2;
    x->data = value;
    x->next = NULL;
    if (dll->head != NULL) {
        x->prev = dll->tail;
        dll->tail->next = x;
    } else {
        dll->head = x;
        x->prev = NULL;
    }
    dll->tail = x;
    return 0;
}

int dll_push_front(struct doubly_linked_list_t *dll, int value) {
    if (dll == NULL)
        return 1;
    struct node_t *x = (struct node_t *) calloc(1, sizeof(struct node_t));
    if (x == NULL)
        return 2;
    x->data = value;
    x->next = NULL;
    if (dll->head != NULL) {
        x->next = dll->head;
        dll->head->prev = x;
    } else {
        dll->tail = x;
        x->next = NULL;
    }
    dll->head = x;
    return 0;
}

int dll_pop_front(struct doubly_linked_list_t *dll, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (dll == NULL || dll->head == NULL || dll->tail == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }

    struct node_t *xd = dll->head;
    int x = xd->data;
    if (xd->next != NULL) {
        xd->next->prev = NULL;
        dll->head = xd->next;
        free(xd);
    } else {
        dll->head = NULL;
        dll->tail = NULL;
        free(xd);
    }
    return x;
}

int dll_pop_back(struct doubly_linked_list_t *dll, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (dll == NULL || dll->head == NULL || dll->tail == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }

    struct node_t *xd = dll->tail;
    int x = xd->data;
    if (xd->prev != NULL) {
        xd->prev->next = NULL;
        dll->tail = xd->prev;
        free(xd);
    } else {
        dll->head = NULL;
        dll->tail = NULL;
        free(xd);
    }
    return x;
}

int dll_back(const struct doubly_linked_list_t *dll, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (dll == NULL || dll->head == NULL || dll->tail == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }
    return dll->tail->data;
}

int dll_front(const struct doubly_linked_list_t *dll, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (dll == NULL || dll->head == NULL || dll->tail == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }
    return dll->head->data;
}

struct node_t *dll_begin(struct doubly_linked_list_t *dll) {
    if (dll == NULL || dll->head == NULL || dll->tail == NULL)
        return NULL;
    return dll->head;
}

struct node_t *dll_end(struct doubly_linked_list_t *dll) {
    if (dll == NULL || dll->head == NULL || dll->tail == NULL)
        return NULL;
    return dll->tail;
}

int dll_size(const struct doubly_linked_list_t *dll) {
    if (dll == NULL)
        return -1;
    int s = 0;
    struct node_t *xd = dll->tail;
    while (xd != NULL) {
        xd = xd->prev;
        s++;
    }
    return s;
}

int dll_is_empty(const struct doubly_linked_list_t *dll) {
    if (dll == NULL)
        return -1;
    if (dll_size(dll) == 0)
        return 1;
    return 0;
}

int dll_at(const struct doubly_linked_list_t *dll, unsigned int index, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (dll == NULL || dll_size(dll) < (int) index) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }
    struct node_t *xd = dll->head;
    int i = 0;
    while (i < (int) index) {
        if (xd == NULL || xd->next == NULL) {
            if (err_code != NULL)
                *err_code = 1;
            return 1;
        }
        xd = xd->next;
        ++i;
    }
    return xd->data;
}

int dll_insert(struct doubly_linked_list_t *dll, unsigned int index, int value) {
    if (dll == NULL || dll_size(dll) < (int) index) {
        return 1;
    }
    if(index==0) {
        int t = dll_push_front(dll, value);
        return t;
    }
    if((int)index== dll_size(dll)) {
        int t = dll_push_back(dll, value);
        return t;
    }

    struct node_t *xd = (struct node_t *) calloc(1, sizeof(struct node_t));
    if (xd == NULL) {
        return 2;
    }


    struct node_t *xd1 = dll->head;
    int i = 0;
    while (i < (int) index) {
        if (xd1 == NULL) {
            free(xd);
            return 1;
        }
        xd1 = xd1->next;
        ++i;
    }
    if(xd1->prev==NULL||xd1->prev->next==NULL)
    {
        free(xd);
        return 1;
    }


    xd->next = xd1;
    xd->prev = xd1->prev;
    xd->data = value;
    if(xd->prev->next!=NULL)
        xd->prev->next=xd;
    xd1->prev = xd;

    return 0;
}

int dll_remove(struct doubly_linked_list_t *dll, unsigned int index, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (dll == NULL ||(int)index<0|| dll_size(dll) <= (int) index || dll_is_empty(dll) == 1) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }

    if(index==0) {
        int t = dll_pop_front(dll, err_code);
        return t;
    }
    if((int)index== dll_size(dll)-1) {
        int t = dll_pop_back(dll, err_code);
        return t;
    }

    struct node_t *xd = dll->head;
    int i = 0;
    while (i < (int) index) {
        if (xd == NULL) {
            if (err_code != NULL)
                *err_code = 1;
            return 1;
        }
        xd = xd->next;
        ++i;
    }

    int x = xd->data;
    xd->next->prev = xd->prev;
    xd->prev->next = xd->next;
    free(xd);
    return x;
}

void dll_clear(struct doubly_linked_list_t *dll) {
    if (dll != NULL) {
        struct node_t *xd, *xd2;
        xd = dll->head;
        while (xd != NULL) {
            xd2 = xd->next;
            free(xd);
            xd = xd2;
        }
        dll->head=NULL;
        dll->tail=NULL;
    }
}

void dll_display(const struct doubly_linked_list_t *dll) {
    if (dll != NULL) {
        struct node_t *xd = dll->head;
        while (xd != NULL) {
            printf("%d ", xd->data);
            xd = xd->next;
        }
    }
}

void dll_display_reverse(const struct doubly_linked_list_t *dll) {
    if (dll != NULL) {
        struct node_t *xd = dll->tail;
        while (xd != NULL) {
            printf("%d ", xd->data);
            xd = xd->prev;
        }
    }
}


