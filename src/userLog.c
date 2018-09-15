#include "userLog.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>//strcpy

#define STRING_SIZE 255

/// <summary>
/// Gets an account login and password.
/// </summary>
/// <return> User object which login and password. </return>
struct userLog getUserLog()
{
  struct userLog m_user;
  char * s_login = malloc(sizeof(char) * STRING_SIZE);//allocates a 256 place for login
  m_user.s_login = malloc(sizeof(char) * STRING_SIZE + 1);
  char * s_password = malloc(sizeof(char) * STRING_SIZE);//allocates a 256 place for password
  m_user.s_password = malloc(sizeof(char) * STRING_SIZE + 1);


  printf("Login:");
  fgets(s_login, STRING_SIZE - 1, stdin);//waits for user input
  strcpy(m_user.s_login, s_login);

  printf("Password:");
  fgets(s_password, STRING_SIZE - 1, stdin);//waits for user input
  strcpy(m_user.s_password, s_password);

  free(s_login);//release a memory from the login
  free(s_password);//relase a memory frome the password

  return m_user;//return a user data
}
