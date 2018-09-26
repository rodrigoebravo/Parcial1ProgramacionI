#include "utn.h"
#include "pantalla.h"
#define CANTIDAD_PANTALLAS 100
#define CANTIDAD_CONTRATACIONES 1000
void limpiarScreen(void);
int mostrarMenu(int* respuesta, int len);
void printMenu(void);
void printPantalla(Pantalla* pantalla, int len, int posicion);

int main()
{
    int opcionIngresada=-1;
    int id;
    char prueba[10]="$12.392";

    Pantalla pantallas[CANTIDAD_PANTALLAS];
    do{
        if(mostrarMenu(&opcionIngresada, 2)==TODOOK)
        {
            switch(opcionIngresada)
            {
                case 1:
                    id=pan_darAltaPantalla(pantallas, CANTIDAD_PANTALLAS);
                    printPantalla(pantallas, CANTIDAD_PANTALLAS, id);
                    break;
                case 2:
                    printf("%s\n", prueba);
                    limpiarNumero(prueba);
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
    }while(opcionIngresada==ERROR);



    return 0;
}

int mostrarMenu(int* respuesta, int len)
{
    int retorno=ERROR;
    printMenu();

    if(utn_getEntero(respuesta, 3, 10, 0, "Ingrese: ", "Error!\n")==TODOOK)
    {
        //*respuestaEntero=atoi(respuesta);
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
