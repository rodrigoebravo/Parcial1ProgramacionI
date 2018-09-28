#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define TODOOK 0
int utn_getEntero(int* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError);
int utn_getDecimal(float* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError);
int utn_getCadena(char* cadenaBuffer, int len, int intentos, char* mensaje, char* mensajeError);
void limpiarNumero(char* cadena);
#endif // UTN_H_INCLUDED
