#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct{
    int id;
    int cantidadAfiches;
    char nombreArchivo[100];
    int zona;
    int estado;
    int idCliente;
    int isEmpty;
}Venta;
#include "utn.h"
#include "Cliente.h"


/**
    funcion para inicializar lista ventas
    parametro: pEntidad lista ventas
    parametro: len longitud de lista de ventas
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int ven_inicializarListaVentas(Venta* pEntidad, int len);
/**
    funcion obtiene posicion del id
    parametro: pEntidad lista ventas
    parametro: len longitud de lista de ventas
    parametro: id id a buscar
    parametro: *indexRetorno la posicion del id
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int ven_obtenerPosicionPorID(Venta* pEntidad, int len, int id, int* indexRetorno);
/**
    funcion modifica una venta por id
    parametro: ven lista ventas
    parametro: lenVen longitud de lista de ventas
    parametro: cli lista de clientes
    parametro: lenCli longitud de lista de clientes
    parametro: *indexRetorno la posicion del id
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int ven_ModificarPorID(Venta* ven, int lenVen, Cliente* cli, int lenCli);
/**
    funcion crea una venta
    parametro: ven lista ventas
    parametro: lenVen longitud de lista de ventas
    parametro: cli lista de clientes
    parametro: lenCli longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int ventaAfiche(Cliente* cli, int lenCli, Venta* ven, int lenVen);
/**
    funcion modifica una venta por di
    parametro: ven lista ventas
    parametro: lenVen longitud de lista de ventas
    parametro: cli lista de clientes
    parametro: lenCli longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int printVentas(Venta* ventas, int len);
#endif // VENTA_H_INCLUDED
