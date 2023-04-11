// Author: Jesus Carlos Martinez Gonzalez
// Date: 10/04/2023
// Recover

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Check proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }

    // Open file to recover
    FILE *infile = fopen(argv[1], "r");

    // Check file is valid
    if (infile == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    unsigned char buffer[512];

    int counter = 0;

    FILE *outfile = NULL;

    char *filename = malloc(8 * sizeof(char));

    // Iterate over the input file searching for .jpg files
    while (fread(buffer, sizeof(char), 512, infile))
    {
        if (buffer[0] == 0xff &&  buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // .jpg file
        {
            // Closes no longer necessary open files, if any
            if (counter > 0)
            {
                fclose(outfile);
            }

            // Create output file

            sprintf(filename, "%03i.jpg", counter);
            outfile = fopen(filename, "w");
            counter++;
        }
        // Write the output file
        if (outfile != NULL)
        {
            fwrite(buffer, sizeof(char), 512, outfile);
        }
    }
    free(filename);
    fclose(outfile);
    fclose(infile);

    return 0;
}