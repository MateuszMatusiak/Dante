#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main(int argc, char* argv[]) {
    if(argc<3)
    {
        printf("Not enough arguments");
        return 9;
    }
    FILE *fr= fopen(*(argv+1),"rb");
    if(fr==NULL)
    {
        printf("Couldn't open file");
        return 4;
    }
    FILE *fw=fopen(*(argv+2),"wb");
    if(fw==NULL)
    {
        printf("Couldn't create file");
        fclose(fr);
        return 5;
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
    printf("File copied");
    return 0;
}

