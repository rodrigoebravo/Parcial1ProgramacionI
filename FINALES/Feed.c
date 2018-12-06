
#include "Feed.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Feed* Feed_new()
{
    Feed* this;
    this=malloc(sizeof(Feed));
    return this;
}

void Feed_delete(Feed* this)
{
    free(this);
}

Feed* Feed_newConParametros(int idPublicacion,char* msg,int likesPublicacion,int idUsuario,char* nick,int likesUsuario)
{
    Feed* this;
    this=Feed_new();

    if(
    !Feed_setIdPublicacion(this,idPublicacion)&&
    !Feed_setMsg(this,msg)&&
    !Feed_setLikesPublicacion(this,likesPublicacion)&&
    !Feed_setIdUsuario(this,idUsuario)&&
    !Feed_setNick(this,nick)&&
    !Feed_setLikesUsuario(this,likesUsuario))
        return this;

    Feed_delete(this);
    return NULL;
}

int Feed_setIdPublicacion(Feed* this,int idPublicacion)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idPublicacion=idPublicacion;
        retorno=0;
    }
    return retorno;
}

int Feed_getIdPublicacion(Feed* this,int* idPublicacion)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idPublicacion=this->idPublicacion;
        retorno=0;
    }
    return retorno;
}

int Feed_setMsg(Feed* this,char* msg)
{
    int retorno=-1;
    if(this!=NULL && msg!=NULL)
    {
        strcpy(this->msg,msg);
        retorno=0;
    }
    return retorno;
}

int Feed_getMsg(Feed* this,char* msg)
{
    int retorno=-1;
    if(this!=NULL && msg!=NULL)
    {
        strcpy(msg,this->msg);
        retorno=0;
    }
    return retorno;
}

int Feed_setLikesPublicacion(Feed* this,int likesPublicacion)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->likesPublicacion=likesPublicacion;
        retorno=0;
    }
    return retorno;
}

int Feed_getLikesPublicacion(Feed* this,int* likesPublicacion)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *likesPublicacion=this->likesPublicacion;
        retorno=0;
    }
    return retorno;
}

int Feed_setIdUsuario(Feed* this,int idUsuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idUsuario=idUsuario;
        retorno=0;
    }
    return retorno;
}

int Feed_getIdUsuario(Feed* this,int* idUsuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idUsuario=this->idUsuario;
        retorno=0;
    }
    return retorno;
}

int Feed_setNick(Feed* this,char* nick)
{
    int retorno=-1;
    if(this!=NULL && nick!=NULL)
    {
        strcpy(this->nick,nick);
        retorno=0;
    }
    return retorno;
}

int Feed_getNick(Feed* this,char* nick)
{
    int retorno=-1;
    if(this!=NULL && nick!=NULL)
    {
        strcpy(nick,this->nick);
        retorno=0;
    }
    return retorno;
}

int Feed_setLikesUsuario(Feed* this,int likesUsuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->likesUsuario=likesUsuario;
        retorno=0;
    }
    return retorno;
}

int Feed_getLikesUsuario(Feed* this,int* likesUsuario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *likesUsuario=this->likesUsuario;
        retorno=0;
    }
    return retorno;
}

