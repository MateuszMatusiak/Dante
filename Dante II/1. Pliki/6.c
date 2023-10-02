#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main()
{
    int i;
    FILE *p2,*p3,*p5,*p0;
    p2=fopen("2.txt","w");

    if(p2==NULL)
    {
        printf("couldn't create file");
        return 5;
    }
    p3=fopen("3.txt","w");


    if(p3==NULL)
    {
        fclose(p2);
        printf("couldn't create file");
        return 5;
    }
    p5=fopen("5.txt","w");
    if(p5==NULL)
    {
        fclose(p3);
        fclose(p2);
        printf("couldn't create file");
        return 5;
    }
    p0=fopen("0.txt","w");
    if(p0==NULL)
    {
        fclose(p3);
        fclose(p5);
        fclose(p2);
        printf("couldn't create file");
        return 5;
    }
    printf("Daj: ");
    while(1)
    {
        scanf("%d",&i);
        if(i==0)
            break;
        if(i%2==0)
        {
            fprintf(p2, "%d\n", i);
        }
        if(i%3==0)
        {
            fprintf(p3, "%d\n", i);
        }
        if(i%5==0)
        {
            fprintf(p5, "%d\n", i);
        }
        if(i%2!=0&&i%3!=0&&i%5!=0)
        {
            fprintf(p0, "%d\n", i);
        }

    }

    fclose(p2);
    fclose(p3);
    fclose(p5);
    fclose(p0);
    printf("Files saved");
    return 0;
}

