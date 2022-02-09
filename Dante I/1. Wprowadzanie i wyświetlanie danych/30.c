#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c,g,m,s;
    printf("podaj czas ");
    scanf("%d",&c);
    s=c%60;
    m=(c%3600)/60;
    g=(c/3600);
    printf("%02d:%02d:%02d",g,m,s);
    return 0;
}
