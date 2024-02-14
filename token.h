/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - token.h
 */
#ifndef TOKEN_H
#define TOKEN_H

struct EOF_Token {
    int tokenId;
    char* tokenInstance;
    int lineNum;
};

struct T1_Token {
    int tokenId;
    char** tokenInstance;
    int lineNum;
};

struct T2_Token {
    int tokenId;
    char** tokenInstance;
    int lineNum;
};

struct T3_Token {
    int tokenId;
    char** tokenInstance;
    int lineNum;
};


#endif
