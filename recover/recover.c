#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //checks if the user used the program correctly
    if (argc != 2)
    {
        return 1;
    }

    //counts amount of jpeg files found
    int counter = 0;

    //creates empty image file
    FILE *img = NULL;

    //array where to store the 512 bytes from the memory card
    BYTE buffer[512];
    char filename[8];

    //Open memory card
    FILE *f = fopen(argv[1], "r");

    //checks if the memory card as any data to begin with
    if (fread(buffer, sizeof(BYTE)*512, 1, f) == 0)
    {
        return 2;
    }

    //Repeat until end of card
    while (fread(buffer, sizeof(BYTE)*512, 1, f) == 1)
    {
        //Read 512 bytes into buffer
        fread(buffer, sizeof(BYTE)*512, 1, f);

        //If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If first JPEG
            if (counter == 0)
            {
                //get the name of the file, open it, write and close it
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename,"w");
                fwrite(buffer, sizeof(BYTE)*512, 1, img);

                counter++;
            }
            //Else (not first JPEG)
            else
            {
                fclose(img);
                //get the name of the file, open it, write and close it
                sprintf(filename, "%03i.jpg", counter);
                img = fopen(filename,"w");
                fwrite(buffer, sizeof(BYTE)*512, 1, img);
                fclose(img);

                counter++;
            }
        }
        //Else
        else
        {
            //If already found JPEG
            if (counter >= 1)
            {
                fwrite(buffer, sizeof(BYTE)*512, 1, img);
            }
            //Else do nothing (continue)
        }
    }
    //Close any remaining files
    fclose(img);
    fclose(f);
    return 0;
}