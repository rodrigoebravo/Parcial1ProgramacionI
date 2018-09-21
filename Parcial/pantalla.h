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

#define TIPO_LED 0
#define TIPO_LCD 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define FALSO 0
#define VERDADERO 1
int pan_inicializarLista(Pantalla* pan, int len);
int pan_Alta(Pantalla* pan, int len, int index);


#endif // PANTALLA_H_INCLUDED
