#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dante.h"
#include "format_type.h"
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"


struct statistic_t {
    int min;
    int max;
    float avg;
    float standard_deviation;
    int range;
};


int load_bin(const char *filename, int ***ptr) {
    if (filename == NULL || ptr == NULL) {
        return 1;
    }
    FILE *f;
    f = fopen(filename, "rb");
    if (f == NULL) {
        return 2;
    }
    if(feof(f))
    {
        fclose(f);
        return 3;
    }
    int counter = 0, x=0;
    while (!feof(f)) {
        int t=fread(&x, sizeof(int), 1, f);
        if(t!=1&&!feof(f))
        {
            fclose(f);
            return 3;
        }
        if (x == -1) {
            counter++;
        }
    }
    if(counter==0)
    {
        fclose(f);
        return 3;
    }
    int **tab;
    tab=(int**)(calloc(counter,sizeof(int*)));
    if(tab==NULL)
    {
        fclose(f);
        return 4;
    }
    *(tab+counter-1)=NULL;
    int lines=counter;
    lines--;
    rewind(f);
    int i;
    for (i = 0; i < lines; ++i) {
        fpos_t pos;
        fgetpos(f, &pos);
        counter=0;
        do{
        fread(&x, sizeof(int), 1, f);
        counter++;
        }while(x!=-1);
        fsetpos(f,&pos);
        *(tab+i)=(int*)calloc(counter,sizeof(int));
        if(*(tab+i)==NULL)
        {
            for (int k = 0; k < i; ++k) {
                free(*(tab+k));
            }
            free(tab);
            fclose(f);
            return 4;
        }
        for(int k=0;k<counter;++k) {
            fread(&x, sizeof(int), 1, f);
            *(*(tab +i)+k)=x;
        }
    }
    *(tab+lines)=NULL;
    *ptr=tab;
    fclose(f);
    return 0;
}

int load_txt(const char *filename, int ***ptr) {
    if(filename==NULL||ptr==NULL)
    {
        return 1;
    }
    FILE *f;
    f=fopen(filename,"r");
    if(f==NULL)
    {
        return 2;
    }
    int x=0,counter=0;
    if(feof(f)) {
        fclose(f);
        return 3;
    }
    while(!feof(f))
    {
        int t=fscanf(f,"%d", &x);
        if(t!=1&&!feof(f))
        {
            fclose(f);
            return 3;
        }
        if(x==-1) {
            counter++;
        }
    }
    if(counter==0)
    {
        fclose(f);
        return 3;
    }
    rewind(f);
    int lines=counter;
    lines--;
    int **tab;
    tab=(int**)calloc(counter,sizeof(int*));
    if(tab==NULL)
    {
        fclose(f);
        return 4;
    }
    *(tab+counter-1)=NULL;
    int i;
    for (i = 0; i < lines; ++i) {
        fpos_t pos;
        fgetpos(f, &pos);
        counter=0;
        do{
            fscanf(f,"%d", &x);
            counter++;
        }while(x!=-1);
        fsetpos(f,&pos);
        *(tab+i)=(int*)calloc(counter,sizeof(int));
        if(*(tab+i)==NULL)
        {
            for (int k = 0; k < i; ++k) {
                free(*(tab+k));
            }
            free(tab);
            fclose(f);
            return 4;
        }
        for(int k=0;k<counter;++k) {
            fscanf(f,"%d", &x);
            *(*(tab +i)+k)=x;
        }
    }
    *(tab+lines)=NULL;
    *ptr=tab;
    fclose(f);
    return 0;
}

int load(const char *filename, int ***ptr, enum save_format_t format) {
    if (filename == NULL || ptr == NULL)
        return 1;
    if (format == fmt_binary) {
        return load_bin(filename, ptr);
    } else if (format == fmt_text) {
        return load_txt(filename, ptr);
    }
    return 1;
}

int statistics_row(int **ptr, struct statistic_t **stats) {
    if (ptr == NULL || stats == NULL)
        return -1;
    int iletab = 0, i = 0, k = 0;
    while (*(ptr + iletab) != NULL)
        iletab++;
    *stats = (struct statistic_t *) calloc(iletab, sizeof(struct statistic_t));
    if (*stats == NULL) {
        return -2;
    }

    for (i = 0; i < iletab; ++i) {
        (*stats + i)->min = **(ptr + i);
        (*stats + i)->max = **(ptr + i);
        (*stats + i)->avg = 0;
        (*stats + i)->standard_deviation = 0;

        k = 0;
        while (*(*(ptr + i) + k) != -1) {
            (*stats + i)->avg = (*stats + i)->avg + (float) (*(*(ptr + i) + k));
            (*stats + i)->standard_deviation = (*stats + i)->standard_deviation + pow((*(*(ptr + i) + k)), 2);
            if ((*stats + i)->min > *(*(ptr + i) + k))
                (*stats + i)->min = *(*(ptr + i) + k);
            if ((*stats + i)->max < *(*(ptr + i) + k))
                (*stats + i)->max = *(*(ptr + i) + k);
            k++;
        }
        if (k == 0) {
            (*stats + i)->range = -1;
            (*stats + i)->avg = -1;
            (*stats + i)->standard_deviation = -1;
            continue;
        }
        (*stats + i)->avg = ((*stats + i)->avg) / (float) k;
        (*stats + i)->standard_deviation = ((*stats + i)->standard_deviation) / (float) k;
        (*stats + i)->standard_deviation = ((*stats + i)->standard_deviation) - pow((*stats + i)->avg, 2);
        (*stats + i)->standard_deviation = sqrt((*stats + i)->standard_deviation);
        (*stats + i)->range = (*stats + i)->max - (*stats + i)->min;
    }
    return iletab;
}

void destroy(int ***ptr) {
    if (ptr != NULL) {
        int i = 0;
        while (*(*ptr + i) != NULL) {
            free(*(*ptr + i));
            i++;
        }
        if (*ptr != NULL)
            free(*ptr);
    }
}

void display(int **ptr) {
    if(ptr==NULL)
    {
        return;
    }
    int i=0,k=0;
    while(*(ptr+i)!=NULL)
    {
        k=0;
        while((*(*(ptr+i)+k)!=-1)&&*(ptr+i)!=NULL)
        {
            printf("%d ",*(*(ptr+i)+k));
            k++;
        }
        printf("\n");
        i++;
    }
}

int main() {
    struct statistic_t *stats;
    char* nz=(char*)calloc(40,sizeof(char));
    if(nz==NULL)
    {
        return r8();
    }
    int t,q;
    printf("Daj:");
    scanf("%39s",nz);
    int **ptr;
    if(str_endswith(nz,".txt"))
    {
       t=load(nz,&ptr,fmt_text);
        switch (t) {
            case 1: {
                free(nz);
                return r1();
                break;
            }
            case 2: {
                free(nz);
                return r4();
                break;
            }
            case 3: {
                free(nz);
                return r6();
                break;
            }
            case 4: {
                free(nz);
                return r8();
                break;
            }
        }
            q=statistics_row(ptr,&stats);
            switch(q){
                case -1:
                {
                    free(nz);
                 return r1();
                break;
                }
                case -2:
                {
                    free(nz);
                    return r8();
                    break;
                }
            }
            for(int i=0;i<q;++i)
            {
                printf("%d %d %d %f %f\n",(stats+i)->min,(stats+i)->max,(stats+i)->range,(stats+i)->avg,(stats+i)->standard_deviation);
            }
            free(nz);
            destroy(&ptr);
            free(stats);
            return 0;
    }
    else if(str_endswith(nz,".bin"))
    {
        t=load(nz,&ptr,fmt_binary);
        switch (t) {
            case 1: {
                free(nz);
                return r1();
                break;
            }
            case 2: {
                free(nz);
                return r4();
                break;
            }
            case 3: {
                free(nz);
                return r6();
                break;
            }
            case 4: {
                free(nz);
                return r8();
                break;
            }
        }
        q=statistics_row(ptr,&stats);
        switch(q){
            case -1:
            {
                free(nz);
                return r1();
                break;
            }
            case -2:
            {
                free(nz);
                return r8();
                break;
            }
        }
        for(int i=0;i<q;++i)
        {
            printf("%d %d %d %f %f\n",(stats+i)->min,(stats+i)->max,(stats+i)->range,(stats+i)->avg,(stats+i)->standard_deviation);
        }
        free(nz);
        destroy(&ptr);
        free(stats);
        return 0;
    }
    else
    {
        free(nz);
        return r7();
    }
    return 0;
}

