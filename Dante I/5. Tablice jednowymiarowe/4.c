#include <stdio.h>
#include <stdlib.h>

int main()
{
    float tab[16]={818.2322865, 0.2559284267, 0.8075320057, 0.420383407, 0.2302881821, 0.8099938753, 0.7093625361, -5.174125467, 0.640470207, 0.34488766,  0.3592073480, 0.667142349, -8.698238416, 97.23240366, 0.0220584254, 0.8590693462};
    int i;
    for(i=0;i<16;i++)
        printf("% 8.3f\n",tab[i]);
    return 0;
}
