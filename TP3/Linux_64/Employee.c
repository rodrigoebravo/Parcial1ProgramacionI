#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void Employee_delete(Employee* this)
{
    free(this);
}

Employee* Employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this=Employee_new();

    if(isValidNombre(nombre) && isValidSueldo(sueldo) && isValidHorasTrabajadas(horasTrabajadas) &&
    !Employee_setId(this,atoi(id))&&
    !Employee_setNombre(this,nombre)&&
    !Employee_setHorasTrabajadas(this,atoi(horasTrabajadas))&&
    !Employee_setSueldo(this,atoi(sueldo)))
        return this;

    Employee_delete(this);
    return NULL;
}

int Employee_setId(Employee* this,int id)
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

int Employee_getId(Employee* this,int* id)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=TODOOK;
    }
    return retorno;
}

int isValidId(char* id)
{
    int ret=FALSE;

    if(id!=NULL && atoi(id)>0)
    {
        ret=TRUE;
    }
    return ret;
}


int Employee_setNombre(Employee* this,char* nombre)
{
    int retorno=ERROR;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=TODOOK;
    }
    return retorno;
}

int Employee_getNombre(Employee* this,char* nombre)
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
    int ret=FALSE;
    if(nombre!=NULL && sizeof(nombre)<50)
    {
        ret=TRUE;
    }
    return ret;
}

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=TODOOK;
    }
    return retorno;
}

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
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
    int ret=FALSE;
    if(HorasTrabajadas!=NULL && esNumero(HorasTrabajadas) && atoi(HorasTrabajadas)<320)
        ret=TRUE;

    return ret;
}

int Employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=TODOOK;
    }
    return retorno;
}

int Employee_getSueldo(Employee* this,int* sueldo)
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
    int ret=FALSE;
    if(sueldo!=NULL && esNumero(sueldo) && atoi(sueldo)>0 && atoi(sueldo)<100000)
    {
        ret=TRUE;
    }
    return ret;
}

void Employee_print(Employee* this)
{
    int idAux, horasTrabajadasAux, sueldoAux;
    char nombreAux[50];

    if(Employee_getId(this, &idAux) ==TODOOK &&
    Employee_getNombre(this, nombreAux) ==TODOOK&&
    Employee_getHorasTrabajadas(this, &horasTrabajadasAux) ==TODOOK&&
    Employee_getSueldo(this, &sueldoAux)==TODOOK)
        printf("id: %d - nombre: %s - horas:%d - sueldo: %d\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
}
