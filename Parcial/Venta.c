#include "Venta.h"
#include "utn.h"
#include "Cliente.h"
#define ESTADO_ACOBRAR 0
static int generarID(void);
static int ven_Alta(Venta* ven, int lenVen, Cliente* cli, int lenCli, int idCliente);
static int ven_obtenerPosicionVacia(Venta* pEntidad, int len, int* indexVacio);
static int ventasTieneDatos(Venta* pEntidad, int len);
int ven_inicializarListaVentas(Venta* pEntidad, int len)
{
    int i;
    int retorno=ERROR;
    if(ven_validarParametros(pEntidad, len)==TODOOK)
    {
        for(i=0; i<len; i++)
        {
            pEntidad[i].isEmpty=TRUE;
        }
        retorno=TODOOK;
    }
    return retorno;
}

int ven_ventaAfiche(Cliente* cli, int lenCli, Venta* ven, int lenVen)
{
    int retorno=ERROR;
    int idCliente;
    int posicionCliente;

    cli_printClientes(cli, lenCli);
    if(ven_validarParametros(ven, lenVen)==TODOOK
        && cli_validarParametros(cli, lenCli)==TODOOK
        && utn_getEntero(&idCliente, 3, lenCli, -1, "Ingrese ID de cliente\n", "Error al cargar el ID cliente")==TODOOK
        && cli_obtenerPosicionPorID(cli, lenCli, idCliente, &posicionCliente)!=ERROR
        && !cli_posicionEstaVacia(cli, lenCli, posicionCliente)
        )
        {
            retorno=ven_Alta(ven, lenVen, cli, lenCli, idCliente);
        }
        else
        {
            limpiarScreen();
            printf("No es posible dar de alta la venta\n");
        }
    return retorno;
}

static int ven_Alta(Venta* ven, int lenVen, Cliente* cli, int lenCli, int idCliente)
{
    Venta aux;
    int retorno=ERROR;
    int indexVentaVacio;
    if(ven_validarParametros(ven, lenVen)==TODOOK
        && cli_validarParametros(cli, lenCli)==TODOOK
        && idCliente>=0
        && utn_getEntero(&(aux.cantidadAfiches), 3, 10000, 0, "Ingrese cantidad de afiches\n", "cantidad incorrecta\n")==TODOOK
        && utn_getEntero(&(aux.zona), 3, 4, 0, "Ingrese zona: \n\t1- CABA\n\t2- ZONA SUR\n\t3- ZONA OESTE\nIngrese:", "Zona incorrecta\n")==TODOOK
        && utn_getCadena(aux.nombreArchivo, 100, 3, "Ingrese nombre archivo\n", "Nombre erroneo")==TODOOK
        && ven_obtenerPosicionVacia(ven, lenVen, &indexVentaVacio)!=ERROR
       )
    {
        aux.id=generarID();
        aux.idCliente=idCliente;
        aux.estado=ESTADO_ACOBRAR;
        aux.isEmpty=FALSE;
        ven[indexVentaVacio]=aux;
        retorno=TODOOK;
    }

    return retorno;
}
static int ven_obtenerPosicionVacia(Venta* pEntidad, int len, int* indexVacio)
{
    int i;
    int retorno=ERROR;

    if(ven_validarParametros(pEntidad, len)==TODOOK)
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


int ven_ModificarPorID(Venta* ven, int lenVen, Cliente* cli, int lenCli)
{
    int retorno=ERROR;
    int idModificar;
    int cantidadAfichesModificar;
    int zonaModificar;
    int posicionModificar;
    if(ventasTieneDatos(ven, lenVen) && ven_validarParametros(ven, lenVen)==TODOOK && cli_validarParametros(cli, lenCli)==TODOOK)
    {
        ven_printVentas(ven, lenVen);
        if(ven_validarParametros(ven, lenVen)==TODOOK && cli_validarParametros(cli, lenCli)==TODOOK
            && utn_getEntero(&idModificar, 3, lenVen, -1,"Ingrese id a modificar\n", "Error al ingresar cuit\n")==TODOOK
            && utn_getEntero(&cantidadAfichesModificar, 3, 32, -1, "Ingrese cantidad de días:\n", "Error al ingresar cantidad de dias\n")==TODOOK
            && utn_getEntero(&zonaModificar, 3, 4, 0, "Ingrese zona:\n\t1- CABA\n\t2- Zona oeste\n\t3- Zona sur", "Zona incorrecta")==TODOOK
            && ven_obtenerPosicionPorID(ven, lenVen, idModificar, &posicionModificar)!=ERROR)
        {
            ven[posicionModificar].cantidadAfiches=cantidadAfichesModificar;
            ven[posicionModificar].zona=zonaModificar;
            retorno=TODOOK;
        }
        else
        {
            limpiarScreen();
            printf("No es posible modificar ventas\n");
        }
    }
    else
    {
        limpiarScreen();
        printf("No existen ventas\n");
    }

    return retorno;
}

static int generarID(void)
{
    static int id=-1;
    id++;
    return id;
}


int ven_obtenerPosicionPorID(Venta* pEntidad, int len, int id, int* indexRetorno)
{
    int i;
    int retorno=ERROR;
    if(ven_validarParametros(pEntidad, len)==TODOOK && indexRetorno!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(pEntidad[i].id==id && !pEntidad[i].isEmpty)
            {
                *indexRetorno=i;
                retorno=TODOOK;
                break;
            }
        }
    }

    return retorno;
}

int ven_cobrarVenta(Venta* ven, int lenVentas, Cliente* cli, int lenCli)
{
    int retorno=ERROR;


    return retorno;
}

int ven_printVentas(Venta* ventas, int len)
{

    int i;
    char zonaAux[11];
    int retorno=ERROR;
    if(ven_validarParametros(ventas, len)==TODOOK)
    {
        for(i=0;i<len; i++)
        {
            if(!ventas[i].isEmpty)
            {
                if(ventas[i].zona==1)
                    strcpy(zonaAux, "CABA");
                if(ventas[i].zona==2)
                    strcpy(zonaAux, "ZONA SUR");
                if(ventas[i].zona==3)
                    strcpy(zonaAux, "ZONA OESTE");

                printf("ID: %d - Archivo: %s - Cantidad de afiches: %d - Zona: %s - IDCliente: %d",
                ventas[i].id,
                ventas[i].nombreArchivo,
                ventas[i].cantidadAfiches,
                zonaAux,
                ventas[i].idCliente);
            }
        }
        retorno=TODOOK;
    }
    return retorno;
}


int ven_validarParametros(Venta* pEntidad, int lenVen)
{
    int retorno=ERROR;
    if(pEntidad!=NULL && lenVen>0)
    {
        retorno=TODOOK;
    }
    return retorno;
}


static int ventasTieneDatos(Venta* pEntidad, int len)
{
    int retorno=FALSE;
    int i;
    if(ven_validarParametros(pEntidad, len)==TODOOK)
    {
        for(i=0; i<len; i++)
        {
            if(!pEntidad[i].isEmpty)
            {
                retorno=TRUE;
                break;
            }
        }
    }
    return retorno;
}
