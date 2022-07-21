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
                string lowercasekey = argv[1];
                for (int i = 0, len = strlen(argv[1]); i < len; i++)
                {
                    if (isupper(lowercasekey[i]))
                    {
                        lowercasekey[i] = (char)((int) lowercasekey[i] + 32);
                    }
                    for (int j = 0; j < i; j++)
                    {
                        if (lowercasekey[j] == lowercasekey[i])
                        {
                            error2++;
                        }
                    }
                }
                if (error2 == 0)
                {
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
                                plaintext[i] = lowercasekey[(((int) plaintext[i]) - 97)];
                            }
                            else if (isupper(plaintext[i]))
                            {
                                plaintext[i] = (char)((int) lowercasekey[(((int) plaintext[i]) - 65)] - 32);
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