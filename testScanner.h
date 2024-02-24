/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - testScanner.h
 */
#ifndef TESTSCANNER_H
#define TESTSCANNER_H

#include "token.h"

extern char nextChar;
extern int colNum;
extern int tokenIndex;
extern int tokenCount;

extern FILE* filePointer;
extern Token token;

//void testScanner(char*);
void testScanner();
void getTableColumn();
//void getChar();
//void avoidComments();
//void getNonBlank();
//void addChar();

#endif
