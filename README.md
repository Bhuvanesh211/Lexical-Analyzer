# Lexical Analyzer in C

## Introduction
In computer science, lexical analysis is the process of converting a sequence of characters into a sequence of tokens. A program or function that performs lexical analysis is called a lexical analyzer, lexer, or scanner. A lexer often exists as a single function that is called by a parser or another function. Popular tools like Lex and Yacc are practical examples of lexical analysis.

## Lexical Analyzers in Compiler Design
Lexical analyzers are designed to recognize keywords, operators, and identifiers. They can also identify items like integers, floating-point numbers, character strings, and other similar elements that are written as part of the source program. These items are called tokens, which are parsed in the given input and matched against predefined rules called grammar. When the program does not match this grammar, an error is provided to the user as a compilation error.

A token is a string of characters categorized according to the rules as a symbol (e.g., Identifier, Number, Comma, etc.). The process of forming tokens from an input stream of characters is called tokenization, and the lexer categorizes them according to a symbol type. A lexical analyzer generally does nothing with combinations of tokens, a task left for a parser. For example, a typical lexical analyzer recognizes parentheses as tokens but does nothing to ensure that each “(” is matched with a “)”, which happens in subsequent steps.

Consider this expression in the C programming language and the tokenized table below:

| Token | Token Type          |
|-------|---------------------|
| sum   | Identifier          |
| =     | Assignment operator |
| 3     | Integer literal     |
| +     | Addition operator   |
| 2     | Integer literal     |
| ;     | End of statement    |

Tokens are frequently defined by regular expressions, which are understood by a lexical analyzer generator such as Lex. The lexical analyzer (either generated automatically by a tool like Lex or hand-crafted) reads in a stream of characters, identifies the lexemes in the stream, and categorizes them into tokens. This is called “tokenizing.” If the lexer finds an invalid token, it will report an error. Following tokenizing is parsing. From there, the interpreted data may be loaded into data structures for general use, interpretation, or compiling.

The goal of this project is to implement some functionalities of the lexer by tokenizing the given input C program. This will ensure you build a sound foundation in C programming and gain a big picture in terms of compiler design.

## Requirement Details
Given the input C program, your lexical analyzer should do the following:
- Identify all the keywords.
- Identify all the identifiers.
- Identify literals such as float, characters, string literals, and decimals.
- Identify arrays.
- Display the tokenized output.

Given the vast nature of C programming, this project can be further extended to functions, pointers, user-defined data types, etc.

## Skeleton Code
The skeleton code is an interesting concept used in Emertxe. By looking into the skeleton code, you will get a clear picture of converting the given requirements into a working solution. This will also take care of important aspects like modularity, clean coding practices, reusability, etc.

## Usage
To use this lexical analyzer, compile the C program and run it with a C source file as input.

```bash
gcc lexical_analyzer.c -o lexer
./lexer input.c

