#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Service.h"
#include "utn.h"
static int isValidId(Service* this,char* id);
static int isValidName(Service* this,char* name);
static int isValidEmail(Service* this,char* email);

Service* Service_new()
{
    Service* this;
    this=malloc(sizeof(Service));
    return this;
}

void Service_delete(Service* this)
{
    free(this);
}

Service* Service_newConParametros(char* id,char* name,char* email)
{
    Service* this;
    this=Service_new();

    if(
    isValidId(this, id)&&
    isValidName(this, name)&&
    isValidEmail(this, email)&&
    !Service_setId(this,atoi(id))&&
    !Service_setName(this,name)&&
    !Service_setEmail(this,email))
        return this;

    Service_delete(this);
    return NULL;
}

int Service_setId(Service* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Service_getId(Service* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

static int isValidId(Service* this,char* id)
{
	int retorno=TRUE;
	return retorno;
}

int Service_setName(Service* this,char* name)
{
    int retorno=-1;
    if(this!=NULL && name!=NULL)
    {
        strcpy(this->name,name);
        retorno=0;
    }
    return retorno;
}

int Service_getName(Service* this,char* name)
{
    int retorno=-1;
    if(this!=NULL && name!=NULL)
    {
        strcpy(name,this->name);
        retorno=0;
    }
    return retorno;
}

static int isValidName(Service* this,char* name)
{
	int retorno=TRUE;
	return retorno;
}

int Service_setEmail(Service* this,char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(this->email,email);
        retorno=0;
    }
    return retorno;
}

int Service_getEmail(Service* this,char* email)
{
    int retorno=-1;
    if(this!=NULL && email!=NULL)
    {
        strcpy(email,this->email);
        retorno=0;
    }
    return retorno;
}

static int isValidEmail(Service* this,char* email)
{
	int retorno=TRUE;
	return retorno;
}

int Service_printService(Service* this)
{
    int retorno=ERROR;
    int idAux;
    char nameAux[33];
    char emailAux[65];

    if(this!=NULL &&
       Service_getId(this, &idAux)==TODOOK&&
       Service_getName(this, nameAux)==TODOOK&&
       Service_getEmail(this, emailAux)==TODOOK
       )
    {

        retorno=TODOOK;

        printf("Id: %d - Name: %s - Email: %s\n",idAux, nameAux, emailAux);
    }
    return retorno;
}
