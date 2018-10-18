#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

static int isValidApellido(char* apellido);
static int isValidNombre(char* nombre);
static int isValidAltura(float altura);

Empleado* empleado_new(void)
{
    return (Empleado*) malloc (sizeof(Empleado));
}
Empleado* empleado_newParametros(char* nombre, char* apellido, float altura)
{
    Empleado* this=NULL;
    //Empleado* pEmpleado=NULL;
    this=empleado_new();
    if(this==NULL
    || empleado_setNombre(this, nombre)
    || empleado_setApellido(this, apellido)
    || empleado_setAltura(this, altura))
    {
        empleado_delete(this);
        this=NULL;
    }
    return this;
}



void empleado_delete(Empleado* this)
{
    free(this);
}

int empleado_setNombre(Empleado* this, char* nombre)
{
    int retorno=ERROR;
    if(this!=NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre, nombre);
        retorno=TODOOK;
    }
    return retorno;
}

int empleado_getNombre(Empleado* this, char* nombre)
{
    int retorno=ERROR;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    return TRUE;
}

int empleado_compareNombre(Empleado* thisA, Empleado* thisB)
{
    return strcmp(thisA->nombre, thisB->nombre);
}



int empleado_setApellido(Empleado* this, char* apellido)
{
    int retorno=ERROR;
    if(this!=NULL && isValidApellido(apellido))
    {
        strcpy(this->apellido, apellido);
        retorno=TODOOK;
    }
    return retorno;
}

int empleado_getApellido(Empleado* this, char* apellido)
{
    int retorno=ERROR;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido, this->apellido);
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidApellido(char* apellido)
{
    return TRUE;
}

int empleado_setAltura(Empleado* this, float altura)
{
    int retorno=ERROR;
    if(this!=NULL && isValidAltura(altura))
    {
        this->altura=altura;
        retorno=TODOOK;
    }
    return retorno;
}

int empleado_getAltura(Empleado* this, float* altura)
{
    int retorno=ERROR;
    if(this!=NULL && altura!=NULL)
    {
        *altura=this->altura;
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidAltura(float altura)
{
    return TRUE;
}

void empleado_print(Empleado* this)
{
    printf("Nombre: %s Apellido: %s Altura: %f IdEmpleado: %d\n",
        this->nombre,
        this->apellido,
        this->altura,
        this->idEmpleado
    );
}
