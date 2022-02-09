#include <stdio.h>
#include <stdlib.h>

int main()
{
    float C;
    printf("podaj temperature w st Celsjusza: ");
    scanf("%f",&C);
    printf("Kelvin: %f",C+273.15);
    printf("\nFahrenheit: %f",(C*1.8)+32);

    return 0;
}
