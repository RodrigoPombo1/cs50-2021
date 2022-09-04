#include "helpers.h"
#include "math.h"
#include "stdio.h"
#include "string.h"


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

int getBlur(int row, int column, int height, int width, RGBTRIPLE image[height][width], char* color)
{
    float counter = 0;
    int resulting_color = 0;

    //Cycles through the 2 rows surrounding the pixel and the row of the pixel itself
    for (int i = row - 1; i < (row + 2); i++)
    {
        //Cycles though the 2 columns surrounding the pixel and the column of the pixel itself
        for (int j = column - 1; j - 1 < (column + 2); j++)
        {
            if(i - 1 < 0 || j - 1 < 0 || i - 1 >= height || j - 1 >= width)
            {
                continue;
            }
            if (strcmp(color, "Red"))
            {
                resulting_color += image[k][l].rgbtRed;
            }
            else if (strcmp(color, "Green"))
            {
                resulting_color += image[k][l].rgbtGreen;
            }
            else
            {
                resulting_color += image[k][l].rgbtBlue;
            }
            counter++;

        }
    }
    return round(resulting_color / counter);
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image2[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image2[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = getBlur(i, j, height, width, image2, "Red");
            image[i][j].rgbtGreen = getBlur(i, j, height, width, image2, "Green");
            image[i][j].rgbtBlue = getBlur(i, j, height, width, image2, "Blue");
        }
    }
    return;
}