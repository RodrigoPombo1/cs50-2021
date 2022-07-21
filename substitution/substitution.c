#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //////////////////////////////////////////////CHECKS THE KEY/////////////////////////////////////////////////
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
                ///////////////////////////////////STARTS CONVERTING TO CYPHERTEXT/////////////////////////////////////////////////
                string plaintext = get_string("plaintext: ");
                //cycles through the entire text
                for (int i = 0, len = strlen(plaintext); i < len; i++)
                {
                    if (isalpha(plaintext[i]))
                    {
                        //converts the plaintext to cyphertext
                        if (islower(plaintext[i]))
                        {
                            //if lower in plaintext then lower in cyphertext
                            if (islower(key[(( (int) plaintext[i]) - 97)]));
                            {
                                plaintext[i] = key[(( (int) plaintext[i]) - 97)];
                            }
                            //if upper in plaintext then lower in cyphertext
                            else
                            {
                                plaintext[i] = (char)  ((int) key[(( (int) plaintext[i]) - 97) - 32]);
                            }
                        }
                        else if (isupper(plaintext[i]))
                        {
                            //if upper in plaintext then lower in cyphertext
                            if (isupper(key[(((int) plaintext[i]) - 97)]));
                            {
                                plaintext[i] = key[(((int) plaintext[i]) - 97)];
                            }
                            //if lower in plaintext then lower in cyphertext
                            else
                            {
                                plaintext[i] = (char) ((int) key[(((int) plaintext[i]) - 65) + 32]);
                            }
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