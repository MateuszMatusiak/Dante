#include <stdio.h>
#include <stdlib.h>
#include "dante.h"
#include "matrix_utils.h"
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"




int main() {
    int t,w,h,x;
    struct matrix_t *m;
    char *nz;

    pd();
    t=scanf("%d %d",&w,&h);
    if(t!=2) {
        return r1();
    }
    if(w<=0||h<=0) {
        return r2();
    }
    m=matrix_create_struct(w,h);
    if(m==NULL) {
        return r8();
    }
    pd();
    t=matrix_read(m);
    if(t!=0) {
        matrix_destroy_struct(&m);
        return r1();
    }
    nz=(char*)calloc(40,sizeof(char));
    if(nz==NULL){
        matrix_destroy_struct(&m);
        return r8();
    }
    while (getchar () != '\n' );
    pd();
    scanf("%39[^\n]",nz);
    x=strlen(nz);
    struct matrix_t *p=matrix_transpose(m);
    if(p==NULL)
    {
        free(nz);
        matrix_destroy_struct(&m);
        return r8();
    }
    matrix_destroy_struct(&m);
    if(*(nz+x-4)=='.'&&*(nz+x-3)=='b'&&*(nz+x-2)=='i'&&*(nz+x-1)=='n'){
        t=matrix_save_b(p,nz);
        if(t!=0){
            free(nz);
            matrix_destroy_struct(&p);
            return r5();
        }
    }
    else if(*(nz+x-4)=='.'&&*(nz+x-3)=='t'&&*(nz+x-2)=='x'&&*(nz+x-1)=='t')
    {
        t=matrix_save_t(p,nz);
        if(t!=0){
            free(nz);
            matrix_destroy_struct(&p);
            return r5();
        }
    }
    else
    {
        free(nz);
        matrix_destroy_struct(&p);
        return r7();
    }
    fs();
    free(nz);
    matrix_destroy_struct(&p);
    return 0;
}


