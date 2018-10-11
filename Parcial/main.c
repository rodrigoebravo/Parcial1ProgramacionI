#include "utn.h"
#include "informar.h"
#include "Cliente.h"
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_VENTAS 31
#include "Venta.h"
int main()
{
    int opcion;
    Cliente clientes[CANTIDAD_CLIENTES];
    Venta ventas [CANTIDAD_VENTAS];
    inicializaListas(clientes, CANTIDAD_CLIENTES, ventas, CANTIDAD_VENTAS);
    do
    {
        if(inf_printMenu(&opcion)==TODOOK)
        {
            switch(opcion)
            {
                case 1:
                    imprimirIDAlta(cli_darAltaCliente(clientes, CANTIDAD_CLIENTES));
                    break;
                case 2:
                    cli_modificarClientePorID(clientes, CANTIDAD_CLIENTES);
                    break;
                case 3:
                    cli_bajaClientePorID(clientes, CANTIDAD_CLIENTES, ventas, CANTIDAD_VENTAS);
                    break;
                case 4:
                    ven_ventaAfiche(clientes,CANTIDAD_CLIENTES, ventas, CANTIDAD_VENTAS);
                    break;
                case 5:
                    ven_ModificarPorID(ventas, CANTIDAD_VENTAS, clientes, CANTIDAD_CLIENTES);
                    break;
                case 6:
                    ven_cobrarVentaPorID(ventas, CANTIDAD_VENTAS, clientes, CANTIDAD_CLIENTES);
                    break;
                case 7:
                    inf_imprimirClientesConVentasACobrar(ventas, clientes, CANTIDAD_VENTAS, CANTIDAD_CLIENTES);
                    break;
                case 8://a
                    inf_printClienteMasVentas(clientes,ventas, CANTIDAD_CLIENTES, CANTIDAD_VENTAS, ESTADO_ACOBRAR, FALSE, FALSE);
                    break;
                case 9://b
                    inf_printClienteMasVentas(clientes,ventas, CANTIDAD_CLIENTES, CANTIDAD_VENTAS, ESTADO_COBRADA, FALSE, FALSE);
                    break;
                case 10://c
                    inf_printClienteMasVentas(clientes,ventas, CANTIDAD_CLIENTES, CANTIDAD_VENTAS, -1, TRUE, TRUE);
                    break;
                case 11://d
                    inf_printClienteMasVentas(clientes,ventas, CANTIDAD_CLIENTES, CANTIDAD_VENTAS, ESTADO_ACOBRAR, FALSE, TRUE);
                    break;
                case 12://e
                    inf_printClienteComproMasAfiches(ventas, CANTIDAD_VENTAS, clientes, CANTIDAD_CLIENTES);
                    break;
                case 13:
                    inf_printVentasPorZonaAfiche(ventas, CANTIDAD_VENTAS);
                    break;

            };
        }
    }while(opcion!=20);


    return 0;
}
