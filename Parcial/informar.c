#include "informar.h"
#include "utn.h"

int inf_printMenu(int* opcion)
{
    int retorno=ERROR;
    int opcionAux;
    limpiarScreen();
    if(opcion!=NULL && utn_getEntero(&opcionAux, 3, 9, 0,
        "1-Alta cliente\n2- Modificar datos de cliente\n3- Baja de cliente\n4- Vender afiches\n5- Editar venta\n6- Cobrar centa\n7-Imprimir Clientes\nIngrese opcion: "
        ,"Opcion incorrecta\n")==TODOOK)
    {
        *opcion=opcionAux;
        retorno=TODOOK;
    }
    return retorno;
}

void inicializaListas(Cliente* cli, int lenCli, Venta* ven, int lenVen)
{
    cli_inicializarListaClientes(cli, lenCli);
    ven_inicializarListaVentas(ven, lenVen);
}
