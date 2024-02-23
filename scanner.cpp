/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - scanner.cpp
 */
#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"

const char* tokenNames[] = {
        "EOF Token",
        "T1 Token",
        "T2 Token",
        "T3 Token"
};

void scanner(Token token) {
    printf("%s\n", tokenNames[token.tokenId]);
}