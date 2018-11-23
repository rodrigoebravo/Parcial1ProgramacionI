#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "Empleado.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Empleado;

Empleado* Empleado_new();
void Empleado_delete();
Empleado* Empleado_newConParametros(char* id,char* nombre,char* horasTrabajadas);

int Empleado_setId(Empleado* this,int id);
int Empleado_getId(Empleado* this,int* id);
int isValidNombre(char* nombre);

int Empleado_setNombre(Empleado* this,char* nombre);
int Empleado_getNombre(Empleado* this,char* nombre);
int isValidNombre(char* nombre);

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);
int isValidHorasTrabajadas(char* HorasTrabajadas);

int Empleado_setSueldo(Empleado* this,int sueldo);
int Empleado_getSueldo(Empleado* this,int* sueldo);
int isValidSueldo(char* sueldo);

int Empleado_print(Empleado* this);

int em_calcularSueldo(void* p);
#endif // EMPLEADO_H_INCLUDED
