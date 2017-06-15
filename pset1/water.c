#include <cs50.h>
#include <stdio.h>

const int BOTTLE_IN_MINUTE = 12;

int get_minutes() //chose a number
    {
        int minutes;
        do
        {
            printf("Minutes: ");
            minutes = get_int();
        }
        while(minutes <= 0);
        return minutes;
    }

int do_calculation(int X) // multiply X minutes
{
    return(X * BOTTLE_IN_MINUTE);
}

int main(void) //result
{
    printf("Bottles: %i\n", do_calculation(get_minutes()));
}

/*=================start version=================
#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int bottles_in_minute = 12;
    int number;
    do
    {
        printf("Minutes: ");
        number = get_int();
    }
    while(number <= 0);
    printf("Bottles: %i \n", bottles_in_minute * number);
}
*/