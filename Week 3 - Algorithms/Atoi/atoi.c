// Author: Jesus Carlos Martinez Gonzalez
// Date: 04/04/2023
// Recursive atoi

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// user-defined function prototypes
int convert(string input, int);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input, 1));
}

// Takes a string and returns it as an integer
// 'pos' refers to its base 10 position
int convert(string input, int pos)
{
    int n = strlen(input);

    // Base case, the string is empty
    if (n == 0)
    {
        return 0;
    }
    else
    {
        // Modifies input by removing its last character
        char last = input[n - 1];
        input[n - 1] = '\0';

        // Turns the last char (stored in 'last') into an int
        // Changing its ascii value into that of its int counterpart
        // Then casting that to int
        int val = ((int) last - 48) * pos;
        return (val + convert(input, pos * 10));
    }
}