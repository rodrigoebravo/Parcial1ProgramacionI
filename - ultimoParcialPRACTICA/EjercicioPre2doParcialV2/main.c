#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "utn.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);
int save_EmployeeToBin(FILE* pArchivo,LinkedList* pArrayListEmployee);
int save_EmployeeToBin(FILE* pArchivo,LinkedList* pArrayListEmployee);
int main()
{
    // Definir lista de empleados
    LinkedList* listaEmpleados;

    // Crear lista empledos
    listaEmpleados=ll_newLinkedList();

    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv", listaEmpleados)==TODOOK)
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        ll_Mapper(listaEmpleados,em_calcularSueldo);

        // Generar archivo de salida
        if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==TODOOK)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyando empleados\n");


    return 0;
}

int generarArchivoSueldos(char* fileName, LinkedList* listaEmpleados)
{
    int retorno=ERROR;
    FILE *pArchivo;

    if(fileName!=NULL && listaEmpleados!=NULL)
    {
        pArchivo=fopen(fileName, "wb");
        if(pArchivo!=NULL)
        {
            retorno=save_EmployeeToBin(pArchivo, listaEmpleados);
            fclose(pArchivo);
        }
    }
    fclose(pArchivo);

    return retorno;
}



int save_EmployeeToBin(FILE* pArchivo,LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int len= ll_len(pArrayListEmployee);
    int i;
    Empleado* pEmpleado;

    if(pArchivo != NULL && pArrayListEmployee!= NULL && len> 0){
        retorno=TODOOK;

        for(i=0;i<len;i++)
        {
            pEmpleado=ll_get(pArrayListEmployee,i);
            if(pEmpleado!= NULL)
                fwrite(pEmpleado,sizeof(pEmpleado),1,pArchivo);
        }
    }
    return retorno;
}
