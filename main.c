#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "lexer.h"

int main (int argc, char *argv[])
{
  FILE *fp = fopen (argv[1], "r");
  if (fp == NULL)
    {
      perror("Error while opening the file\n");
      exit(1);
    }
  char a, buffer[40960], current[256];
  int i, j;
  
  for (i = 0; (a = fgetc (fp)) != EOF; i++)     //feed the entire file into the buffer
  {
    buffer[i] = a;
  }
  fclose (fp);
  
  
  for (i = 0; buffer[i] != '\0'; i++)   //parsing portion begins here
    {				
      if (buffer[i] == ' ' || buffer[i] == '\n')   /* This section skips white space. */
	continue;		
      else if (buffer[i] == '/' && buffer[i + 1] == '*')    /* This section checks for comments. */
	{
	  printf ("%c", buffer[i]);
	  while (1)
	    {
	      if (buffer[i + 2] == '*' && buffer[i + 3] == '/')
		break;
	      i++;
	      printf ("%c", buffer[i]);
	    }
	  printf ("%c%c%c (comment)\n", buffer[i + 1], buffer[i + 2],
		  buffer[i + 3]);
	  i += 4;
	}			
      else if (buffer[i] == '\"')   //checks for strings
	{
	  j = 0;
	  current[j] = buffer[i];
	  i++;
	  j++;
	  while (buffer[i] != '\"')
	    {
	      current[j] = buffer[i];
	      i++;
	      j++;
	    }
	  current[j] = buffer[i];
	  current[j + 1] = '\0';
	  printf ("%s (string)\n", current);
	}			
      else if (buffer[i] == '\'')   //checks for character literals
	{
	  for (j = 0; j < 3; j++)
	    {
	      current[j] = buffer[i];
	      i++;
	    }
	  current[j] = '\0';
	  i--;
	  printf ("%s (character literal)\n", current);
	}			
      else if (buffer[i] > '/' && buffer[i] < ':')    //checks for numeric literals
	{
	  j = 0;
	  while ((buffer[i] > '/' && buffer[i] < ':')
		 || (buffer[i] > '@' && buffer[i] < 'G')
		 || (buffer[i] > '`' && buffer[i] < 'g')
		 || buffer[i] == '#' || buffer[i] == '.'
		 || buffer[i] == '_')
	    {
	      current[j] = buffer[i];
	      i++;
	      j++;
	    }
	  i--;
	  current[j] = '\0';
	  printf ("%s (numeric literal)\n", current);
	}			
      else if ((buffer[i] > '`' && buffer[i] < '{')//checks for identifiers and possible keywords
	       || (buffer[i] > '@' && buffer[i] < '['))
	{
	  j = 0;
	  while ((buffer[i] > '`' && buffer[i] < '{')
		 || (buffer[i] > '@' && buffer[i] < '[')
		 || (buffer[i] > '/' && buffer[i] < ':')
		 || (buffer[i] == '_'))
	    {
	      current[j] = buffer[i];	//put lexeme into array
	      i++;
	      j++;
	    }
	  i--;
	  current[j] = '\0';
	  if (iskeyword (current) == 0)	// Check if keyword
	    printf ("%s (keyword)\n", current);
	  else
	    printf ("%s (identifier)\n", current);
	}			
      else if ((buffer[i] > '\'' && buffer[i] < '0')   //checks for operators
	       || (buffer[i] > '9' && buffer[i] < '?') || buffer[i] == '!'
	       || buffer[i] == '&' || buffer[i] == '[' || buffer[i] == ']'
	       || buffer[i] == '|')
	{
	  j = 0;
	  current[j] = buffer[i];
	  i++;
	  j++;
	  if (buffer[i] == '=' || buffer[i] == '.' || buffer[i] == '<'
	      || buffer[i] == '>' || buffer[i] == '*')
	    {
	      current[j] = buffer[i];
	      j++;
	    }
	  else
	    i--;
	  current[j] = '\0';
	  if (isoperator (current) == 0)
	    printf ("%s (operator)\n", current);
	  else
	    {
	      printf ("ILLEGAL OPERATOR\n");
	      return 0;
	    }
	}			
      else
	{
	  printf ("UNK\n");
	  return 0;
	}
    }
  //printf ("\n");
  return 0;
}