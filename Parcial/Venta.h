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
#define ESTADO_ACOBRAR 0
#define ESTADO_COBRADA 1

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
    parametro ven: lista ventas
    parametro lenVen: longitud de lista de ventas
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
    parametro *indexRetorno: la posicion del id
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int ven_ModificarPorID(Venta* ven, int lenVen, Cliente* cli, int lenCli);
/**
    funcion crea una venta
    parametro ven: lista ventas
    parametro lenVen: longitud de lista de ventas
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int ven_ventaAfiche(Cliente* cli, int lenCli, Venta* ven, int lenVen);
/**
    funcion modifica una venta por di
    parametro ven: lista ventas
    parametro lenVen: longitud de lista de ventas
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int ven_printVentas(Venta* ventas, int len);
/**
    funcion para cobrar las ventas en estado A COBRAR
    parametro ven: lista ventas
    parametro lenVen: longitud de lista de ventas
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int ven_cobrarVentaPorID(Venta* ven, int lenVentas, Cliente* cli, int lenCli);
/**
    funcion para validar puntero Venta(array) y longitud
    parametro ven: lista ventas
    parametro lenVen: longitud de lista de ventas
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
int ven_validarParametros(Venta* pEntidad, int lenVen);

/**
    funcion para imprimir ventas por posicion
    parametro ven: lista ventas
    parametro lenVen: longitud de lista de ventas
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
    return -1 si ocurre algun error o 0 si esta todo OK
*/
void ven_printVentaPorIndex(Venta* venta, int index);
#endif // VENTA_H_INCLUDED
