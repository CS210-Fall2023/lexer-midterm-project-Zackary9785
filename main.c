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
    fp = fopen("test.txt","r");

    if(fp == NULL)
    {
        printf("error while opening the file\n");
        exit(0);
    }
    while((ch = fgetc(fp)) != EOF)
    {
        // for(i = 0; i < 6; ++i)
        // {
        //     if(ch == operators[i])
        //     printf("%c is operator\n", ch);
        // }
    
        if(isalnum(ch))
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
            // else
            //     printf("%s is indentifier\n", buffer);
        }
    
    }
    fclose(fp);
    return 0;
}