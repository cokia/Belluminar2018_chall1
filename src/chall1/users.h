#ifndef USERS_H
#define USERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct user_struct {
   char *id;
   char *pw;
   char *intro;
};

struct user_struct query_user(char *id);

struct user_struct login_user(char *id, char *pw);

bool register_user(char *id, char *pw, char *intro);

#endif
