#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int counter = 0;
    //Open memory card
    FILE *f = fopen(argv[1], "r");
    //Repeat until end of card
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        buffer[];
        //Read 512 bytes into buffer
        fread(, f)
        //If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If first JPEG
            if (counter == 0)
            {
                
                counter++;
            }
            //Else (not first JPEG)
            else
            {
                //give file name
                counter++;
            }
        }
        //Else
        else
        {
            //If already found JPEG

            //Else
        }
    }
    //Close any remaining files
}