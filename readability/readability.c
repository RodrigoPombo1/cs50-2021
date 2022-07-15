#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int letter = 0;
    int word = 1;
    int sentence = 0;
    //check what is inside the string
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        char character = text[i];
        if (character == '!' || character == '?' || character == '.')
        {
            sentence += 1;
        }
        else if (character == ' ')
        {
            word += 1;
        }
        else if (character != ',' && character != ':' && character != '"')
        {
            letter += 1;
        }
    }
    //grade calculation
    int grade = 0.0588 * (float) letter / (float) word * 100 - 0.296 * (float) sentence / (float) word * 100 - 15.8;
    if (1 <= grade && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}