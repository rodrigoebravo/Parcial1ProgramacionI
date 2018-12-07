#include "utn.h"
#include "Vendedor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int isValidId(char* id);
static int isValidNombreVendedor(char* nombreVendedor);
static int isValidNivel(char* nivel);
static int isValidCantidadProductos(char* cantidadProductos);
static int isValidMontoVendido(char* montoVendido);
static int isValidComision(char* comision);
Vendedor* Vendedor_new()
{
    Vendedor* this;
    this=malloc(sizeof(Vendedor));
    return this;
}

void Vendedor_delete(Vendedor* this)
{
    free(this);
}

Vendedor* Vendedor_newConParametros(char* id,char* nombreVendedor,char* nivel,char* cantidadProductos,char* montoVendido, char* comision)
{
    Vendedor* this;
    this=Vendedor_new();

    if(
    isValidId(id)&&
    isValidNombreVendedor(nombreVendedor)&&
    isValidNivel(nivel)&&
    isValidCantidadProductos(cantidadProductos)&&
    isValidMontoVendido(montoVendido)&&
    !Vendedor_setId(this,atoi(id))&&
    !Vendedor_setNombreVendedor(this,nombreVendedor)&&
    !Vendedor_setNivel(this,atoi(nivel))&&
    !Vendedor_setCantidadProductos(this,atoi(cantidadProductos))&&
    !Vendedor_setMontoVendido(this,atof(montoVendido))&&
    !Vendedor_setComision(this,atof(comision)))
        return this;

    Vendedor_delete(this);
    return NULL;
}

int Vendedor_setId(Vendedor* this,int id)
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

int Vendedor_getId(Vendedor* this,int* id)
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

int Vendedor_setNombreVendedor(Vendedor* this,char* nombreVendedor)
{
    int retorno=-1;
    if(this!=NULL && nombreVendedor!=NULL)
    {
        strcpy(this->nombreVendedor,nombreVendedor);
        retorno=0;
    }
    return retorno;
}

int Vendedor_getNombreVendedor(Vendedor* this,char* nombreVendedor)
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

int Vendedor_setNivel(Vendedor* this,int nivel)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->nivel=nivel;
        retorno=0;
    }
    return retorno;
}

int Vendedor_getNivel(Vendedor* this,int* nivel)
{
    int retorno=-1;
    if(this!=NULL)
    {
        printf("------------------aaaaaaaaaagetnivel1\n");
        *nivel=this->nivel;
        printf("------------------aaaaaaaaaasadhbfawbfvwbvw\n");
        retorno=0;
    }
    return retorno;
}


static int isValidNivel(char* nivel)
{
    int retorno=TRUE;
    return retorno;
}


int Vendedor_setCantidadProductos(Vendedor* this,int cantidadProductos)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidadProductos=cantidadProductos;
        retorno=0;
    }
    return retorno;
}

int Vendedor_getCantidadProductos(Vendedor* this,int* cantidadProductos)
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

int Vendedor_setMontoVendido(Vendedor* this,float montoVendido)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->montoVendido=montoVendido;
        retorno=0;
    }
    return retorno;
}

int Vendedor_getMontoVendido(Vendedor* this,float* montoVendido)
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

int Vendedor_setComision(Vendedor* this,float comision)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->comision=comision;
        retorno=0;
    }
    return retorno;
}

int Vendedor_getComision(Vendedor* this, float* comision)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *comision=this->comision;
        retorno=0;
    }
    return retorno;
}


static int isValidComision(char* comision)
{
    int retorno=TRUE;
    return retorno;
}

void Vendedor_printVendedor(Vendedor* this)
{
    int idAux;
    char nombreVendedorAux[50];
    int nivelAux;
    int cantidadProductosAux;
    float montoVendidoAux;
    float comisionAux;
    if(this!=NULL&&
    Vendedor_getId(this, &idAux)==TODOOK &&
    Vendedor_getNombreVendedor(this, nombreVendedorAux)==TODOOK &&
    Vendedor_getNivel(this, &nivelAux)==TODOOK &&
    Vendedor_getCantidadProductos(this, &cantidadProductosAux)==TODOOK &&
    Vendedor_getMontoVendido(this, &montoVendidoAux)==TODOOK &&
    Vendedor_getComision(this, &comisionAux)==TODOOK)
    {
        printf("ID: %d NOMBRE_VENDEDOR: %s NIVEL: %d CANTIDAD_PRODUCTOS:%d MONTO_VENDIDO:%f COMISION: %f\n",
        idAux, nombreVendedorAux, nivelAux, cantidadProductosAux, montoVendidoAux, comisionAux);
    }
}
