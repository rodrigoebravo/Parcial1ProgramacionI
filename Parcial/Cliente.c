#include "Cliente.h"
#include "Venta.h"
#include "utn.h"

static int cli_altaCliente(Cliente* pEntidad, int len, int index);
static int cli_BajaPorPosicion(Cliente* cli, int lenCli, int index, Venta* ven, int lenVen);
static int cli_obtenerPosicionVacia(Cliente* pEntidad, int len, int* indexVacio);
static int generarID(void);
static int validarParametros(Cliente* pEntidad, int lenCli);
static void printCliente(Cliente* pEntidad, int index);
static int cli_modificar(Cliente* pEntidad, int len, int index);


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
    int index;
    int retorno=ERROR;

    if(cli_obtenerPosicionVacia(pEntidad, len, &index)==TODOOK)
    {
        cli_altaCliente(pEntidad, len, index);
        retorno=index;
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
       cli_modificar(pEntidad, len, indexModificar)==TODOOK)
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

static int cli_altaCliente(Cliente* pEntidad, int len, int index)
{
    int retorno=ERROR;
    Cliente auxCli;

    if(validarParametros(pEntidad, len)==TODOOK &&
            index>=0 &&
            index<len &&
            utn_getCadena(auxCli.nombre, 20, 3, "Ingrese nombre\n", "Nombre incorrecto\n")==TODOOK &&
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

static int cli_modificar(Cliente* pEntidad, int len, int index)
{
    int retorno=ERROR;
    int opcionModificar;
    Cliente auxCli;

    if(validarParametros(pEntidad, len)==TODOOK && index>=0 && index<len)
    {
        auxCli=pEntidad[index];

        limpiarScreen();
        if(utn_getEntero(&opcionModificar, 3, 5, 0, "1-Nombre\n2-Apellido\n3-CUIT\nIngrese Opcion a modificar:", "Opcion incorrecta")==TODOOK)
        {
            switch(opcionModificar)
            {
                case 1:
                    utn_getCadena(auxCli.nombre, 20, 3, "Ingrese nombre\n", "Nombre incorrecto\n");
                    break;
                case 2:
                    utn_getCadena(auxCli.apellido, 20, 3, "Ingrese apellido\n", "Apellido incorrecto\n");
                    break;
                case 3:
                    utn_getCadena(auxCli.cuit, 20, 3, "Ingrese cuit\n", "Cuit incorrecto\n");
                    break;
                case 4:
                    break;
            }
            pEntidad[index]=auxCli;
        }
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

static int cli_obtenerPosicionVacia(Cliente* pEntidad, int len, int* indexVacio)
{
    int i;
    int retorno=ERROR;

    if(validarParametros(pEntidad, len)==TODOOK)
    {
        for(i=0; i<len; i++)
        {
            if(pEntidad[i].isEmpty)
            {
                *indexVacio=i;
                retorno=TODOOK;
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

int cli_printClientes(Cliente* pEntidad, int lenCli)
{
    int retorno=ERROR;
    int i;
    if(validarParametros(pEntidad, lenCli)==TODOOK)
    {
        retorno=TODOOK;
        for(i=0; i<lenCli; i++)
        {
            if(!pEntidad[i].isEmpty)
            {
                printCliente(pEntidad, i);
            }
        }
    }
    return retorno;
}

static void printCliente(Cliente* pEntidad, int index)
{
    printf("ID: %d Nombre: %s Apellido: %s Cuit: %s \n", pEntidad[index].id, pEntidad[index].nombre, pEntidad[index].apellido, pEntidad[index].cuit);
}

static int validarParametros(Cliente* pEntidad, int lenCli)
{
    int retorno=ERROR;
    if(pEntidad!=NULL && lenCli>0)
    {
        retorno=TODOOK;
    }
    return retorno;
}