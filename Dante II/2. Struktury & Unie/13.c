#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct message_t {
    char a;
    double b;
    int c;
};

int load_data(struct message_t *cp, int size, const char *filename) {
    if (cp == NULL || size <= 0 || filename == NULL) {
        return -1;
    }
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
        return -2;
    int x;
    int t = fread(&x, sizeof(int), 1, f);
    if (t != 1) {
        fclose(f);
        return -3;
    }
    if (x % 24 != 0) {
        fclose(f);
        return -3;
    }
    int p=x/24;
    x = x > size ? size : x;
    if(x<=0)
    {
        fclose(f);
        return -3;
    }
    fread(cp, sizeof(struct message_t), x, f);
    fclose(f);
    return p;
}

int decode_message(const struct message_t *cp, int size, char *msg, int text_size) {
    if (cp == NULL || size <= 0 || msg == NULL || text_size <= 0) {
        return 1;
    }
    strcpy(msg, "");
    if(text_size==1)
        return 0;
    int s1,s2;
    int i = 0;
    while (i < size) {
        s1 = sizeof(double) - sizeof(char);
        s2 = sizeof(double) - sizeof(int);
        char *xd = (char *) (cp + i);
        if((int)strlen(msg)+s1>text_size-1)
        {
            s1=text_size- (int)strlen(msg)-1;
        }
        strncat(msg, (xd + sizeof(char)), s1);
        if((int)strlen(msg)+s2>text_size-1)
        {
            s2=text_size- (int)strlen(msg)-1;
        }
        strncat(msg, (xd + 2*sizeof(double) + sizeof(int)), s2);
        ++i;
    }
    *(msg+i*11)='\0';
    return 0;
}

int main() {
    char nz[31];
    struct message_t xd[100];
    char txt[1100];
    printf("Daj: ");
    scanf("%30[^\n]",nz);
    int t= load_data(xd,100,nz);
    if(t==-1)
    {
        printf("Incorrect input");
        return 1;
    }
    if(t==-2)
    {
        printf("Couldn't open file");
        return 4;
    }
    if(t==-3)
    {
        printf("File corrupted");
        return 6;
    }
    int t1= decode_message(xd,t,txt,1101);
    if(t1==1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%s",txt);
    return 0;
}


