#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct{
    char nombre[50];
    char apellido[50];
    int idCliente;
    int isEmpty;
}Cliente;



Cliente* clientes_new();
void clientes_delete();
Cliente* clientes_newConParametros(char* nombre,char* apellido,char* idCliente,char* isEmpty);

int clientes_setNombre(Cliente* this,char* nombre);
int clientes_getNombre(Cliente* this,char* nombre);

int clientes_setApellido(Cliente* this,char* apellido);
int clientes_getApellido(Cliente* this,char* apellido);

int clientes_setIdCliente(Cliente* this,char* idCliente);
int clientes_getIdCliente(Cliente* this,int* idCliente);

int clientes_setIsEmpty(Cliente* this,char* isEmpty);
int clientes_getIsEmpty(Cliente* this,int* isEmpty);

#endif // CLIENTES_H_INCLUDED
