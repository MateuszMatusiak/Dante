#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    struct linked_list_t *ll=ll_create();
    if(ll==NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    struct linked_list_t *ll2=ll_create();
    if(ll2==NULL)
    {
        printf("Failed to allocate memory");
        ll_clear(ll);
        free(ll);
        return 8;
    }

    printf("Daj: ");
    int x=0;
    while(1)
    {
        int t= scanf("%d",&x);
        if(t!=1)
        {
            printf("Incorrect input");
            ll_clear(ll);
            ll_clear(ll2);
            free(ll);
            free(ll2);

            return 1;
        }
        if(x==-1)
            break;
        t= ll_push_back(ll,x);
        if(t!=0)
        {
            printf("Failed to allocate memory");
            ll_clear(ll);
            ll_clear(ll2);
            free(ll);
            free(ll2);
            return 8;
        }
    }
    printf("Daj: ");
    x=0;
    while(1)
    {
        int t= scanf("%d",&x);
        if(t!=1)
        {
            printf("Incorrect input");
            ll_clear(ll);
            ll_clear(ll2);
            free(ll);
            free(ll2);
            return 1;
        }
        if(x==-1)
            break;
        t= ll_push_back(ll2,x);
        if(t!=0)
        {
            printf("Failed to allocate memory");
            ll_clear(ll);
            ll_clear(ll2);
            free(ll);
            free(ll2);
            return 8;
        }
    }

    if(ll_size(ll)==0|| ll_size(ll2)==0)
    {
        printf("Not enough data available");
        ll_clear(ll);
        ll_clear(ll2);
        free(ll);
        free(ll2);
        return 3;
    }
    int t=ll_remove_sequence(ll,ll2);
    printf("%d\n",t);
    if(ll_size(ll)==0)
    {
        printf("Nothing to show");
    }
    else
    {
        ll_display(ll);
    }
    ll_clear(ll);
    ll_clear(ll2);
    free(ll);
    free(ll2);
    return 0;
}


