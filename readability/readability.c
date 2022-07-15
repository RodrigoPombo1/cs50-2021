#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string text = get_string("Text: ")
    int letter = 0;
    int word = 0;
    int sentence = 0;
    //check what is inside the string
    for (i = 0, len = strlen(text); i < len; i++)
    {
        char character = text[i]
        if character = "!" || character = "?" || character = "."
        {
            letter += 1;
        }
        else if character = " "
        {
            word += 1;
        }
        else
        {
            letter += 1;
        }
    }
    //grade calculation
    int grade = 
    if 1 <= grade && grade <16
    {
        printf("Grade %i", grade);
    }
    else if grade < 1
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade 16+");
    }
}