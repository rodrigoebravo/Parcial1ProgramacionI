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
void main_menu(int* option);

int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    Employee* empleado;
    do{
        system("clear");
        main_menu(&option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);

                break;
        }
    }while(option != 10);
    return 0;
}
void main_menu(int* option){
    printf("\n****************************************************\nMenu:\n\
1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n\
2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n\
3. Alta de empleado\n\
4. Modificar datos de empleado\n\
5. Baja de empleado\n\
6. Listar empleados\n\
7. Ordenar empleados\n\
8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n\
9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n\
10. Salir\n\
*****************************************************/\n");
    utn_getEntero(option,3,"INGRESE UNA OPCION :  ","Error...Ingrese una opion valida",1,10);
}
