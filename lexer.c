#include "lexer.h"

int iskeyword (char current[])
{
char *keywords[34] ={	"accessor", "and", "array", "begin",	
"bool", "case", "else", "elsif", "end", "exit",	"function", "if", "in", "integer", "interface", "is",	
"loop", "module", "mutator", "natural", "null",	"of", "or", "others", "out", "positive", "procedure",	
"return", "struct", "subtype", "then",	"type", "when", "while"};

  int flag = 0;
  for (int i = 0; i < 34; i++)
    {
      if (strcmp (keywords[i], current) == 0)
	{
	  flag = 1;
	  break;
	}
    }
  if (flag == 1)
    return 0;
  else
    return 1;
}

int isoperator (char current[])
{
char *operators[27] ={	".", "<", ">", "(", ")", "+", "-", "*", "/",	
"|", "&", ";", ",", ":", "[", "]", "=", ":=",	"..", "<<", ">>", "<>", "<=", ">=", "**",	"!=", "=>"};

  int flag = 0;
  for (int i = 0; i < 27; i++)
    {
      if (strcmp (operators[i], current) == 0)
	{
	  flag = 1;
	  break;
	}
    }
  if (flag == 1)
    return 0;
  else
    return 1;
}