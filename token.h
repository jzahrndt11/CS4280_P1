/*
 *  CS4280 - Project P1
 *          - by. Jeremy Zahrndt
 *          - token.h
 *      Resources:
 *          - https://www.geeksforgeeks.org/enumeration-enum-c/
 */
#ifndef TOKEN_H
#define TOKEN_H

const int MAX_TOKEN_SIZE = 100;

// Enumeration - mainly used to assign names to integral constants
typedef enum {
    EOF_Token,
    T1_Token = 1002,
    T2_Token = 1003,
    T3_Token = 1004
} TokenId;

struct Token {
    TokenId tokenId;
    char tokenInstance[MAX_TOKEN_SIZE];
    int lineNum;
};

#endif
