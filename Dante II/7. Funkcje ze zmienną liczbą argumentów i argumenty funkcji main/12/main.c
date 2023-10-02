#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int sum=0;
    if(argc==1)
    {
        printf("Not enough arguments");
        return 9;
    }
    int i;
    for(int k=1;k<argc;++k)
    {
        int o=0;
        int m=0;
        while(*(*(argv+k)+o)!='\0')
        {
            if(*(*(argv+k)+o)=='-'&&m==0)
            {
                m=1;
                ++o;
            }

            if(!isdigit(*(*(argv+k)+o)))
            {

                    printf("Incorrect input");
                    return 1;

            }
            ++o;
        }

        i=atoi(*(argv+k));
        sum+=i;
    }
    printf("%d",sum);
    return 0;
}
