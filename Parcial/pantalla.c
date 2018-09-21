
#include "pantalla.h"


static int generarID(void);
static int pan_getIdVacio(Pantalla* pan, int len);
static int pan_obtenerPosicionPorID(Pantalla* pantallas, int len, int id, int* indexRetorno);
int pan_inicializarLista(Pantalla* pan, int len)
{
    int i;
    int retorno=-1;
    if(pan !=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            pan[i].isEmpty=VERDADERO;
        }
        retorno=0;
    }
    return retorno;
}

static int pan_getIdVacio(Pantalla* pan, int len)
{
    int i=0;
    int retorno=-1;
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

static int generarID(void)
{
    static int id=-1;
    id++;
    return id;
}

int pan_Alta(Pantalla* pan, int len, int index)
{
    int retorno=-1;
    int idAux;
    int tipoAux;
    char nombreAux[100];
    char direccionAux[100];
    float precioAux;

    char pedidoTipo[]="Ingrese tipo de pantalla( 0-LED 1-LCD): \n";
    if(pan!=NULL && len > 0 && index>0 && index<len)
    {
        if(utn_getEntero(tipoAux, 3, 1, 0, pedidoTipo, "Error al ingresar tipo\n")==0)
        {
            if(utn_getCadena(nombreAux, 3,100,0,"Ingrese nombre:\n","Error en nombre!\n")==0)
            {
                if(utn_getCadena(direccionAux, 3, 100,0,"Ingrese direccion\n","Error al ingresar\n" )==0)
                {
                    if(utn_getDecimal(&precioAux,3,3000,0,"Ingrese precio: \n", "Error al ingresar precio\n")==0)
                    {
                        pan[index].tipo=tipoAux;
                        strncpy(pan[index].nombre,nombreAux,sizeof(nombreAux));
                        strncpy(pan[index].direccion,direccionAux,sizeof(direccionAux));
                        pan[index].precio=precioAux;
                        pan[index].isEmpty=FALSO;
                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}


static int pan_obtenerPosicionPorID(Pantalla* pantallas, int len, int id, int* indexRetorno)
{
    int i;
    int retorno=-1;
    for(i=0;i<len;i++)
    {
        if(pantallas[i].id==id)
        {
            indexRetorno=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
