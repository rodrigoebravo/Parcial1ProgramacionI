#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isLetras(char*pBuffer);
static int isInt(char *pBuffer);
static int isValidSueldo(int sueldo);
static int isValidId(int id);
static int isValidHoras(int horas);
static int isValidNombre(char* nombre);

/** \brief crea un nuevo puntero del tipo empleado de manera dinamica
 * \return puntero nuevo o null si no se pudo crear
 *
 */
Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

/** \brief libera puntero del tipo empleado de manera dinamica
 * \param this Employee* Puntero a la estructura a borrar
 */
void Employee_delete(Employee* this)
{
    free(this);
}
/** \brief crea un nuevo puntero del tipo empleado de manera dinamica y guarda los datos
            en cada uno de sus campos despues de validarlos
 * \param id char*
 * \param nombre char*
 * \param horastrabajadas char*
 * \param sueldo char*
 * \return puntero nuevo o null si no se pudo crear
 *
 */
Employee* Employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this=Employee_new();
    if( !isInt(id) && !isLetras(nombre) && !isInt(horasTrabajadas)&& !isInt(sueldo) &&
        !Employee_setId(this,atoi(id))&&
        !Employee_setNombre(this,nombre)&&
        !Employee_setHorasTrabajadas(this,atoi(horasTrabajadas))&&
        !Employee_setSueldo(this,atoi(sueldo))){
            return this;
    }
    Employee_delete(this);
    return NULL;
}
/** \brief Guarda el dato en el campo id, si ya tiene valor lo guarda asi y contabiliza el maximo
            si se ingresa -1 genera uno nuevo apartir del mayor
 * \param id int
 * \return 0 todo bien 1 error
 */
int Employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1 && !isValidId(id))
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else{
        this->id=id;
        retorno=0;
    }

    if(id>proximoId)
    {
        proximoId=id;
        retorno=0;
    }
    return retorno;
}
/** \brief devuelve el dato en el campo id
 * \param id int*
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */
int Employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}
/** \brief guarda el dato en el campo nombre
 * \param nombre char* nombre a guardar
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */
int Employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && !isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}
/** \brief devuelve el dato en el campo nombre
 * \param nombre char*
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */
int Employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}
/** \brief guarda el dato en el campo horasTrabajadas
 * \param horasTrabajadas int horasTrabajadas a guardar
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */
int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && !isValidHoras(horasTrabajadas))
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
/** \brief devuelve el dato en el campo horas
 * \param horas int*
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
/** \brief guarda el dato en el campo sueldo
 * \param sueldo int sueldo a guardar
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien 1 error
 */
int Employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && !isValidSueldo(sueldo))
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}
/** \brief devuelve el dato en el campo sueldo
 * \param sueldo int*
 * \param this Employee* Puntero a la estructura Employee
 * \return 0 todo bien -1 error
 */
int Employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
/** \brief Valida un entero valido en formato char
 * \param pBuffer char* cadena a validar
 * \return 0 todo bien -1 error
 */
static int isInt(char *pBuffer){
    int retorno=-1;
    int i=0;
    do{
        if(*(pBuffer+i)<48||*(pBuffer+i)>57){
                break;
        }
        i++;
    }while (i<strlen(pBuffer));
    if(i==strlen(pBuffer)){
        retorno=0;
    }
    return retorno;
}
/** \brief Valida un nombre valido (acepta nombres compuestos)
 * \param pBuffer char* cadena a validar
 * \return 0 todo bien -1 error
 */
static int isLetras(char*pBuffer){
    int retorno=-1;
    int i=0;
    if(pBuffer!=NULL){
        do{
            if(*(pBuffer+i)==' '||*(pBuffer+i)=='-'){
                i++;
                continue;
            }
            if((*(pBuffer+i)<65||*(pBuffer+i)>90) && (*(pBuffer+i)<97||*(pBuffer+i)>122)){
                break;
            }
            i++;
        }while(i<strlen(pBuffer));
        if(i==strlen(pBuffer)){
            retorno=0;
        }
    }
    return retorno;
}
/** \brief Valida un nombre para guardar en el campo nombre
 * \param nombre char* cadena a validar
 * \return 0 todo bien -1 error
 */
static int isValidNombre(char* nombre){
    int retorno=-1;
    if(nombre!= NULL && strlen(nombre)<50 && strlen(nombre)>1){
        retorno=0;
    }
    return retorno;
}
/** \brief Valida una hora valida
 * \param horas int
 * \return 0 todo bien -1 error
 */
static int isValidHoras(int horas){
    int retorno=-1;
    if(horas>0){
        retorno=0;
    }
    return retorno;
}
/** \brief Valida un id valido
 * \param id int
 * \return 0 todo bien -1 error
 */
static int isValidId(int id){
    int retorno=-1;
    if(id>-2){
        retorno=0;
    }
    return retorno;
}
/** \brief Valida un sueldo valido
 * \param sueldo int
 * \return 0 todo bien -1 error
 */
static int isValidSueldo(int sueldo){
    int retorno=-1;
    if(sueldo>0){
        retorno=0;
    }
    return retorno;
}
/** \brief Valida que una estructura Employee tenga datos validos
 * \param pEmpleado Employee* puntero a la estructura
 * \return 0 todo bien -1 error
 */
int Employee_validarEmpleado(Employee* pEmpleado){
    int retorno=-1;

    if(!isValidId(pEmpleado->id)&&
        !isValidNombre(pEmpleado->nombre) &&
        !isValidHoras(pEmpleado->horasTrabajadas)&&
        !isValidSueldo(pEmpleado->sueldo)){
            retorno=0;
        }
    return retorno;
}
