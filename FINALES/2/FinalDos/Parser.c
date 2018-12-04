#include "parser.h"

/** \brief Guarda en la lista el contenido del archivo como ventas
 * \param fileName *char
 * \param LinkedList* listaVentas
 * \return int
 */
 /*
int parser_GuardarServiceDesdeArchivo(FILE* pFile , LinkedList* listaService)
{
	char idAux[1024];
	char nameAux[1024];
    char emailAux[1024];
    int retorno=ERROR;
    int flagOnce=TRUE;
    Service* service;

    if(pFile != NULL && listaService!=NULL)
    {
        retorno=TODOOK;
        printf("Procesando archivo...\n");
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce=FALSE;
                fscanf(pFile, "%[^;];%[^;];%[^\n]\n", idAux, nameAux, emailAux);
            }
            fscanf(pFile, "%[^;];%[^;];%[^\n]\n", idAux, nameAux, emailAux);
            service=Service_newConParametros(idAux, nameAux, emailAux);
            if(service!=NULL)
                ll_add(listaService, service);
        }

        printf("Archivo cargado exitosamente.\nTotal de registros ingresados: %d\n", ll_len(listaService));
    }
    return retorno;
}


int parser_GuardarLogDesdeArchivo(FILE* pFile , LinkedList* listaLog)
{
    char dateAux[1024];
    char timeAux[1024];
    char serviceIdAux[1024];
    char gravedadAux[1024];
    char msgAux[1024];
    int retorno=ERROR;
    int flagOnce=TRUE;
    LogEntry* pLog;

    if(pFile != NULL && listaLog!=NULL)
    {
        retorno=TODOOK;
        printf("Procesando archivo...\n");
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce=FALSE;
                fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", dateAux, timeAux, serviceIdAux, gravedadAux, msgAux);
            }
            fscanf(pFile, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", dateAux, timeAux, serviceIdAux, gravedadAux, msgAux);
            pLog=LogEntry_newConParametros(dateAux, timeAux, serviceIdAux, gravedadAux, msgAux);
            if(pLog!=NULL)
                ll_add(listaLog, pLog);
        }

        printf("Archivo cargado exitosamente.\nTotal de registros ingresados: %d\n", ll_len(listaLog));
    }
    return retorno;
}
*/
