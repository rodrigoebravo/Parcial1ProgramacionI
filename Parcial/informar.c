#include "informar.h"
#include "utn.h"

int inf_printMenu(int* opcion)
{
    int retorno=ERROR;
    int opcionAux;
    char mensajeMenu[]="1- Alta cliente\n2- Modificar datos de cliente\n3- Baja de cliente\n4- Vender afiches\n5- Editar venta\n6- Cobrar centa\n7- Imprimir Clientes\n8- Cliente con mas ventas a cobrar\n9- cliente con mas ventas cobradas\n10- Cliente con mas ventas\n11- Cliente con mas afiches a cobrar\n12- Cliente que cobro mas afiches\n13- Zona con menos afiches vendidos\nIngrese opcion: ";
    if(opcion!=NULL && utn_getEntero(&opcionAux, 3, 18, 0, mensajeMenu,"Opcion incorrecta\n")==TODOOK)
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

void inf_imprimirClientesConVentasACobrar(Venta* ven, Cliente* cli, int lenVen, int lenCli)
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


int inf_printClienteMasVentas(Cliente* cli, Venta* ven, int lenCli, int lenVen, int estado, int estadoNoClasificado, int imprimirAfiches)
{

    int i;
    int retorno;
    int cantidadClientesVentas;
    ClienteCantidadVentas aux[lenCli];
    ClienteCantidadVentas clienteMasVentas;

    if(ven_validarParametros(ven, lenVen)==TODOOK
    && cli_validarParametros(cli, lenCli)==TODOOK
    && clientesTieneDatos(cli, lenCli)==TRUE
    && ventasTieneDatos(ven, lenVen)==TRUE)
    {
        for(i=0; i<lenCli; i++)
        {
            if(!cli[i].isEmpty)
            {
                aux[i].cliente=cli[i];
                aux[i].cantidadVentas=inf_cantidadDeVentasPorIDEstado(ven, lenVen, cli[i].id, estado, estadoNoClasificado);
                aux[i].cantidadAfiches=inf_cantidadDeAfichesPorIDEstado(ven, lenVen, cli[i].id, estado);
                aux[i].isEmpty=FALSE;
            }
        }

        cantidadClientesVentas=i;
        clienteMasVentas=aux[0];

        for(i=0; i<cantidadClientesVentas;i++)
        {
            if(!aux[i].cliente.isEmpty && !aux[i].isEmpty &&
            ((aux[i].cantidadVentas > clienteMasVentas.cantidadVentas && imprimirAfiches==FALSE) ||
            (aux[i].cantidadAfiches > clienteMasVentas.cantidadAfiches && imprimirAfiches==TRUE))
            )
            {
                clienteMasVentas=aux[i];
            }

        }

        printf("ID: %d nombre: %s apellido: %s cuit: %s Cantidad de ventas:%d Cantidad afiches:%d\n",
        clienteMasVentas.cliente.id,
        clienteMasVentas.cliente.nombre,
        clienteMasVentas.cliente.apellido,
        clienteMasVentas.cliente.cuit,
        clienteMasVentas.cantidadVentas,
        clienteMasVentas.cantidadAfiches);

        retorno=TODOOK;
    }


    return retorno;
}

int inf_cantidadDeVentasPorIDEstado(Venta* pEntidad, int len, int idCliente, int estado, int estadoNoClasificado)
{
    int i;
    int cantidadVentas=0;
    for(i=0; i<len; i++)
    {
        if(pEntidad[i].id==idCliente && !pEntidad[i].isEmpty && (pEntidad[i].estado==estado || estadoNoClasificado))
        {
            cantidadVentas++;
        }
    }
    return cantidadVentas;
}

int inf_cantidadDeAfichesPorIDEstado(Venta* pEntidad, int len, int idCliente, int estado)
{
    int i;
    int cantidadAfiches=0;
    for(i=0; i<len; i++)
    {
        if(pEntidad[i].id==idCliente && !pEntidad[i].isEmpty && pEntidad[i].estado==estado)
        {
            cantidadAfiches+=pEntidad[i].cantidadAfiches;
        }
    }
    return cantidadAfiches;
}


void inf_printVentasPorZonaAfiche(Venta* pEntidad, int len)
{
    int i;
    int cantidadZonaSur;
    int cantidadZonaOeste;
    int cantidadCaba;

    for(i=0;i<len;i++)
    {
        switch(pEntidad[i].zona)
        {
            case 1:
                cantidadCaba++;
                break;
            case 2:
                cantidadZonaSur++;
                break;
            case 3:
                cantidadZonaOeste++;
                break;
        }
    }

    if(cantidadCaba<cantidadZonaOeste && cantidadCaba<cantidadZonaSur)
    {
        printf("La con menos afiches vendidos es CABA\n");
    }
    else if(cantidadZonaOeste<cantidadCaba && cantidadZonaOeste<cantidadZonaSur)
    {
        printf("La con menos afiches vendidos es Zona Oeste\n");
    }
    else
    {
        printf("La con menos afiches vendidos es Zona Sur\n");
    }

}


void inf_printClienteComproMasAfiches(Venta* ven, int lenVen, Cliente* cli, int lenCli)
{
    int i;
    int indexClienteMasAfiches;
    int cantMasAfiches;
    int auxCantidad;
    cantMasAfiches=inf_cantidadDeAfichesPorID(ven, lenVen, cli[0].id);
    for(i=0; i<lenCli; i++)
    {
        auxCantidad=inf_cantidadDeAfichesPorID(ven, lenVen, cli[i].id);
        if(auxCantidad>cantMasAfiches)
        {
            cantMasAfiches=auxCantidad;
            indexClienteMasAfiches=i;
        }
    }
        printf("ID: %d nombre: %s apellido: %s cuit: %s Cantidad afiches:%d\n",
                cli[indexClienteMasAfiches].id,
                cli[indexClienteMasAfiches].nombre,
                cli[indexClienteMasAfiches].apellido,
                cli[indexClienteMasAfiches].cuit,
                cantMasAfiches);
}


int inf_cantidadDeAfichesPorID(Venta* pEntidad, int len, int idCliente)
{
    int i;
    int cantidadAfiches=0;
    for(i=0; i<len; i++)
    {
        if(pEntidad[i].id==idCliente && !pEntidad[i].isEmpty)
        {
            cantidadAfiches+=pEntidad[i].cantidadAfiches;
        }
    }
    return cantidadAfiches;
}
