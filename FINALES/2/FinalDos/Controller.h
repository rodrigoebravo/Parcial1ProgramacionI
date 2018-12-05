#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"
#include "utn.h"
#include "parser.h"
#include "Usuario.h"
#include "Publicacion.h"
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
int Controller_cargarUsuarios(char* nombreArchivo, LinkedList* pLista);
int Controller_cargarPublicaciones(char* nombreArchivo, LinkedList* pLista);
int Controller_procesarListas(LinkedList* listaUsuarios, LinkedList*  listaPublicaciones);

void* buscarUsuario(Publicacion* pEntidad, LinkedList* listaUsuarios);
int criterioPorID(Usuario* pEntidad, void* id);
int criterioOrdenamiento(void* pEntidadA, void* pEntidadB);
#endif // CONTROLLER_H_INCLUDED
