#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Parser.h"
#include "Operacion.h"
int printMenu(int* option);
int printMenuNivel(int* option);
int main()
{

    int opcion;
    int opcionNivel;
    LinkedList* listaVendedores=ll_newLinkedList();
    do{
        printMenu(&opcion);
        switch(opcion)
        {
            case 1:
                limpiarScreen();
                Controller_cargarLista("DATA.csv", listaVendedores, parser_GuardarVendedoresDesdeArchivo);
                break;
            case 2:
                limpiarScreen();
                ll_Mapper(listaVendedores, Vendedor_printVendedor);
                break;
            case 3:
                limpiarScreen();
                Controller_procesarLista(listaVendedores);
                break;
            case 4:
                limpiarScreen();

                printMenuNivel(&opcionNivel);

                Controller_guardarLista("Comisiones.csv", listaVendedores, &opcionNivel);
                break;
            case 5:
                break;
        }
    }while(opcion<5);
    return 0;
}

int printMenu(int* option)
{
    int retorno;
    char menu[]="1- Cargar Archivo \n2- Imprimir Vendedores \n3-Calcular comisiones \n4-Generar archivo de comisiones para nivel \n5-Salir \nIngresar:";
    retorno=utn_getEntero(option, 3, 6, 0, menu, "ERROR!");
    return retorno;
}

int printMenuNivel(int* option)
{
    int retorno;
    char menu[]="Elija nivel: \n1-Junior\n2-Estandard\n3-Experto\nIngrese:";

    retorno=utn_getEntero(option, 3, 4, 0, menu, "ERROR!");
    return retorno;
}
