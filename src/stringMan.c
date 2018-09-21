#include "stringMan.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define STRING_SIZE 255

/// <summary>
/// Assing a string to proper answer.
/// </summary>
/// <param name = "answer"> Answer form main function. </param>
/// <return> The proper answer. </return>
void assingSource(const unsigned int answer, char ** stringOut)
{
  char * s_string = malloc(sizeof(char) * STRING_SIZE);
  switch (answer)
  {
    case 1:
      strcpy(s_string, "inline");
    break;

    case 2:
      strcpy(s_string,"group");
    break;

    case 3:
      strcpy(s_string,"book");
    break;

    default:
      strcpy(s_string, "inline");
  }
  (*stringOut) = s_string;
}

/// <summary>
/// Gets an information from user inputs.
/// </summary>
/// <param name = "consoleWrite"> An information prints in console </param>
/// <return> user inputs </return>
void assingString(const char * consoleWrite, char ** stringOut)
{
  (*stringOut) = malloc(sizeof(char) * STRING_SIZE);
  printf("%s",consoleWrite);
  fgets((*stringOut), STRING_SIZE - 1, stdin);
  removeNewLine((*stringOut));
}

/// <summary>
/// Removes a new line created by "fgets"
/// </summary>
/// <param name = "string"> String with new line created by "fgets". </param>
void removeNewLine(char* string)
{
  unsigned int u_length = 0;
  if((u_length = strlen(string)) > 0)
  {
    if(string[u_length-1] == '\n')
      string[u_length-1] ='\0';
  }
}
