#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
    int id;
    char fecha[11];
    char codigoProducto[20];
    int cantidad;
    float precioUnitario;
    char cuitCliente[20];
}Venta;

Venta* Venta_new();
void Venta_delete();
Venta* Venta_newConParametros(char* id, char* fecha, char* codigoProducto,char* cantidad,char* precioUnitario,char* cuitCliente);

int Venta_setId(Venta* this,int id);
int Venta_getId(Venta* this,int* id);

int Venta_setFecha(Venta* this,char* fecha);
int Venta_getFecha(Venta* this,char* fecha);

int Venta_setCodigoProducto(Venta* this,char* codigoProducto);
int Venta_getCodigoProducto(Venta* this,char* codigoProducto);

int Venta_setCantidad(Venta* this,int cantidad);
int Venta_getCantidad(Venta* this,int* cantidad);

int Venta_setPrecioUnitario(Venta* this,float precioUnitario);
int Venta_getPrecioUnitario(Venta* this,float* precioUnitario);

int Venta_setCuitCliente(Venta* this,char* cuitCliente);
int Venta_getCuitCliente(Venta* this,char* cuitCliente);
void Venta_print(Venta* this);
#endif // VENTA_H_INCLUDED
