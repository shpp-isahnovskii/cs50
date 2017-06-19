#include <cs50.h>
#include <stdio.h>
#include <math.h>

const int NICKEL = 5;
const int DIME = 10;
const int QUARTER = 25;
const int DOLLARS_TO_COINS = 100;

float getChange()
{
    float change = 0.0;
    
    printf("O hai! ");
    do
    {
        printf("How much change is owed?\n");
        change = get_float();
    }
    while (change < 0 || change > 2147483647);
    change *= DOLLARS_TO_COINS;
    return round(change); //float rounded up with <math.h>
}

int greedyMachine(int free_cents)
{

    int count = free_cents / QUARTER;
    free_cents %= QUARTER;

    count += free_cents / DIME;
    free_cents %= DIME;

    count += free_cents / NICKEL;
    free_cents %= NICKEL;
    
    return count += free_cents;
}

int main()
{
    printf("%i\n",greedyMachine(getChange()));
}