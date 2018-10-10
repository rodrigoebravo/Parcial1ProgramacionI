#include "Venta.h"
#include "utn.h"
#include "Cliente.h"
static int generarID(void);
static int getAltaVenta(Venta* ven, int lenVen, Cliente* cli, int lenCli, int idCliente);
static int obtenerPosicionVaciaVentas(Venta* pEntidad, int len, int* indexVacio);
static int ventasTieneDatos(Venta* pEntidad, int len);
static int obtenerMaximoID(Venta* pEntidad, int len, int* idRetorno);
static int obtenerIndexClientePorIDVenta(Venta* ven, int lenVen, Cliente* cli, int lenCli, int idVen, int* indexClienteRetorno);
static void ventaForzada(Venta* pEntidad, int cantidadAfiches, int idCliente, char* nombreArchivo, int zona, int estado, int i);
static void forzarAltas(Venta* pEntidad, int len);

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
        forzarAltas(pEntidad, len);
        retorno=TODOOK;
    }
    return retorno;
}

int ven_ventaAfiche(Cliente* cli, int lenCli, Venta* ven, int lenVen)
{
    int retorno=ERROR;
    int idCliente;
    int posicionCliente;
    int maxIDCliente=cli_getMaxIDCliente(cli, lenCli);

    cli_printClientes(cli, lenCli);
    if(ven_validarParametros(ven, lenVen)==TODOOK
        && cli_validarParametros(cli, lenCli)==TODOOK
        && utn_getEntero(&idCliente, 3, maxIDCliente+1, -1, "Ingrese ID de cliente\n", "Error al cargar el ID cliente")==TODOOK
        && cli_obtenerPosicionPorID(cli, lenCli, idCliente, &posicionCliente)!=ERROR
        && !cli_posicionEstaVacia(cli, lenCli, posicionCliente)
        )
        {
            retorno=getAltaVenta(ven, lenVen, cli, lenCli, idCliente);
        }
        else
        {
            limpiarScreen();
            printf("No es posible dar de alta la venta\n");
        }
    return retorno;
}

static int getAltaVenta(Venta* ven, int lenVen, Cliente* cli, int lenCli, int idCliente)
{
    Venta aux;
    int retorno=ERROR;
    int indexVentaVacio;
    if(ven_validarParametros(ven, lenVen)==TODOOK
        && cli_validarParametros(cli, lenCli)==TODOOK
        && idCliente>=0
        && utn_getEntero(&(aux.cantidadAfiches), 3, 10000, 0, "Ingrese cantidad de afiches\n", "cantidad incorrecta\n")==TODOOK
        && utn_getEntero(&(aux.zona), 3, 4, 0, "Ingrese zona: \n\t1- CABA\n\t2- ZONA SUR\n\t3- ZONA OESTE\nIngrese:", "Zona incorrecta\n")==TODOOK
        && utn_getCadena(aux.nombreArchivo, 100, 100, 4, 3, "Ingrese nombre archivo\n", "Nombre erroneo\n")==TODOOK
        && obtenerPosicionVaciaVentas(ven, lenVen, &indexVentaVacio)!=ERROR
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

static int obtenerPosicionVaciaVentas(Venta* pEntidad, int len, int* indexVacio)
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

int ven_cobrarVentaPorID(Venta* ven, int lenVen, Cliente* cli, int lenCli)
{
    int retorno=ERROR;
    int idCobrar;
    int indexCliente;
    int indexVentaCobrada;
    int idMaximo;
    int opcion;
    char mensaje[50]="No se pudo realizar cobro.\n";

    limpiarScreen();

    ven_printVentas(ven, lenVen);
    if(obtenerMaximoID(ven, lenVen, &idMaximo)==TODOOK &&
       utn_getEntero(&idCobrar, 3, idMaximo+1, -1, "Ingrese ID de la venta a cobrar:\n", "ID incorrecto")==TODOOK &&
       obtenerIndexClientePorIDVenta(ven, lenVen, cli, lenCli, idCobrar, &indexCliente)==TODOOK)
    {
        printf("CLIENTE:\t");
        cli_printCliente(cli, indexCliente);
        if(utn_getEntero(&opcion, 3, 3, 0, "Confirma? \n\t1-Si\n\t2-No\n", "Opcion incorrecta\n")==TODOOK)
        {
            switch(opcion)
            {
                case 1:
                    if(ven_obtenerPosicionPorID(ven, lenVen , idCobrar, &indexVentaCobrada)==TODOOK)
                    {
                        ven[indexVentaCobrada].estado=ESTADO_COBRADA;
                        strcpy(mensaje, "Venta cobrada exitosamente.\n");
                    }
                    break;
                case 2:
                        strcpy(mensaje, "Operacion abortada.\n");
                    break;
            }
        }
    }
    limpiarScreen();
    printf(mensaje);

    return retorno;
}

static int obtenerIndexClientePorIDVenta(Venta* ven, int lenVen, Cliente* cli, int lenCli, int idVen, int* indexClienteRetorno)
{
    int retorno=ERROR;
    int i;
    int indexVen;
    if(ven_obtenerPosicionPorID(ven, lenVen, idVen, &indexVen)==TODOOK)
    {
        for(i=0; i<lenCli; i++)
        {
            if(cli[i].id==ven[indexVen].id && !cli[i].isEmpty)
            {
                *indexClienteRetorno=i;
                retorno=TODOOK;
            }
        }
    }
    return retorno;
}

int ven_printVentas(Venta* ventas, int len)
{

    int i;
    int retorno=ERROR;
    if(ven_validarParametros(ventas, len)==TODOOK)
    {
        limpiarScreen();
        for(i=0;i<len; i++)
        {
            if(!ventas[i].isEmpty)
            {
                ven_printVentaPorIndex(ventas, i);
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

static int obtenerMaximoID(Venta* pEntidad, int len, int* idRetorno)
{
    int maxID;
    int retorno=ERROR;
    int i;


    if(ven_validarParametros(pEntidad, len)==TODOOK && ventasTieneDatos(pEntidad, len))
    {

        for(i=0; i<len; i++)
        {
            if(!pEntidad[i].isEmpty)
            {
                if(i==0)
                {
                    maxID=pEntidad[i].id;

                }
                else if(pEntidad[i].id>maxID)
                {
                    maxID=pEntidad[i].id;
                }

            }
        }
        *idRetorno=maxID;
        retorno=TODOOK;

    }
    return retorno;
}

static int generarID(void)
{
    static int id=-1;
    id++;
    return id;
}

static int ventasTieneDatos(Venta* pEntidad, int len)
{
    int retorno=FALSE;
    int i;
    if(ven_validarParametros(pEntidad, len)==TODOOK)
    {
        for(i=0; i<len; i++)
        {
            if(pEntidad[i].isEmpty==FALSE)
            {
                retorno=TRUE;
                break;
            }
        }
    }

    return retorno;
}

static void forzarAltas(Venta* pEntidad, int len)
{
    ventaForzada(pEntidad, 1, 0, "asd.av", 1, 0,0);
    ventaForzada(pEntidad, 10, 1, "ertryrsd.av", 1, 1,1);
    ventaForzada(pEntidad, 1, 2, "ggga3sd.av", 1, 0,2);
    ventaForzada(pEntidad, 18, 3, "123dasd.av", 2, 0,3);
    ventaForzada(pEntidad, 107, 3, "098asd.av", 3, 0,4);
    ventaForzada(pEntidad, 1066, 4, "1345asd.av", 1, 0,5);
    ventaForzada(pEntidad, 1048, 5, "x2asd.av", 2, 0,6);
    ventaForzada(pEntidad, 10, 2, "dxasd.av", 1, 0,7);
    ventaForzada(pEntidad, 200, 9, "sawasd.av", 3, 1,8);
    ventaForzada(pEntidad, 100, 11, "vsasd.av", 3, 1,9);
    ventaForzada(pEntidad, 10, 19, "vvasd.av", 3, 1,10);
    ventaForzada(pEntidad, 300, 22, "gbasd.av", 3, 1,11);
    ventaForzada(pEntidad, 400, 29, "poiasd.av", 2, 1,12);
    ventaForzada(pEntidad, 1, 30, "mmasd.av", 1, 1,13);
    ventaForzada(pEntidad, 2, 26, "mmasd.aCv", 2, 0,14);
    ventaForzada(pEntidad, 77, 15, "dsvFVRasd.av", 3, 1,15);
    ventaForzada(pEntidad, 66, 14, "ccasd.av", 2, 0,16);
    ventaForzada(pEntidad, 66, 13, "ccasd.av", 1, 1,17);
    ventaForzada(pEntidad, 54, 18, "cdsasd.av", 2, 0,18);
    ventaForzada(pEntidad, 1, 19, "cdsasd.av", 1, 1,19);
    ventaForzada(pEntidad, 5, 10, "dcasd.av", 2, 0,20);
    ventaForzada(pEntidad, 8, 8, "fbasd.av", 3, 1,21);
    ventaForzada(pEntidad, 10, 1, "ascasd.av", 2, 0,22);
    ventaForzada(pEntidad, 24, 1, "fdsasd.av", 1, 0,23);
    ventaForzada(pEntidad, 1, 29, "fasd.av", 2, 0,24);
    ventaForzada(pEntidad, 14, 25, "7asd.av", 2, 0,25);
    ventaForzada(pEntidad, 145, 11, "rasd.av", 2, 0,26);
    ventaForzada(pEntidad, 1, 12, "4asd.av", 3, 0,27);
    ventaForzada(pEntidad, 1, 12, "3asd.av", 2, 1,28);
    ventaForzada(pEntidad, 3, 12, "2asd.av", 1, 0,29);
    ventaForzada(pEntidad, 5, 14, "1asd.av", 2, 0,30);
}

static void ventaForzada(Venta* pEntidad, int cantidadAfiches, int idCliente, char* nombreArchivo, int zona, int estado, int i)
{
    pEntidad[i].id=generarID();
    pEntidad[i].cantidadAfiches=cantidadAfiches;
    pEntidad[i].idCliente=idCliente;
    strcpy(pEntidad[i].nombreArchivo, nombreArchivo);
    pEntidad[i].zona=zona;

    pEntidad[i].estado=estado;
    pEntidad[i].isEmpty=FALSE;
}

void ven_printVentaPorIndex(Venta* venta, int index)
{
    char zonaAux[11];
    char estado[9];
    switch(venta[index].zona)
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
                switch(venta[index].estado)
                {
                    case ESTADO_ACOBRAR:
                        strcpy(estado, "A COBRAR");
                        break;
                    case ESTADO_COBRADA:
                        strcpy(estado, "COBRADA");
                        break;
                }

                printf("ID: %d - Archivo: %s - Cantidad de afiches: %d - Zona: %s - IDCliente: %d - Estado: %s\n",
                venta[index].id,
                venta[index].nombreArchivo,
                venta[index].cantidadAfiches,
                zonaAux,
                venta[index].idCliente,
                estado);
}

