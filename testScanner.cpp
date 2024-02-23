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
                // Set token instance string and line #
                tokenArray[tokenCount].tokenInstance[tokenIndex] = '\0'; // Null-terminate the token string
                tokenArray[tokenCount].lineNum = line;

                // Find TokenId
                //scanner(token)

                // Print Result
                printf("%s  :  %d\n", tokenArray[0].tokenInstance, tokenArray[0].lineNum);
                printf("%s  :  %d\n", tokenArray[1].tokenInstance, tokenArray[1].lineNum);

                // Increment line if new line is found
                if (c == 10) {
                    line++;
                }

                tokenIndex = 0;
                tokenCount++;
            }
            continue;
        }

        // Start of token
        tokenArray[tokenCount].tokenInstance[tokenIndex++] = c;

        // Handle New Line
        printf("%d ", c);
        if (c == 10) {
            line++;
        }
    }



}