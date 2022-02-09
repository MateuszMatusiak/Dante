#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Podaj liczbe 1-6: ");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
    {
        printf("Brak promocji do nastepnej klasy");
        break;
    }
    case 2:
    case 3:
    case 4:
    case 5:
    {
        printf("Promocja do nastepnej klasy");
        break;
    }
    case 6:
        {
            printf("Promocja z ocena celujaca");
            break;
        }
    default:
    {
        printf("Wprowadzona ocena jest niepoprawna");
        break;
    }
    }
    return 0;
}
