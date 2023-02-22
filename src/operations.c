#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "helper-functions.h"

int getValueOf(char*, char*, int*);
int andOp(int, char*, char*, int*);
int orOp(int, char*, char*, int*);

int calculate(char* expression, char* vars, int* values) {
    char* expressionCpy = malloc(strlen(expression));
    strcpy(expressionCpy, expression);

    char* expressionCpyAddress = expressionCpy;

    int acc = getValueOf(expression, vars, values);
    while (*expressionCpy) {
        switch (*expressionCpy) {
            case '*':
                acc = andOp(acc, expressionCpy, vars, values);
                skipToNextOperator(&expressionCpy);
                break;
            case '+':
                acc = orOp(acc, expressionCpy, vars, values);
                skipToNextOperator(&expressionCpy);
                break;
            default:
                skipToNextOperator(&expressionCpy);
        }
    }

    free(expressionCpyAddress);

    return acc;
}

int calculateSlice(char* expression, char* vars, int* values) {
    char* slice = strSlice(expression, 1, strIndexOfClosingPar(expression));
    int valueOfSlice = calculate(slice, vars, values);
    free(slice);
    return valueOfSlice;

}

int andOp(int acc, char* expression, char* vars, int* values) {
    return acc && getValueOf(expression + sizeof(char), vars, values);
}

int orOp(int acc, char* expression, char* vars, int* values) {
    return acc || getValueOf(expression + sizeof(char), vars, values);
}

int getValueOf(char* var, char* vars, int* values) {
    switch (*var) {
        case '\'':
            return !getValueOf(var + sizeof(char), vars, values);
        case '(':
            return calculateSlice(var, vars, values);
        default:
            return values[strchr(vars, *var) - vars];
    }
}

int isOperator(char op) {
    if (op == '*' || op == '+' || op == '\0') {
        return 1;
    }
    return 0;
}

void skipToNextOperator(char** str) {
    while(**str) {
        (*str)++;
        if (**str == '(') {
            *str += strIndexOfClosingPar(*str);
        }
        if (isOperator(**str)) {
            break;
        }
    }
}

