#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        int error = 0;
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            if (!isalnum(argv[1][i]))
            {
                error ++;
            }
        }
        if (error == 0)
        {
            string plaintext = get_string("plaintext: ");
            int k = (int) argv[1];
            string ciphertext = "";
            for (int i = 0, len = strlen(plaintext); i < len; i++)
            {
                if (isalpha(plaintext[i]))
                {
                    if (islower(plaintext[i]))
                    {
                        ciphertext = ciphertext + (char) ((( (int) plaintext[i] + k) - 65) % 26) + 65;
                    }
                    else if (isupper(plaintext[i]))
                    {
                        ciphertext = ciphertext + (char) ((( (int) plaintext[i] + k) - 97) % 26) + 97;
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