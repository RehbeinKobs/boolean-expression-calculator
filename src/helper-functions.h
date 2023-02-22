#pragma once

char* strSlice(char*, int, int);
int strIndexOf(char*, char);
void strPrint(char*);
int strIndexOfClosingPar(char*);
int isInRange(char, char, char);

int calculate(char*, char*, int*);
int getValueOf(char*, char*, int*);
void skipToNextOperator(char**);
