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
//int colNum = 0;
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

int getTableColumn() {
    if (isalpha(nextChar)) {
        //colNum = 0;
        return 0;
    } else if (isdigit(nextChar)){
        //colNum = 1;
        return 1;
    } else {
        switch (nextChar) {
            case '#':
                //colNum = -1;
                return -1;
            case '%':
                //colNum = 2;
                return 2;
            case '.':
                //colNum = 3;
                return 3;
            case '!':
                //colNum = 3;
                return 3;
            case '*':
                //colNum = 4;
                return 4;
            case '\"':
                //colNum = 5;
                return 5;
            case '?':
                //colNum = 6;
                return 6;
            case '$':
                //colNum = 7;
                return 7;
            case ',':
                //colNum = 8;
                return 8;
            case ';':
                //colNum = 9;
                return 9;
            case ' ':
                //colNum = 10;
                return 10;
            case '\n':
                //colNum = 10;
                return 10;
            case '\t':
                //colNum = 10;
                return 10;
            case EOF:
                //colNum = 11;
                return 11;
            default:
                //colNum = 11;
                return 11;
        }
    }
}