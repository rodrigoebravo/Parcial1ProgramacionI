#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreVendedor[50];
    int nivel;
    int cantidadProductos;
    float montoVendido;
    float comision;
}Vendedor;

Vendedor* Vendedor_new();
void Vendedor_delete();
Vendedor* Vendedor_newConParametros(char* id,char* nombreVendedor,char* nivel,char* cantidadProductos,char* montoVendido, char* comision);

int Vendedor_setId(Vendedor* this,int id);
int Vendedor_getId(Vendedor* this,int* id);

int Vendedor_setNombreVendedor(Vendedor* this,char* nombreVendedor);
int Vendedor_getNombreVendedor(Vendedor* this,char* nombreVendedor);

int Vendedor_setNivel(Vendedor* this,int nivel);
int Vendedor_getNivel(Vendedor* this,int* nivel);

int Vendedor_setCantidadProductos(Vendedor* this,int cantidadProductos);
int Vendedor_getCantidadProductos(Vendedor* this,int* cantidadProductos);

int Vendedor_setMontoVendido(Vendedor* this,float montoVendido);
int Vendedor_getMontoVendido(Vendedor* this,float* montoVendido);

int Vendedor_setComision(Vendedor* this,float comision);
int Vendedor_getComision(Vendedor* this,float* comision);

void Vendedor_printVendedor(Vendedor* this);

#endif // VENDEDOR_H_INCLUDED
