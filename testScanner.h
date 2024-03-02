/*
 *  CS4280 - Project P1
 *      - by. Jeremy Zahrndt
 *      - testScanner.h
 */
#ifndef TESTSCANNER_H
#define TESTSCANNER_H

#include "token.h"

extern char nextChar;
extern FILE* filePointer;

void testScanner();
int getTableColumn(int);

#endif
