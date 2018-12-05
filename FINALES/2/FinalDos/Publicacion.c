
#include "Publicacion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
static int isValidIdUsuario(char* idUsuario);
static int isValidPopularidad(char* popularidad);
static int isValidMsg(char* msg);
static int isValidId(char* id);

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

Publicacion* Publicacion_newConParametros(char* id, char* msg, char* popularidad, char* idUsuario)
{
    Publicacion* this;
    this=Publicacion_new();

    if(
    isValidIdUsuario(idUsuario)&&
    isValidPopularidad(popularidad)&&
    isValidMsg(msg)&&
    isValidId(id)&&
    !Publicacion_setId(this,atoi(id))&&
    !Publicacion_setMsg(this,msg)&&
    !Publicacion_setPopularidad(this,atoi(popularidad))&&
    !Publicacion_setIdUsuario(this,atoi(idUsuario)))
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

static int isValidId(char* id)
{
    int retorno=TRUE;
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

static int isValidMsg(char* msg)
{
    int retorno=TRUE;
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

static int isValidPopularidad(char* popularidad)
{
    int retorno=TRUE;
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

static int isValidIdUsuario(char* idUsuario)
{
    int retorno=TRUE;
    return retorno;
}

void Publicacion_printPublicacion(Publicacion* pPublicacion)
{
    int idAux;
    char msgAux[4092];
    int popularidadAux;
    int idUsuarioAux;

    if(pPublicacion!=NULL && Publicacion_getId(pPublicacion, &idAux)==TODOOK && Publicacion_getMsg(pPublicacion, msgAux)==TODOOK && Publicacion_getPopularidad(pPublicacion, &popularidadAux)==TODOOK &&
       Publicacion_getIdUsuario(pPublicacion, &idUsuarioAux)==TODOOK)
    {
        printf("Publicacion - ID: %d IdUsuario: %d Msg: %s Popularidad: %d\n", idAux, idUsuarioAux, msgAux, popularidadAux);
    }
}
