/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - P1.cpp
 */
#include <stdio.h>
#include <stdlib.h>

#include "token.h"
#include "scanner.h"

// Main function
int main(int argc, char* argv[]) {
    // Declare Variables
        char* file;
        char character;

        struct Token token;

    // check the number of commands
    if (argc > 2) {
        printf("Fatal: Improper Usage!\nUsage: P0 [fileName]\n");
        return EXIT_FAILURE;
    }

    // process command line arguments
    if (argv[1] != NULL) {
        file = argv[1];
    } else {
        // set up keyboard processing so that hereafter the input method is not relevant
        file = "out";
        FILE* outputFilePointer = fopen(file, "w");
        character = getchar();
        while (character != EOF) {
            fputc(character, outputFilePointer);
            character = getchar();
        }
        fclose(outputFilePointer);
    }

    // make sure file is readable, error otherwise
    FILE* filePointer = fopen(file, "r");
    if (filePointer == NULL) {
        perror("Fatal: Error Opening File!\n");
        fclose(filePointer);
        return EXIT_FAILURE;
    }

    token.tokenId = EOF_Token;
    scanner(token);

    printf("End of Main\n");
    return 0;
}