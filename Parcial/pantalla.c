#include "pantalla.h"
#include "contrataciones.h"

static int generarID(void);
static int pan_getIdVacio(Pantalla* pan, int len);
static int pan_obtenerPosicionPorID(Pantalla* pantallas, int len, int id, int* indexRetorno);

int pan_inicializarLista(Pantalla* pan, int len)
{
    int i;
    int retorno=ERROR;
    if(pan !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            pan[i].isEmpty=TRUE;
        }
        retorno=TODOOK;
    }
    return retorno;
}

int pan_Alta(Pantalla* pan, int len, int index)
{
    int retorno=ERROR;
    int tipoAux;
    char nombreAux[100];
    char direccionAux[100];
    float precioAux;

    if(pan!=NULL && len > 0 && index>=0 && index<len)
    {

        if(utn_getEntero(&tipoAux, 3, 2, -1, "Ingrese tipo de pantalla( 0-LED 1-LCD): \n", "Error al ingresar tipo\n")==TODOOK)
        {
            if(utn_getCadena(nombreAux, 100, 3,"Ingrese nombre:\n","Error en nombre!\n")==TODOOK)
            {
                if(utn_getCadena(direccionAux, 100, 3, "Ingrese direccion\n","Error al ingresar\n" )==TODOOK)
                {
                    if(utn_getDecimal(&precioAux,3,3000,0,"Ingrese precio: \n", "Error al ingresar precio\n")==TODOOK)
                    {
                        pan[index].tipo=tipoAux;
                        strncpy(pan[index].nombre,nombreAux,sizeof(nombreAux));
                        strncpy(pan[index].direccion,direccionAux,sizeof(direccionAux));
                        pan[index].precio=precioAux;
                        pan[index].id=generarID();
                        pan[index].isEmpty=FALSE;
                        retorno=TODOOK;
                    }
                }
            }
        }
    }
    return retorno;
}

int pan_darAltaPantalla(Pantalla* pantallas, int len)
{
    int id=0;
    int retorno=ERROR;
    int indexRetorno;

    id=pan_getIdVacio(pantallas, len);
    pan_Alta(pantallas, len, id);

    if(pan_obtenerPosicionPorID(pantallas, len, id, &indexRetorno)==TODOOK)
    {
        retorno=indexRetorno;
    }
    return retorno;
}

static int generarID(void)
{
    static int id=-1;
    id++;
    return id;
}

static int pan_obtenerPosicionPorID(Pantalla* pantallas, int len, int id, int* indexRetorno)
{
    int i;
    int retorno=ERROR;
    for(i=0; i<len; i++)
    {
        if(pantallas[i].id==id)
        {
            *indexRetorno=i;
            retorno=TODOOK;
            break;
        }
    }
    return retorno;
}

static int pan_getIdVacio(Pantalla* pan, int len)
{
    int i=0;
    int retorno;
    if(pan !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(pan[i].isEmpty==TRUE)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int pan_modificarPantallaPorID(Pantalla* pantalla, int len)
{
    int retorno=ERROR;
    int idModificar;
    int indexModificar;
    if(utn_getEntero(&idModificar, 3, len, -1, "Ingrese ID a modificar:\n", "ID erroneo\n")==TODOOK)
    {

        if(pan_obtenerPosicionPorID(pantalla, len, idModificar, &indexModificar)==TODOOK)
        {

            if(pan_pantallaVacia(pantalla, len, indexModificar)==FALSE)
            {

                if(pan_Alta(pantalla, len, indexModificar)==TODOOK)
                {
                    retorno=TODOOK;
                }
            }
        }
    }
    return retorno;
}

int pan_pantallaVacia(Pantalla* pantalla, int len, int index)
{
    int retorno=TRUE;

    if(pantalla!=NULL && index>=0 && len>0 && index<len)
    {
        retorno=pantalla[index].isEmpty;
    }
    return retorno;
}

int pan_alta_forzada(Pantalla* pantallas, int len, char* nombre, int tipo, char* direccion, float precio)
{
    int index=pan_getIdVacio(pantallas, len);
    if(index>=0)
    {
        pantallas[index].tipo=tipo;
        strncpy(pantallas[index].nombre,nombre,strlen(nombre));
        strncpy(pantallas[index].direccion,direccion,strlen(direccion));
        pantallas[index].precio=precio;
        pantallas[index].id=generarID();
        pantallas[index].isEmpty=FALSE;
    }
    return index;
}

int pan_bajaPantallaPorID(Pantalla* pan, int lenPan, Contratacion* con, int lenCon)
{
    int retorno=ERROR;
    int idBaja;
    int indexBaja;

    if(pan!=NULL && lenPan>0)
    {
        if(utn_getEntero(&idBaja, 3, lenPan, -1, "Ingrese ID a dar de baja\n", "Error al dar de baja el ID\n")==TODOOK)
        {
            if(pan_obtenerPosicionPorID(pan, lenPan, idBaja, &indexBaja)==TODOOK)
            {
                if(pan_pantallaVacia(pan, lenPan, indexBaja)==FALSE)
                {
                    retorno=pan_BajaPorPosicion(pan, lenPan, indexBaja, con, lenCon);
                }
            }
        }
    }

    return retorno;
}

int pan_BajaPorPosicion(Pantalla* pan, int lenPan, int index, Contratacion* con, int lenCon)
{
    int retorno=ERROR;
    int i;
    if(pan!=NULL && con!=NULL && lenCon>0 && lenPan>0 && index>=0)
    {
        pan[index].isEmpty=TRUE;
        for(i=0; i<lenCon; i++)
        {
            if(con[i].idPantalla==pan[index].id && con[i].isEmpty==FALSE)
            {
                con[i].isEmpty=TRUE;
            }
        }
        retorno=TODOOK;
    }
    return retorno;
}

int contratarPantallasPorID(Pantalla* pan, int lenPan, Contratacion* con, int lenCon)
{
    int retorno=ERROR;
    int idContratar;
    if(pan!=NULL && con!=NULL && lenPan>0 && lenCon>0)
    {
        if(utn_getEntero(&idContratar, 3, lenPan, -1, "Ingrese ID de pantalla a contratar\n", "Error al cargar el ID de pantalla a contratar")==TODOOK)
        {
            if(pan_pantallaVacia(pan, lenPan, idContratar)==FALSE)
            {
                retorno=con_Alta(con, lenCon, idContratar);
            }
        }
    }
    return retorno;
}
