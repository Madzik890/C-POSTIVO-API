#ifndef USER_H
#define USER_H

/// <summary>
/// Contain user login and password.
/// Use only in function "getUserLog".
/// </summary>
struct userLog
{
  char * s_login;
  char * s_password;
};

struct userLog  getUserLog();

#endif
