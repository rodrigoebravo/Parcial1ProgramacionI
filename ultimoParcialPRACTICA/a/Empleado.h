#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
  int isEmpty;
}Empleado;

#endif // EMPLEADO_H_INCLUDED