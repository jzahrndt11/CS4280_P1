/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - testScanner.cpp
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"

#include "testScanner.h"
#include "scanner.h"

const char* tokenNames[] = {
        "EOF Token",
        "T1 Token",
        "T2 Token",
        "T3 Token",
        "Unknown"
};

// Initialization of Global Variables
char nextChar = 0;

void testScanner() {
    Token tokenInfo;
    int line = 1;
    bool comment = false;
    memset(tokenInfo.tokenInstance, '\0', MAX_TOKEN_SIZE);

    nextChar = fgetc(filePointer);

    do {
        // Skip Comments
        while (comment) {
            nextChar = fgetc(filePointer);
            if (nextChar == 10) {
                line++;
            }
            if (nextChar == 35) {
                comment = false;
                nextChar = fgetc(filePointer);
            }
        }

        // Check for start of comment
        if (nextChar == 35) {
            comment = true;
            continue;
        }

        // Skip Spaces
        while (isspace(nextChar)) {
            // Increment line if new line is found
            if (nextChar == 10) {
                line++;
            }

            nextChar = fgetc(filePointer);
        }

        // start scanner function
        tokenInfo = scanner(line);

        // Print token info
        printf("%s\t%s\t%d\n", tokenNames[tokenInfo.tokenId], tokenInfo.tokenInstance, tokenInfo.lineNum);

    } while (nextChar != EOF);
}

int getTableColumn(int line) {
    if (isalpha(nextChar)) {
        return 0;
    } else if (isdigit(nextChar)){
        return 1;
    } else {
        switch (nextChar) {
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
            case '\n':
                return 10;
            case '\t':
                return 10;
            case EOF:
                return 11;
            default:
                printf("Error Unknown Character { %c } Line { %d }\n", nextChar, line);
                exit(EXIT_FAILURE);
        }
    }
}