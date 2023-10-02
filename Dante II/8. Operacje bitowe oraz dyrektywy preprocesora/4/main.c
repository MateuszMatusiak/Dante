#include <stdio.h>

int main() {
    long long int x;
    printf("Daj: ");
    int t= scanf("%lld",&x);
    if(t!=1)
    {
        printf("Incorrect input");
        return 1;
    }
    char m=1;
    char b;
    for(int i=7;i>=0;--i)
    {
        b=x>>i*8;
        for(int k=7;k>=0;--k)
            printf("%d",(b>>k)&m);
        printf(" ");
    }
    return 0;
}
