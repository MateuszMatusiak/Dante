#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x;
    printf("Podaj plan: ");
    scanf("%c",&x);
    switch(x)
    {
    default:
    {
        printf("Incorrect input");
        return 1;
    }
    case 'A':
    case 'B':
    case 'C':
        printf("You chose");
    }

    switch(x)
    {
    case 'A':
    {
        printf(" Breakfast,");
    }
    case 'B':
    {
        printf(" Lunch and");
    }
    case 'C':
    {
        printf(" Dinner as your meal plan.");
        return 0;
    }

    }
}
