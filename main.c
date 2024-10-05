#include "lexical_analyzer.h"

int main()
{
    char lex_input[MAX_LENGTH + 1];

    // Ask the user to input an expression
    printf("Enter an expression (max length %d): ", MAX_LENGTH);
    fgets(lex_input, MAX_LENGTH + 1, stdin);

    // Remove the newline character if present
    size_t len = strlen(lex_input);
    if (len > 0 && lex_input[len - 1] == '\n')
    {
        lex_input[len - 1] = '\0';
    }

    // Print the input expression and perform lexical analysis
    printf("For Expression \"%s\":\n", lex_input);
    lexicalAnalyzer(lex_input);

    return 0;
}
