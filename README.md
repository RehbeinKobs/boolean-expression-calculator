<p align="center"> Disclaimer: This project was created for learning and practicing C and is not intended to be used as a serious application </p>

# Boolean Expression Calculator
The Boolean Expression Calculator is a simple command line tool for calculating boolean expressions.
# Instalation
### Compiling
To compile the program, use the following command:

`gcc main.c str-functions.c operations.c -o app`
### Running
:warning: This program does not check for errors. If given incorrect arguments it will break :warning:

On Linux, use the following command to run the program:

`./app [expression] [value 1] [value 2] ...`

On Windows, use the following command to run the program:

`app [expression] [value 1] [value 2] ...`
# Usage
To use the program, write a boolean expression using variables from A to Z and pass their values as arguments. The order of the value arguments will depend on the order of appearance of the variables in the expression.
 For example, given the expression "A+C+B+C" the order of the value arguments will be `./app [expression] [A] [C] [B]`.

:warning: Letters must be uppercase and values must be either 1 or 0 :warning:

The expression follows the pattern "variable operator variable operator variable...", considering the NOT operator and parenthesis blocks as variables. The calculation runs from left to right, prioritizing parenthesis blocks.

### Operators

The program supports the following operators:

- `*` AND
- `+` OR
- `'` NOT

### Examples

Here are some examples of how to use the program:

`./app "A+B*'(A*'B)*C" 1 0 1`
- A+B*'(A*'B)*C
- 1+0*'(1*'0)*1
- 1*'(1*'0)*1
- 1*'(1*1)*1
- 1*'(1)*1
- 1\*0\*1
- 0*1
- 0


