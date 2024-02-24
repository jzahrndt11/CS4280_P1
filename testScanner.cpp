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

void testScanner(char* file) {
    // Declare Variables
    int line = 1;
    bool comment = false;
    int tokenIndex = 0;
    int tokenCount = 0;
    char nextChar;

    Token tokenArray[100];

    FILE* filePointer = fopen(file, "r");

    do {
            nextChar = fgetc(filePointer);

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

            // check for EOF
            if (nextChar == EOF) {
                tokenArray[tokenCount].lineNum = line;
                tokenArray[tokenCount].tokenInstance[tokenIndex] = '\0';

                // Find TokenId
                int tokenId = scanner(tokenArray[tokenCount].tokenInstance);

                // Print Result
                printf("%s\t\t%d\n", tokenNames[tokenId], tokenArray[tokenCount].lineNum);
            }

            // Start of token
            tokenArray[tokenCount].tokenInstance[tokenIndex++] = nextChar;
    } while (nextChar != EOF);

}

int getTableColumn(char currentChar) {
    if (isalpha(currentChar)) {
        return 0;
    } else if (isdigit(currentChar)){
        return 1;
    } else {
        switch (currentChar) {
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
            case '\0':
                return 11;
            default:
                return 11;
        }
    }
}




