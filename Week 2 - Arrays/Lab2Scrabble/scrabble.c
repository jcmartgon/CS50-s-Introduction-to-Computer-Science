// Author: Jesus Carlos Martinez Gonzalez
// Date: 01/04/2023
// Scrabble

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Compute and return score for string
int compute_score(string word)
{
    int score = 0;
    char curr = '0';

    // Iterate over 'word', if element at word[i] is a letter, set it to its upper case variant...
    // ... then take 65 from its integer value in the ASCII chart, and add the corresponding value from 'POINTS' to the sum, then return it
    for (int i = 0; curr != '\0'; i++)
    {
        curr = word[i];
        if (isalpha(curr))
        {
            score += POINTS[(int) toupper(curr) - 65];
        }
    }
    return score;
}
