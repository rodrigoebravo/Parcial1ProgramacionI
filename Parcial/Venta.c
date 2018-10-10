#include "Venta.h"
#include "utn.h"
#include "Cliente.h"
#define ESTADO_ACOBRAR 0
static int generarID(void);
static int ven_Alta(Venta* ven, int lenVen, Cliente* cli, int lenCli, int idCliente);
static int ven_obtenerPosicionVacia(Venta* pEntidad, int len, int* indexVacio);
static int ventasTieneDatos(Venta* pEntidad, int len);
static void ven_altaForzada(Venta* pEntidad, int cantidadAfiches, int idCliente, char* nombreArchivo, int zona, int i);
static void ven_forzarAltas(Venta* pEntidad, int len);
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
        ven_forzarAltas(pEntidad, len);
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
        && utn_getCadena(aux.nombreArchivo, 100, 3, "Ingrese nombre archivo\n", "Nombre erroneo\n")==TODOOK
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
            && utn_getEntero(&idModificar, 3, lenVen, -1,"Ingrese id a modificar\n", "Error al ingresar id\n")==TODOOK
            && utn_getEntero(&cantidadAfichesModificar, 3, 10000, -1, "Ingrese cantidad de afiches:\n", "Error al ingresar cantidad de dias\n")==TODOOK
            && utn_getEntero(&zonaModificar, 3, 4, 0, "Ingrese zona:\n\t1- CABA\n\t2- Zona sur\n\t3- Zona oeste\nIngrese: ", "Zona incorrecta")==TODOOK
            && ven_obtenerPosicionPorID(ven, lenVen, idModificar, &posicionModificar)==TODOOK)
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
        limpiarScreen();
        for(i=0;i<len; i++)
        {
            if(!ventas[i].isEmpty)
            {
                switch(ventas[i].zona)
                {
                    case 1:
                        strcpy(zonaAux, "CABA");
                        break;
                    case 2:
                        strcpy(zonaAux, "ZONA SUR");
                        break;
                    case 3:
                        strcpy(zonaAux, "ZONA OESTE");
                        break;
                }

                printf("ID: %d - Archivo: %s - Cantidad de afiches: %d - Zona: %s - IDCliente: %d\n",
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



static void ven_forzarAltas(Venta* pEntidad, int len)
{
	ven_altaForzada(pEntidad, 1, 0, "asd.av", 1, 0);
    ven_altaForzada(pEntidad, 10, 1, "ertryrsd.av", 1, 1);
    ven_altaForzada(pEntidad, 1, 2, "ggga3sd.av", 1, 2);
    ven_altaForzada(pEntidad, 18, 3, "123dasd.av", 2, 3);
    ven_altaForzada(pEntidad, 107, 3, "098asd.av", 3, 4);
    ven_altaForzada(pEntidad, 1066, 4, "1345asd.av", 1, 5);
    ven_altaForzada(pEntidad, 1048, 5, "x2asd.av", 2, 6);
    ven_altaForzada(pEntidad, 10, 2, "dxasd.av", 1, 7);
    ven_altaForzada(pEntidad, 200, 9, "sawasd.av", 3, 8);
    ven_altaForzada(pEntidad, 100, 11, "vsasd.av", 3, 9);
    ven_altaForzada(pEntidad, 10, 19, "vvasd.av", 3, 10);
    ven_altaForzada(pEntidad, 300, 22, "gbasd.av", 3, 11);
    ven_altaForzada(pEntidad, 400, 29, "poiasd.av", 2, 12);
    ven_altaForzada(pEntidad, 1, 30, "mmasd.av", 1, 13);
    ven_altaForzada(pEntidad, 2, 26, "mmasd.aCv", 2, 14);
    ven_altaForzada(pEntidad, 77, 15, "dsvqRWFVRasd.av", 3, 15);
    ven_altaForzada(pEntidad, 66, 14, "ccasd.av", 2, 16);
    ven_altaForzada(pEntidad, 66, 13, "ccasd.av", 1, 17);
    ven_altaForzada(pEntidad, 54, 18, "cdsasd.av", 2, 18);
    ven_altaForzada(pEntidad, 1, 19, "cdsasd.av", 1, 19);
    ven_altaForzada(pEntidad, 5, 10, "dcasd.av", 2, 20);
    ven_altaForzada(pEntidad, 8, 8, "fbasd.av", 3, 21);
    ven_altaForzada(pEntidad, 10, 1, "ascasd.av", 2, 22);
    ven_altaForzada(pEntidad, 24, 1, "fdsasd.av", 1, 23);
    ven_altaForzada(pEntidad, 1, 29, "fasd.av", 2, 24);
    ven_altaForzada(pEntidad, 14, 25, "7asd.av", 2, 25);
    ven_altaForzada(pEntidad, 145, 11, "rasd.av", 2, 26);
    ven_altaForzada(pEntidad, 1, 12, "4asd.av", 3, 27);
    ven_altaForzada(pEntidad, 1, 12, "3asd.av", 2, 28);
    ven_altaForzada(pEntidad, 3, 12, "2asd.av", 1, 29);
    ven_altaForzada(pEntidad, 5, 14, "1asd.av", 2, 30);
}

static void ven_altaForzada(Venta* pEntidad, int cantidadAfiches, int idCliente, char* nombreArchivo, int zona, int i)
{
    pEntidad[i].id=generarID();
    pEntidad[i].cantidadAfiches=cantidadAfiches;
    pEntidad[i].idCliente=idCliente;
    strcpy(pEntidad[i].nombreArchivo, nombreArchivo);
    pEntidad[i].zona=zona;

    pEntidad[i].estado=ESTADO_ACOBRAR;
    pEntidad[i].isEmpty=FALSE;
}
