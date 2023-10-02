#include "dante.h"
#include <stdio.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

int r1()
{
    printf("Incorrect input\n");
    return 1;
}
int r2()
{
    printf("Incorrect input data\n");
    return 2;
}
int r4()
{
    printf("Couldn't open file\n");
    return 4;
}
int r5()
{
    printf("Couldn't create file\n");
    return 5;
}
int r6()
{
    printf("File corrupted\n");
    return 6;
}
int r7()
{
    printf("Unsupported file format\n");
    return 7;
}
int r8()
{
    printf("Failed to allocate memory\n");
    return 8;
}
int str_endswith(char* txt, char* sub)
{
int lent=strlen(txt);
int lens=strlen(sub);
if(lens>lent)
    return 0;
int c=0;
for(int i=1;i<=lens;++i)
{
if(*(sub+lens-i)==*(txt+lent-i))
    c++;
}
if(c==lens)
    return 1;
return 0;
}



