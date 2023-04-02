// Author: Jesus Carlos Martinez Gonzalez
// Date: 01/04/2023
// Readability

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

// Counts letters in the string
int count_letters(string);

// Counts words in the string
int count_words(string);

// Counts sentences in the string
int count_sentences(string);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
    // L is the average number of letters per 100 words in the text
    // S is the average number of sentences per 100 words in the text

    float l = (letters * 100) / (float) words;
    float s = (sentences * 100) / (float) words;

    float findex = 0.0588 * l - 0.296 * s - 15.8;
    int index = round(findex);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Iterate over the text, increasing letters with every alphabetical character
int count_letters(string text)
{
    int letters = 0;
    char curr = '0';

    for (int i = 0; curr != '\0'; i++)
    {
        curr = text[i];
        if (isalpha(curr))
        {
            letters++;
        }
    }

    return letters;
}

// Iterate over the text, increasing words with every space character
int count_words(string text)
{
    int words = 1; // Starts at 1 to compensate for the last word in the sentence, which ends with a period
    char curr = '0';

    for (int i = 0; curr != '\0'; i++)
    {
        curr = text[i];
        if (curr == ' ')
        {
            words++;
        }
    }

    return words;
}

// Iterate over the text, increasing sentences with every '.', '!', or '?' encountered
int count_sentences(string text)
{
    int sentences = 0;
    char curr = '0';

    for (int i = 0; curr != '\0'; i++)
    {
        curr = text[i];
        if (curr == '.' || curr == '!' || curr == '?')
        {
            sentences++;
        }
    }

    return sentences;
}