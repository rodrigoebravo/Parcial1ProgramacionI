#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
#define FALSO 0
#define VERDADERO 1
#define CANTIDAD_PANTALLAS 100
#define CANTIDAD_CONTRATACIONES 1000
int main()
{

    if(mostrarMenu()==-1)
    {

    }
    return 0;
}

int mostrarMenu(void)
{
    char respuesta[2];
    int res;

    printMenu();

    if(utn_getEntero(respuesta, 3, 9, 1, "Ingrese:\n", "Error!\n")==0)
    {

    }

    return 0;
}

void printMenu(void)
{
    printf("1- Nueva pantalla\n2- Modificar Pantalla\n3- Eliminar Pantalla\n4- Contratar publicidad\n5- Modificar publicidad\6- Cancelar publicidad\n7- Consultar facturacion por cliente(CUIT)\n8- Listar publicidades contratadas\n 9- Listar Pantallas");
}
