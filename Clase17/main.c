#include "Cliente.h"
#define CANT_CLIENTES 100
int main()
{
    Cliente* clientes[CANT_CLIENTES];
    Cliente* aux;
    int i;

    for(i=0;i<CANT_CLIENTES;i++)
    {
        clientes[i]=NULL;
    }

    aux=cliente_new();
    if(aux!=NULL)
    {
        clientes[0] = cliente_newParametros("bla", "bla");
    }


    return 0;
}
