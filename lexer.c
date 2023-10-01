#include "lexer.h"

int isKeyword(char buffer[])
{
    char keywords[37][10] = {"accessor", "and", "array", "begin", "bool", "case", "character", "constant",
    "else", "elseif", "end", "exit", "function", "if", "in", "integer", "interface", "is", "loop", "module",
    "mutator", "natural", "null", "of", "or", "other", "out", "positive", "procedure", "range", "return",
    "struct", "subtype", "then", "type", "when", "while"};
    int i, flag = 0;

    for(i = 0; i < 37; ++i)
    {
        if(strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int isOperator(char buffer[])
{
    char operators[27][3]= {".", "<", ">", "(", ")", "+", "-", "*", "/", "|", "&", ";", ",", ":",
    "[", "]", "=", ":=", "..", "<<", ">>", "<>", "<=", ">=", "**", "!=", "=>"};
    int i, flag = 0;

    for(i = 0; i < 27; ++i)
    {
        if(strcmp(operators[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int isDigit(char buffer[])
{
    char operators[10][2]= {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int i, flag = 0;

    for(i = 0; i < 10; ++i)
    {
        if(strcmp(operators[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int isString(char buffer[])
{
    for(int i=0; i<256; i++)
    {
        if(buffer[i] == '"')
        {
            return 1;
        }
    }
}

int isComment(char buffer[])
{
    for(int i=0; i<256; i++)
    {
        if(buffer[i] == '"')
        {
            return 1;
        }
    }
}