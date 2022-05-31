#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;


    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;


    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;


    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;


    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
    //printf("The number of coins are %i which are made up of %i quarters, %i dimes, %i nichels and %i pennies\n ", coins,quarters, dimes, nickels, pennies );
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Ingrese centimos: ");
    }
    while (cents < 0);

    return cents;
}

//calculo de cuartos

int calculate_quarters(int cents)
{
    int quarters;

    if (cents >= 25)
    {
        quarters = cents / 25;
        return quarters;
    }
    return 0;
}
//calculo de dimes

int calculate_dimes(int cents)
{
    int dimes;

    if (cents >= 10)
    {
        dimes = cents / 10;
        return dimes;
    }
    return 0;
}

//calculo de nickels

int calculate_nickels(int cents)
{
    int nickels;

    if (cents >= 5)
    {
        nickels = cents / 5;
        return nickels;
    }
    return 0;
}

//calculo de pennies

int calculate_pennies(int cents)
{
    int pennies;

    if (cents >= 1)
    {
        pennies = cents / 1;
        return pennies;
    }
    return 0;
}
