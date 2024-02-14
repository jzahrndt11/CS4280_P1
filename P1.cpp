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
    struct T1_Token* t1Token;
    struct T2_Token* t2Token;
    struct T3_Token* t3Token;
    struct EOF_Token* eofToken;

    // check the number of commands
    if (argc > 2) {
        printf("Fatal: Improper Usage!\nUsage: P0 [fileName]\n");
        return EXIT_FAILURE;
    }

    // Initialize token struct to correct tokenId
    eofToken->tokenId = 1001;
    t1Token->tokenId = 1002;
    t2Token->tokenId = 1003;
    t3Token->tokenId = 1004;

    scanner(t1Token);

    printf("End of Main\n");
    return 0;
}