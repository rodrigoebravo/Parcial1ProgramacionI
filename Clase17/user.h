#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR -1
#define TODOOK 0
#define TRUE 1
#define FALSE 0

typedef struct
{
    int id;
    char name[33];
    char email[65];
}User;

User* user_new(void);
User* user_newParametros(char* name, char* email);
void user_delete(User* this);
int user_setName(User* this, char* name);
int user_compareName(User* thisA, User* thisB);
int user_setEmail(User* this, char* email);
int user_getEmail(User* this, char* email);
int user_compareEmail(User* thisA, User* thisB);
void user_print(User* this);
#endif // USER_H_INCLUDED
