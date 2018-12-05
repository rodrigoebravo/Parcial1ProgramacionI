
#include "Usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Usuario* Usuario_new()
{
    Usuario* this;
    this=malloc(sizeof(Usuario));
    return this;
}

void Usuario_delete(Usuario* this)
{
    free(this);
}

Usuario* Usuario_newConParametros(int id,char* nick,int popularidad)
{
    Usuario* this;
    this=Usuario_new();

    if(
    !Usuario_setId(this,id)&&
    !Usuario_setNick(this,nick)&&
    !Usuario_setPopularidad(this,popularidad))
        return this;

    Usuario_delete(this);
    return NULL;
}

int Usuario_setId(Usuario* this,int id)
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

int Usuario_getId(Usuario* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Usuario_setNick(Usuario* this,char* nick)
{
    int retorno=-1;
    if(this!=NULL && nick!=NULL)
    {
        strcpy(this->nick,nick);
        retorno=0;
    }
    return retorno;
}

int Usuario_getNick(Usuario* this,char* nick)
{
    int retorno=-1;
    if(this!=NULL && nick!=NULL)
    {
        strcpy(nick,this->nick);
        retorno=0;
    }
    return retorno;
}

int Usuario_setPopularidad(Usuario* this,int popularidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->popularidad=popularidad;
        retorno=0;
    }
    return retorno;
}

int Usuario_getPopularidad(Usuario* this,int* popularidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *popularidad=this->popularidad;
        retorno=0;
    }
    return retorno;
}

