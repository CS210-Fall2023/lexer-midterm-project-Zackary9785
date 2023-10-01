#ifndef LEXER_H
#define LEXER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char buffer[]);
int isOperator(char buffer[]);
int isDigit(char buffer[]);
int isString(char buffer[]);
int isComment(char buffer[]);

#endif