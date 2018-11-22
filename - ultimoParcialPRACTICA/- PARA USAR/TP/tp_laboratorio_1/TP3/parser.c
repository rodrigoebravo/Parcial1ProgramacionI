#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
*
 * \param path FILE* puntero al archivo a leer
 * \param pArrayListEmployee LinkedList* puntero a linkedlist
 * \return int 0 todo bien -1 error al guardar
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHoras[1024];
    char bufferSueldo[1024];
    int flagOnce=0;
    Employee* employees;
    if(pFile != NULL && pArrayListEmployee != NULL){
        retorno=0;
        do{
            if(!flagOnce){
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);
                flagOnce=1;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", bufferId,bufferNombre,bufferHoras,bufferSueldo);
            employees=Employee_newConParametros(bufferId,bufferNombre,bufferHoras,bufferSueldo);
            if(employees!=NULL){
                ll_add(pArrayListEmployee,employees);
            }else{
                printf("%s,%s,%s,%s\n", bufferId,bufferNombre,bufferHoras,bufferSueldo);
                getchar();
            }
        }while(!feof(pFile));
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path FILE* puntero al archivo a leer
 * \param pArrayListEmployee LinkedList* puntero a linkedlist
 * \return int 0 todo bien -1 error al guardar
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* pEmpleado;
    if(pFile!=NULL && pArrayListEmployee!= NULL){
        do{
            pEmpleado=Employee_new();
            fread(pEmpleado,sizeof(Employee),1,pFile);
            if(!Employee_validarEmpleado(pEmpleado))
                ll_add(pArrayListEmployee,pEmpleado);
            else
                Employee_delete(pEmpleado);
        }while(!feof(pFile));
        retorno=0;
    }
    return retorno;
}
