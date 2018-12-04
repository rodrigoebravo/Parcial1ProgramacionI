#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "Service.h"
#include "LogEntry.h"
#include "LinkedList.h"
#include "utn.h"
int parser_GuardarServiceDesdeArchivo(FILE* pFile , LinkedList* listaService);
int parser_GuardarLogDesdeArchivo(FILE* pFile , LinkedList* listaLog);
#endif // PARSER_H_INCLUDED
