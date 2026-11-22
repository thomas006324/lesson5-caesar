#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns true only if every character in s is a digit
bool only_digits(string s);

// Shifts one letter forward by key, keeping its case; other characters stay the same
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // Refuse to run unless there is exactly one argument and it is all digits
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Turn the key from text into a number
    int key = atoi(argv[1]);

    // Ask for the message to encrypt
    string plaintext = get_string("plaintext:  ");

    // Rotate each character and print the result
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    // Check every character; one non-digit makes the whole key invalid
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
{
    // Uppercase: turn A-Z into 0-25, shift, wrap with % 26, turn back into a letter
    if (isupper(c))
    {
        return 'A' + (c - 'A' + key) % 26;
    }
    // Lowercase: same idea, starting from 'a'
    if (islower(c))
    {
        return 'a' + (c - 'a' + key) % 26;
    }
    // Not a letter: leave it exactly as it was
    return c;
}
