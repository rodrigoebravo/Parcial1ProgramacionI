#include "Cliente.h"
#include "Venta.h"
#include "utn.h"

static int cli_Alta(Cliente* pEntidad, int len, int index);
static int cli_BajaPorPosicion(Cliente* cli, int lenCli, int index, Venta* ven, int lenVen);
static int cli_getIdVacio(Cliente* pEntidad, int len);
static int generarID(void);


int cli_inicializarListaClientes(Cliente* pEntidad, int len)
{
    int i;
    int retorno=ERROR;
    if(pEntidad !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            pEntidad[i].isEmpty=TRUE;
        }
        retorno=TODOOK;
    }
    return retorno;
}

int cli_darAltaCliente(Cliente* pEntidad, int len)
{
    int id;
    int retorno=ERROR;
    int indexRetorno;

    id=cli_getIdVacio(pEntidad, len);
    if(id!=ERROR)
    {
        cli_Alta(pEntidad, len, id);
    }

    if(cli_obtenerPosicionPorID(pEntidad, len, id, &indexRetorno)==TODOOK)
    {
        retorno=indexRetorno;
    }
    return retorno;
}

int cli_modificarClientePorID(Cliente* pEntidad, int len)
{
    int retorno=ERROR;
    int idModificar;
    int indexModificar;
    if(utn_getEntero(&idModificar, 3, len, -1, "Ingrese ID a modificar:\n", "ID erroneo\n")==TODOOK &&
       cli_obtenerPosicionPorID(pEntidad, len, idModificar, &indexModificar)==TODOOK &&
       cli_posicionEstaVacia(pEntidad, len, indexModificar)==FALSE &&
       cli_Alta(pEntidad, len, indexModificar)==TODOOK)
        {
            retorno=TODOOK;
        }
    return retorno;
}


int cli_bajaClientePorID(Cliente* cli, int lenCli, Venta* ven, int lenVen)
{
    int retorno=ERROR;
    int idBaja;
    int indexBaja;

    if(cli!=NULL && lenCli>0 && ven!=NULL
       && utn_getEntero(&idBaja, 3, lenCli, -1, "Ingrese ID del cliente a dar de baja\n", "Error al dar de baja el ID\n")==TODOOK
       && cli_obtenerPosicionPorID(cli, lenCli, idBaja, &indexBaja)==TODOOK
       && cli_posicionEstaVacia(cli, lenCli, indexBaja)==FALSE)
       {
           retorno=cli_BajaPorPosicion(cli, lenCli, indexBaja, ven, lenVen);
       }

    return retorno;
}

static int cli_Alta(Cliente* pEntidad, int len, int index)
{
    int retorno=ERROR;
    Cliente auxCli;

    if(pEntidad!=NULL && len > 0 && index>=0 && index<len &&
            utn_getCadena(auxCli.nombre, 20, 3, "Ingrese nombre\n","Nombre incorrecto\n")==TODOOK &&
            utn_getCadena(auxCli.apellido, 20, 3, "Ingrese apellido\n", "Apellido incorrecto\n")==TODOOK &&
            utn_getCadena(auxCli.cuit, 20, 3, "Ingrese cuit\n", "Cuit incorrecto\n")==TODOOK)
    {
        auxCli.id=generarID();
        auxCli.isEmpty=FALSE;
        pEntidad[index]=auxCli;
        retorno=TODOOK;
    }
    return retorno;
}

static int cli_BajaPorPosicion(Cliente* cli, int lenCli, int index, Venta* ven, int lenVen)
{
    int retorno=ERROR;
    int i;
    if(cli!=NULL && ven!=NULL && lenVen>0 && lenCli>0 && index>=0)
    {
        cli[index].isEmpty=TRUE;

        for(i=0; i<lenVen; i++)
        {
            if(ven[i].idCliente==cli[index].id && ven[i].isEmpty==FALSE)
            {
                ven[i].isEmpty=TRUE;
            }
        }
        retorno=TODOOK;
    }
    return retorno;
}

int cli_posicionEstaVacia(Cliente* pEntidad, int len, int index)
{
    int retorno=TRUE;

    if(pEntidad!=NULL && index>=0 && len>0 && index<len)
    {
        retorno=pEntidad[index].isEmpty;
    }
    return retorno;
}

static int cli_getIdVacio(Cliente* pEntidad, int len)
{
    int i=ERROR;
    int retorno;
    if(pEntidad !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(pEntidad[i].isEmpty==TRUE)
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

int cli_obtenerPosicionPorID(Cliente* pEntidad, int len, int id, int* indexRetorno)
{
    int i;
    int retorno=ERROR;
    for(i=0; i<len; i++)
    {
        if(pEntidad[i].id==id && !pEntidad[i].isEmpty)
        {
            *indexRetorno=i;
            retorno=TODOOK;
            break;
        }
    }
    return retorno;
}

