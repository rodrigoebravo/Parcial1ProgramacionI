#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR -1
#define TODOOK 0
#define TRUE 1
#define FALSE 0
typedef struct
{
    int id;
    char name[33];
    char apellido[65];
}Cliente;


Cliente* cliente_new(void);
Cliente* cliente_newParametros(char* name, char* apellido);
void cliente_delete(Cliente* this);
int cliente_setName(Cliente* this, char* name);
int cliente_getName(Cliente* this, char* name);
int cliente_compareName(Cliente* thisA, Cliente* thisB);
int cliente_setApellido(Cliente* this, char* apellido);
int cliente_getApellido(Cliente* this, char* apellido);
int cliente_compareApellido(Cliente* thisA, Cliente* thisB);
int cliente_buscarLugarVacio(Cliente* pBuffer[], int len);
void cliente_print(Cliente* this);

#endif // CLIENTE_H_INCLUDED
