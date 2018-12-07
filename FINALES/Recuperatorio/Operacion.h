#ifndef OPERACION_H_INCLUDED
#define OPERACION_H_INCLUDED
typedef struct
{
    int id;
    char nombreVendedor[50];
    int nivel;
    int cantidadProductos;
    float montoVendido;
}Operacion;

Operacion* Operacion_new();
void Operacion_delete();
Operacion* Operacion_newConParametros(char* id,char* nombreVendedor,char* nivel,char* cantidadProductos,char* montoVendido);

int Operacion_setId(Operacion* this,int id);
int Operacion_getId(Operacion* this,int* id);

int Operacion_setNombreVendedor(Operacion* this,char* nombreVendedor);
int Operacion_getNombreVendedor(Operacion* this,char* nombreVendedor);

int Operacion_setNivel(Operacion* this,int nivel);
int Operacion_getNivel(Operacion* this,int* nivel);

int Operacion_setCantidadProductos(Operacion* this,int cantidadProductos);
int Operacion_getCantidadProductos(Operacion* this,int* cantidadProductos);

int Operacion_setMontoVendido(Operacion* this,float montoVendido);
int Operacion_getMontoVendido(Operacion* this,float* montoVendido);

void Operacion_printOperacion(Operacion* this);
#endif // OPERACION_H_INCLUDED
