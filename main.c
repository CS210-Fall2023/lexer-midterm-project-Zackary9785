#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "lexer.h"

  
int main(int argc, char *argv[])
{
    char ch, buffer[256];
    FILE *fp;
    int i,j=0;
    fp = fopen(argv[1],"r");

    if(fp == NULL)
    {
        printf("error while opening the file\n");
        exit(0);
    }
    while((ch = fgetc(fp)) != EOF)
    {

        if(isalnum(ch) || ch == '.' || ch == '<' || ch == '>' || ch == '(' || ch == ')' || ch == '+' || ch == '-'
           || ch == '*' || ch == '/' || ch == '|' || ch == '&' || ch == ';' || ch == ',' || ch == ':' || ch == '['
           || ch == ']' || ch == '=' || ch == ":=" || ch == ".." || ch == "<<" || ch == ">>" || ch == "<>" || ch == "<="
           || ch == ">=" || ch == "**" || ch == "!=" || ch == "=>")
        {
            buffer[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n') && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;
                
            if(isOperator(buffer)== 1)
            {
                printf("%s is operator\n", buffer);
            }
            if(isKeyword(buffer) == 1)
                printf("%s is keyword\n", buffer);
            if(isDigit(buffer)==1)
                printf("%s is digit\n", buffer);
            // if(isString(buffer)==1)
            // {
            //     while((buffer[j]) != '"')
            //     {
            //         printf("%s", buffer[j]);
            //     }
            //     printf("%s is string\n", buffer);
            // }
            // if(isComment(buffer)==1)
            // {
            //     while((buffer[j]) != '*/')
            //     {
            //         printf("%s", buffer[j]);
            //     }
            //     printf("%s is comment\n", buffer);
            // }
                
            // else
            //     printf("%s is indentifier\n", buffer);
        }
    
    }
    fclose(fp);
    return 0;
}