#include "Controller.h"
int escribirLog(char* pArchivo, LogEntry* pLog, Service* pService);
int Controller_cargarLog(char* pNombreArchivo, LinkedList* listaLog)
{
    int retorno=ERROR;
    FILE* pArchivo=fopen(pNombreArchivo, "r");

    if(pArchivo!=NULL)
        retorno=parser_GuardarLogDesdeArchivo(pArchivo, listaLog);
    fclose(pArchivo);

    return retorno;
}
int Controller_cargarService(char* pNombreArchivo, LinkedList* listaService)
{
    int retorno=ERROR;
    FILE* pArchivo=fopen(pNombreArchivo, "r");

    if(pArchivo!=NULL)
        retorno=parser_GuardarServiceDesdeArchivo(pArchivo, listaService);
    fclose(pArchivo);

    return retorno;
}
int Controller_leerLog(LinkedList* listaLog, LinkedList* listaService)
{
    int retorno=ERROR;
    Controller_cargarLog("log.txt", listaLog);
    Controller_cargarService("service.txt", listaService);
    //ll_Mapper(listaLog, LogEntry_printLog);
    //ll_Mapper(listaService, Service_printService);
    return retorno;
}
int Controller_procesarInformacion(LinkedList* listaLog, LinkedList*  listaService)
{
    int retorno=ERROR;
    retorno=ll_MapperConValor(listaLog, procesarLog, listaService);
    return retorno;
}
int Controller_mostrarEstadisticas(LinkedList* listaLog, LinkedList*  listaService)
{
    int retorno=ERROR;
    int contadorPorGravedadMenor3=ll_count(listaLog, contarPorGravedadMenor3);
    int contadorPorGravedad3=ll_count(listaLog, contarPorGravedad3);
    int contadorPorGravedadEntre4y7=ll_count(listaLog, contarPorGravedadEntre4y7);
    int contadorPorGravedadMayores7=ll_count(listaLog, contarPorGravedadMayores7);
    printf("Menores a 3: %d\nigual a 3: %d\nentre 4 y 7 (inclusive): %d \nMayores a 7%d\n",contadorPorGravedadMenor3, contadorPorGravedad3, contadorPorGravedadEntre4y7, contadorPorGravedadMayores7);
    return retorno;
}
int contarPorGravedadMenor3(LogEntry* pLog)
{
    int gravedadAux;
    if(pLog!=NULL && LogEntry_getGravedad(pLog, &gravedadAux)==TODOOK && gravedadAux<3)
    {
        return 1;
    }
    return 0;
}

int contarPorGravedad3(LogEntry* pLog)
{
    int gravedadAux;
    if(pLog!=NULL && LogEntry_getGravedad(pLog, &gravedadAux)==TODOOK && gravedadAux==3)
    {
        return 1;
    }
    return 0;
}

int contarPorGravedadEntre4y7(LogEntry* pLog)
{
    int gravedadAux;
    if(pLog!=NULL && LogEntry_getGravedad(pLog, &gravedadAux)==TODOOK && gravedadAux<8 && gravedadAux>3)
    {
        return 1;
    }
    return 0;
}

int contarPorGravedadMayores7(LogEntry* pLog)
{
    int gravedadAux;
    if(pLog!=NULL && LogEntry_getGravedad(pLog, &gravedadAux)==TODOOK && gravedadAux>7)
    {
        return 1;
    }
    return 0;
}







int procesarLog(LogEntry* pLog, LinkedList* listaService)
{
    int retorno=ERROR;
    int gravedadAux;
    int idServicioAux=0;
    Service* pServiceAux;
    //char emailServiceAux[100];

    if(pLog!=NULL && LogEntry_getGravedad(pLog, &gravedadAux)==TODOOK && LogEntry_getServiceId(pLog, &idServicioAux)==TODOOK)
    {
        retorno=TODOOK;
        pServiceAux=ll_BuscarValor(listaService, criterioPorID, &idServicioAux);
        if(gravedadAux<8 && gravedadAux>3 && pServiceAux!=NULL)
        {
             printLog(pLog, pServiceAux);
        }
        else if(gravedadAux==3 && idServicioAux!=45 && pServiceAux!=NULL)
        {
            escribirLog("warnings.txt", pLog, pServiceAux);
        }
        else if(gravedadAux>7)
        {
            escribirLog("errors.txt", pLog, pServiceAux);
        }
    }
    return retorno;
}

int criterioPorID(Service* pService, void* id)
{
    int idEncontrado=0;
    int pId=*((int*)id);
    int retorno=FALSE;
    if(pService!=NULL && id!=NULL && Service_getId(pService, &idEncontrado)==TODOOK && idEncontrado==pId)
        retorno=TRUE;
    return retorno;
}
void printLog(LogEntry* pLog, Service* pService)
{
    char dateAux[11];
    char timeAux[6];
    char msgAux[65];
    char nameAux[33];
    char emailAux[65];
    int gravedadAux;
    int retorno=ERROR;
    if(pLog!=NULL &&
       pService!=NULL &&
       Service_getName(pService, nameAux)==TODOOK &&
       Service_getEmail(pService, emailAux)==TODOOK &&
       LogEntry_getDate(pLog, dateAux)==TODOOK &&
       LogEntry_getTime(pLog, timeAux)==TODOOK &&
       LogEntry_getMsg(pLog, msgAux)==TODOOK &&
       LogEntry_getGravedad(pLog, &gravedadAux)==TODOOK)
        printf("%s;%s;%s;%s;%d\n", dateAux, timeAux, nameAux, msgAux, gravedadAux);
}
int escribirLog(char* pArchivo, LogEntry* pLog, Service* pService)
{
    char dateAux[11];
    char timeAux[6];
    char msgAux[65];
    char nameAux[33];
    char emailAux[65];
    int retorno=ERROR;
    FILE* pFile;
    pFile=fopen(pArchivo, "w");
    if(pLog!=NULL &&
       pService!=NULL &&
       pFile!=NULL &&
       Service_getName(pService, nameAux)==TODOOK &&
       Service_getEmail(pService, emailAux)==TODOOK &&
       LogEntry_getDate(pLog, dateAux)==TODOOK &&
       LogEntry_getTime(pLog, timeAux)==TODOOK &&
       LogEntry_getMsg(pLog, msgAux)==TODOOK)
       {
           printf("aaaaaaaaaaaaaa");
           fprintf(pFile, "%s;%s;%s;%s;%s\n", dateAux, timeAux, nameAux, msgAux, emailAux);
       }


    retorno=TODOOK;

    return retorno;
}
