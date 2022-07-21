#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //checks if the user made the mistake of not putting 2 arguments
    if (argc == 2)
    {
        //checks if the key the user provided contains 26 characters
            //checks if all the characters are letters
                //checks if there is the same character (case insensitive)
        int error = 0;
        for (int i = 0, len = strlen(argv[1]); i < len; i++) // fazer um array e ir comparando ao array para ver se nao se repete
        {
            if ((int) argv[1][i] < 48 || 57 < (int) argv[1][i]) //
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
                            plaintext[i] = (char) key[(((int) plaintext[i]) - 97)] + 97; //
                        }
                        else if (isupper(plaintext[i]))
                        {
                            plaintext[i] = (char)((((int) plaintext[i] + k) - 65) % 26) + 65; //
                        }
                    }
                }
                printf("ciphertext: %s\n", plaintext);
            }
                else
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}