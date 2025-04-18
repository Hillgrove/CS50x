#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open input file\n");
        return 1;
    }

    // Read header
    WAVHEADER header;
    fread(&header, 1, sizeof(WAVHEADER), input);

    // Use check_format to ensure WAV format
    if (!check_format(header))
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Open output file for writing
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open output file\n");
        return 1;
    }

    // Write header to file
    fwrite(&header, 1, sizeof(WAVHEADER), output);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    BYTE audio_block[block_size];
    // Read from end of inputfile and backwards
    for (long i = 0; i < header.subchunk2Size; i += block_size)
    {
        // Sets pointer to end of file and moves it backwards
        fseek(input, -(i + block_size), SEEK_END);
        // save to array
        fread(audio_block, 1, block_size, input);
        // Write to output file
        fwrite(audio_block, 1, block_size, output);
    }
    // Close files
    fclose(input);
    fclose(output);
    return 0;
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    return header.blockAlign;
}