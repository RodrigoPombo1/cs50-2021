#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    if (strlen(argv[]) == 2 && isalpha(argv[2]))
    {
        string plaintext = getstring("plaintext: ");
        string
        string ciphertext = "";
        for (int i = 0, len = strlen(plaintext); i < len; i++)
        {
            if (isalpha(plaintext[i]))
            {
                if (islower(plaintext[i]))
                {
                    ciphertext = ciphertext + (plaintext[i] + k) % 65
                }
                else if (isupper(plaintext[i]))
                {
                    ciphertext = ciphertext + (plaintext[i] + k) % 97
                }
            }
            else
            {
                ciphertext = ciphertext + plaintext[i]
            }
        }
        printf("ciphertext: %s\n", ciphertext)
    else
    {
        printf("Usage: ./caesar key\n")
    }
}