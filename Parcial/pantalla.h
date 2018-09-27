#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
/*
typedef struct S_Pantalla{
    int id;
    char tipo[4];
    char nombre[100];
    char direccion[100];
    int isEmpty;
};
typedef struct S_Pantalla pantalla;
*/

typedef struct{
    int id;
    int tipo;
    char nombre[100];
    char direccion[100];
    float precio;
    int isEmpty;

}Pantalla;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "contrataciones.h"
#define FALSE 0
#define TRUE 1
#define TIPO_LED 0
#define TIPO_LCD 1
int pan_inicializarLista(Pantalla* pan, int len);
int pan_Alta(Pantalla* pan, int len, int index);
int pan_darAltaPantalla(Pantalla* pantallas, int len);
int pan_modificarPantalla(Pantalla* pantalla, int len);
int pan_pantallaVacia(Pantalla* pantalla, int len, int index);
int pan_modificarPantallaPorID(Pantalla* pantalla, int len);
int pan_alta_forzada(Pantalla* pantallas, int len, char* nombre, int tipo, char* direccion, float precio);
int pan_BajaPorPosicion(Pantalla* pan, int lenPan, int index, Contratacion* con, int lenCon);
int pan_bajaPantallaPorID(Pantalla* pan, int lenPan, Contratacion* con, int lenCon);
void contratarPantallasPorID(Pantalla* pan, int lenPan, Contratacion* con, int lenCon);
#endif // PANTALLA_H_INCLUDED
