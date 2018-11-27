#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "utn.h"
typedef struct
{
    int id;
    char fechaVenta[10];
    char codigoProducto[20];
    int cantidadVendida;
    float precioUnitario;
    char cuitCliente[20];
}Venta;


Venta* Venta_new();
void Venta_delete(Venta* this);
Venta* Venta_newConParametros(char* id, char* fechaVenta, char* codigoProducto, char* cantidadVendida, char* precioUnitario, char* cuitCliente);

int Venta_setId(Venta* this,int id);
int Venta_getId(Venta* this,int* id);
int isValidId(int* id);

int Venta_setFechaVenta(Venta* this,char* fechaVenta);
int Venta_getFechaVenta(Venta* this,char* fechaVenta);
int isValidFechaVenta(char* fechaVenta);

int Venta_setCantidadVendida(Venta* this,int cantidadVendida);
int Venta_getCantidadVendida(Venta* this,int* cantidadVendida);
int isValidCantidadVendida(char* CantidadVendida);

int Venta_setPrecioUnitario(Venta* this,float precioUnitario);
int Venta_getPrecioUnitario(Venta* this,float* precioUnitario);
int isValidPrecioUnitario(char* precioUnitario);

int Venta_setCuitCliente(Venta* this,char* cuitCliente);
int Venta_getCuitCliente(Venta* this,char* cuitCliente);
int isValidCuitCliente(char* cuitCliente);

int Venta_setCodigoProducto(Venta* this,char* codigoProducto);
int Venta_getCodigoProducto(Venta* this,char* codigoProducto);
int isValidCodigoProducto(char* codigoProducto);

int Venta_print(Venta* this);

#endif // VENTA_H_INCLUDED
