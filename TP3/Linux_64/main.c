#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
/*
    1- crear entidad, no está.
    2- parser.txt
    3-ABM
    4- escribir archivo nuevo, borrar
    mockaroo.com
    build targer, build option, linker settings
*/
void printMenu(int* option);
int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        printMenu(&option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
        }
    }while(option != 10);
    return 0;
    //MAIN CLASE
    //---------------------------------------------------------------------case 1
    //controller_loadFromText("data.csv", listaEmpleados);
    //controller_loadFromBinary("data.bin", listaEmpleados);
    //---------------------------------------------------------------------case 6
    //ll_sort(listaEmpleados, employee_criterioSortNombre, 1);
    //controller_saveAsBinary("data.bin", listaEmpleados);
}
void printMenu(int* option)
{
    char menu[]="1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\n";
    if(utn_getEntero(option, 3, 11, 0, menu, "Opcion incorrecta\n")==TODOOK)
    {

    }
}
