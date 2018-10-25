#include "persona.h"


Persona* persona_new()
{
    Persona* this;
    this=malloc(sizeof(Persona));
    return this;
}

void persona_delete(Persona* this)
{
    free(this);
}

Persona* persona_newConParametros(char* id,char* nombre,char* apellido)
{
    Persona* this;
    int auxId;
    this=persona_new();

    if(esNumero(id))
    {
        auxId=atoi(id);
        if(
        !persona_setNombre(this, nombre)&&
        !persona_setId(this,auxId)&&
        !persona_setApellido(this,apellido))
            return this;
    }


    persona_delete(this);
    return NULL;
}

int persona_setId(Persona* this,int id)
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

int persona_getId(Persona* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int persona_setNombre(Persona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int persona_getNombre(Persona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int persona_setApellido(Persona* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int persona_getApellido(Persona* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

void persona_print(Persona* this)
{
    printf("Id: %d nombre: %s apellido: %s", this->id, this->nombre, this->apellido);
}
