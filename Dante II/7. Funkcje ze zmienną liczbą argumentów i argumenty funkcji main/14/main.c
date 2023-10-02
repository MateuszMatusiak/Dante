#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main(int argc, char* argv[]) {
    if(argc<=2)
    {
        printf("Not enough arguments\n");
        return 9;
    }
    if(strcmp(*(argv+1),"-m")==0)
    {
        FILE *f=fopen(*(argv+2),"w");
        if(f==NULL)
        {
            printf("Couldn't create file\n");
            return 5;
        }
        printf("File created");
        fclose(f);
    }
    else if(strcmp(*(argv+1),"-c")==0)
    {
        if(argc<4)
        {
            printf("Not enough arguments\n");
            return 9;
        }
        FILE *fw=fopen(*(argv+2),"w");
        if(fw==NULL)
        {
            printf("Couldn't create file\n");
            return 5;
        }
        FILE *fr=fopen(*(argv+3),"r");
        if(fr==NULL)
        {
            fclose(fw);
            printf("Couldn't open file\n");
            return 4;
        }
        while(!feof(fr))
        {
            char xd;
            fread(&xd,sizeof(char),1,fr);
            if(feof(fr))
                break;
            fwrite(&xd,sizeof(char),1,fw);
        }
        fclose(fw);
        fclose(fr);
        printf("File copied\n");

    }
    else if(strcmp(*(argv+1),"-a")==0)
    {
        if(argc<4)
        {
            printf("Not enough arguments");
            return 9;
        }
        FILE *fr;
        FILE *fw=fopen(*(argv+2),"a");
        if(fw==NULL)
        {
            printf("Couldn't open file\n");
            return 4;
        }

        for(int i=3;i<argc;++i)
        {
            fr=fopen(*(argv+i),"r");
            if(fr==NULL)
            {
                printf("Couldn't open file: %s\n",*(argv+i));
                continue;
            }
            while(!feof(fr))
            {
                char xd;
                fread(&xd,sizeof(char),1,fr);
                if(feof(fr))
                    break;
                fwrite(&xd,sizeof(char),1,fw);
            }
            fclose(fr);
        }
        printf("File saved\n");
        fclose(fw);
    }
    else
    {
        printf("Incorrect command\n");
        return 10;
    }
    return 0;
}

