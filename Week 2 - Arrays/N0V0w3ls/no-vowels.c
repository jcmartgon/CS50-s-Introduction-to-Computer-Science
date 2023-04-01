// Author: Jesus Carlos Martinez Gonzalez
// Date: 01/04/2023
// No Vowels

// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    printf("%s\n", replace(argv[1]));
}

// Gets argv[1] and returns a modified version of it
string replace(string word)
{
    // Iterate over 'word' using 'curr' as the current char being analyzed
    // If 'curr' is any of the vowels to change, do so, otherwise ingore
    char curr = '0';
    for (int i = 0; curr != '\0'; i++)
    {
        curr = word[i];
        switch (curr)
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            default:
                break;
        }
    }
    return word;
}