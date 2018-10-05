#include "utn.h"
#include "pantalla.h"
#include "contrataciones.h"
#define CANTIDAD_PANTALLAS 100
#define CANTIDAD_CONTRATACIONES 1000

int mostrarMenu(int* respuesta, int len);
void printMenu(void);
void printPantallaPorPosicion(Pantalla* pantalla, int len, int posicion);
void printPantallaPorID(Pantalla* pantalla, int len, int id);
void llenarPantallas(Pantalla* pantallas);
void llenarContratacion(Contratacion* con);
void imprimirIDPantallasConInfo(Pantalla* pantallas);
void imprimirContratacionesConInfo(Contratacion* con);


int main()
{

    int opcionIngresada=ERROR;
    int id;

    Pantalla pantallas[CANTIDAD_PANTALLAS];
    Contratacion contrataciones[CANTIDAD_CONTRATACIONES];

    llenarPantallas(pantallas);
    llenarContratacion(contrataciones);

    do
    {
        if(mostrarMenu(&opcionIngresada, 2)==TODOOK)
        {
            switch(opcionIngresada)
            {
            case 1:
                limpiarScreen();
                id=pan_darAltaPantalla(pantallas, CANTIDAD_PANTALLAS);
                printf("El ID ingresado es: %d \n", id);
                opcionIngresada=ERROR;
                break;
            case 2:
                limpiarScreen();
                pan_modificarPantallaPorID(pantallas, CANTIDAD_PANTALLAS);
                opcionIngresada=ERROR;
                break;
            case 3:
                limpiarScreen();
                imprimirIDPantallasConInfo(pantallas);
                pan_bajaPantallaPorID(pantallas, CANTIDAD_PANTALLAS, contrataciones, CANTIDAD_CONTRATACIONES);
                opcionIngresada=ERROR;
                break;
            case 4:
                limpiarScreen();
                imprimirIDPantallasConInfo(pantallas);
                contratarPantallasPorID(pantallas, CANTIDAD_PANTALLAS, contrataciones, CANTIDAD_CONTRATACIONES);
                imprimirContratacionesConInfo(contrataciones);
                opcionIngresada=ERROR;
                break;
            case 5:
                limpiarScreen();
                if(con_ModificarPorCuit(contrataciones, CANTIDAD_CONTRATACIONES, pantallas, CANTIDAD_PANTALLAS)==TODOOK)
                {
                    limpiarScreen();
                    printf("Modificacion exitosa");
                }
                break;
            case 6:
                con_cancelar(contrataciones, CANTIDAD_CONTRATACIONES, pantallas, CANTIDAD_PANTALLAS);
                imprimirContratacionesConInfo(contrataciones);
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            }
        }
    }
    while(opcionIngresada==ERROR);

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
    printf("1- Nueva pantalla\n2- Modificar Pantalla\n3- Eliminar Pantalla\n4- Contratar publicidad\n5- Modificar publicidad\n6- Cancelar publicidad\n7- Consultar facturacion por cliente(CUIT)\n8- Listar publicidades contratadas\n9- Listar Pantallas\n");
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

    for(i=0; i<len; i++)
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

void llenarContratacion(Contratacion* con)
{
    con_inicializarLista(con, CANTIDAD_CONTRATACIONES);
    con_alta_forzada(con, CANTIDAD_CONTRATACIONES, "asd1", 100, 20, 0, "23359762879");
    con_alta_forzada(con, CANTIDAD_CONTRATACIONES, "asd2", 96, 18, 1, "23359762879");
    con_alta_forzada(con, CANTIDAD_CONTRATACIONES, "asd3", 19, 17, 2, "23359762870");
    con_alta_forzada(con, CANTIDAD_CONTRATACIONES, "asd4", 99, 16, 0, "23359762870");
    con_alta_forzada(con, CANTIDAD_CONTRATACIONES, "asd5", 102, 15, 2, "23359762870");
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

void imprimirContratacionesConInfo(Contratacion* con)
{
    int len=CANTIDAD_PANTALLAS;
    int i;
    for(i=0; i<len; i++)
    {
        if(con[i].isEmpty==FALSE)
        {
            printf("id:\t%d\nvideo:\t%s\nprecio:\t%f\ndias:\t%d\nidPantalla:\t%d\ncuit:\t%s\n",
                    con[i].id,
                    con[i].video,
                    con[i].precio,
                    con[i].dias,
                    con[i].idPantalla,
                    con[i].cuit);
            printf("****************************\n");
        }
    }
}
