#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "helper-functions.h"

char* setvars(char*, int);
int* setvalues(char**, int);

int main(int argc, char** argv) {
    char* EXPRESSION = argv[1];
    int LENGTH = argc - 2;

    char* VARIABLES = setvars(EXPRESSION, LENGTH); 
    int* VALUES = setvalues(argv, LENGTH);

    int RESULT = calculate(EXPRESSION, VARIABLES, VALUES);
    printf("%s = %d\n", EXPRESSION, RESULT);

    free(VARIABLES);
    free(VALUES);

    return 0;
}

char* setvars(char* expr, int len) {
    int count = 0;
    char* vars = malloc((sizeof(char) * len) + 1);

    for (char* c = expr; *c; c++) {
        if (*c >= 0x41 && *c <= 0x5A) {
            if (strchr(vars, *c) == NULL) {
                vars[count] = *c;
                count++;
            }
        }
    }

    vars[len + 1] = '\0';
    return vars;
}

int* setvalues(char** argv, int len) {
    int* values = malloc(len);
    for (int i = 0; i < len; i++) {
        values[i] = atoi(argv[i + 2]);
    }
    return values;
}
