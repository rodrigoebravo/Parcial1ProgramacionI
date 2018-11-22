#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

Empleado* Empleado_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Empleado* this;
    this=Empleado_new();

    if(
    !Empleado_setId(this,id)&&
    !Empleado_setNombre(this,nombre)&&
    !Empleado_setHorasTrabajadas(this,horasTrabajadas)&&
    !Empleado_setSueldo(this,sueldo))
        return this;

    Empleado_delete(this);
    return NULL;
}

int Empleado_setId(Empleado* this,int id)
{
    int retorno=ERROR;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=TODOOK;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=TODOOK;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=TODOOK;
    }
    return retorno;
}


int isValidId(int* id)
{
    int retorno=TRUE;

    return retorno;
}


int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=ERROR;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=TODOOK;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=ERROR;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=TODOOK;
    }
    return retorno;
}
int isValidNombre(char* nombre)
{
    int retorno=TRUE;

    return retorno;
}
int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=TODOOK;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=TODOOK;
    }
    return retorno;
}
int isValidHorasTrabajadas(char* HorasTrabajadas)
{
    int retorno=TRUE;

    return retorno;
}
int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=TODOOK;
    }
    return retorno;
}

int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=TODOOK;
    }
    return retorno;
}

int isValidSueldo(char* sueldo)
{
    int retorno=TRUE;

    return retorno;
}


int em_calcularSueldo(void* p)
{
    return 1;
}
