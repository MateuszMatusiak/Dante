#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int A[4][4];
    int B[4][4];
    int C[4][4];
    int AB[4][4];
    int BA[4][4];
    int AC[4][4];
    int CA[4][4];
    int i,k;
    srand(time(NULL));
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            A[i][k]=rand()%100;
        }
    }
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            B[i][k]=rand()%100;
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

    for(i=0; i<4; i++)
        for(k=0; k<4; k++)
        {
            AB[i][k]=A[i][0]*B[0][k]+A[i][1]*B[1][k]+A[i][2]*B[2][k]+A[i][3]*B[3][k];
        }
    for(i=0; i<4; i++)
        for(k=0; k<4; k++)
        {
            BA[i][k]=B[i][0]*A[0][k]+B[i][1]*A[1][k]+B[i][2]*A[2][k]+B[i][3]*A[3][k];
        }
    for(i=0; i<4; i++)
        for(k=0; k<4; k++)
        {
            AC[i][k]=A[i][0]*C[0][k]+A[i][1]*C[1][k]+A[i][2]*C[2][k]+A[i][3]*C[3][k];
        }
    for(i=0; i<4; i++)
        for(k=0; k<4; k++)
        {
            CA[i][k]=C[i][0]*A[0][k]+C[i][1]*A[1][k]+C[i][2]*A[2][k]+C[i][3]*A[3][k];
        }

    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            printf("%d\t",AB[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            printf("%d\t",BA[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            printf("%d\t",AC[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<4; i++)
    {
        for(k=0; k<4; k++)
        {
            printf("%d\t",CA[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
