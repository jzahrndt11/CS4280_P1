/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - P1.cpp
 */
#include <stdio.h>
#include <stdlib.h>

#include "token.h"
#include "testScanner.h"

// Main function
int main(int argc, char* argv[]) {
    // Declare Variables
        char* file;
        int character;

    // check the number of commands
    if (argc > 2) {
        printf("Fatal: Improper Usage!\nUsage: P0 [fileName]\n");
        return EXIT_FAILURE;
    }

    // process command line arguments
    if (argv[1] != nullptr) {
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
    if (filePointer == nullptr) {
        perror("Fatal: Error Opening File!\n");
        fclose(filePointer);
        return EXIT_FAILURE;
    }

    // Test Scanner function call
    testScanner(file);

    // End of main
    printf("End of Main\n");
    return 0;
}