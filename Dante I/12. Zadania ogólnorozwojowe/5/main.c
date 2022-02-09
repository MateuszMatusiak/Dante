#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,t,i=0,k,p,o,j,m,q,r,x;
    int tb[11];
    do
    {        printf("Daj: ");
        t=scanf("%d",&m);
        if((t!=1)||(abs(m)>10))
        {
            printf("Incorrect intput");
            return 1;
        }
        tb[i]=m;
        i++;
    }
    while((m!=0)&&(i<11));


    x=0;
    while((tb[x]!=0)&&(x<11))
    {
        n=abs(tb[x]);
        char tab[20][20];
        for(i=0; i<2*n; i++)
        {
            for(k=0; k<2*n; k++)
            {
                tab[i][k]=' ';
            }
        }
        tab[n][n]='X';
        tab[n][n-1]='X';
        tab[n-1][n]='X';
        tab[n-1][n-1]='X';
        for(i=n-2,r=0,o=n+1; i>=0; i--,o++,r++)
        {
            tab[i][i]='X';
            tab[i][o]='X';
            tab[o][i]='X';
            tab[o][o]='X';
            if(tb[x]<0)
            {
                p=0;
                q=0;
                for(k=i+1,j=o-1; k<o-1; k++,j--)
                {
                    if(p<=r+1)
                    {
                        tab[i][k]='X';
                        tab[k][o]='X';
                        tab[o][j]='X';
                        tab[j][i]='X';
                        p++;
                    }

                    if((p==r+2)&&(q<=r+1))
                    {
                        tab[i][k]=' ';
                        tab[k][o]=' ';
                        tab[o][j]=' ';
                        tab[j][i]=' ';
                        q++;
                    }
                }
            }
            if(tb[x]>0)
            {
                p=0;
                q=0;
                for(k=o-1,j=i+1; k>i+1; k--,j++)
                {
                    if(p<=r+1)
                    {
                        tab[i][k]='X';
                        tab[k][o]='X';
                        tab[o][j]='X';
                        tab[j][i]='X';
                        p++;
                    }

                    if((p==r+2)&&(q<=r+1))
                    {
                        tab[i][k]=' ';
                        tab[k][o]=' ';
                        tab[o][j]=' ';
                        tab[j][i]=' ';
                        q++;
                    }
                }
            }


        }
        for(i=0; i<2*n; i++)
        {
            for(k=0; k<2*n; k++)
            {
                printf("%c",tab[i][k]);
            }
            printf("\n");
        }
        printf("\n");
        x++;
    }
    return 0;
}
