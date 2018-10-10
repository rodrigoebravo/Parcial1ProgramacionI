#include "utn.h"
#include "informar.h"
#include "Cliente.h"
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_VENTAS 1000
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
                    ventaAfiche(clientes,CANTIDAD_CLIENTES, ventas, CANTIDAD_VENTAS);
                    break;
                case 5:
                    ven_ModificarPorID(ventas, CANTIDAD_VENTAS, clientes, CANTIDAD_CLIENTES);
                    break;
                case 6:
                    ven_cobrarVenta(ventas, CANTIDAD_VENTAS, clientes, CANTIDAD_CLIENTES);
                    break;
                case 7:
                    break;
                case 8:
                    break;
            };
        }
    }while(opcion!=8);


    return 0;
}
