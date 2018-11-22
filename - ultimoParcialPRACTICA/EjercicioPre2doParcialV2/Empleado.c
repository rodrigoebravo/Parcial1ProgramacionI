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

Empleado* Empleado_newConParametros(char* id,char* nombre,char* horasTrabajadas)
{
    Empleado* this;
    this=Empleado_new();
    char sueldo[]="0";
    if(
    esNumero(id)&&
    esNumero(horasTrabajadas)&&
    esNumero(sueldo)&&
    !Empleado_setId(this,atoi(id))&&
    !Empleado_setNombre(this,nombre)&&
    !Empleado_setHorasTrabajadas(this,atoi(horasTrabajadas))&&
    !Empleado_setSueldo(this,atoi(sueldo)))
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
    int retorno=FALSE;
    int horas;
    if(esNumero(HorasTrabajadas))
    {
        horas=atoi(HorasTrabajadas);
        if(horas>79 && horas<241)
            retorno=TRUE;
    }
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

int Empleado_print(Empleado* this)
{
    int idAux, horasTrabajadasAux, sueldoAux;
    char nombreAux[50];
    int ret=ERROR;
    if(Empleado_getId(this, &idAux) ==TODOOK &&
    Empleado_getNombre(this, nombreAux) ==TODOOK&&
    Empleado_getHorasTrabajadas(this, &horasTrabajadasAux) ==TODOOK&&
    Empleado_getSueldo(this, &sueldoAux)==TODOOK)
    {
        //printf("id: %d - nombre: %s - horas:%d - sueldo: %d\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
        ret=TODOOK;
    }
    return ret;
}

int em_calcularSueldo(void* p)
{
    Empleado* aux=(Empleado*)p;
    int horas, sueldo;
    int retorno=ERROR;
    if(p!=NULL &&
       Empleado_getHorasTrabajadas(aux, &horas)==TODOOK &&
       Empleado_getSueldo(aux, &sueldo)==TODOOK)
    {
        if(horas>119 && horas>0)
        {
            sueldo=horas*180;
        }
        else
        {
            if(horas>120 && horas<161)
                sueldo=120*180+(horas-120)*240;
            else
                sueldo=120*180+40*240+(horas-160)*350;
        }
        retorno=Empleado_setSueldo(aux, sueldo);
    }

    return retorno;
}
