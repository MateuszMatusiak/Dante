#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

union double_to_char_t
{
    double d;
    char tab[8];
};
int save_double(const union double_to_char_t *dtc, const char *filename)
{
    if(dtc==NULL||filename==NULL)
        return 1;
    int x;
    FILE *f;
    f=fopen(filename,"wb");
    if(f==NULL)
        return 2;
    x=fwrite(dtc->tab,sizeof(union double_to_char_t),1,f);
    if(x!=1)
    {
        fclose(f);
        return 3;
    }
    fclose(f);
    return 0;
}
int load_double(union double_to_char_t *dtc, const char *filename)
{
    if(dtc==NULL||filename==NULL)
        return 1;
    FILE *f;
    int x;
    f=fopen(filename,"rb");
    if(f==NULL)
        return 2;
    x=fread(dtc->tab,sizeof(union double_to_char_t),1,f);
    if(x!=1)
    {
        fclose(f);
        return 3;
    }
    fclose(f);
    return 0;
}
int main()
{
    double y;
    int t;
    union double_to_char_t p;
    char nz[40];
    printf("Daj: ");
    t=scanf("%lf",&y);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    while (getchar () != '\n' );
    p.d=y;
    printf("Daj: ");
    scanf("%39[^\n]",nz);
    t=save_double(&p,nz);
    if(t==2)
    {
        printf("couldn't create file");
        return 5;
    }
    if(t==3)
    {
        printf("File corrupted");
        return 6;
    }
    printf("File saved\n");
    while (getchar () != '\n' );
    printf("Daj: ");
    scanf("%39[^\n]",nz);
    t=load_double(&p,nz);
    if(t==2)
    {
        printf("couldn't open file");
        return 4;
    }
    if(t==3)
    {
        printf("File corrupted");
        return 6;
    }
    printf("%lf",p.d);
    return 0;
}

