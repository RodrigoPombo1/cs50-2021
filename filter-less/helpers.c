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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //taking each pixel, and computing new red, green, and blue values based on the original values of the three
    //loops through the whole image
    //each row
    int auxblue, auxred, auxgreen;
    for (int i = 0; i < height; i++)
    {
        //each column
        for (int j = 0; j < width; j++)
        {
            //calculates the values
            auxred = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            auxgreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            auxblue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            //corrects the values if they exceed 255
            if (auxblue > 255)
            {
                auxblue = 255;
            }
            if (auxred > 255)
            {
                auxred = 255;
            }
            if (auxgreen > 255)
            {
                auxgreen = 255;
            }

            //changes the original values
            image[i][j].rgbtBlue = auxblue;
            image[i][j].rgbtRed = auxred;
            image[i][j].rgbtGreen = auxgreen;
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
    //creates a copy of the original image that won't be modified
    RGBTRIPLE image2[height][width];
    //eachrow
    for (int i = 0; i < height; i++)
    {
        //each column
        for (int j = 0; j < width; j++)
        {
            image2[i][j] = image[i][j];
        }
    }

    //does the 4 corners

    //top left
    image[0][0].rgbtRed = round((float)(image2[0][0].rgbtRed + image2[0][1].rgbtRed + image2[1][0].rgbtRed + image2[1][1].rgbtRed) / 4);
    image[0][0].rgbtBlue = round((float)(image2[0][0].rgbtBlue + image2[0][1].rgbtBlue + image2[1][0].rgbtBlue + image2[1][1].rgbtBlue) / 4);
    image[0][0].rgbtGreen = round((float)(image2[0][0].rgbtGreen + image2[0][1].rgbtGreen + image2[1][0].rgbtGreen + image2[1][1].rgbtGreen) / 4);
    //top right
    image[0][width - 1].rgbtRed = round((float) (image2[0][width - 1].rgbtRed + image2[0][width - 2].rgbtRed + image2[1][width - 1].rgbtRed + image2[1][width - 2].rgbtRed) / 4);
    image[0][width - 1].rgbtBlue = round((float) (image2[0][width - 1].rgbtBlue + image2[0][width - 2].rgbtBlue + image2[1][width - 1].rgbtBlue + image2[1][width - 2].rgbtBlue) / 4);
    image[0][width - 1].rgbtGreen = round((float) (image2[0][width - 1].rgbtGreen + image2[0][width - 2].rgbtGreen + image2[1][width - 1].rgbtGreen + image2[1][width - 2].rgbtGreen) / 4);
    //bottom left
    image[height - 1][0].rgbtRed = round((float) (image2[height - 1][0].rgbtRed + image2[height - 1][1].rgbtRed + image2[height - 2][0].rgbtRed + image2[height - 2][1].rgbtRed) / 4);
    image[height - 1][0].rgbtGreen = round((float) (image2[height - 1][0].rgbtGreen + image2[height - 1][1].rgbtGreen + image2[height - 2][0].rgbtGreen + image2[height - 2][1].rgbtGreen) / 4);
    image[height - 1][0].rgbtBlue = round((float) (image2[height - 1][0].rgbtBlue + image2[height - 1][1].rgbtBlue + image2[height - 2][0].rgbtBlue + image2[height - 2][1].rgbtBlue) / 4);
    //bottom right
    image[height - 1][width - 1].rgbtRed = round((float) (image2[height - 1][width - 1].rgbtRed + image2[height - 1][width - 2].rgbtRed + image2[height - 2][width - 1].rgbtRed + image2[height - 2][width - 2].rgbtRed) / 4);
    image[height - 1][width - 1].rgbtGreen = round((float) (image2[height - 1][width - 1].rgbtGreen + image2[height - 1][width - 2].rgbtGreen + image2[height - 2][width - 1].rgbtGreen + image2[height - 2][width - 2].rgbtGreen) / 4);
    image[height - 1][width - 1].rgbtBlue = round((float) (image2[height - 1][width - 1].rgbtBlue + image2[height - 1][width - 2].rgbtBlue + image2[height - 2][width - 1].rgbtBlue + image2[height - 2][width - 2].rgbtBlue) / 4);

    //does first row, last row, first column and last column (except the corners)

    //top row
    for (int i = 1; i < width - 1; i++)
    {
        image[0][i] =
    }
    //bottom row
    for (int i = 1; i < width - 1; i++)
    {
        image[height - 2][i] =
    }
    //left row
    for (int i = 1; i < height - 1; i++)
    {
        image[i][0] =
    }
    //right row
    for (int i = 1; i < height - 1; i++)
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
