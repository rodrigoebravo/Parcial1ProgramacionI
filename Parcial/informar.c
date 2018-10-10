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


//Yo hice ordenamiento de clientes.  X nombre apellido y cuit
//Una función q me devuelve cuantos afiches tiene cada id
//Otra q me calcula el Max y min de afiches, y los datos del cliente quien los compro
//Cantidad de a pagar y cantidad de cobrados


int inf_ordenarNombreApellidoCuit(Cliente* pEntidad,int len)
{
    int retorno = ERROR;
    int flagSwap;
    int i;
    Cliente auxiliarVenta;
    if(pEntidad != NULL && len > 0)
    {
        retorno = TODOOK;
        do
        {

            flagSwap = FALSE;
            for(i=0;i<len-1;i++)
            {
                if( strcmp(pEntidad[i].nombre, pEntidad[i+1].nombre)>0 ||
                    (strcmp(pEntidad[i].nombre, pEntidad[i+1].nombre)==0 && strcmp(pEntidad[i].apellido, pEntidad[i+1].apellido)>0) ||
					(strcmp(pEntidad[i].apellido, pEntidad[i+1].apellido)==0 && strcmp(pEntidad[i].cuit,pEntidad[i+1].cuit)>0)
                  )
                {
                    flagSwap = TRUE;
                    auxiliarVenta = pEntidad[i];
                    pEntidad[i] = pEntidad[i+1];
                    pEntidad[i+1] = auxiliarVenta;
                }
            }
        }while(flagSwap);
    }
    cli_printClientes(pEntidad, len);
    return retorno;
}

void inf_cantidadAfichesPorIDCliente(Cliente* cli, Venta* ven, int lenCli, int lenVen)
{
    int i;
    int j;
    int cantidadAfiches;
    for(i=0; i<lenCli; i++)
    {
        if(!cli[i].isEmpty)
        {
            cli_printCliente(cli, i);
            cantidadAfiches=0;
            for(j=0; j<lenVen; j++)
            {
                if(cli[i].id==ven[j].idCliente && !cli[i].isEmpty && !ven[j].isEmpty)
                {
                    cantidadAfiches++;
                }
            }
            printf("Cantidad de ventas %d\n", cantidadAfiches);
        }
    }
}

