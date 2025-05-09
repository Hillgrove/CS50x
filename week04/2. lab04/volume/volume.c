// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open infile.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open outfile.\n");
        return 1;
    }

    float factor = atof(argv[3]);


    // Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    int size8 = sizeof(uint8_t);

    fread(header, size8, HEADER_SIZE, input);
    fwrite(header, size8, HEADER_SIZE, output);


    // Read samples from input file and write updated data to output file
    int16_t buffer;
    int size16 = sizeof(int16_t);

    while (fread(&buffer, size16, 1, input))
    {
        // Update volume
        buffer *= factor;
        fwrite(&buffer, size16, 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}