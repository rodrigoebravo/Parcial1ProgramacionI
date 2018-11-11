#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

#include "save.h"
#include "parser.h"
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
void Controller_print(LinkedList* pArrayListEmployee);
int controller_compararPorCriterioNombre(void* thisUno, void* thisDos);
int controller_validarEmployee(LinkedList* pArrayListEmployee, Employee* pEmpleado);
int controller_getMaximoId(LinkedList* pArrayListEmployee, int* idMaximo);

