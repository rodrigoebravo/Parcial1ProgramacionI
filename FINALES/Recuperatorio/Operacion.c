#include "utn.h"
#include "Operacion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int isValidId(char* id);
static int isValidNombreVendedor(char* nombreVendedor);
static int isValidNivel(char* nivel);
static int isValidCantidadProductos(char* cantidadProductos);
static int isValidMontoVendido(char* montoVendido);
Operacion* Operacion_new()
{
    Operacion* this;
    this=malloc(sizeof(Operacion));
    return this;
}

void Operacion_delete(Operacion* this)
{
    free(this);
}

Operacion* Operacion_newConParametros(char* id,char* nombreVendedor,char* nivel,char* cantidadProductos,char* montoVendido)
{
    Operacion* this;
    this=Operacion_new();

    if(
    isValidId(id)&&
    isValidNombreVendedor(nombreVendedor)&&
    isValidNivel(nivel)&&
    isValidCantidadProductos(cantidadProductos)&&
    isValidMontoVendido(montoVendido)&&
    !Operacion_setId(this,atoi(id))&&
    !Operacion_setNombreVendedor(this,nombreVendedor)&&
    !Operacion_setNivel(this,atoi(nivel))&&
    !Operacion_setCantidadProductos(this,atoi(cantidadProductos))&&
    !Operacion_setMontoVendido(this,atof(montoVendido)))
        return this;

    Operacion_delete(this);
    return NULL;
}

int Operacion_setId(Operacion* this,int id)
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

int Operacion_getId(Operacion* this,int* id)
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

int Operacion_setNombreVendedor(Operacion* this,char* nombreVendedor)
{
    int retorno=-1;
    if(this!=NULL && nombreVendedor!=NULL)
    {
        strcpy(this->nombreVendedor,nombreVendedor);
        retorno=0;
    }
    return retorno;
}

int Operacion_getNombreVendedor(Operacion* this,char* nombreVendedor)
{
    int retorno=-1;
    if(this!=NULL && nombreVendedor!=NULL)
    {
        strcpy(nombreVendedor,this->nombreVendedor);
        retorno=0;
    }
    return retorno;
}

static int isValidNombreVendedor(char* nombreVendedor)
{
    int retorno=TRUE;
    return retorno;
}

int Operacion_setNivel(Operacion* this,int nivel)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->nivel=nivel;
        retorno=0;
    }
    return retorno;
}

int Operacion_getNivel(Operacion* this,int* nivel)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *nivel=this->nivel;
        retorno=0;
    }
    return retorno;
}


static int isValidNivel(char* nivel)
{
    int retorno=TRUE;
    return retorno;
}


int Operacion_setCantidadProductos(Operacion* this,int cantidadProductos)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidadProductos=cantidadProductos;
        retorno=0;
    }
    return retorno;
}

int Operacion_getCantidadProductos(Operacion* this,int* cantidadProductos)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidadProductos=this->cantidadProductos;
        retorno=0;
    }
    return retorno;
}

static int isValidCantidadProductos(char* cantidadProductos)
{
    int retorno=TRUE;
    return retorno;
}

int Operacion_setMontoVendido(Operacion* this,float montoVendido)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->montoVendido=montoVendido;
        retorno=0;
    }
    return retorno;
}

int Operacion_getMontoVendido(Operacion* this,float* montoVendido)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *montoVendido=this->montoVendido;
        retorno=0;
    }
    return retorno;
}


static int isValidMontoVendido(char* montoVendido)
{
    int retorno=TRUE;
    return retorno;
}


void Operacion_printOperacion(Operacion* this)
{
    int idAux;
    char nombreVendedorAux[50];
    int nivelAux;
    int cantidadProductosAux;
    float montoVendidoAux;

    if(this!=NULL&&
    Operacion_getId(this, &idAux)==TODOOK &&
    Operacion_getNombreVendedor(this, nombreVendedorAux)==TODOOK &&
    Operacion_getNivel(this, &nivelAux)==TODOOK &&
    Operacion_getCantidadProductos(this, &cantidadProductosAux)==TODOOK &&
    Operacion_getMontoVendido(this, &montoVendidoAux)==TODOOK)
    {
        printf("ID: %d NOMBRE_VENDEDOR: %s NIVEL: %d CANTIDAD_PRODUCTOS:%d MONTO_VENDIDO:%f\n",
        idAux, nombreVendedorAux, nivelAux, cantidadProductosAux, montoVendidoAux);
    }
}
