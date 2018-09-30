#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED

typedef struct
{
    int id;
    char video[20];
    float precio;
    int dias;
    int idPantalla;
    char cuit[20];
    int isEmpty;
}Contratacion;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define FALSE 0
#define TRUE 1
int con_inicializarLista(Contratacion* con, int len);
int con_Alta(Contratacion* con, int len, int index);


#endif // CONTRATACIONES_H_INCLUDED
