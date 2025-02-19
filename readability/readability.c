#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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
        if (isalpha(character))
        {
            letter ++;
        }
        else if (character == ' ')
        {
            word ++;
        }
        else if (character == '!' || character == '?' || character == '.')
        {
            sentence ++;
        }
    }
    //grade calculation
    int grade = round(0.0588 * (float) letter / (float) word * 100 - 0.296 * (float) sentence / (float) word * 100 - 15.8);
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