#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float lrzecz1, luroj1, lrzecz2, luroj2, lrzecz3, luroj3;
    printf("podaj czesc rzeczywista pierwszej liczby ");
    scanf("%f",&lrzecz1);
    printf("podaj czesc urojona pierwszej liczby ");
    scanf("%f",&luroj1);
    printf("podaj czesc rzeczywista drugiej liczby ");
    scanf("%f",&lrzecz2);
    printf("podaj czesc urojona drugiej liczby ");
    scanf("%f",&luroj2);
    printf("liczby: ");
    printf("%.3f %c i%.3f %.3f %c i%.3f",lrzecz1,(luroj1>=0)*'+'+(luroj1<0)*'-',fabs(luroj1), lrzecz2, (luroj2>=0)*'+'+(luroj2<0)*'-',fabs(luroj2));
    lrzecz3=lrzecz1+lrzecz2;
    luroj3=luroj1+luroj2;
    printf("\n%.3f %c i%.3f",lrzecz3,(luroj3>=0)*'+'+(luroj3<0)*'-',fabs(luroj3));
    lrzecz3=lrzecz1-lrzecz2;
    luroj3=luroj1-luroj2;
    printf("\n%.3f %c i%.3f",lrzecz3,(luroj3>=0)*'+'+(luroj3<0)*'-',fabs(luroj3));
    lrzecz3=(lrzecz1*lrzecz2-luroj1*luroj2);
    luroj3=(luroj1*lrzecz2+lrzecz1*luroj2);
   printf("\n%.3f %c i%.3f",lrzecz3,(luroj3>=0)*'+'+(luroj3<0)*'-',fabs(luroj3));
   lrzecz3=((lrzecz1*lrzecz2)+(luroj1*luroj2))/((lrzecz2*lrzecz2)+(luroj2*luroj2));
   luroj3=((luroj1*lrzecz2)-(lrzecz1*luroj2))/((lrzecz2*lrzecz2)+(luroj2*luroj2));
    printf("\n%.3f %c i%.3f",lrzecz3,(luroj3>=0)*'+'+(luroj3<0)*'-',fabs(luroj3));
    return 0;
}

