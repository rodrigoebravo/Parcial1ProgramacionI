#include "utn.h"
#include "pantalla.h"
#include "contrataciones.h"
#define CANTIDAD_PANTALLAS 100
#define CANTIDAD_CONTRATACIONES 1000

int mostrarMenu(int* respuesta, int len);
void printMenu(void);
void limpiarScreen(void);
void printPantallaPorPosicion(Pantalla* pantalla, int len, int posicion);
void printPantallaPorID(Pantalla* pantalla, int len, int id);
void llenarPantallas(Pantalla* pantallas);
void imprimirIDPantallasConInfo(Pantalla* pantallas);

int main()
{

    int opcionIngresada=-1;
    int id;

    Pantalla pantallas[CANTIDAD_PANTALLAS];
    Contratacion contrataciones[CANTIDAD_CONTRATACIONES];
    llenarPantallas(pantallas);
    do{
        if(mostrarMenu(&opcionIngresada, 2)==TODOOK)
        {
            switch(opcionIngresada)
            {
                case 1:
                    id=pan_darAltaPantalla(pantallas, CANTIDAD_PANTALLAS);
                    printf("El ID ingresado es: %d \n", id);
                    opcionIngresada=ERROR;
                    break;
                case 2:
                    pan_modificarPantallaPorID(pantallas, CANTIDAD_PANTALLAS);
                    opcionIngresada=ERROR;
                    break;
                case 3:
                    pan_bajaPantallaPorID(pantallas, CANTIDAD_PANTALLAS, contrataciones, CANTIDAD_CONTRATACIONES);
                    opcionIngresada=ERROR;
                    break;
                case 4:
                    imprimirIDPantallasConInfo(pantallas);
                    contratarPantallasPorID(pantallas, CANTIDAD_PANTALLAS, contrataciones, CANTIDAD_CONTRATACIONES);
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
    }while(opcionIngresada==ERROR);

    return 0;
}

int mostrarMenu(int* respuesta, int len)
{
    int retorno=ERROR;
    printMenu();

    if(utn_getEntero(respuesta, 3, 10, 0, "Ingrese: ", "Error!\n")==TODOOK)
    {
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
    system("cls");//windows
    //system("clear");//linux
}

void printPantallaPorPosicion(Pantalla* pantalla, int len, int posicion)
{
 printf("id: \t%d\nTipo:\t%d\nNombre:\t%s\nDireccion:\t%s\nPrecio:\t%f\nEsta vacio?\t%d\nBella Chao!",
        pantalla[posicion].id,
        pantalla[posicion].tipo,
        pantalla[posicion].nombre,
        pantalla[posicion].direccion,
        pantalla[posicion].precio,
        pantalla[posicion].isEmpty);
}

void printPantallaPorID(Pantalla* pantalla, int len, int id)
{
    int i;

    for(i=0;i<len;i++)
    {
        if(pantalla[i].id==id)
        {
            printf("id: \t%d\nTipo:\t%d\nNombre:\t%s\nDireccion:\t%s\nPrecio:\t%f\nEsta vacio?\t%d\nBella Chao!",
                    pantalla[i].id,
                    pantalla[i].tipo,
                    pantalla[i].nombre,
                    pantalla[i].direccion,
                    pantalla[i].precio,
                    pantalla[i].isEmpty);
            break;
        }
    }
}

void llenarPantallas(Pantalla* pantallas)
{
    pan_inicializarLista(pantallas, CANTIDAD_PANTALLAS);
    pan_alta_forzada(pantallas, CANTIDAD_PANTALLAS, "aaaa", 0, "aaaa", 1.2);
    pan_alta_forzada(pantallas, CANTIDAD_PANTALLAS, "bbbb", 1, "bbbb", 3.0);
    pan_alta_forzada(pantallas, CANTIDAD_PANTALLAS, "cccc", 0, "cccc", 2.0);
    pan_alta_forzada(pantallas, CANTIDAD_PANTALLAS, "dddd", 1, "dddd", 1.5);
}

void imprimirIDPantallasConInfo(Pantalla* pantallas)
{
    int len=CANTIDAD_PANTALLAS;
    int i;
    for(i=0; i<len; i++)
    {
        if(pantallas[i].isEmpty==FALSE)
        {
                    printf("id: \t%d\nTipo:\t%d\nNombre:\t%s\nDireccion:\t%s\nPrecio:\t%f\n",
                    pantallas[i].id,
                    pantallas[i].tipo,
                    pantallas[i].nombre,
                    pantallas[i].direccion,
                    pantallas[i].precio);
                    printf("****************************\n");
        }
    }
}
