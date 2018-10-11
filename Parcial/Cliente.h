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
/**
    funcion para inicializar array
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int cli_inicializarListaClientes(Cliente* pEntidad, int len);
/**
    funcion para dar de alta un cliente
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int cli_darAltaCliente(Cliente* pEntidad, int len);
/**
    funcion para modificar cliente por ID
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int cli_modificarClientePorID(Cliente* pEntidad, int len);
/**
    funcion para eliminar cliente por ID
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int cli_bajaClientePorID(Cliente* cli, int lenCli, Venta* ven, int lenVen);
/**
    funcion para buscar posicion en clientes por id
    parametro id: id a modificar en clientes
    parametro *indexRetorno: posicion para guardar posicion donde se encuentra el id
    parametro pEntidad: lista de clientes
    parametro len: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int cli_obtenerPosicionPorID(Cliente* pEntidad, int len, int id, int* indexRetorno);
/**
    funcion para saber si la posicion esta vacia en el array
    parametro pEntidad: lista de clientes
    parametro len: longitud de lista de clientes
    parametro index: index a comprobar la informacion que tiene
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int cli_posicionEstaVacia(Cliente* pEntidad, int len, int index);
/**
    funcion imprimir array de clientes
    parametro pEntidad: lista de clientes
    parametro lenCli: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int cli_printClientes(Cliente* pEntidad, int lenCli);
/**
    funcion para validar puntero Cliente(array) y longitud
    parametro pEntidad: lista de clientes
    parametro lenCli: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int cli_validarParametros(Cliente* pEntidad, int lenCli);
/**
    funcion imprimir un cliente por posicion
    parametro pEntidad: lista de clientes
    parametro index: posicion en array clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
void cli_printCliente(Cliente* pEntidad, int index);
/**
    funcion buscar maximo ID en clientes
    parametro pEntidad: lista de clientes
    parametro len: longitud de lista de clientes
    parametro *idRetorno: id maximo encontrado
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int cli_obtenerMaximoID(Cliente* pEntidad, int len, int* idRetorno);

/**
    funcion devuelve mayor ID
    parametro pEntidad: lista de clientes
    parametro len: longitud de lista de clientes
    return -1 si ocurre algun error o >=0 si esta todo OK (id)
*/
int cli_getMaxIDCliente(Cliente* pEntidad, int len);
/**
    funcion pregunta si el array de clientes tiene datos
    parametro pEntidad: lista de clientes
    parametro len: longitud de lista de clientes
    return -1 si ocurre algun error o >=0 si esta todo OK
*/
int clientesTieneDatos(Cliente* pEntidad, int len);
#endif // CLIENTE_H_INCLUDED
