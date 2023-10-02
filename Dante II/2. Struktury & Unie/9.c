#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int read_bo_fscanf_nie_dziala(char *t, int sz,FILE *f)
{
    int i=0,c=0;
    char s;
    s=getc(f);
    while(s!='|'&&s!='\n')
    {
        if(s==' ')
        {
            if(c==0)
            {
                s=getc(f);
                continue;
            }
            else
            {
                if(i==sz-1)
                    return 0;
                *(t+i)=s;
                i++;
                s=getc(f);
                if(s=='|')
                {
                    *(t+i-1)='\0';
                    return 1;
                }
                continue;
            }
        }
        if((s>='a'&&s<='z')||(s>='A'&&s<='Z')||s=='.')
        {
            if(i==sz-1)
                return 0;
            *(t+i)=s;
            i++;
            s=getc(f);
            c=1;
        }
        else
            return 0;

    }
    if(s=='\n'||c==0)
        return 0;
    *(t+i)='\0';
    return 1;
}

struct entry_t
{
    char name[20];
    char last_name[40];
    int number;
};
/*
void display(const struct entry_t* p)
{
    if(p!=NULL)
    {
        printf("Name: %s\n",p->name);
        printf("Last name: %s\n",p->last_name);
        printf("Phone number: %d\n",p->number);
    }

}
*/


int load_phonebook_t(const char *filename, struct entry_t* p, int size)
{
    if(p==NULL)
    {
        return -1;
    }
    if(filename==NULL)
    {
        return -1;
    }
    if(size<=0)
    {
        return -1;
    }
    FILE *cp;
    cp=fopen(filename,"r");
    if(cp==NULL)
    {
        return -2;
    }
    int t,i=0;

    while(!feof(cp))
    {
        t=read_bo_fscanf_nie_dziala((*(p+i)).name,20,cp);
        if(t!=1)
        {
            continue;
        }
        t+=read_bo_fscanf_nie_dziala((*(p+i)).last_name,40,cp);
        if(t!=2)
        {
            continue;
        }
        t+=fscanf(cp,"%d",&(*(p+i)).number);
        if(t!=3)
        {
            continue;
        }
        if(t==3)
        {
            i++;
        }
        if(i==size)
            break;
    }

    if(i==0)
    {
        fclose(cp);
        return 0;
    }
    fclose(cp);
    return i;

}



const struct entry_t* find_by_last_name(const struct entry_t* p, int size, const char *last_name)
{
    if(p==NULL)
    {
        return NULL;
    }
    if(size<=0)
    {
        return NULL;
    }
    if(last_name==NULL)
    {
        return NULL;
    }
    int k,i;
    for(i=0; i<size; i++)
    {
        if(*last_name==*(*(p+i)).last_name)
        {
            k=0;
            while(*(last_name+k)!='\0')
            {
                if(*(last_name+k)!=*(((p+i)->last_name)+k))
                    break;
                k++;
            }
            if(*(last_name+k)=='\0')
            {
                return p+i;
            }
        }
    }
    return NULL;
}

int remove_entry_by_last_name(struct entry_t* p, int size, const char* last_name)
{
    const struct entry_t *t;
    t=find_by_last_name(p,size,last_name);
    if(t==NULL)
    {
        return size;
    }
    int i,k;
    for(i=t-p;i<size-1;i++)
    {
        //k=0;
     // while(*(((p+i+1)->name)+k)!='\0')
     for(k=0;k<20;k++)
            {
                *(((p+i)->name)+k)=*(((p+i+1)->name)+k);
                //k++;
            }
        //k=0;
     // while(*(((p+i+1)->last_name)+k)!='\0')
     for(k=0;k<40;k++)
            {
                *(((p+i)->last_name)+k)=*(((p+i+1)->last_name)+k);
               // k++;
            }
           (*(p+i)).number= (*(p+i+1)).number;
    }
    return size-1;
}
int save_phonebook_t(const char *filename, const struct entry_t* p, int size)
{
    if(p==NULL)
    {
        return -1;
    }
    if(filename==NULL)
    {
        return -1;
    }
    if(size<=0)
    {
        return -1;
    }
    FILE *cp;
    cp=fopen(filename,"w");
    if(cp==NULL)
    {
        return -2;
    }
    int i;
    for(i=0; i<size; i++)
    {
        if(*(p+i)->name=='\0'||*(p+i)->last_name=='\0'||(p+i)->number=='\0')
            break;
        fprintf(cp,"%s | %s | %d\n",(*(p+i)).name, (*(p+i)).last_name, (*(p+i)).number);
    }
    fclose(cp);
    return i;
}

int main()
{
    struct entry_t p[10];
    int x;
    char n[100];
    char nz[100];
    int t;
    printf("Daj: ");
    scanf("%100[^\n]",n);
    t=load_phonebook_t(n,p,10);
    if(t==-2)
    {
        printf("Couldn't open file");
        return 4;
    }
    if(t==0)
    {
        printf("File corrupted");
        return 6;
    }
    while (getchar () != '\n' );
    printf("Daj: ");
    scanf("%100[^\n]",nz);
    x=remove_entry_by_last_name(p,10,nz);
    if(x==10)
    {
        printf("Couldn't find name");
        return 0;
    }
    if(x==9)
        {
        printf("Entry removed\n");
    }
    t=save_phonebook_t(n,p,x);
    if(t==-2)
    {
        printf("Couldn't create file");
        return 6;
    }
    printf("File saved");
    return 0;
}


