#include "Controller.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    FILE* pFile;

    pFile=fopen(path, "r");
    if(pFile!=NULL)
        retorno=parser_EmployeeFromText(pFile, pArrayListEmployee);
    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    FILE* pFile;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb");
        if(pFile!=NULL)
            retorno=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    char idAux[1024];
    char nombreAux[1024];
    char horasTrabajadasAux[1024];
    char sueldoAux[1024];
    Employee* pEmpleado;
    if(pArrayListEmployee!=NULL &&
       utn_getCadena(idAux, 1024, 1024,0,3,"Ingrese id:\n", "Error al ingresar id\n")==TODOOK &&
       utn_getCadena(nombreAux, 1024, 1024,0,3,"Ingrese nombre\n", "Error al ingresar nombre\n")==TODOOK&&
       utn_getCadena(horasTrabajadasAux, 1024,1024,0,3,"Ingrese cantidad de horas\n","Error al ingresar cantidad de horas\n")==TODOOK &&
       utn_getCadena(sueldoAux, 1024,1024,0,3,"Ingrese sueldo\n","Error al ingresar sueldo\n")==TODOOK)
    {
        pEmpleado=Employee_newConParametros(idAux, nombreAux, horasTrabajadasAux, sueldoAux);
        if(pEmpleado!=NULL && controller_validarEmployee(pArrayListEmployee, pEmpleado)==TODOOK)
        {
            ll_add(pArrayListEmployee, pEmpleado);
            retorno=TODOOK;
        }

    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int idBuffer=0;
    int idEmpleado=0;
    int option=0;
    int len = ll_len(pArrayListEmployee);
    int i;
    Employee *pEmpleado;
    char nombreAux[50];
    int horasTrabajadasAux, sueldoAux, idMaximo;
    controller_getMaximoId(pArrayListEmployee, &idMaximo);
    controller_ListEmployee(pArrayListEmployee);
    if(pArrayListEmployee != NULL
    && utn_getEntero(&idBuffer, 3, idMaximo, 0, "Ingrese id que desea modificar\n", "Id incorrecto\n")==TODOOK)
    {
        for(i=0; i<len; i++)
        {

            pEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
            Employee_getId(pEmpleado, &idEmpleado);
            if(idEmpleado!=0 && idBuffer==idEmpleado
            && utn_getEntero(&option, 3, 4, 0, "Ingrese campo a modificar:\n\t1- Nombre\n\t2- Cantidad de horas\n\t3- Sueldo\nIngrese: ", "Opcion incorrecta")==TODOOK
            )
            {
                switch(option)
                {
                    case 1:
                        if(utn_getCadena(nombreAux, 50, 50, 0, 3, "Ingrese nombre:\n", "Nombre erroneo\n")==TODOOK)
                        {
                            Employee_setNombre(pEmpleado, nombreAux);
                        }
                        break;
                    case 2:
                        if(utn_getEntero(&horasTrabajadasAux, 3, 500, 0, "Ingrese cantidad de horas:\n", "Nombre erroneo\n")==TODOOK)
                        {
                            Employee_setHorasTrabajadas(pEmpleado, horasTrabajadasAux);
                        }
                        break;
                    case 3:
                        if(utn_getEntero(&sueldoAux, 3, 500, 0, "Ingrese sueldo:\n", "Nombre erroneo\n")==TODOOK)
                        {
                            Employee_setSueldo(pEmpleado, sueldoAux);
                        }
                        break;
                }
            }
        }
        retorno=TODOOK;
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int idBuffer, i, idEmpleado, idMaximo;
    int len=ll_len(pArrayListEmployee);
    Employee* pEmpleado;
    idMaximo=controller_getMaximoId(pArrayListEmployee, &idMaximo);
    if(pArrayListEmployee!=NULL
    && utn_getEntero(&idBuffer, 3, idMaximo, 0, "Ingrese id que desea modificar\n", "Id incorrecto\n")==TODOOK)
    {
        for(i=0; i<len; i++)
        {
            pEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
            Employee_getId(pEmpleado, &idEmpleado);
            if(idBuffer==idEmpleado)
            {
                ll_remove(pArrayListEmployee, i);
                retorno=TODOOK;
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    int len=ll_len(pArrayListEmployee);
    Employee* pEmpleado;

    if(pArrayListEmployee!=NULL)
    {

        retorno=TODOOK;
        for(int i=0; i<len;i++)
        {
            pEmpleado=(Employee*)ll_get(pArrayListEmployee, i);
            if(pEmpleado!=NULL)
                Employee_print(pEmpleado);

        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee, controller_compararPorCriterioNombre, 0);
        retorno=TODOOK;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE*pArchivo;
    int retorno=ERROR;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo=fopen(path,"w");
        if(pArchivo != NULL)
        {
            retorno=save_EmployeeToText(pArchivo,pArrayListEmployee);
            fclose(pArchivo);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=ERROR;
    FILE *pArchivo;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pArchivo=fopen(path, "wb");
        if(pArchivo!=NULL)
        {
            retorno=save_EmployeeToBin(pArchivo, pArrayListEmployee);
            fclose(pArchivo);
        }
    }
    fclose(pArchivo);

    return retorno;
}

/** \brief Decide el criterio para posterior ordenamiento.
 * \param void* thisUno Empleado 1
 * \param void* thisDos Empleado 2
 * \return int TodoOK o Error
 */
int controller_compararPorCriterioNombre(void* thisUno, void* thisDos)
{

    char nombreUnoAux[100], nombreDosAux[100];
    int retorno=0;
    Employee_getNombre(thisUno,nombreUnoAux);
    Employee_getNombre(thisDos,nombreDosAux);

    if(strcmp(nombreUnoAux,nombreDosAux)<0)
        retorno=-1;
    else if(strcmp(nombreUnoAux,nombreDosAux)>0)
        retorno=1;
    return retorno;
}

/** \brief Busca el id Maximo.
 * \param LinkedList* pArrayListEmployee
 * \param Employee* pEmpleado
 * \return int TodoOK o Error
 */
int controller_validarEmployee(LinkedList* pArrayListEmployee, Employee* pEmpleado)
{
    int retorno=TODOOK;
    int idEmpleado, idEmpleadoAux, i;
    int len=ll_len(pArrayListEmployee);
    Employee* pEmpleadoAux;
    for(i=0; i<len; i++)
    {
        pEmpleadoAux=(Employee*)ll_get(pArrayListEmployee, i);

        if(Employee_getId(pEmpleado, &idEmpleado)==TODOOK &&
        Employee_getId(pEmpleadoAux, &idEmpleadoAux)==TODOOK &&
        idEmpleado==idEmpleadoAux)
        {
            retorno=ERROR;
            break;
        }
    }

    return retorno;
}

int controller_getMaximoId(LinkedList* pArrayListEmployee, int* idMaximo)
{
    int retorno=ERROR;
    int id, i;
    int idMaximoAux=-1;

    int len=ll_len(pArrayListEmployee);
    Employee* pEmpleado;
    for(i=0; i<len; i++)
    {
        pEmpleado=(Employee*)ll_get(pArrayListEmployee, i);

        if(pEmpleado!=NULL &&
            Employee_getId(pEmpleado, &id)==TODOOK &&
            id>idMaximoAux
        )
           idMaximoAux=id;

        *idMaximo=idMaximoAux;
        retorno=TODOOK;
    }
    return retorno;
}
