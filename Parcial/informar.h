#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED

#include "Cliente.h"
#include "Venta.h"
int inf_printMenu(int* opcion);
void inicializaListas(Cliente* cli, int lenCli, Venta* ven, int lenVen);
void imprimirIDAlta(int id);
void imprimirClientesConVentasACobrar(Venta* ven, Cliente* cli, int lenVen, int lenCli);
int inf_ordenarNombreApellidoCuit(Cliente* pEntidad,int len);
#endif // INFORMAR_H_INCLUDED
