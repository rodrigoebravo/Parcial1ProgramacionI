#include "contrataciones.h"

static int con_getIdVacio(Contratacion* con, int len);
static int generarID(void);
void con_bajaPorCuitId(Contratacion* con, int lenCon, int idBaja, char* cuitAux);

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

int con_Alta(Contratacion* con, int lenCon, Pantalla* pan, int lenPan, int indexPan)
{
    int idAux;
    char videoAux[20];
    float precioAux;
    int diasAux;
    char cuitAux[20];

    int retorno=ERROR;

    if(con!=NULL && pan!=NULL && lenPan > 0 && lenCon > 0 && indexPan>=0)
    {
        if(pan[indexPan].isEmpty==FALSE)
        {
            if(utn_getCadena(videoAux, 20, 3, "Ingrese video: \n", "Error al ingresar video!\n")==TODOOK)
            {
                if(utn_getDecimal(&precioAux, 3, 10000, -1, "Ingrese precio:\n", "Error al ingresar precio!\n")==TODOOK)
                {
                    if(utn_getEntero(&diasAux, 3, 32, 0, "Ingrese dias contratados:\n", "Error al ingresar dias contratados\n")==TODOOK)
                    {
                        if(utn_getCadena(cuitAux, 20, 3, "Ingrese CUIT\n", "error al ingresar CUIT\n")==TODOOK)
                        {
                            idAux=con_getIdVacio(con, lenCon);
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
    }
    return retorno;
}

int con_ModificarPorCuit(Contratacion* con, int lenCon, Pantalla* pan, int lenPan)
{
    char cuitAux[20];
    int retorno=ERROR;
    int idModificar;
    int cantidadDiasModificado;
    int i;

    if(utn_getCadena(cuitAux, 20, 3, "Ingrese cuit a modificar\n", "Error al ingresar cuit\n")==TODOOK)
    {
        if(con_printPantallaPorCuit(con, lenCon, cuitAux, 20, pan, lenPan)==TODOOK)
        {
            if(utn_getEntero(&idModificar, 3, lenPan, -1, "Ingrese id a modificar\n", "error al ingresar id a modificar")==TODOOK)
            {

                if(utn_getEntero(&cantidadDiasModificado, 3, 32, -1, "Ingrese cantidad de días:\n", "Error al ingresar cantidad de dias\n")==TODOOK)
                {

                    for(i=0; i<lenCon; i++)
                    {
                        if(con[i].idPantalla==idModificar && strcmp(con[i].cuit, cuitAux)==TODOOK && con[i].isEmpty==FALSE)
                        {
                            con[i].dias=cantidadDiasModificado;
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

int con_printPantallaPorCuit(Contratacion* con, int lenCon, char* cuit, int lenCuit, Pantalla* pan, int lenPan)
{
    int retorno=ERROR;
    int i;
    int j;
    if(con!=NULL && lenCon>0 && lenCuit>0)
    {
        if(esCuit(cuit, lenCuit)==TRUE)
        {
            for(i=0; i<lenCon; i++)
            {
                if(strcmp(con[i].cuit, cuit)==TODOOK && con[i].isEmpty==FALSE)
                {
                    for(j=0; j<lenPan; j++)
                    {
                        if(con[i].idPantalla==pan[j].id && pan[j].isEmpty==FALSE)
                        {
                            printf("id: \t%d\nTipo:\t%d\nNombre:\t%s\nDireccion:\t%s\nPrecio:\t%f\nEsta vacio?\t%d\n",
                                   pan[j].id,
                                   pan[j].tipo,
                                   pan[j].nombre,
                                   pan[j].direccion,
                                   pan[j].precio,
                                   pan[j].isEmpty);
                            printf("******************\n");
                        }
                    }
                }
            }
            retorno=TODOOK;
        }
    }
    return retorno;
}

int con_alta_forzada(Contratacion* con, int len, char* video, float precio, int dias, int idPan, char* cuit)
{
    int index=con_getIdVacio(con, len);
    if(index>=0)
    {
        con[index].dias=dias;
        con[index].id=generarID();
        con[index].idPantalla=idPan;
        con[index].isEmpty=FALSE;
        con[index].precio=precio;
        strncpy(con[index].video, video, strlen(video));

        strncpy(con[index].cuit, cuit, strlen(cuit));
    }
    return index;
}

int con_cancelar(Contratacion* con, int lenCon, Pantalla* pan, int lenPan)
{
    char cuitAux[20];
    int idBaja;
    int retorno=ERROR;
    if(utn_getCadena(cuitAux, 20, 3, "Ingrese cuit a cancelar\n", "Error al ingresar cuit\n")==TODOOK)
    {
        if(con_printPantallaPorCuit(con, lenCon, cuitAux, 20, pan, lenPan)==TODOOK)
        {
            if(utn_getEntero(&idBaja, 3, lenPan, -1, "Ingrese ID a cancelar\n", "Error al ingresar ID\n")==TODOOK)
            {
                con_bajaPorCuitId(con, lenCon, idBaja, cuitAux);

                retorno=TODOOK;

            }
        }
    }
    return retorno;
}

void con_bajaPorCuitId(Contratacion* con, int lenCon, int idBaja, char* cuitAux)
{
    int i;
    for(i=0; i<lenCon; i++)
    {
        if(con[i].idPantalla==idBaja && strcmp(con[i].cuit, cuitAux)==TODOOK)
        {
            printf("asdjkvwkdnvcdssssssssssssssssssssssssssssssssss i:%d\n", i);
            con[i].isEmpty=TRUE;
        }
    }
}


static int generarID(void)
{
    static int id=-1;
    id++;
    return id;
}
