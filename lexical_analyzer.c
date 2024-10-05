#include "lexical_analyzer.h"

#define KEYWORDS_COUNT 32

// Function to check if a character is a delimiter
bool isDelimiter(char chr)
{
    return (chr == ' ' || chr == '+' || chr == '-' || chr == '*' ||
            chr == '/' || chr == ',' || chr == ';' || chr == '%' ||
            chr == '>' || chr == '<' || chr == '=' || chr == '(' ||
            chr == ')' || chr == '[' || chr == ']' || chr == '{' ||
            chr == '}');
}

// Function to check if a character is an operator
bool isOperator(char chr)
{
    return (chr == '+' || chr == '-' || chr == '*' || chr == '/' ||
            chr == '>' || chr == '<' || chr == '=');
}

// Function to check if a string is a valid identifier
bool isValidIdentifier(char *str)
{
    // An identifier cannot start with a digit or be a delimiter
    return (!isdigit(str[0]) && !isDelimiter(str[0]));
}

// Function to check if a string is a keyword
bool isKeyword(char *str)
{
    const char *keywords[KEYWORDS_COUNT] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for",
        "goto", "if", "int", "long", "register", "return", "short",
        "signed", "sizeof", "static", "struct", "switch", "typedef",
        "union", "unsigned", "void", "volatile", "while"};

    // Compare the input string with all keywords
    for (int i = 0; i < KEYWORDS_COUNT; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

// Function to check if a string is an integer
bool isInteger(char *str)
{
    if (str == NULL || *str == '\0')
    {
        return false;
    }

    int i = 0;
    // Check if all characters in the string are digits
    while (isdigit(str[i]))
    {
        i++;
    }

    // Return true if end of the string is reached
    return (str[i] == '\0');
}

// Function to extract a substring from a given string
char *getSubstring(char *str, int start, int end)
{
    static char subStr[MAX_LENGTH + 1]; // Using static array to avoid dynamic allocation
    int subLength = end - start + 1;
    strncpy(subStr, str + start, subLength);
    subStr[subLength] = '\0';
    return subStr;
}

// Function to perform lexical analysis on the input string
int lexicalAnalyzer(char *input)
{
    int left = 0, right = 0;
    int len = strlen(input);

    while (right <= len && left <= right)
    {
        // Move right pointer until a delimiter is found
        if (!isDelimiter(input[right]))
        {
            right++;
        }

        // When a delimiter is found
        if ((isDelimiter(input[right]) && left == right))
        {
            if (isOperator(input[right]))
            {
                printf("Token: Operator, Value: %c\n", input[right]);
            }
            right++;
            left = right;
        }
        else if ((isDelimiter(input[right]) && left != right) ||
                 (right == len && left != right))
        {
            // Extract the substring
            char *subStr = getSubstring(input, left, right - 1);

            // Determine the token type and print it
            if (isKeyword(subStr))
            {
                printf("Token: Keyword, Value: %s\n", subStr);
            }
            else if (isInteger(subStr))
            {
                printf("Token: Integer, Value: %s\n", subStr);
            }
            else if (isValidIdentifier(subStr) && !isDelimiter(input[right - 1]))
            {
                printf("Token: Identifier, Value: %s\n", subStr);
            }
            else if (!isValidIdentifier(subStr) && !isDelimiter(input[right - 1]))
            {
                printf("Token: Unidentified, Value: %s\n", subStr);
            }
            left = right;
        }
    }
    return 0;
}
