// Author: Jesus Carlos Martinez Gonzalez
// Date: 30/03/2023
// Mario-More

#include <cs50.h>
#include <stdio.h>

// Function header
void PrintLevel(int, int);

int main(void)
{
    // Ask the user for a height value between 1 and 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Print each pyramid level, starting from the top
    for (int i = 1; i <= height; i++)
    {
        PrintLevel(height, i);
    }
}

void PrintLevel(int height, int lvl)
{
    int filler = height - lvl; // Space filler at the start of the level

    // Filler
    for (int i = 0; i < filler; i++)
    {
        printf(" ");
    }

    // Left blocks
    for (int i = 0; i < lvl; i++)
    {
        printf("#");
    }

    // Space between sides
    printf("  ");

    // Right blocks
    for (int i = 0; i < lvl; i++)
    {
        printf("#");
    }
    printf("\n");
}