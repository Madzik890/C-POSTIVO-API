#include "clientOptions.h"
#include "postivoAPI.h"
#include <stdio.h>//files
#include <stdlib.h>
#include <string.h>

#define CONFIG_NAME "clientConfig.txt"

/// <global instances>
int i_loadedConfig = 0;
/// </global instances>

void createOptionsFile();
void defaultOptions();

/// <summary>
/// Converts a config line to parameter.
/// </summary>
/// <param name = line> Line read from config file </param>
void setOptionsParam(char line[50])
{
  char s_param[50];
  if(strstr(line, "[SERVER IP AND PORT]:"))
  {
    strncpy(s_param, line + 21, strlen(line) - 21);
    s_endAction = malloc(strlen(s_param) + 1);
    strcpy(s_endAction, s_param);
  }
}

/// <summary>
/// Loads options about server configuration.
/// Client options options:
/// -ip
/// -port
/// When did not read a file, client connect 
/// with default options.
/// <summary>
void loadClientOptions()
{
  FILE * m_file = NULL;

  m_file = fopen(CONFIG_NAME, "r");
  if(m_file != NULL)
  {
    char s_buffer[50];
    while (fgets(s_buffer, sizeof(s_buffer), m_file) != NULL)
    {
      s_buffer[strlen(s_buffer) - 1] = '\0'; //delete a newline sign
      setOptionsParam(s_buffer);
    }
    i_loadedConfig = 1;
    fclose(m_file);
  }
}

/// <summary>
/// Creates a options file with default values.
/// <summary>
void createClientOptions()
{
  FILE * m_file = NULL;

  m_file = fopen(CONFIG_NAME, "ab+");
  if(m_file != NULL)
  {
    fwrite("[SERVER IP AND PORT]:127.0.0.1:65463 \n", 1, 38, m_file);
    fclose(m_file);
    printf("Created the new config file. \n");
  }
}
