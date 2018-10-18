#include "Cliente.h"
static int isValidName(char* name);
static int isValidApellido(char* apellido);

Cliente* cliente_new(void)
{
    return (Cliente*) malloc (sizeof(Cliente));
}

Cliente* cliente_newParametros(char* name, char* apellido)
{
    Cliente* this=NULL;
    this=cliente_new();
    if(this==NULL
    || cliente_setName(this, name)
    || cliente_setApellido(this, apellido))
    {
        cliente_delete(this);
        this=NULL;
    }
    return this;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

int cliente_setName(Cliente* this, char* name)
{
    int retorno=ERROR;
    if(this!=NULL && isValidName(name))
    {
        strcpy(this->name,name);
        retorno=TODOOK;
    }
    return retorno;
}

int cliente_getName(Cliente* this, char* name)
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

int cliente_compareName(Cliente* thisA, Cliente* thisB)
{
    return strcmp(thisA->name, thisB->name);
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno=ERROR;
    if(this!=NULL && isValidApellido(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno=TODOOK;
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno=ERROR;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidApellido(char* apellido)
{
    return TRUE;
}

int cliente_compareApellido(Cliente* thisA, Cliente* thisB)
{
    return strcmp(thisA->apellido, thisB->apellido);
}

void cliente_print(Cliente* this)
{
    printf("Name: %s apellido: %s ID: %d\n",
        this->name,
        this->apellido,
        this->id
          );
}
