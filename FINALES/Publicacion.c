
#include "Publicacion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Publicacion* Publicacion_new()
{
    Publicacion* this;
    this=malloc(sizeof(Publicacion));
    return this;
}

void Publicacion_delete(Publicacion* this)
{
    free(this);
}

Publicacion* Publicacion_newConParametros(int id,char* msg,int popularidad,int idUsuario)
{
    Publicacion* this;
    this=Publicacion_new();

    if(
    !Publicacion_setId(this,id)&&
    !Publicacion_setMsg(this,msg)&&
    !Publicacion_setPopularidad(this,popularidad)&&
    !Publicacion_setIdUsuario(this,idUsuario))
        return this;

    Publicacion_delete(this);
    return NULL;
}

int Publicacion_setId(Publicacion* this,int id)
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

int Publicacion_getId(Publicacion* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Publicacion_setMsg(Publicacion* this,char* msg)
{
    int retorno=-1;
    if(this!=NULL && msg!=NULL)
    {
        strcpy(this->msg,msg);
        retorno=0;
    }
    return retorno;
}

int Publicacion_getMsg(Publicacion* this,char* msg)
{
    int retorno=-1;
    if(this!=NULL && msg!=NULL)
    {
        strcpy(msg,this->msg);
        retorno=0;
    }
    return retorno;
}

int Publicacion_setPopularidad(Publicacion* this,int popularidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->popularidad=popularidad;
        retorno=0;
    }
    return retorno;
}

int Publicacion_getPopularidad(Publicacion* this,int* popularidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *popularidad=this->popularidad;
        retorno=0;
    }
    return retorno;
}

int Publicacion_setIdUsuario(Publicacion* this,int idUsuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idUsuario=idUsuario;
        retorno=0;
    }
    return retorno;
}

int Publicacion_getIdUsuario(Publicacion* this,int* idUsuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idUsuario=this->idUsuario;
        retorno=0;
    }
    return retorno;
}

