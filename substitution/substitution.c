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
        if (strlen(argv[1]) == 26)
        {
            //checks if all the characters are letters
            int error = 0;
            for (int i = 0, len = strlen(argv[1]); i < len; i++)
            {
                if (!isalpha(argv[1][i]))
                {
                    error++;
                }
            }
            if (error == 0)
            {
                //checks if there is the same character (case insensitive)
                int error2 = 0;
                string aux = "00000000000000000000000000";
                string character = argv[1];
                for (int i = 0, len = strlen(argv[1]); i < len; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (isupper(character[i]))
                        {
                            
                        }
                        else if (islower(character[i]))
                        {
                            error2++;
                        }
                    }
                    aux[i] = (char) character[i];
                }
                if (error2 == 0)
                {
                    string key = argv[1];
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
                                if (islower(key[(( (int) plaintext[i]) - 97)]))
                                {
                                    plaintext[i] = (char)key[(( (int) plaintext[i]) - 97)];
                                }
                                //if upper in plaintext then lower in cyphertext
                                else
                                {
                                    plaintext[i] = (char)((int) key[(( (int) plaintext[i]) - 97) - 32]);
                                }
                            }
                            else if (isupper(plaintext[i]))
                            {
                                //if upper in plaintext then lower in cyphertext
                                if (isupper(key[(((int) plaintext[i]) - 97)]))
                                {
                                    plaintext[i] = (char)key[(((int) plaintext[i]) - 97)];
                                }
                                //if lower in plaintext then lower in cyphertext
                                else
                                {
                                    plaintext[i] = (char)((int) key[(((int) plaintext[i]) - 65) + 32]);
                                }
                            }
                        }
                    }
                    printf("ciphertext: %s\n", plaintext);
                    ////////////////////////////////////////////END OF CONVERTING///////////////////////////////////////////////
                }
                else
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
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