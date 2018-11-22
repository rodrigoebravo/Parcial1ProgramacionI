#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "lib.h"
int menu(int*opcion);
int main()
{
    Employee employees[CANTIDADEMPLOYEES];
    int opcion;
    int auxSector;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxid;
    float total;
    float promedio;
    int cantidadMayorAlPromedio;
    emp_inicializarArray(employees,CANTIDADEMPLOYEES);
    emp_alta(employees,emp_obtenerID(),CANTIDADEMPLOYEES,"fede","andrade",400,2);
    emp_alta(employees,emp_obtenerID(),CANTIDADEMPLOYEES,"luis","enrique",300,1);
    emp_alta(employees,emp_obtenerID(),CANTIDADEMPLOYEES,"fede","migual",200,1);
    emp_alta(employees,emp_obtenerID(),CANTIDADEMPLOYEES,"paola","semedo",1200,1);
    emp_alta(employees,emp_obtenerID(),CANTIDADEMPLOYEES,"jorge","andrade",300,3);
    emp_alta(employees,emp_obtenerID(),CANTIDADEMPLOYEES,"lucas","pintos",1300,0);
    emp_alta(employees,emp_obtenerID(),CANTIDADEMPLOYEES,"fernanda","pintos",5020,4);
    do{
        system("clear");
        menu(&opcion);
        switch (opcion){
            case 1:
                if(utn_getLetras(auxName,CANTIDADEMPLOYEES,3,"\nIngrese el nombre: ","\nError...Ingrese un nombre valido")==0&&
                    utn_getLetras(auxLastName,CANTIDADEMPLOYEES,3,"\nIngrese el apellido: ","\nError...Ingrese un apellido valido")==0&&
                    utn_getFloat(&auxSalary,3,"\nIngrese el salario: ","\nError...Ingrese un salario valio",0,999999)==0&&
                    utn_getEntero(&auxSector,3,"\nIngrese el sector: ","\nError...Ingrese un sector valido",1,3)==0){
                    auxid=emp_obtenerID();
                    emp_alta(employees,auxid,CANTIDADEMPLOYEES,auxName,auxLastName,auxSalary,auxSector);
                }
                break;
            case 2:
                if(utn_getEntero(&auxid,3,"\nIngrese el id del empleado a modificar :","\nError..Ingrese un id valido",-1,999)==0){
                    emp_modificarById(employees,CANTIDADEMPLOYEES,auxid);
                }
                break;
            case 3:
                if(utn_getEntero(&auxid,3,"\nIngrese el id del empleado a borrar :","\nError..Ingrese un id valido",-1,999)==0){
                    emp_borrarbyId(employees,CANTIDADEMPLOYEES,auxid);
                }
                break;
            case 4:
                emp_ordenarByLastNameOrSector(employees,CANTIDADEMPLOYEES,1);
                emp_imprimir(employees,CANTIDADEMPLOYEES);
                emp_totalPromedioYMayoresAlPromedio(employees,CANTIDADEMPLOYEES,&cantidadMayorAlPromedio,&total,&promedio);
                printf("\nEl total es: %.2f\t y el promedio es %.2f\nLa cantidad de salarios mayores al promedio son: %d",total,promedio,cantidadMayorAlPromedio);
                getchar();
                break;
        }
    }while(opcion!=5);
    return 0;
}
int menu(int*opcion){
    printf("\n1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-SALIR");
    utn_getEntero(opcion,3,"\nIngrese una opcion: ","\nError...ingrese una opcion valida...",1,5);
    return 0;

}
