#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "tested_declarations.h"
#include "rdebug.h"

struct linked_list_t *ll_create() {
    struct linked_list_t *xd = (struct linked_list_t *) calloc(1, sizeof(struct linked_list_t));
    if (xd == NULL)
        return NULL;
    xd->head = NULL;
    xd->tail = NULL;
    return xd;
}

int ll_push_back(struct linked_list_t *ll, int value) {
    if (ll == NULL)
        return 1;
    struct node_t *x = (struct node_t *) calloc(1, sizeof(struct node_t));
    if (x == NULL)
        return 2;
    x->data = value;
    x->next = NULL;
    if (ll->head != NULL) {
        ll->tail->next = x;
    } else {
        ll->head = x;
    }
    ll->tail = x;
    return 0;
}

int ll_push_front(struct linked_list_t *ll, int value) {
    if (ll == NULL)
        return 1;
    struct node_t *x = (struct node_t *) calloc(1, sizeof(struct node_t));
    if (x == NULL)
        return 2;
    x->data = value;
    x->next = NULL;
    if (ll->head != NULL) {
        x->next = ll->head;
    } else {
        ll->tail = x;
        x->next = NULL;
    }
    ll->head = x;
    return 0;
}

int ll_pop_front(struct linked_list_t *ll, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (ll == NULL || ll->head == NULL || ll->tail == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }

    struct node_t *xd = ll->head;
    int x = xd->data;
    if (xd->next != NULL) {
        ll->head = xd->next;
        free(xd);
    } else {
        ll->head = NULL;
        ll->tail = NULL;
        free(xd);
    }
    return x;
}

int ll_pop_back(struct linked_list_t *ll, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (ll == NULL || ll->head == NULL || ll->tail == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }

    if(ll->head->next==NULL)
    {
        int x=ll->head->data;
        free(ll->head);
        ll->head=NULL;
        ll->tail=NULL;
        return x;
    }

    struct node_t *xd = ll->head;
    struct node_t *xd1=ll->head;
    while(xd->next!=NULL)
    {
        xd1=xd;
        xd=xd->next;
    }

    ll->tail=xd1;
    int x = xd->data;
    free(xd);
    xd1->next=NULL;
    return x;
}

int ll_back(const struct linked_list_t *ll, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (ll == NULL || ll->head == NULL || ll->tail == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }
    return ll->tail->data;
}

int ll_front(const struct linked_list_t *ll, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (ll == NULL || ll->head == NULL || ll->tail == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }
    return ll->head->data;
}

struct node_t *ll_begin(struct linked_list_t *ll) {
    if (ll == NULL || ll->head == NULL || ll->tail == NULL)
        return NULL;
    return ll->head;
}

struct node_t *ll_end(struct linked_list_t *ll) {
    if (ll == NULL || ll->head == NULL || ll->tail == NULL)
        return NULL;
    return ll->tail;
}

int ll_size(const struct linked_list_t *ll) {
    if (ll == NULL)
        return -1;
    int s = 0;
    struct node_t *xd = ll->head;
    while (xd != NULL) {
        xd = xd->next;
        s++;
    }
    return s;
}

int ll_is_empty(const struct linked_list_t *ll) {
    if (ll == NULL)
        return -1;
    if (ll_size(ll) == 0)
        return 1;
    return 0;
}

int ll_at(const struct linked_list_t *ll, unsigned int index, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (ll == NULL || ll_size(ll) < (int) index) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }
    struct node_t *xd = ll->head;
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

int ll_insert(struct linked_list_t *ll, unsigned int index, int value) {
    if (ll == NULL ||(int)index<0|| ll_size(ll)< (int) index) {
        return 1;
    }
    if(index==0) {
        int t = ll_push_front(ll, value);
        return t;
    }
    if((int)index== ll_size(ll)) {
        int t = ll_push_back(ll, value);
        return t;
    }

    struct node_t *xd = (struct node_t *) calloc(1, sizeof(struct node_t));
    if (xd == NULL) {
        return 2;
    }


    struct node_t *xd1 = ll->head;
    struct node_t *xd2 = ll->head;


    int i = 0;
    while (i < (int) index) {
        if (xd1 == NULL) {
            free(xd);
            return 1;
        }
        xd2=xd1;
        xd1 = xd1->next;
        ++i;
    }


    xd->next = xd1;
    xd->data = value;
    xd2->next=xd;
    return 0;
}

int ll_remove(struct linked_list_t *ll, unsigned int index, int *err_code) {
    if (err_code != NULL)
        *err_code = 0;
    if (ll == NULL ||(int)index<0|| ll_size(ll) <= (int) index || ll_is_empty(ll) == 1) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }

    if(index==0) {
        int t = ll_pop_front(ll, err_code);
        return t;
    }
    if((int)index== ll_size(ll)-1) {
        int t = ll_pop_back(ll, err_code);
        return t;
    }

    struct node_t *xd = ll->head;
    struct node_t *xd1=NULL;
    int i = 0;
    while (i < (int) index) {
        if (xd == NULL) {
            if (err_code != NULL)
                *err_code = 1;
            return 1;
        }
        xd1=xd;
        xd = xd->next;
        ++i;
    }

    int x = xd->data;
    xd1->next = xd->next;
    free(xd);
    xd=NULL;
    return x;
}


void ll_clear(struct linked_list_t *ll) {
    if (ll != NULL) {
        struct node_t *xd, *xd2;
        xd = ll->head;
        while (xd != NULL) {
            xd2 = xd->next;
            free(xd);
            xd = xd2;
        }
        ll->head=NULL;
        ll->tail=NULL;
    }
}

void ll_display(const struct linked_list_t *ll) {
    if (ll != NULL) {
        struct node_t *xd = ll->head;
        while (xd != NULL) {
            printf("%d ", xd->data);
            xd = xd->next;
        }
    }
}

