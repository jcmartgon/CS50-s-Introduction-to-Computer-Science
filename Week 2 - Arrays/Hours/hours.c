// Author: Jesus Carlos Martinez Gonzalez
// Date: 30/03/2023
// Hours

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// Function header
float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Returns either the total sum of values within 'hours' or their average
float calc_hours(int hours[], int weeks, char output)
{
    int sum = 0;

    // Add up all the values in 'hours'
    for (int i = 0; i < weeks; i++)
    {
        sum += hours[i];
    }
    return (output == 'T') ? sum : sum / (float) weeks;  // If 'output' is 'T' returns the sum, otherwise returns the average
}