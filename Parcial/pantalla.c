
#include "pantalla.h"


static int generarID(void);
static int pan_getIdVacio(Pantalla* pan, int len);

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

int pan_Alta(char* pan, int len, int index)
{
    int retorno=-1;
    if(utn_getCadena(pan, 3,len,0,"Ingrese nombre:\n","Error en nombre!"))
    {

    }
    return retorno;
}
