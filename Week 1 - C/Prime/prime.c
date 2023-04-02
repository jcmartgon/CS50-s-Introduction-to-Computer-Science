// Author: Jesus Carlos Martinez Gonzalez
// Date: 29/03/2023
// Find all prime numbers within a range

#include <cs50.h>
#include <stdio.h>

// Function header
bool prime(int number);

int main(void)
{
    int min;

    // Ask for a minimum value until input is 1 or greater
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;

    // Ask for a maximum value until input is greater than or equal the minimum value
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Loop through each integer between min and max, if i is prime print it
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

// Figure out if 'number' is prime or not
bool prime(int number)
{
    // 1 is technically not prime
    if (number == 1)
    {
        return false;
    }

    // Loop through every number between min and max (inclusive)
    for (int i = 1; i <= number; i++)
    {
        if (i == 1 || i == number) // Ignore min and max since we're trying to find which number isn't a prime
        {
            continue;
        }
        if (number % i == 0) // Not a prime
        {
            return false;
        }
    }
    return true; // Prime
}
