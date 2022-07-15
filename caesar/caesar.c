#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            
        }
        if
        {
            string plaintext = getstring("plaintext: ");
            int k = argv[1];
            string ciphertext = "";
            for (int i = 0, len = strlen(plaintext); i < len; i++)
            {
                if (isalpha(plaintext[i]))
                {
                    if (islower(plaintext[i]))
                    {
                        ciphertext = ciphertext + (((plaintext[i] + k) - 65) % 26) + 65;
                    }
                    else if (isupper(plaintext[i]))
                    {
                        ciphertext = ciphertext + (((plaintext[i] + k) - 97) % 26) + 97;
                    }
                }
                else
                {
                    ciphertext = ciphertext + plaintext[i];
                }
            }
            printf("ciphertext: %s\n", ciphertext);
        }
        else
        {
            printf("Usage: ./caesar key\n");
        }
    else
    {
        printf("Usage: ./caesar key\n");
    }
}