#include "utn.h"
#include "pantalla.h"
#define CANTIDAD_PANTALLAS 100
#define CANTIDAD_CONTRATACIONES 1000
void limpiarScreen(void);
int mostrarMenu(char* respuesta, int len, int* respuestaEntero);
void printMenu(void);
void printPantalla(Pantalla* pantalla, int len, int posicion);

int main()
{
    char opcionIngresada[2];
    int opcionIngresadaEntero=ERROR;
    int id;
    char prueba[10];
    Pantalla pantallas[CANTIDAD_PANTALLAS];
    do{
        if(mostrarMenu(opcionIngresada, 2, &opcionIngresadaEntero)==TODOOK)
        {
            switch(opcionIngresadaEntero)
            {
                case 1:
                    id=pan_darAltaPantalla(pantallas, CANTIDAD_PANTALLAS);
                    printPantalla(pantallas, CANTIDAD_PANTALLAS, id);
                    break;
                case 2:
                    utn_getCadena(prueba, 10, 100, "ingrese carajo:\t", "No\n");
                    printf("%s\n", prueba);
                    utn_toUpperCadena(prueba,sizeof(prueba));
                    printf("%s\n", prueba);
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    break;

            }
        }
    }while(opcionIngresadaEntero==ERROR);



    return 0;
}

int mostrarMenu(char* respuesta, int len, int* respuestaEntero)
{
    int retorno=ERROR;
    printMenu();

    if(utn_getEntero(respuesta, 3, 10, 0, "Ingrese: ", "Error!\n")==TODOOK)
    {
        *respuestaEntero=atoi(respuesta);
        retorno=TODOOK;
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

void printPantalla(Pantalla* pantalla, int len, int posicion)
{
 printf("id: \t%d\nTipo:\t%d\nNombre:\t%s\nDireccion:\t%s\nPrecio:\t%f\nEsta vacio?\t%d\nBella Chao!",
        pantalla[posicion].id,
        pantalla[posicion].tipo,
        pantalla[posicion].nombre,
        pantalla[posicion].direccion,
        pantalla[posicion].precio,
        pantalla[posicion].isEmpty);
}
