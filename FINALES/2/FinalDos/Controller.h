#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"
#include "utn.h"
#include "parser.h"
#include "Usuario.h"
#include "Publicacion.h"
#include "Feed.h"
//int Controller_cargarLog(char* pNombreArchivo, LinkedList* listaLog);
//int Controller_cargarService(char* pNombreArchivo, LinkedList* listaService);
//int Controller_leerLog(LinkedList* listaLog, LinkedList* listaService);
//int Controller_procesarInformacion(LinkedList* listaLog, LinkedList*  listaService);
//int Controller_mostrarEstadisticas(LinkedList* listaLog, LinkedList*  listaService);


//int procesarLog(LogEntry* pLog, LinkedList* listaService);
//Service* Service_buscarPorID(LinkedList* listaService, int id);
//int criterioPorID(Service* pService, void* id);
//void printLog(LogEntry* pLog, Service* pService);
//int contarPorGravedadMenor3(LogEntry* pLog);
//int contarPorGravedad3(LogEntry* pLog);
//int contarPorGravedadEntre4y7(LogEntry* pLog);
//int contarPorGravedadMayores7(LogEntry* pLog);
int Controller_cargarLista(char* nombreArchivo, LinkedList* pLista, int fn(void*, void*));
int Controller_procesarListas(LinkedList* listaUsuarios, LinkedList*  listaPublicaciones, LinkedList* listaFeed);

void* buscarUsuario(Publicacion* pEntidad, LinkedList* listaUsuarios);
int criterioPorID(Usuario* pEntidad, void* id);
int criterioOrdenamientoLikes(void* pEntidadA, void* pEntidadB);
void printFeedEnArchivo(void* pEntidad, FILE* file);
#endif // CONTROLLER_H_INCLUDED
