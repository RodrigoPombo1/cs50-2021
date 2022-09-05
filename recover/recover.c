#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Open memory card
    FILE *f = fopen(argv[1], "r");
    //Repeat until end of card
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        int buffer[];
        //Read 512 bytes into buffer
        fread(, f)
        //If start of new JPEG
        if (buffer[0] == || buffer[1] == || buffer[2] == || buffer[3] == )
            //If first JPEG

            //Else
        //Else
            //If already found JPEG

            //Else
    }
    //Close any remaining files
}