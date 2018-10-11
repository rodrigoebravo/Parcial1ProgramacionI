#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED

#include "Cliente.h"
#include "Venta.h"

typedef struct
{
    Cliente cliente;
    int cantidadVentas;
    int cantidadAfiches;
    int isEmpty;
}ClienteCantidadVentas;
/**
    Imprime menu principal
    parametro *opcion: opcion a ingresar por el usurio
*/
int inf_printMenu(int* opcion);
/**
    funcion que inicializa listas de ventas y clientes
    parametro ven: lista ventas
    parametro lenVen: longitud de lista de ventas
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
*/
void inicializaListas(Cliente* cli, int lenCli, Venta* ven, int lenVen);
/**
    funcion que imprime id si no es error
    parametro id: id a imprimir
*/
void imprimirIDAlta(int id);
/**
    funcion que imprime clientes con ventas a cobrar
    parametro ven: lista ventas
    parametro lenVen: longitud de lista de ventas
    parametro cli: lista de clientes
    parametro lenCli: longitud de lista de clientes
*/
void inf_imprimirClientesConVentasACobrar(Venta* ven, Cliente* cli, int lenVen, int lenCli);

/**
    funcion que reordena lista clientes por nombre apellido y cuit
    parametro pEntidad: lista de clientes
    parametro len: longitud de lista de clientes
*/
int inf_ordenarNombreApellidoCuit(Cliente* pEntidad,int len);
int inf_cantidadDeVentasPorIDEstado(Venta* pEntidad, int len, int idCliente, int estado, int estadoNoClasificado);
int inf_cantidadDeAfichesPorIDEstado(Venta* pEntidad, int len, int idCliente, int estado);
int inf_printClienteMasVentas(Cliente* cli, Venta* ven, int lenCli, int lenVen, int estado, int estadoNoClasificado, int imprimirAfiches);
void inf_printVentasPorZonaAfiche(Venta* pEntidad, int len);
void inf_printClienteComproMasAfiches(Venta* ven, int lenVen, Cliente* cli, int lenCli);
int inf_cantidadDeAfichesPorID(Venta* pEntidad, int len, int idCliente);
#endif // INFORMAR_H_INCLUDED
