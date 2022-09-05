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
    BYTE buffer[512];
    int BLOCK_SIZE = 1;
    char *filename = "000";
    while (fread(buffer, sizeof(BYTE)*512, BLOCK_SIZE, f) == BLOCK_SIZE)
    {
        //Read 512 bytes into buffer
        fread(buffer, 512, BLOCK_SIZE, f);
        //If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If first JPEG
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                FILE *img = fopen(filename,"w");
                counter++;
                fwrite(buffer, sizeof(BYTE)*512, BLOCK_SIZE, img);
                fclose(filename);
            }
            //Else (not first JPEG)
            else
            {
                //give file name
                sprintf(filename, "%03i.jpg", counter);
                FILE *img = fopen(filename,"w");
                counter++;
                fwrite(buffer, sizeof(BYTE)*512, BLOCK_SIZE, img);
                fclose(filename);
            }
        }
        //Else
        else
        {
            //If already found JPEG
            if (counter >= 1)
            {
                FILE *img = fopen(filename,"w");
                fwrite(buffer, sizeof(BYTE)*512, BLOCK_SIZE, img);
                fclose(filename);
            }
            //Else
        }
    }
    //Close any remaining files
    fclose(argv[1]);
    return 0;
}