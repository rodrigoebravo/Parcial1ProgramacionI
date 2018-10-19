#include "Cliente.h"
#define CANT_CLIENTES 100
int main()
{
    Cliente* clientes[CANT_CLIENTES];
    Cliente* aux;
    int i, indexVacio;

    //inicializar
    for(i=0;i<CANT_CLIENTES;i++)
    {
        clientes[i]=NULL;
    }
    //ALTA CLIENTE
    aux=cliente_new();
    indexVacio=cliente_buscarLugarVacio(clientes, CANT_CLIENTES);
    if(aux!=NULL && indexVacio>=0)
    {
        clientes[indexVacio] = cliente_newParametros("bla", "bla");
    }

    return 0;
}
