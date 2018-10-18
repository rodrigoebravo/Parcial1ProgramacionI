#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR -1
#define TODOOK 0
#define TRUE 1
#define FALSE 0

typedef struct
{
    int gravedad;
    char mensaje[65];
    int serviceId;
}Service;

Service* service_new(void);
Service* service_newParametros(int gravedad, char* mensaje);
void service_delete(Service* this);

int service_setGravedad(Service* this, int gravedad);
int service_getGravedad(Service* this, int* gravedad);

int service_setMensaje(Service* this, char* mensaje);
int service_getMensaje(Service* this, char* mensaje);


void service_print(Service* this);
int service_compareMensaje(Service* thisA, Service* thisB);

#endif // SERVICE_H_INCLUDED
