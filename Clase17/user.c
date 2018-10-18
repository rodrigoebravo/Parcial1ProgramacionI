#include "user.h"
static int isValidName(char* name);
static int isValidEmail(char* email);

User* user_new(void)
{
    return (User*) malloc (sizeof(User));
}

User* user_newParametros(char* name, char* email)
{
    User* this=NULL;
    this=user_new();
    if(this==NULL
    || user_setName(this, name)
    || user_setEmail(this, email))
    {
        user_delete(this);
        this=NULL;
    }
    return this;
}

void user_delete(User* this)
{
    free(this);
}

int user_setName(User* this, char* name)
{
    int retorno=ERROR;
    if(this!=NULL && isValidName(name))
    {
        strcpy(this->name,name);
        retorno=TODOOK;
    }
    return retorno;
}

int user_getName(User* this, char* name)
{
    int retorno=ERROR;
    if(this!=NULL && name!=NULL)
    {
        strcpy(name,this->name);
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidName(char* name)
{
    return TRUE;
}

int user_compareName(User* thisA, User* thisB)
{
    return strcmp(thisA->name, thisB->name);
}

int user_setEmail(User* this, char* email)
{
    int retorno=ERROR;
    if(this!=NULL && isValidEmail(email))
    {
        strcpy(this->email,email);
        retorno=TODOOK;
    }
    return retorno;
}

int user_getEmail(User* this, char* email)
{
    int retorno=ERROR;
    if(this!=NULL && email!=NULL)
    {
        strcpy(email,this->email);
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidEmail(char* email)
{
    return TRUE;
}

int user_compareEmail(User* thisA, User* thisB)
{
    return strcmp(thisA->email, thisB->email);
}

void user_print(User* this)
{
    printf("Name: %s email: %s ID: %d\n",
        this->name,
        this->email,
        this->id
          );
}
