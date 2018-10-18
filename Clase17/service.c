
#include "service.h"

/*
    int gravedad, char* mensaje, int serviceId;
*/
static int isValidMensaje(char* mensaje);
static int isValidGravedad(int gravedad);

Service* service_new(void)
{
    return (Service*) malloc (sizeof(Service));
}

Service* service_newParametros(int gravedad, char* mensaje)
{
    Service* this=NULL;
    this=service_new();
    if(this==NULL
    || service_setGravedad(this, gravedad)
    || service_setMensaje(this, mensaje))
    {
        service_delete(this);
        this=NULL;
    }
    return this;
}

void service_delete(Service* this)
{
    free(this);
}

int service_setGravedad(Service* this, int gravedad)
{
    int retorno=ERROR;
    if(this!=NULL && isValidGravedad(gravedad))
    {
        this->gravedad=gravedad;
        retorno=TODOOK;
    }
    return retorno;
}

int service_getGravedad(Service* this, int* gravedad)
{
    int retorno=ERROR;
    if(this!=NULL && gravedad!=NULL)
    {
        *gravedad=this->gravedad;
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidGravedad(int gravedad)
{
    return TRUE;
}


int service_setMensaje(Service* this, char* mensaje)
{
    int retorno=ERROR;
    if(this!=NULL && isValidMensaje(mensaje))
    {
        strcpy(this->mensaje,mensaje);
        retorno=TODOOK;
    }
    return retorno;
}

int service_getMensaje(Service* this, char* mensaje)
{
    int retorno=ERROR;
    if(this!=NULL && mensaje!=NULL)
    {
        strcpy(mensaje,this->mensaje);
        retorno=TODOOK;
    }
    return retorno;
}

static int isValidMensaje(char* mensaje)
{
    return TRUE;
}

int service_compareMensaje(Service* thisA, Service* thisB)
{
    return strcmp(thisA->mensaje, thisB->mensaje);
}

void service_print(Service* this)
{
    printf("Gravedad: %d Mensaje: %s ID: %d\n",
        this->gravedad,
        this->mensaje,
        this->serviceId
          );
}
