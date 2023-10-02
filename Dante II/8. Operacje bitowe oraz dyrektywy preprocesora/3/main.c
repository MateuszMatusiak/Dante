#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

void show(const void* ptr, size_t count)
{
    if(ptr!=NULL)
    {
        unsigned char z;
        unsigned int i;
        char *x;
        x=(char*)ptr;
        for(i=0; i<count; i++)
        {
            z=*(x+i*sizeof(char));
            printf("%02x ",z);
        }
    }
}
void inverse_bits(void* ptr, size_t offset, size_t count)
{
    if(ptr!=NULL&&count>0)
    {
        unsigned int i;
        char *x;
        x=(char*)ptr;
        for(i=offset; i<offset+count; i++)
            *(x+i*sizeof(char))=~(*(x+i*sizeof(char)));
    }
}
int main()
{
    char tab[101];
    unsigned int l;
    printf("Daj: ");
    fgets(tab, 101, stdin);
    l=strlen(tab);
    tab[l-1]='\0';
    show(tab,l);
    printf("\n");
    inverse_bits(tab,0,l);
    show(tab,l);
    return 0;
}


