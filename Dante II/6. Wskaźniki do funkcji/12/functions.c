#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#include "tested_declarations.h"
#include "rdebug.h"

void *easter(int size, p chicken, p egg, p rabbit)
{
    if(size<=0||chicken==NULL||egg==NULL||rabbit==NULL)
        return NULL;
    srand(time(NULL));
    int i,w;
    p *funcs;
    funcs=(p*)calloc(size,sizeof(p));
    if(funcs==NULL)
    {
        return NULL;
    }
    for(i=0; i<size; i++)
    {
        w=rand()%3;
        if(w==0)
        {
            *(funcs+i)=chicken;
        }
        else if(w==1)
        {
            *(funcs+i)=egg;
        }
        else if(w==2)
        {
            *(funcs+i)=rabbit;
        }
    }
    return funcs;
}
void print_chicken(void)
{
    printf(" MM\n");
    printf("<' \\___/|\n");
    printf("  \\_  _/\n");
    printf("    ][\n");

}
void print_egg(void)
{
    printf("  .~~~.\n");
    printf(" /     \\\n");
    printf("(\\/\\/\\/\\)\n");
    printf(" \\     /\n");
    printf("  `~~~`\n");
}
void print_rabbit(void)
{
    printf(" \\\\   //\n");
    printf("  )\\-/(\n");
    printf("  /o o\\\n");
    printf(" ( =T= )\n");
    printf(" /'---'\\\n");
}

