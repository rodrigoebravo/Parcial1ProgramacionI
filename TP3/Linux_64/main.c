#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
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
