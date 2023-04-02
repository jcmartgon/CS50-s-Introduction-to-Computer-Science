// Author: Jesus Carlos Martinez Gonzalez
// Date: 30/03/2023
// Credit

//  Card type by data:
//
//  Visa
//      13 or 16 digit numbers
//      Start with a 4
//
//  American Express
//      15 digit numbers
//      Start with either 34 or 37
//
//  MasterCard
//      16 digit numbers
//      Start with 51, 52, 53, 54, or 55


#include <cs50.h>
#include <stdio.h>

// Function header
int Luhn(long);

int main(void)
{
    long number = get_long("Number: ");

    int checksum = Luhn(number); // Check if valid card according to Luhn's algorithm

    // Checksum returns either a -1 or the length of the number, use that value to check the type of card
    switch (checksum)
    {
        case 13:
            if (number / 1000000000000 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        case 15:
            if (number / 10000000000000 == 34 || number / 10000000000000 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        case 16:
            if (number / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else if (number / 100000000000000 >= 51 && number / 100000000000000 <= 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;
        default:
            printf("INVALID\n");
    }
}

// Gets a card number, if the checksum isn't 0, returns -1, otherwise it returns the length of the number
int Luhn(long number)
{
    int i = 1, sum = 0, mod;

    // Use the modulus operator on the number to iterate over its last digit until there's none left
    while (number > 0)
    {
        mod = number % 10;
        number /= 10;

        // If the digit being analyzed is pair, multiple it by 2 and add its digits to the sum
        // In the case that the number is 1 digit long, it will be added alongside a 0
        if (i % 2 == 0)
        {
            mod *= 2;
            sum += mod % 10 + mod / 10;
        }
        else // Otherwise the digit will be added as is
        {
            sum += mod;
        }
        i++;
    }

    // If checksum is 0, return the length of the number
    if (sum % 10 == 0)
    {
        return i - 1;
    }

    return -1;
}