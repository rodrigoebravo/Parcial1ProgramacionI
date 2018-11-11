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
void printMenu(int* option);
int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int hayDatosEnLista=FALSE;

    do{
        printMenu(&option);
        switch(option)
        {
            case 1:
                limpiarScreen();
                if(controller_loadFromText("data.csv",listaEmpleados)==TODOOK)
                    hayDatosEnLista=TRUE;
                break;
            case 2:
                limpiarScreen();
                if(controller_loadFromBinary("data.b",listaEmpleados)==TODOOK)
                    hayDatosEnLista=TRUE;
                break;
            case 3:
                limpiarScreen();
                if(hayDatosEnLista && controller_addEmployee(listaEmpleados)==TODOOK)
                {
                    printf("Dato ingresado correctamente");
                }
                else
                {
                    printf("No hay datos para procesar\n");
                }
                break;
            case 4:
                limpiarScreen();
                if(hayDatosEnLista && controller_editEmployee(listaEmpleados)==TODOOK)
                {
                    printf("Modificacion exitosa\n");
                }
                else
                {
                    printf("No hay datos para procesar\n");
                }
                break;
            case 5:
                limpiarScreen();
                if(hayDatosEnLista && controller_removeEmployee(listaEmpleados)==TODOOK)
                {
                    printf("Dato eliminado correctamente\n");
                }
                else
                {
                    printf("No hay datos para procesar\n");
                }
                break;
            case 6:
                limpiarScreen();
                if(!hayDatosEnLista || controller_ListEmployee(listaEmpleados)!=TODOOK)
                    printf("No es posible listar datos\n");
                break;
            case 7:
                limpiarScreen();
                if(hayDatosEnLista && controller_sortEmployee(listaEmpleados)==TODOOK)
                {
                    printf("Ordenamiento exitoso\n");
                }
                else
                {
                    printf("No fue posible ordenar\n");
                }
                break;
            case 8:
                limpiarScreen();
                if(hayDatosEnLista && controller_saveAsText("data.csv", listaEmpleados)==TODOOK)
                {
                    printf("El archivo fue grabado exitosamente\n");
                }
                else
                {
                    printf("No fue posible grabar datos\n");
                }

                break;
            case 9:
                if(hayDatosEnLista && controller_saveAsBinary("data.b", listaEmpleados)==TODOOK)
                {
                    printf("Creado exitosamente\n");
                }
                else
                {
                    printf("No fue posible grabar datos\n");
                }

                break;
        }
    }while(option != 10);
    return 0;
}
/** \brief Muestra menu y pide opcion.
 * \param int* option
 * \return void
 */
void printMenu(int* option)
{
    char menu[]="1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\n";
    utn_getEntero(option, 3, 11, 0, menu, "Opcion incorrecta\n");
}
