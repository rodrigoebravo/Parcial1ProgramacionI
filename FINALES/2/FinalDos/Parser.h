#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Publicacion.h"
#include "Usuario.h"
int parser_GuardarUsuariosDesdeArchivo(FILE* pFile , LinkedList* pLista);
int parser_GuardarPublicacionesDesdeArchivo(FILE* pFile , LinkedList* pLista);
int parser_GuardarFeed(FILE* pFile, Usuario* pUsuario, Publicacion* pPublicacion);
#endif // PARSER_H_INCLUDED
