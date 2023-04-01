// Author: Jesus Carlos Martinez Gonzalez
// Date: 01/04/2023
// No Vowels

// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Gets a password string, iterates over its characters
// For every character, checks if they meet any of the requirements and if so updates the respective variable
bool valid(string password)
{
    bool lower = false, upper = false, number = false, symbol = false;
    char curr = '0';

    for (int i = 0; curr != '\0'; i++)
    {
        curr = password[i];
        if (isupper(curr))
        {
            upper = true;
        }
        else if (islower(curr))
        {
            lower = true;
        }
        else if (isdigit(curr))
        {
            number = true;
        }
        else if (ispunct(curr))
        {
            symbol = true;
        }
    }
    if (lower == true && upper == true && number == true && symbol == true)
    {
        return true;
    }
    return false;
}
