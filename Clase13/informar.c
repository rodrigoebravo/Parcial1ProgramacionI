#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "pantalla.h"

/*G.  Listado de clientes en el cual se indique la cantidad de contrataciones que ha realizado
    y por que importe. Ordenado por los siguientes criterios:
        o Importe (descendentemente)
        o Cuit (ascendentemente)*/

typedef struct
{
    char cuit[50];
    float importe;
    int cantidadCont;
    int isEmpty;
}InfoCliente;
static int estaCuitEnInfoCliente(InfoCliente arrayInfoC[], int limiteInfoC, char cuit[]);
InfoCliente arrayIC[1000];

static void initInfoCliente(Contratacion* arrayCont, int limiteCont,
InfoCliente arrayInfoC[], int limiteInfoC)
{
    int i;
    int proximoLibre=0;
    for(i=0; i<limiteInfoC;i++)
    {
        arrayInfoC[i].isEmpty=1;
    }

    for(i=0; i<limiteInfoC;i++)
    {
        if(!estaCuitEnInfoCliente(arrayCont, limiteCont, arrayCont[i].cuit))
        {
            strcpy(arrayInfoC[proximoLibre].cuit, arrayCont[i].cuit);
            arrayInfoC[proximoLibre].isEmpty=1;
            proximoLibre++;
        }
    }

}

static int estaCuitEnInfoCliente(InfoCliente arrayInfoC[], int limiteInfoC, char cuit[])
{
    int i;
    int retorno=0;
    for(i=0; i<limiteInfoC;i++)
    {
        if(!arrayInfoC[i].isEmpty && !strcmp(arrayInfoC[i].cuit, cuit))
        {
            retorno=1;
            break;
        }
    }
    return retorno;
}



int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;

    return retorno;
}


void informar_ListadoPantallas(Pantalla* list, int len)
{
    int i;
    int flag;
    if(list!=NULL && len>0)
    {

        pantalla_mostrarDebug(list, len);
        pantalla_ordenarPrecioNombre(list, len);
    }

}
