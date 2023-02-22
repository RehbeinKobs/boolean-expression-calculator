#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "helper-functions.h"

char* strSlice(char* src, int begin, int end) {
    char* dest = malloc(end - begin);
    return strncpy(dest, src + (sizeof(char) * begin), end);
}

int strIndexOfClosingPar(char* str) {
	int cur = 0;
	for (char* c = str; *c; c++) {
		switch (*c) {
			case '(':
				cur++;
				break;
			case ')':
				cur--;
				break;
		}
		if (cur == 0) {
			return c - str;
		}
	}
    return 0;
}
