#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

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

Venta* Venta_newConParametros(char* id,
				char* fechaVenta,
				char* codigoProducto,
				char* cantidadVendida,
				char* precioUnitario,
				char* cuitCliente)
{
    Venta* this;
    this=Venta_new();
    if(
    esNumero(id)&&
    esNumero(cantidadVendida)&&
    !Venta_setId(this,atoi(id)) &&
    !Venta_setFechaVenta(this,fechaVenta)&&
    !Venta_setCodigoProducto(this,codigoProducto)&&
    !Venta_setCantidadVendida(this,atoi(cantidadVendida))&&
    !Venta_setPrecioUnitario(this,atof(precioUnitario))&&
    !Venta_setCuitCliente(this,cuitCliente))
    {
        return this;
    }
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


int isValidId(int* id)
{
    int retorno=TRUE;

    return retorno;
}


int Venta_setFechaVenta(Venta* this,char* fechaVenta)
{
    int retorno=ERROR;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(this->fechaVenta,fechaVenta);
        retorno=TODOOK;
    }
    return retorno;
}

int Venta_getFechaVenta(Venta* this,char* fechaVenta)
{
    int retorno=ERROR;
    if(this!=NULL && fechaVenta!=NULL)
    {
        strcpy(fechaVenta,this->fechaVenta);
        retorno=TODOOK;
    }
    return retorno;
}
int isValidFechaVenta(char* fechaVenta)
{
    int retorno=TRUE;

    return retorno;
}


int Venta_setCantidadVendida(Venta* this,int cantidadVendida)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        this->cantidadVendida=cantidadVendida;
        retorno=TODOOK;
    }
    return retorno;
}

int Venta_getCantidadVendida(Venta* this,int* cantidadVendida)
{
    int retorno=ERROR;
    if(this!=NULL)
    {
        *cantidadVendida=this->cantidadVendida;
        retorno=TODOOK;
    }
    return retorno;
}
int isValidCantidadVendida(char* CantidadVendida)
{
    int retorno=FALSE;
    if(esNumero(CantidadVendida))
    {
        retorno=TRUE;
    }
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
int isValidPrecioUnitario(char* precioUnitario)
{
    int retorno=FALSE;
    if(esDecimal(precioUnitario))
    {
        retorno=TRUE;
    }
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
int isValidCuitCliente(char* cuitCliente)
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
int isValidCodigoProducto(char* codigoProducto)
{
    int retorno=TRUE;

    return retorno;
}


int Venta_print(Venta* this)
{
    int idAux;
    char fechaVentaAux[10];
    char codigoProductoAux[20];
    int cantidadVendidaAux;
    float precioUnitarioAux;
    char cuitClienteAux[20];

    int ret=ERROR;
    if(Venta_getId(this, &idAux)==TODOOK &&
	Venta_getCodigoProducto(this, codigoProductoAux)==TODOOK &&
	Venta_getCantidadVendida(this, &cantidadVendidaAux)==TODOOK &&
	Venta_getPrecioUnitario(this, &precioUnitarioAux)==TODOOK &&
	Venta_getCuitCliente(this, cuitClienteAux)==TODOOK
	)
    {
        printf("id: %d - Fecha Venta: %s - codigo de producto:%s - cantidad vendida: %d - precio unitario: %f - CUIT cliente: %s\n",
    idAux,
    fechaVentaAux,
    codigoProductoAux,
    cantidadVendidaAux,
    precioUnitarioAux,
    cuitClienteAux);
        ret=TODOOK;
    }
    return ret;
}
