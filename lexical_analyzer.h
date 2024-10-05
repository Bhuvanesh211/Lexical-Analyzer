#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length for input expression
#define MAX_LENGTH 25

// Function declarations for the lexical analyzer
bool isDelimiter(char chr);           // Check if character is a delimiter
bool isOperator(char chr);            // Check if character is an operator
bool isValidIdentifier(char* str);    // Check if string is a valid identifier
bool isKeyword(char* str);            // Check if string is a keyword
bool isInteger(char* str);            // Check if string is an integer
char* getSubstring(char* str, int start, int end); // Get substring from start to end indices
int lexicalAnalyzer(char* input);     // Perform lexical analysis on input

#endif // LEXICAL_ANALYZER_H
