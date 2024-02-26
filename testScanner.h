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
//extern int tokenIndex;
extern FILE* filePointer;

void testScanner();
void getTableColumn();


#endif
