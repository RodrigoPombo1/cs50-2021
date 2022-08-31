#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //selects pixel and averages it's green blue and red values and changes the green blue and red values to the average
    //loops through the whole image
    //each row
    int average;
    for (int i = 0; i < height; i++)
    {
        //each column
        for (int j = 0; j < width; j++)
        {
            //calculates the average of blue, green and red values
            average = round((float)(image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3);
            //changes the values to the average
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loops through the whole image
    //each row
    int auxblue, auxred, auxgreen;
    int middle = width / 2;
    for (int i = 0; i < height; i++)
    {
        //each column
        for (int j = 0; j < middle; j++)
        {
            //copy to an auxiliary variable to not lose the value
            auxblue = image[i][j].rgbtBlue;
            auxred = image[i][j].rgbtRed;
            auxgreen = image[i][j].rgbtGreen;
            //swap one with the other (the j with width - j)
            //swapping the left part
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            //swapping the right part
            image[i][width - j - 1].rgbtBlue = auxblue;
            image[i][width - j - 1].rgbtRed = auxred;
            image[i][width - j - 1].rgbtGreen = auxgreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //does the 4 corners

    //top left
    image[0][0] =
    //top right
    image[0][width - 1] =
    //bottom left
    image[height - 1][0] =
    //bottom right
    image[height - 1][width - 1] =

    //does first row, last row, first column and last column (except the corners)

    //top row
    for(int i = 1; i < width - 1; i++)
    {
        image[0][i] =
    }
    //bottom row
    for(int i = 1; i < width - 1; i++)
    {
        image[height - 2][i] =
    }
    //left row
    for(int i = 1; i < height - 1; i++)
    {
        image[i][0] =
    }
    //right row
    for(int i = 1; i < height - 1; i++)
    {
        image[i][width - 2] =
    }

    //does all the others that aren't the first/last row/column
    //each row
    for (int i = 1; i < height - 1; i++)
    {
        //each column
        for (int j = 1; j < width - 1; j++)
        {
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //does the 4 corners

    //top left
    image[0][0] =
    //top right
    image[0][width - 1] =
    //bottom left
    image[height - 1][0] =
    //bottom right
    image[height - 1][width - 1] =

    //does first row, last row, first column and last column (except the corners)

    //top row
    for(int i = 1; i < width - 1; i++)
    {
        image[0][i] =
    }
    //bottom row
    for(int i = 1; i < width - 1; i++)
    {
        image[height - 2][i] =
    }
    //left row
    for(int i = 1; i < height - 1; i++)
    {
        image[i][0] =
    }
    //right row
    for(int i = 1; i < height - 1; i++)
    {
        image[i][width - 2] =
    }

    //does all the others that aren't the first/last row/column
    //each row
    for (int i = 1; i < height - 1; i++)
    {
        //each column
        for (int j = 1; j < width - 1; j++)
        {
        }
    }
    return;
}