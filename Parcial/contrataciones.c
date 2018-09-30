#include "contrataciones.h"
static int con_getIdVacio(Contratacion* con, int len);
static int generarID(void);

int con_inicializarLista(Contratacion* con, int len)
{
    int i;
    int retorno=ERROR;
    if(con !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            con[i].isEmpty=TRUE;
        }
        retorno=TODOOK;
    }
    return retorno;
}

int con_Alta(Contratacion* con, int len, int indexPan)
{
    int idAux;
    char videoAux[20];
    float precioAux;
    int diasAux;
    int idPantallaAux;
    char cuitAux[20];

    int retorno=ERROR;

    if(con!=NULL && len > 0 && indexPan>=0)
    {
        if(utn_getCadena(videoAux, 20, 3, "Ingrese video: \n", "Error al ingresar video!\n")==TODOOK)
        {
            if(utn_getDecimal(&precioAux, 3, 10000, -1, "Ingrese precio:\n", "Error al ingresar precio!\n")==TODOOK)
            {
                if(utn_getEntero(&diasAux, 3, 32, 0, "Ingrese dias contratados:\n", "Error al ingresar dias contratados\n")==TODOOK)
                {
                    if(utn_getCadena(cuitAux, 20, 3, "Ingrese CUIT\n", "error al ingresar CUIT\n")==TODOOK)
                    {
                        idAux=con_getIdVacio(con, len);
                        if(idAux != ERROR)
                        {
                            con[idAux].id=idAux;
                            strncpy(con[idAux].video, videoAux, sizeof(videoAux));
                            con[idAux].precio=precioAux;
                            con[idAux].dias=diasAux;
                            con[idAux].idPantalla=indexPan;
                            con[idAux].isEmpty=FALSE;
                            strncpy(con[idAux].cuit, cuitAux, sizeof(cuitAux));
                            retorno=TODOOK;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

static int con_getIdVacio(Contratacion* con, int len)
{
    int i=0;
    int retorno=ERROR;
    if(con !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(con[i].isEmpty==TRUE)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

static int generarID(void)
{
    static int id=-1;
    id++;
    return id;
}
