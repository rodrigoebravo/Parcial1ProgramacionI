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
    LinkedList* listaEmpleados;
    int flagTexto=0;
    int flagBin=0;
    int flagAdd=0;
    do{
        system("clear");
        main_menu(&option);
        switch(option)
        {
            case 1:
                if(!flagTexto && !flagBin){
                    listaEmpleados = ll_newLinkedList();
                    controller_loadFromText("data.csv",listaEmpleados);
                    printf("\nLos datos fueron cargados correctamente..");
                    getchar();
                    flagTexto=1;
                }else{
                    system("clear");
                    printf("Los datos de emplados ya fueron cargados..");
                    getchar();
                }
                break;
            case 2:
                if(!flagTexto && !flagBin){
                    listaEmpleados = ll_newLinkedList();
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    printf("\nLos datos fueron cargados correctamente..");
                    getchar();
                    flagBin=1;
                }else{
                    system("clear");
                    printf("Los datos de emplados ya fueron cargados..");
                    getchar();
                }
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados)){
                    printf("Los datos ingresados son invalidos..");
                    getchar();
                }else
                    flagAdd=1;
                break;
            case 4:
                if(!flagBin && !flagTexto && !flagAdd){
                    system("clear");
                    printf("No hay datos cargados..");
                    getchar();
                }else if(!controller_editEmployee(listaEmpleados)){
                    printf("La modificacion se realizo con exito..");
                    getchar();
                }else{
                    printf("No pudo realizarse la modificacion intente nuevamente...");
                    getchar();
                }
                break;
            case 5:
                if(!flagBin && !flagTexto && !flagAdd){
                      system("clear");
                      printf("No hay datos cargados..");
                      getchar();
                }else if(!controller_removeEmployee(listaEmpleados)){
                    printf("La baja se realizo con exito..");
                    getchar();
                }else{
                    printf("No pudo realizarse la baja intente nuevamente...");
                    getchar();
                }
                break;
            case 6:
                if(flagBin || flagTexto || flagAdd){
                    controller_ListEmployee(listaEmpleados);
                }else{
                    system("clear");
                    printf("No hay datos cargados..");
                    getchar();
                }
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                if(!flagBin && !flagTexto && !flagAdd){
                      system("clear");
                      printf("No hay datos cargados..");
                      getchar();
                }else if(!controller_saveAsText("data.csv",listaEmpleados)){
                    ll_deleteLinkedList(listaEmpleados);
                    flagTexto=0;
                    flagBin=0;
                    flagAdd=0;
                }else{
                    printf("Error al guardar...");
                    getchar();
                }
                break;
            case 9:
                if(!flagBin && !flagTexto && !flagAdd){
                      system("clear");
                      printf("No hay datos cargados..");
                      getchar();
                }else if(!controller_saveAsBinary("data.bin",listaEmpleados)){
                    ll_deleteLinkedList(listaEmpleados);
                    flagTexto=0;
                    flagBin=0;
                    flagAdd=0;
                }else{
                    printf("Error al guardar...");
                    getchar();
                }
                break;
        }
    }while(option != 10);
    return 0;
}
void main_menu(int* option){
    printf("\n****************************************************\nMenu:\n\
1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n\
2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n\
3. Alta de empleado\n\
4. Modificar datos de empleado\n\
5. Baja de empleado\n\
6. Listar empleados\n\
7. Ordenar empleados\n\
8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n\
9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n\
10. Salir\n\
*****************************************************/\n");
    utn_getEntero(option,3,"INGRESE UNA OPCION :  ","Error...Ingrese una opion valida",1,10);
}
