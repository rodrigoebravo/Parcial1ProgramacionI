#include "pantalla.h"

static int generarID(void);
static int pan_getIdVacio(Pantalla* pan, int len);
static int pan_obtenerPosicionPorID(Pantalla* pantallas, int len, int id, int* indexRetorno);

int pan_inicializarLista(Pantalla* pan, int len)
{
    int i;
    int retorno=ERROR;
    if(pan !=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            pan[i].isEmpty=VERDADERO;
        }
        retorno=TODOOK;
    }
    return retorno;
}

int pan_Alta(Pantalla* pan, int len, int index)
{
    int retorno=-1;
    int tipoAux;
    char nombreAux[100];
    char direccionAux[100];
    float precioAux;
    char pedidoTipo[]="Ingrese tipo de pantalla( 0-LED 1-LCD): \n";

    if(pan!=NULL && len > 0 && index>=0 && index<len)
    {

        if(utn_getEntero(&tipoAux, 3, 2, -1, pedidoTipo, "Error al ingresar tipo\n")==TODOOK)
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
                        pan[index].isEmpty=FALSO;
                        retorno=0;
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

    pan_inicializarLista(pantallas,len);
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
    for(i=0;i<len;i++)
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
    int retorno=ERROR;
    if(pan !=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(pan[i].isEmpty==VERDADERO)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
