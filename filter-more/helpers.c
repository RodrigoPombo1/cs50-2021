#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //selects pixel and averages it's green blue and red values and changes the green blue and red values to the average
    //loops through the whole image
    //each row
    for (int i = 0; i < height; i++)
    {
        //each column
        for (int j = 0; j < width; j++)
        {
        //calculates the average of blue, green and red values
        //changes the values to the average
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loops through the whole image
    //each row
    for (int i = 0; i < height; i++)
    {
        //each column
        for (int j = 0; j < width; j++)
        {
        //copy to an auxiliary variable to not lose the value
        //swap one with the other (the j with width - j)
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //does the 4 corners
    //does first row, last row, first colon and last colon (except the corners)
    //does all the others that aren't the first/last row/colon
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
