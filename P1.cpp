/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - P1.cpp
 */
#include <stdio.h>
#include <stdlib.h>

// Main function
int main(int argc, char* argv[]) {

    // check the number of commands
    if (argc > 2) {
        printf("Fatal: Improper Usage!\nUsage: P0 [fileName]\n");
        return EXIT_FAILURE;
    }

    printf("Hello World\n");
    return 0;
}