#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
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
            printf("%s,%s,%s,%s\n", bufferId,bufferNombre,bufferHoras,bufferSueldo);
            employees=Employee_newConParametros(bufferId,bufferNombre,bufferHoras,bufferSueldo);
            if(employees!=NULL){
                ll_add(pArrayListEmployee,employees);
            }
        }while(!feof(pFile));
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
