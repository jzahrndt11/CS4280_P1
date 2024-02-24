/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - testScanner.cpp
 */

#include <stdio.h>
#include <ctype.h>

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
int tokenIndex = 0;
int tokenCount = 0;
Token token;

void testScanner() {
    int line = 1;
    bool comment = false;

    do {
        nextChar = fgetc(filePointer);

        if (isspace(nextChar)) {
            continue;
        }

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

        // Set line # for token about to be scanned
        token.lineNum = line;

        // start scanner function
        scanner();

        // Print token info
        printf("%s\t%s\t%d\n", tokenNames[token.tokenId], token.tokenInstance, token.lineNum);

        // Increment line if new line is found
        if (nextChar == 10) {
            line++;
        }

        tokenCount++;

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
            case '\0':
                colNum = 11;
                return;
            default:
                return;
        }
    }
}

//void getChar() {
//    if ((nextChar = getc(filePointer)) != EOF) {
//        colNum = getTableColumn(nextChar);
//    } else {
//        colNum = 11;
//    }
//}

//void avoidComments() {
//    while (nextChar != '#') {
//        getChar();
//    }
//}

//void getNonBlank() {
//    while (isspace(nextChar))
//        nextChar = fgetc(filePointer);
//}

//void addChar() {
//    if (tokenIndex <= 98) {
//        tokenArray[tokenCount].tokenInstance[tokenIndex++] = nextChar;
//        tokenArray[tokenCount].tokenInstance[tokenIndex] = 0;
//    } else {
//        printf("Error (testScanner: addChar) - String is too long!");
//    }
//}

//void testScanner(char* file) {
//    // Declare Variables
//    int line = 1;
//    bool comment = false;
//    int tokenIndex = 0;
//    int tokenCount = 0;
//    char nextChar;
//
//    Token tokenArray[100];
//
//    FILE* filePointer = fopen(file, "r");
//
//    do {
//            nextChar = fgetc(filePointer);
//
//            // Skip Comments
//            if (comment) {
//                if (nextChar == '#') {
//                    comment = false;
//                }
//                continue;
//            }
//
//            // Check for start of comment
//            if (nextChar == '#') {
//                comment = true;
//                continue;
//            }
//
//            // Skip Spaces and Prints Token
//            if (isspace(nextChar)) {
//                if (tokenIndex > 0) { // Found a token
//                    // Set token instance string and line #
//                    tokenArray[tokenCount].tokenInstance[tokenIndex] = '\0'; // Null-terminate the token string
//                    tokenArray[tokenCount].lineNum = line;
//
//                    // Find TokenId
//                    int tokenId = scanner(tokenArray[tokenCount].tokenInstance);
//
//                    // Print Result
//                    printf("%s\t%s\t%d\n", tokenNames[tokenId], tokenArray[tokenCount].tokenInstance, tokenArray[tokenCount].lineNum);
//
//                    // Increment line if new line is found
//                    if (nextChar == 10) {
//                        line++;
//                    }
//
//                    tokenIndex = 0;
//                    tokenCount++;
//                }
//                continue;
//            }
//
//            // check for EOF
//            if (nextChar == EOF) {
//                tokenArray[tokenCount].lineNum = line;
//                tokenArray[tokenCount].tokenInstance[tokenIndex] = '\0';
//
//                // Find TokenId
//                int tokenId = scanner(tokenArray[tokenCount].tokenInstance);
//
//                // Print Result
//                printf("%s\t\t%d\n", tokenNames[tokenId], tokenArray[tokenCount].lineNum);
//            }
//
//            // Start of token
//            tokenArray[tokenCount].tokenInstance[tokenIndex++] = nextChar;
//
//    } while (nextChar != EOF);
//}