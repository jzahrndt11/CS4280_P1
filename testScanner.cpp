/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - testScanner.cpp
 */

#include <stdio.h>
#include <ctype.h>

#include "token.h"
#include "testScanner.h"
#include "scanner.h"

const char* tokenNames[] = {
        "EOF Token",
        "T1 Token",
        "T2 Token",
        "T3 Token",
        "Unknown"
};

void testScanner() {
    // Declare Variables
    int line = 1;
    bool comment = false;
    int tokenIndex = 0;
    int tokenCount = 0;


    while ((nextChar = fgetc(filePointer)) != EOF) {
        // Skip Comments
        if (comment) {
            if (nextChar == '#') {
                comment = false;
            }
            continue;
        }

        // Check for start of comment
        if (nextChar == '#') {
            comment = true;
            continue;
        }

        // Skip Spaces and Prints Token
        if (isspace(nextChar)) {
            if (tokenIndex > 0) { // Found a token
                // Set token instance string and line #
                tokenArray[tokenCount].tokenInstance[tokenIndex] = '\0'; // Null-terminate the token string
                tokenArray[tokenCount].lineNum = line;

                // Find TokenId
                int tokenId = scanner(tokenArray[tokenCount].tokenInstance);

                // Print Result
                printf("%s\t%s\t%d\n", tokenNames[tokenId], tokenArray[tokenCount].tokenInstance, tokenArray[tokenCount].lineNum);

                // Increment line if new line is found
                if (nextChar == 10) {
                    line++;
                }

                tokenIndex = 0;
                tokenCount++;
            }
            continue;
        }

        // Start of token
        tokenArray[tokenCount].tokenInstance[tokenIndex++] = nextChar;
    }
}

int getTableColumn(char currentChar) {
        switch (currentChar) {
            case 'A' ... 'Z':
                return 0;
            case 'a' ... 'z':
                return 0;
            case 0 ... 9:
                return 1;
            case '%':
                return 2;
            case '.':
                return 3;
            case '!':
                return 3;
            case '*':
                return 4;
            case '\"':
                return 5;
            case '?':
                return 6;
            case '$':
                return 7;
            case ',':
                return 8;
            case ';':
                return 9;
            case ' ':
                return 10;
            default:
                return 11;
        }
}




