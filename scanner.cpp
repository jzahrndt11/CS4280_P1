/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - scanner.cpp
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scanner.h"
#include "testScanner.h"

int tableArr[12][12] = {
        { 1, -1, 3, 5, 6, -2, 8, -3, 10, -4, 0, 1001 },
        { -5, 2, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5 },
        { 1002, 2, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002, 1002 },
        { -5, 4, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5 },
        { 1003, 4, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003, 1003 },
        { 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004 },
        { 1004, 1004, 1004, 1004, 1004, 7, 1004, 1004, 1004, 1004, 1004, 1004 },
        { 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004 },
        { 1004, 1004, 1004, 1004, 1004, 1004, 1004, 9, 1004, 1004, 1004, 1004 },
        { 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004 },
        { 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 11, 1004, 1004 },
        { 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1004 }
};

// Scanner function return Token with string and tokenId
Token scanner(int line) {
    Token token;
    int state = 0;
    int nextState;
    int tokenIndex = 0;

    token.lineNum = line;
    memset(token.tokenInstance, '\0', MAX_TOKEN_SIZE);
    token.tokenId = Unknown;


    while (true) {
        int colNum = getTableColumn(line);

        if (state < 12 && colNum < 12) {
            nextState = tableArr[state][colNum];
        } else {
            printf("Error index greater than 11");
        }

        if (nextState < 0) {
            token.tokenInstance[tokenIndex++] = nextChar;
            switch (nextState) {
                case -1:
                    printf("Error (scanner): No Tokens starts with a { digit }\n");
                    exit(EXIT_FAILURE);
                case -2:
                    printf("Error (scanner): No Tokens starts with a { \" }\n");
                    exit(EXIT_FAILURE);
                case -3:
                    printf("Error (scanner): No Tokens starts with a { $ }\n");
                    exit(EXIT_FAILURE);
                case -4:
                    printf("Error (scanner): No Tokens starts with a { ; }\n");
                    exit(EXIT_FAILURE);
                case -5:
                    printf("Error (scanner): Token { %s } must be followed by a { digit }\n", token.tokenInstance);
                    exit(EXIT_FAILURE);
                default:
                    printf("Error (scanner): Unknown Error");
                    exit(EXIT_FAILURE);
            }
        }

        if (nextState > 1000) {
            switch (nextState) {
                case 1001:
                    token.tokenId = EOF_Token;
                    return token;
                case 1002:
                    token.tokenId = T1_Token;
                    return token;
                case 1003:
                    token.tokenId = T2_Token;
                    return token;
                case 1004:
                    token.tokenId = T3_Token;
                    return token;
                default:
                    printf("Error! (scanner): Unknown Error");
                    token.tokenId = Unknown;
                    return token;
            }
        } else {
            state = nextState;
            token.tokenInstance[tokenIndex++] = nextChar;
            nextChar = fgetc(filePointer);
        }
    }
}
