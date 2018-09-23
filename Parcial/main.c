#include "utn.h"
#define CANTIDAD_PANTALLAS 100
#define CANTIDAD_CONTRATACIONES 1000
void limpiarScreen(void);
int mostrarMenu(char* respuesta, int len, int* respuestaEntero);
void printMenu(void);

int main()
{
//    char opcionIngresada[2];
//    int opcionIngresadaEntero;
//    int rta;
//    do{
//            if(mostrarMenu(opcionIngresada, 2, &opcionIngresadaEntero)==0)
//            {
//                rta=0;
//            }
//            else
//            {
//                rta=-1;
//            }
//
//    }while(rta==-1);
    char a[10];
    printf("respuesta de utn_getDecimal(): %d \n", utn_getDecimal(a,3,100,0,"ingrese decimal\n","error\n"));
    return 0;
}

int mostrarMenu(char* respuesta, int len, int* respuestaEntero)
{
    int retorno=-1;
    printMenu();

    if(utn_getEntero(respuesta, 3, 10, 0, "Ingrese:\n", "Error!\n")==0)
    {
        *respuestaEntero=atoi(respuesta);
        retorno=0;
    }

    return retorno;
}

void printMenu(void)
{
    printf("1- Nueva pantalla\n2- Modificar Pantalla\n3- Eliminar Pantalla\n4- Contratar publicidad\n5- Modificar publicidad\6- Cancelar publicidad\n7- Consultar facturacion por cliente(CUIT)\n8- Listar publicidades contratadas\n9- Listar Pantallas\n");
}

void limpiarScreen(void)
{
    system("cls");
}
