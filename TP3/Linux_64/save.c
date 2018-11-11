#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
#include "Controller.h"
#include "save.h"

/** \brief Guarda como texto un empleado en archivo de texto.
 * \param FILE* pFile
 * \param LinkedList* pArrayListEmployee
 * \return int TodoOK o Error
 */
int save_EmployeeToText(FILE* pFile,LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int i=0;
    int len, idAux, horasAux, sueldoAux;
    Employee* empleado;
    char nombreAux[50];

    if(pFile!=NULL && pArrayListEmployee!= NULL)
    {
        retorno=TODOOK;
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        len=ll_len(pArrayListEmployee);
        do
        {
            empleado=(Employee*)ll_get(pArrayListEmployee,i);
            if(empleado!=NULL &&
            Employee_getNombre(empleado, nombreAux)&&
            Employee_getId(empleado,&idAux)&&
            Employee_getSueldo(empleado,&sueldoAux)&&
            Employee_getHorasTrabajadas(empleado,&horasAux))
            fprintf(pFile,"%d,%s,%d,%d\n",idAux,nombreAux,horasAux,sueldoAux);
            i++;
        }
        while(i<len);
    }
    return retorno;
}

/** \brief Guarda un empleado en archivo binario.
 * \param FILE* pFile
 * \param LinkedList* pArrayListEmployee
 * \return int TodoOK o Error
 */
int save_EmployeeToBin(FILE* pArchivo,LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int len= ll_len(pArrayListEmployee);
    int i;
    Employee* pEmpleado;

    if(pArchivo != NULL && pArrayListEmployee!= NULL){
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
