#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdio_ext.h>
#define VERDADERO 1
#define FALSO 0
#define ERROR -1
#define TODOOK 0
int utn_getEntero(int* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError);
int utn_getDecimal(char* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError);
int utn_getCadena(char* cadenaBuffer, int len, int intentos, char* mensaje, char* mensajeError);
int utn_contieneNumero(char* cadena);
void utn_toUpperCadena(char* cadena, int len);
#endif // UTN_H_INCLUDED
