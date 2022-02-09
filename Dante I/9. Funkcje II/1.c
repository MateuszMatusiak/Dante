#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned int my_strlen(const char tab[])
{
    unsigned int i=0;
    while(tab[i]!='\0')
    {
        i++;
    }
    return i;
}
int my_atoi(const char tab[])
{
    int liczba=0,o=0,j;
    unsigned int n=my_strlen(tab),u,k,i,y;

    for(u=0; u<n; u++)
    {
        if((tab[u]=='.'))
        {
            break;
        }
        if(tab[u]!='-')
        if((tab[u]<'0')||(tab[u]>'9'))
            break;
    }
    for(y=0; y<n; y++)
    {
        if((tab[y]=='.'))
        {
            continue;
        }
        if(tab[y]!='-')
        if((tab[y]<'0')||(tab[y]>'9'))
            break;
    }
    for(i=u, k=0; k<u+1; i--, k++)
    {
        j=1;
        if(k==0)
            if(tab[k]=='-')
            {
                o++;
                k++;
                i--;
            }
        if((tab[k]=='.'))
        {
            if(o==0)
                return liczba;
            else
                return liczba*(-1);
        }
        if(tab[k]!='-')
        if((tab[k]<'0')||(tab[k]>'9'))
        {
            if(o==0)
                return liczba;
            else
                return liczba*(-1);
        }
        if(i!=0)
            for(int q=i; q>1; q--)
                j=j*10;
        else
            j=1;

        switch(tab[k])
        {
        case '0':
        {
            liczba=liczba+0;
            break;
        }
        case '1':
        {
            liczba=liczba+1*j;
            break;
        }
        case '2':
        {
            liczba=liczba+2*j;
            break;
        }
        case '3':
        {
            liczba=liczba+3*j;
            break;
        }
        case '4':
        {
            liczba=liczba+4*j;
            break;
        }
        case '5':
        {
            liczba=liczba+5*j;
            break;
        }
        case '6':
        {
            liczba=liczba+6*j;
            break;
        }
        case '7':
        {
            liczba=liczba+7*j;
            break;
        }
        case '8':
        {
            liczba=liczba+8*j;
            break;
        }
        case '9':
        {
            liczba=liczba+9*j;
            break;
        }
        default:
        {
            return 0;
        }
        }

    }
    if(o==0)
        return liczba;
    else
        return liczba*(-1);
}
float my_atof(const char tab[])
{
    int i;
    float j,liczba=0;
    unsigned int n=my_strlen(tab),u,k,q,o=0,y;
    for(u=0; u<n; u++)
    {
        if(tab[u]=='.')
        {
            break;
        }
        if(tab[u]!='-')
        if((tab[u]<'0')||(tab[u]>'9'))
            break;
    }
    for(y=0; y<n; y++)
    {
        if(tab[y]=='.')
        {
            continue;
        }
        if(tab[y]!='-')
        if((tab[y]<'0')||(tab[y]>'9'))
            break;
    }
    for(i=u,k=0; k<y; i--, k++)
    {
        j=1;
        if(k==0)
            if(tab[k]=='-')
            {
                o++;
                k++;
                i--;
            }
        if((tab[k]=='\0'))
        {
            if(o==0)
                return liczba;
            else
                return liczba*(-1);
        }
        if(tab[k]!='.')
            if((tab[k]<'0')||(tab[k]>'9'))
            {
                if(o==0)
                    return liczba;
                else
                    return liczba*(-1);
            }
        if(i>0)
        {
            for(q=i; q>1; q--)
                j=j*10;
        }
        else if(i<0)
        {
            for(int q=i; q<=-1; q++)
                j=j/10.0;
        }
        else
        {
            j=1;
        }
        if(tab[k]=='.')
            continue;
        else
            switch(tab[k])
            {
            case '0':
            {
                liczba=liczba+0;
                break;
            }
            case '1':
            {
                liczba=liczba+1*j;
                break;
            }
            case '2':
            {
                liczba=liczba+2*j;
                break;
            }
            case '3':
            {
                liczba=liczba+3*j;
                break;
            }
            case '4':
            {
                liczba=liczba+4*j;
                break;
            }
            case '5':
            {
                liczba=liczba+5*j;
                break;
            }
            case '6':
            {
                liczba=liczba+6*j;
                break;
            }
            case '7':
            {
                liczba=liczba+7*j;
                break;
            }
            case '8':
            {
                liczba=liczba+8*j;
                break;
            }
            case '9':
            {
                liczba=liczba+9*j;
                break;
            }
            default:
            {
                return 0;
            }
            }

    }
    if(o==0)
        return liczba;
    else
        return liczba*(-1);
}

int main()
{
    char tab[16];
    printf("Daj: ");
    scanf("%15[^\n]",tab);
    printf("%u\n%d\n%.4f",my_strlen(tab),my_atoi(tab),my_atof(tab));
    return 0;
}

