#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    // decclare variables
    float change = 0.0;
    int cents = 0;
    int coins = 0;
    int rest = 0;

    // specify what coins are available
    int values[4] = {25, 10, 5, 1};

    // get input from user
    do
    {
        printf("O hai! How much change is owed?\n");
        change = GetFloat();
    } while( change <= 0 );

    // convert float to cents int
    cents = round(change * 100);

    // calculate the number of coins
    int value;
    int i;
    int total = sizeof(values) / sizeof(values[0]);
    rest = cents;
    for( i = 0 ; i < total ; i++)
    {
        value = values[i];
        rest = rest % value;
        coins += (cents - rest) / value;
        cents -= (cents - rest);
    }

    printf("%i\n", coins);
    return 0;
}
