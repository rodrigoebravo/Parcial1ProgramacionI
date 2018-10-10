#include "informar.h"
#include "utn.h"

int inf_printMenu(int* opcion)
{
    int retorno=ERROR;
    int opcionAux;
    if(opcion!=NULL && utn_getEntero(&opcionAux, 3, 9, 0,
        "1- Alta cliente\n2- Modificar datos de cliente\n3- Baja de cliente\n4- Vender afiches\n5- Editar venta\n6- Cobrar centa\n7- Imprimir Clientes\n8- Salir\nIngrese opcion: "
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

void imprimirIDAlta(int id)
{
    if(id!=ERROR)
    {
        limpiarScreen();
        printf("ID: %d\n", id);
    }
}

void imprimirClientesConVentasACobrar(Venta* ven, Cliente* cli, int lenVen, int lenCli)
{
    int i;
    int j;

    for(i=0; i<lenCli; i++)
    {
        if(!cli[i].isEmpty)
            cli_printCliente(cli, i);

        for(j=0; j<lenVen; j++)
        {
            if(cli[i].id==ven[j].idCliente && !cli[i].isEmpty && !ven[j].isEmpty && ven[j].estado==ESTADO_ACOBRAR)
            {
                ven_printVentaPorIndex(ven, j);
            }
        }
    }
}
