#ifndef INFORMAR_H_INCLUDED
#define INFORMAR_H_INCLUDED

#include "Cliente.h"
#include "Venta.h"
int inf_printMenu(int* opcion);
void inicializaListas(Cliente* cli, int lenCli, Venta* ven, int lenVen);
#endif // INFORMAR_H_INCLUDED
