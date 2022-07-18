#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //checks if the user made a mistake
    if (argc == 2)
    {
        int error = 0;
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            if ((int) argv[1][i] < 48 || 57 < (int) argv[1][i])
            {
                error ++;
            }
        }
        if (error == 0)
        {
            //gets the key and converts it from a string to an integer
            string plaintext = get_string("plaintext: ");
            int k = 0;
            for (int i = 0, len = strlen(argv[1]); i < len; i++)
            {
                if (k == 0)
                {
                    k = k + (int) argv[1][i] - 48;
                }
                else
                {
                    k = k * 10 * i + (int) argv[1][i] - 48;
                }

            }
            //cycles through the entire text
            for (int i = 0, len = strlen(plaintext); i < len; i++)
            {
                if (isalpha(plaintext[i]))
                {
                    //converts the letters
                    if (islower(plaintext[i]))
                    {
                        plaintext[i] = (char)((((int) plaintext[i] + k) - 97) % 26) + 97;
                    }
                    else if (isupper(plaintext[i]))
                    {
                        plaintext[i] = (char)((((int) plaintext[i] + k) - 65) % 26) + 65;
                    }
                }
            }
            printf("ciphertext: %s\n", plaintext);
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}