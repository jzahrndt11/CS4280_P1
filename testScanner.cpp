/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - testScanner.cpp
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "token.h"
#include "testScanner.h"

Token tokenArray[100];

void testScanner(char* inputFile) {
    // Declare Variables
    int line = 1;
    bool comment = false;
    int tokenIndex = 0;
    int tokenCount = 0;
    int c;

    FILE* inputFilePtr = fopen(inputFile, "r");


    while ((c = fgetc(inputFilePtr)) != EOF) {

        // Handle New Line
        if (c == '\n') {
            line++;
        }

        // Skip Comments
        if (comment) {
            if (c == '#') {
                comment = false;
            }
            continue;
        }

        // Check for start of comment
        if (c == '#') {
            comment = true;
            continue;
        }

        // Skip Spaces and Prints Token
        if (isspace(c)) {
            if (tokenIndex > 0) { // Found a token
                tokenArray[tokenCount].tokenInstance[tokenIndex] = '\0'; // Null-terminate the token string
                tokenArray[tokenCount].lineNum = line;
                //scanner(token) // Find TokenId
                // Print Result
                printf("Made it here");
                printf("%s  :  %d", tokenArray[0].tokenInstance, tokenArray[0].lineNum);
                tokenIndex = 0;
            }
            continue;
        }

        // Start of token
        tokenArray[tokenCount].tokenInstance[tokenIndex++] = c;
    }

    //("%s  :  %d\n", tokenArray[0].tokenInstance, tokenArray[0].lineNum);


}