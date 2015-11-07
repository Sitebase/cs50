/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define SOURCE "card.raw"

int main(int argc, char* argv[])
{

    // open file
    FILE* fp = fopen(SOURCE, "r");

    // check if file could be opened
    if(fp == NULL) {
        printf("Could not open %s", SOURCE);
        return 1;
    }

    // buffer to hold the current readed block
    uint8_t block[512];

    // JPEG markers
    uint8_t mark1[4] = {0xff, 0xd8, 0xff, 0xe0};
    uint8_t mark2[4] = {0xff, 0xd8, 0xff, 0xe1};

    // destination file pointer
    FILE* fw = NULL;
    int counter = 0;

    while (fread(block, 512, 1, fp))
    {

        // check if the magic numbers do match a JPEG
        if(memcmp(block, mark1, 4) == 0||memcmp(block, mark2, 4) == 0) {

            // close file if it's open
            if (fw != NULL)
                fclose(fw);

            // generate filename
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);

            // open file to store the jpeg in
            fw = fopen(filename, "w");

            // increase the jpeg filename counter
            counter++;
        }

        if (fw != NULL)
            fwrite(block, 512, 1, fw);
    }

    if (fw != NULL)
        fclose(fw);

    fclose(fp);

}
