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
    image[0][0].rgbtBlue = round((float)(image2[0][0].rgbtBlue + image2[0][1].rgbtBlue + image2[1][0].rgbtBlue
                                         + image2[1][1].rgbtBlue) / 4);
    image[0][0].rgbtGreen = round((float)(image2[0][0].rgbtGreen + image2[0][1].rgbtGreen + image2[1][0].rgbtGreen
                                          + image2[1][1].rgbtGreen) / 4);
    //top right
    image[0][width - 1].rgbtRed = round((float)(image2[0][width - 1].rgbtRed + image2[0][width - 2].rgbtRed + image2[1][width -
                                        1].rgbtRed + image2[1][width - 2].rgbtRed) / 4);
    image[0][width - 1].rgbtBlue = round((float)(image2[0][width - 1].rgbtBlue + image2[0][width - 2].rgbtBlue + image2[1][width
                                         - 1].rgbtBlue + image2[1][width - 2].rgbtBlue) / 4);
    image[0][width - 1].rgbtGreen = round((float)(image2[0][width - 1].rgbtGreen + image2[0][width - 2].rgbtGreen
                                          + image2[1][width - 1].rgbtGreen + image2[1][width - 2].rgbtGreen) / 4);
    //bottom left
    image[height - 1][0].rgbtRed = round((float)(image2[height - 1][0].rgbtRed + image2[height - 1][1].rgbtRed
                                         + image2[height - 2][0].rgbtRed + image2[height - 2][1].rgbtRed) / 4);
    image[height - 1][0].rgbtGreen = round((float)(image2[height - 1][0].rgbtGreen + image2[height - 1][1].rgbtGreen
                                           + image2[height - 2][0].rgbtGreen + image2[height - 2][1].rgbtGreen) / 4);
    image[height - 1][0].rgbtBlue = round((float)(image2[height - 1][0].rgbtBlue + image2[height - 1][1].rgbtBlue
                                          + image2[height - 2][0].rgbtBlue + image2[height - 2][1].rgbtBlue) / 4);
    //bottom right
    image[height - 1][width - 1].rgbtRed = round((float)(image2[height - 1][width - 1].rgbtRed + image2[height - 1][width - 2].rgbtRed
                                           + image2[height - 2][width - 1].rgbtRed + image2[height - 2][width - 2].rgbtRed) / 4);
    image[height - 1][width - 1].rgbtGreen = round((float)(image2[height - 1][width - 1].rgbtGreen + image2[height - 1][width
            - 2].rgbtGreen + image2[height - 2][width - 1].rgbtGreen + image2[height - 2][width - 2].rgbtGreen) / 4);
    image[height - 1][width - 1].rgbtBlue = round((float)(image2[height - 1][width - 1].rgbtBlue + image2[height - 1][width -
                                            2].rgbtBlue + image2[height - 2][width - 1].rgbtBlue + image2[height - 2][width - 2].rgbtBlue) / 4);

    //does first row, last row, first column and last column (except the corners)

    //top row
    for (int i = 1; i < width - 2; i++)
    {
        image[0][i].rgbtRed = round((float)(image2[0][i - 1].rgbtRed + image2[0][i].rgbtRed
                                           + image2[0][i + 1].rgbtRed + image2[1][i - 1].rgbtRed
                                            + image2[1][i].rgbtRed + image2[1][i + 1].rgbtRed) / 6);
        image[0][i].rgbtGreen = round((float)(image2[0][i - 1].rgbtGreen + image2[0][i].rgbtGreen
                                           + image2[0][i + 1].rgbtGreen + image2[1][i - 1].rgbtGreen
                                            + image2[1][i].rgbtGreen + image2[1][i + 1].rgbtGreen) / 6);
        image[0][i].rgbtBlue = round((float)(image2[0][i - 1].rgbtBlue + image2[0][i].rgbtBlue
                                           + image2[0][i + 1].rgbtBlue + image2[1][i - 1].rgbtBlue
                                            + image2[1][i].rgbtBlue + image2[1][i + 1].rgbtBlue) / 6);

    }
    //bottom row
    for (int i = 1; i < width - 2; i++)
    {
        image[height - 1][i].rgbtRed = round((float)(image2[height - 1][i - 1].rgbtRed + image2[height - 1][i].rgbtRed
                                           + image2[height - 1][i + 1].rgbtRed + image2[height - 2][i - 1].rgbtRed
                                            + image2[height - 2][i].rgbtRed + image2[height - 2][i + 1].rgbtRed) / 6);
        image[height - 1][i].rgbtGreen = round((float)(image2[height - 1][i - 1].rgbtGreen + image2[height - 1][i].rgbtGreen
                                           + image2[height - 1][i + 1].rgbtGreen + image2[height - 2][i - 1].rgbtGreen
                                            + image2[height - 2][i].rgbtGreen + image2[height - 2][i + 1].rgbtGreen) / 6);
        image[height - 1][i].rgbtBlue = round((float)(image2[height - 1][i - 1].rgbtBlue + image2[height - 1][i].rgbtBlue
                                           + image2[height - 1][i + 1].rgbtBlue + image2[height - 2][i - 1].rgbtBlue
                                            + image2[height - 2][i].rgbtBlue + image2[height - 2][i + 1].rgbtBlue) / 6);
    }
    //left row
    for (int i = 1; i < height - 2; i++)
    {
        image[i][0].rgbtRed = round((float)(image2[i - 1][0].rgbtRed + image2[i][0].rgbtRed
                                           + image2[i + 1][0].rgbtRed + image2[i - 1][0].rgbtRed
                                            + image2[i][0].rgbtRed + image2[i + 1][0].rgbtRed) / 6);
        image[i][0].rgbtGreen = round((float)(image2[i - 1][0].rgbtGreen + image2[i][0].rgbtGreen
                                           + image2[i + 1][0].rgbtGreen + image2[i - 1][0].rgbtGreen
                                            + image2[i][0].rgbtGreen + image2[i + 1][0].rgbtGreen) / 6);
        image[i][0].rgbtBlue = round((float)(image2[i - 1][0].rgbtBlue + image2[i][0].rgbtBlue
                                           + image2[i + 1][0].rgbtBlue + image2[i - 1][0].rgbtBlue
                                            + image2[i][0].rgbtBlue + image2[i + 1][0].rgbtBlue) / 6);
    }
    //right row
    for (int i = 1; i < height - 2; i++)
    {
        image[i][width - 1].rgbtRed = round((float)(image2[i - 1][width - 1].rgbtRed + image2[i][width - 1].rgbtRed
                                           + image2[i + 1][width - 1].rgbtRed + image2[i - 1][width - 1].rgbtRed
                                            + image2[i][width - 1].rgbtRed + image2[i + 1][width - 1].rgbtRed) / 6);
        image[i][width - 1].rgbtGreen = round((float)(image2[i - 1][width - 1].rgbtGreen + image2[i][width - 1].rgbtGreen
                                           + image2[i + 1][width - 1].rgbtGreen + image2[i - 1][width - 1].rgbtGreen
                                            + image2[i][width - 1].rgbtGreen + image2[i + 1][width - 1].rgbtGreen) / 6);
        image[i][width - 1].rgbtBlue = round((float)(image2[i - 1][width - 1].rgbtBlue + image2[i][width - 1].rgbtBlue
                                           + image2[i + 1][width - 1].rgbtBlue + image2[i - 1][width - 1].rgbtBlue
                                            + image2[i][width - 1].rgbtBlue + image2[i + 1][width - 1].rgbtBlue) / 6);
    }

    //does all the others that aren't the first/last row/column
    //each row
    for (int i = 1; i < height - 2; i++)
    {
        //each column
        for (int j = 1; j < width - 2; j++)
        {
            image[i][j].rgbtRed = round((float)(image2[i - 1][j - 1].rgbtRed + image2[i][j - 1].rgbtRed
                                           + image2[i + 1][j - 1].rgbtRed + image2[i - 1][j].rgbtRed
                                            + image2[i][j].rgbtRed + image2[i + 1][j].rgbtRed + image2[i][j
                                            + 1].rgbtRed + image2[i][j + 1].rgbtRed + image2[i][j + 1].rgbtRed) / 9);
            image[i][j].rgbtGreen = round((float)(image2[i - 1][j - 1].rgbtGreen + image2[i][j - 1].rgbtGreen
                                           + image2[i + 1][j - 1].rgbtGreen + image2[i - 1][j].rgbtGreen
                                            + image2[i][j].rgbtGreen + image2[i + 1][j].rgbtGreen + image2[i][j
                                            + 1].rgbtGreen + image2[i][j + 1].rgbtGreen + image2[i][j + 1].rgbtGreen) / 9);
            image[i][j].rgbtBlue = round((float)(image2[i - 1][j - 1].rgbtBlue + image2[i][j - 1].rgbtBlue
                                           + image2[i + 1][j - 1].rgbtBlue + image2[i - 1][j].rgbtBlue
                                            + image2[i][j].rgbtBlue + image2[i + 1][j].rgbtBlue + image2[i][j
                                            + 1].rgbtBlue + image2[i][j + 1].rgbtBlue + image2[i][j + 1].rgbtRed) / 9);
        }
    }
    return;
}