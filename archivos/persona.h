#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char nombre[100];
    char apellido[100];
}Persona;

Persona* persona_new();
void persona_delete();
Persona* persona_newConParametros(char* id,char* nombre,char* apellido);

int persona_setId(Persona* this,int id);
int persona_getId(Persona* this,int* id);

int persona_setNombre(Persona* this,char* nombre);
int persona_getNombre(Persona* this,char* nombre);

int persona_setApellido(Persona* this,char* apellido);
int persona_getApellido(Persona* this,char* apellido);
void persona_print(Persona* this);

#endif // PERSONA_H_INCLUDED
