#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    int counter = 0;
    typedef uint8_t BYTE;
    //Open memory card
    FILE *f = fopen(argv[1], "r");
    //Repeat until end of card
    BYTE buffer[];
    int BLOCK_SIZE = 512;
    while (fread(buffer[], 1, BLOCK_SIZE, f) == BLOCK_SIZE)
    {
        //Read 512 bytes into buffer
        fread(buffer[], 1, BLOCK_SIZE, f)
        //If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If first JPEG
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                FILE *img = fopen(filename,"w");
                counter++;
                fwrite(buffer[], 1, BLOCK_SIZE, filename);
            }
            //Else (not first JPEG)
            else
            {
                //give file name
                sprintf(filename, "%03i.jpg", counter);
                FILE *img = fopen(filename,"w");
                counter++;
                fwrite(buffer[], 1, BLOCK_SIZE, filename);
            }
        }
        //Else
        else
        {
            //If already found JPEG
            if (counter >= 1)
            {
                fwrite(buffer[], 1, BLOCK_SIZE, filename);
            }
            //Else
        }
    }
    //Close any remaining files
}