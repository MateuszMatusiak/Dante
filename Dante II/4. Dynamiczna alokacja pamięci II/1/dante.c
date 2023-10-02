#include "dante.h"
#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int ii()
{
    printf("Incorrect input\n");
    return 1;
}
int id()
{
    printf("Incorrect input data\n");
    return 2;
}
int io()
{
    printf("Couldn't open file\n");
    return 4;
}
int ic()
{
    printf("Couldn't create file\n");
    return 5;
}
int uf()
{
    printf("Unsupported file format\n");
    return 7;
}
int fa()
{
    printf("Failed to allocate memory\n");
    return 8;
}

