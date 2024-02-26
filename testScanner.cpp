/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - testScanner.cpp
 */

#include <stdio.h>
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
int colNum = 0;
//int tokenIndex = 0;

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
            //nextChar = fgetc(filePointer);
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

void getTableColumn() {
    if (isalpha(nextChar)) {
        colNum = 0;
        return;
    } else if (isdigit(nextChar)){
        colNum = 1;
        return;
    } else {
        switch (nextChar) {
            case '#':
                colNum = -1;
                return;
            case '%':
                colNum = 2;
                return;
            case '.':
                colNum = 3;
                return;
            case '!':
                colNum = 3;
                return;
            case '*':
                colNum = 4;
                return;
            case '\"':
                colNum = 5;
                return;
            case '?':
                colNum = 6;
                return;
            case '$':
                colNum = 7;
                return;
            case ',':
                colNum = 8;
                return;
            case ';':
                colNum = 9;
                return;
            case ' ':
                colNum = 10;
                return;
            case '\n':
                colNum = 10;
                return;
            case '\t':
                colNum = 10;
                return;
            case EOF:
                colNum = 11;
                return;
            default:
                colNum = 11;
                return;
        }
    }
}