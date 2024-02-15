/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - scanner.cpp
 */
#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"

void scanner(struct Token token) {
    printf("%s\n", tokenNames[token.tokenId]);
}