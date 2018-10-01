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
#include "pantalla.h"
#define FALSE 0
#define TRUE 1
int con_inicializarLista(Contratacion* con, int len);
int con_Alta(Contratacion* con, int lenCon, Pantalla* pan, int lenPan, int indexPan);
int con_printPantallaPorCuit(Contratacion* con, int lenCon, char* cuit, int lenCuit, Pantalla* pan, int lenPan);
int con_ModificarPorCuit(Contratacion* con, int lenCon, Pantalla* pan, int lenPan);
int con_alta_forzada(Contratacion* con, int len, char* video, float precio, int dias, int idPan, char* cuit);
int con_cancelar(Contratacion* con, int lenCon, Pantalla* pan, int lenPan);

#endif // CONTRATACIONES_H_INCLUDED
