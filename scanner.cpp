/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - scanner.cpp
 */
#include <stdio.h>
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
    tokenIndex = 0;
    token.lineNum = line;

    memset(token.tokenInstance, '\0', MAX_TOKEN_SIZE);


    while (true) {
        getTableColumn();

        if (state < 12 && colNum < 12) {
            nextState = tableArr[state][colNum];
            //printf("nextState = %d\n", nextState);
        } else {
            printf("Error index greater than 11");
        }

        if (nextState < 0) {
            token.tokenInstance[tokenIndex++] = nextChar;
            switch (nextState) {
                case -1:
                    printf("Error (scanner): No Tokens starts with digit\n");
                    token.tokenId = Unknown;
                    return token;
                case -2:
                    printf("Error (scanner): No Tokens starts with \"\n");
                    token.tokenId = Unknown;
                    return token;
                case -3:
                    printf("Error (scanner): No Tokens starts with $\n");
                    token.tokenId = Unknown;
                    return token;
                case -4:
                    printf("Error (scanner): No Tokens starts with ;\n");
                    token.tokenId = Unknown;
                    return token;
                case -5:
                    printf("Error (scanner): Must be a digit\n");
                    token.tokenId = Unknown;
                    return token;
                default:
                    printf("Error! (scanner)");
                    token.tokenId = Unknown;
                    return token;
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
                    printf("Error! (scanner)");
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



//int scanner(const char token[MAX_TOKEN_SIZE]) {
//    int state = 0;
//    int nextState;
//    int tokenIndex = 0;
//
//    while (true) {
//        char currentChar = token[tokenIndex];
//        int col = getTableColumn(currentChar);
//
//        if (state < 12 && col < 12) {
//            nextState = tableArr[state][col];
//            //printf("nextState = %d\n", nextState);
//        } else {
//            printf("Error index greater than 11");
//        }
//
//        if (nextState < 0) {
//            switch (nextState) {
//                case -1:
//                    printf("Error: No Tokens starts with digit\n");
//                    return 4; // Unknown
//                case -2:
//                    printf("Error: No Tokens starts with \"\n");
//                    return 4; // Unknown
//                case -3:
//                    printf("Error: No Tokens starts with $\n");
//                    return 4; // Unknown
//                case -4:
//                    printf("Error: No Tokens starts with ;\n");
//                    return 4; // Unknown
//                case -5:
//                    printf("Error: Must be a digit\n");
//                    return 4; // Unknown
//                default:
//                    printf("Error!");
//                    return 4; // Unknown
//            }
//        }
//
//        if (nextState > 1000) {
//            switch (nextState) {
//                case 1001:
//                    return 0; // EOF Token
//                case 1002:
//                    return 1; // T1 Token
//                case 1003:
//                    return 2;  // T2 Token
//                case 1004:
//                    return 3; // T3 Token
//                default:
//                    perror("Error!");
//                    return 4; // Unknown
//            }
//        } else {
//            state = nextState;
//            tokenIndex++;
//        }
//    }
//}