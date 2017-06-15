#include <cs50.h>
#include <stdio.h>
#include <math.h>

const int PENNIE = 1;
const int NICKEL = 5;
const int DIME = 10;
const int QUARTER = 25;
const int DOLLARS_TO_COINS = 100;
//const int COINS_VALUE[] = {25, 10, 5, 1}; \\in future :)

float get_change()
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

int greedy_machine(int free_cents)
{
    int count = free_cents / QUARTER;
    free_cents %= QUARTER;
    count += free_cents / DIME;
    free_cents %= NICKEL;
    count += free_cents / NICKEL;
    free_cents %= NICKEL;
    count += free_cents;
    
    return count;
}

int main()
{
    printf("change is: %i\n",greedy_machine(get_change()));
}