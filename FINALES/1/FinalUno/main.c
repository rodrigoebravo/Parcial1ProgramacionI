#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LogEntry.h"
#include "Service.h"
#include "Controller.h"
int printMenu(int* option);
void GetChar(void);
int main()
{
    int option=0;
    LinkedList* listaLog;
    LinkedList* listaService;

    listaLog=ll_newLinkedList();
    listaService=ll_newLinkedList();

    do{
        printMenu(&option);

        switch(option)
        {
            case 1:
                Controller_leerLog(listaLog, listaService);
                GetChar();
                break;
            case 2:
                Controller_procesarInformacion(listaLog, listaService);
                GetChar();
                break;
            case 3:
                Controller_mostrarEstadisticas(listaLog, listaService);
                GetChar();
                break;
        }

    }while(option<4);
    return 0;
}

int printMenu(int* option)
{
    int retorno=ERROR;
    //limpiarScreen();
    if(utn_getEntero(option, 3, 5, 0, "1. Leer Log\n2. Procesar informacion\n3. Mostrar estadisticas\n4. Salir\nIngrese: ", "Error!\n")==TODOOK)
    {
        retorno=TODOOK;
    }
    return retorno;
}

void GetChar(void)
{
    printf("Presione cualquier tecla\n");
    getchar();
}
