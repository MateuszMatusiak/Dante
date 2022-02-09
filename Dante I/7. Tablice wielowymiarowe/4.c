#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int A[4][4];
    int B[4][4];
    int C[4][4];
    int i,k;
    srand(time(NULL));
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            A[i][k]=rand();
        }
    }
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            B[i][k]=rand();
        }
    }
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            C[i][k]=0;
        }
    }
    for(i=0; i<4; i++)
        C[i][i]=1;
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            printf("%d\t",A[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            printf("%d\t",B[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            printf("%d\t",C[i][k]);
        }
        printf("\n");
    }
    return 0;
}
