#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //while loop ask user the height he wants
    int height = 0;
    do
    {
    height = get_int("Height of the pyramid? (it must be between 1 and 8 inclusive) ");
    }while (height < 1 || height > 8);
    //for loop to build the pyramid
    for(int i=1; i <= height; i++)
    {
        for(int j=0; j < height-i; j++)
        {
            printf(" ");
        }
        for(int j=height; j <= 1; j-- )
        {
            printf("#");
        }
        printf("\n");
    }
}