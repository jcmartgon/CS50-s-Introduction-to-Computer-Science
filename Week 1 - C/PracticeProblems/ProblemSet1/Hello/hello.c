// Author: Jesus Carlos Martinez Gonzalez
// Date: 30/03/2023
// Hello

#include <stdio.h>
#include <cs50.h>

// Ask the user for their names and greet them with it
int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}