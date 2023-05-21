#include <stdio.h>
#include <string.h>

void printBinary(char character);

int main(void) {
    char input[100];

    // Step 1: Ask the user for input
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Step 2: Convert string to ASCII code and print binary representation
    for (int i = 0; i < strlen(input); i++) {
        char character = input[i];

        // Step 3: Convert ASCII code to 8-bit binary and print
        printBinary(character);
    }

    return 0;
}

void printBinary(char character) {
    // Step 3: Convert ASCII code to 8-bit binary and print
    for (int i = 7; i >= 0; i--) {
        char bit = (character >> i) & 1;
        printf("%d", bit);

        // Step 4: Print 8 characters per line
        if (i % 8 == 0) {
            printf(" ");
        }
    }

    printf("\n");
}
