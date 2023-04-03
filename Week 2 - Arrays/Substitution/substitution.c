// Author: Jesus Carlos Martinez Gonzalez
// Date: 02/04/2023
// Substitution

#include <cs50.h>
#include <stdio.h>
#include <string.h> // strlen
#include <ctype.h> // // To work with alphabet case

bool check_key(string);
int occurances(char, string);
string cipher(string, string);

int main(int argc, string argv[])
{
    // Make sure user provides 1 command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check if key provided is valid
    if (check_key(argv[1]) != true)
    {
        printf("Key must be 26 letters long, and each letter may only appear once in it\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = cipher(plaintext, argv[1]);

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

// Checks if the key provided is valid
bool check_key(string key)
{
    // If key isn't 26 characters long
    if (strlen(key) != 26)
    {
        return false;
    }

    // Iterates over 'key', if any element is repeated within it, return false, else true
    char curr = '\0';
    for (int i = 0; i < strlen(key); i++)
    {
        curr = key[i];
        if (isalpha(curr))
        {
            if (occurances(curr, key) > 1)
            {
                return false;
            }

        }
        else
        {
            return false;
        }
    }
    return true;
}

// Checks how many times a given char appears in the given string
int occurances(char x, string text)
{
    int occurances = 0;
    char curr = '\0';

    // Iterates over 'text', and returns the amount of times 'x' appears within it
    for (int i = 0; i < strlen(text); i++)
    {
        curr = text[i];
        if (curr == x)
        {
            occurances++;
        }
    }
    return occurances;
}

// Transforms a word into another given a cipher
string cipher(string text, string key)
{
    string ciphertext = text;
    char curr = '\0';

    // Iterates over 'text'
    for (int i = 0; i < strlen(text); i++)
    {
        // Gets the ciphered equivalent to 'curr' while respecting case
        curr = text[i];
        if (isalpha(curr))
        {
            if (isupper(curr))
            {
                ciphertext[i] = toupper(key[(((int) curr) - 65)]);
            }
            else
            {
                ciphertext[i] = tolower(key[(((int) toupper(curr)) - 65)]);
            }
        }
        else
        {
            ciphertext[i] = curr;
        }
    }
    return ciphertext;
}