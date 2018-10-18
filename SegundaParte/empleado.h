#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    float altura;
    int idEmpleado;
}Empleado;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR -1
#define TODOOK 0
#define TRUE 1
#define FALSE 0
/*
funciones obligatorias, constructor (new), destructor(delete), getters, setters,isValid de cada prop.

*/

Empleado* empleado_new(void);
Empleado* empleado_newParametros(char* nombre, char* apellido, float altura);
void empleado_delete(Empleado* this);
int empleado_setNombre(Empleado* this, char* nombre);
int empleado_getNombre(Empleado* this, char* nombre);
int empleado_setApellido(Empleado* this, char* apellido);
int empleado_getApellido(Empleado* this, char* apellido);
int empleado_setAltura(Empleado* this, float altura);
int empleado_getAltura(Empleado* this, float* altura);
int empleado_compareNombre(Empleado* thisA, Empleado* thisB);
void empleado_print(Empleado* this);
#endif // EMPLEADO_H_INCLUDED
