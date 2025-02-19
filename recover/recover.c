#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    //checks if the user used the program correctly
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    //Open memory card
    FILE *f = fopen(argv[1], "r");

    //checks if the memory card as any data to begin with
    if (f == NULL)
    {
        printf("Failed to open file");
        return 1;
    }

    //array where to store the 512 bytes from the memory card
    BYTE buffer[BLOCK_SIZE];

    //counts amount of jpeg files found
    int counter = 0;

    //creates empty image file
    FILE *img = NULL;

    char filename[8];

    //Repeat until end of card
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, f) == BLOCK_SIZE)
    {
        //checks if the next chunk of memory is the start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If first JPEG
            if (counter == 0)
            {
                //get the name of the file, open it, write and close it (start first image)
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);

                counter++;
            }
            //Else (not first JPEG)
            else
            {
                //close the previous image (completed)
                fclose(img);

                //get the name of the file, open it and write (start new image)
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);

                counter++;
            }
        }
        //if already found at least 1 JPEG previously, continue writing the data
        else if (counter >= 1)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }
    //Close any remaining files
    fclose(img);
    fclose(f);
    return 0;
}