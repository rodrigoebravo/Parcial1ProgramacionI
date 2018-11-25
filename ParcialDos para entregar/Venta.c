
#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
static int isValidId(char* id);
static int isValidFecha(char* fecha);
static int isValidCodigoProducto(char* codigoProducto);
static int isValidCantidad(char* cantidad);
static int isValidPrecioUnitario(char* precioUnitario);
static int isValidCuitCliente(char* cuitCliente);

Venta* Venta_new()
{
    Venta* this;
    this=malloc(sizeof(Venta));
    return this;
}

void Venta_delete(Venta* this)
{
    free(this);
}

Venta* Venta_newConParametros(char* id, char* fecha, char* codigoProducto,char* cantidad,char* precioUnitario,char* cuitCliente)
{
    Venta* this;
    this=Venta_new();

    if(
    isValidId(id) &&
    isValidFecha(fecha) &&
    isValidCodigoProducto(codigoProducto) &&
    isValidCantidad(cantidad) &&
    isValidPrecioUnitario(precioUnitario) &&
    isValidCuitCliente(cuitCliente) &&
    Venta_setId(this, atoi(id))==TODOOK &&
    Venta_setFecha(this, fecha)==TODOOK &&
    Venta_setCodigoProducto(this, codigoProducto)==TODOOK &&
    Venta_setCantidad(this, atoi(cantidad))==TODOOK &&
    Venta_setPrecioUnitario(this, atof(precioUnitario))==TODOOK &&
    Venta_setCuitCliente(this, cuitCliente)==TODOOK)
        return this;

    Venta_delete(this);
    return NULL;
}

int Venta_setId(Venta* this,int id)
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

int Venta_getId(Venta* this,int* id)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidId(char* id)
{
    int retorno=TRUE;
    return retorno;
}

int Venta_setFecha(Venta* this,char* fecha)
{
    int retorno=ERROR;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=TODOOK;
    }
    return retorno;
}

int Venta_getFecha(Venta* this,char* fecha)
{
    int retorno=ERROR;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidFecha(char* fecha)
{
    int retorno=TRUE;
    return retorno;
}

int Venta_setCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=ERROR;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(this->codigoProducto,codigoProducto);
        retorno=TODOOK;
    }
    return retorno;
}

int Venta_getCodigoProducto(Venta* this,char* codigoProducto)
{
    int retorno=ERROR;
    if(this!=NULL && codigoProducto!=NULL)
    {
        strcpy(codigoProducto,this->codigoProducto);
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidCodigoProducto(char* codigoProducto)
{
    int retorno=TRUE;
    return retorno;
}

int Venta_setCantidad(Venta* this,int cantidad)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=TODOOK;
    }
    return retorno;
}

int Venta_getCantidad(Venta* this,int* cantidad)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidCantidad(char* cantidad)
{
    int retorno=TRUE;
    return retorno;
}


int Venta_setPrecioUnitario(Venta* this,float precioUnitario)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=TODOOK;
    }
    return retorno;
}

int Venta_getPrecioUnitario(Venta* this,float* precioUnitario)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidPrecioUnitario(char* precioUnitario)
{
    int retorno=TRUE;
    return retorno;
}

int Venta_setCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=ERROR;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(this->cuitCliente,cuitCliente);
        retorno=TODOOK;
    }
    return retorno;
}

int Venta_getCuitCliente(Venta* this,char* cuitCliente)
{
    int retorno=ERROR;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(cuitCliente,this->cuitCliente);
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidCuitCliente(char* cuitCliente)
{
    int retorno=TRUE;
    return retorno;
}

void Venta_print(Venta* this)
{
    if(this!=NULL)
    {
        printf("Id: %d, Fecha: %s, Codigo Producto: %s, Cantidad: %d Precio Unitario: %f, Cuit: %s\n",
                    this->id,
                    this->fecha,
                    this->codigoProducto,
                    this->cantidad,
                    this->precioUnitario,
                    this->cuitCliente);
    }
}
