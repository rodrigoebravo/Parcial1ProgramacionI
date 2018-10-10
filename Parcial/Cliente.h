#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char cuit[20];
    int isEmpty;
}Cliente;

#include "utn.h"
#include "Venta.h"
int cli_inicializarListaClientes(Cliente* pEntidad, int len);
int cli_darAltaCliente(Cliente* pEntidad, int len);
int cli_modificarClientePorID(Cliente* pEntidad, int len);
int cli_bajaClientePorID(Cliente* cli, int lenCli, Venta* ven, int lenVen);
int cli_obtenerPosicionPorID(Cliente* pEntidad, int len, int id, int* indexRetorno);
int cli_posicionEstaVacia(Cliente* pEntidad, int len, int index);
int cli_printClientes(Cliente* pEntidad, int lenCli);
int cli_validarParametros(Cliente* pEntidad, int lenCli);

#endif // CLIENTE_H_INCLUDED
