#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"

#define DEFINE_DEL_ARCHIVO  "hola"

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Pantalla* array,int limite);
static int pan_swap(Pantalla* list, int i);
static int pan_sortPantalla(Pantalla* list, int len, int order);
static int pan_imprimirPantalla(Pantalla* list, int len);

//__________________



/** \brief
 * \param array Pantalla*
 * \param limite int
 * \return int
 *
 */
int pantalla_init(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int pantalla_mostrarDebug(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %s - %f - %d - %d\n",array[i].idPantalla, array[i].nombre,array[i].direccion,array[i].precio,array[i].tipo, array[i].isEmpty);
        }
    }
    return retorno;
}

int pantalla_mostrar(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %d\n",array[i].idPantalla, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int pantalla_alta(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char direccion[50];
    float precio;
    int tipo;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nDireccion? ","\nEso no es un direccion","El maximo es 40",direccion,40,2))
                {
                    if(!getValidFloat("\nPrecio? ","\nEso no es un precio",&precio,0,9999999,2))
                    {
                        if(!getValidInt("\nTipo? ","\nEso no es un precio",&tipo,0,1,2))
                        {
                            retorno = 0;
                            strcpy(array[i].nombre,nombre);
                            strcpy(array[i].direccion,direccion);
                            array[i].precio = precio;
                            array[i].tipo = tipo;
                            //------------------------------
                            //------------------------------
                            array[i].idPantalla = proximoId();
                            array[i].isEmpty = 0;
                        }
                    }
                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}

int pantalla_baja(Pantalla* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = pantalla_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


int pantalla_modificacion(Pantalla* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char buffer[50];

    indiceAModificar = pantalla_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
        {
            retorno = 0;
            strcpy(array[indiceAModificar].nombre,buffer);
            //------------------------------
            //TODO
        }
        else
        {
            retorno = -3;
        }
    }
    return retorno;
}

int pantalla_ordenar(Pantalla* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int buscarLugarLibre(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


int pantalla_buscarPorId(Pantalla* array,int limite, int id)
//static int buscarPorId(Pantalla* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idPantalla==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int pantalla_altaForzada(Pantalla* array,int limite,char* nombre,char* direccion, float precio, int tipo)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].direccion,direccion);
            array[i].precio = precio;
            array[i].tipo = tipo;
            //------------------------------
            //------------------------------
            array[i].idPantalla = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}


static int pan_sortPantalla(Pantalla* list, int len, int order)
{
    int retorno=-1;
    int i;
    int flag=1;

    if(list!=NULL && len>0)
    {
        retorno=0;

        flag=1;
        while(flag==1)
        {
            flag=0;
            for(i=0; i<(len-1); i++)
            {
                if((order==1 && list[i].precio > list[i+1].precio) ||
                   (order==0 && list[i].precio < list[i+1].precio))
                {
                    flag=1;
                    pan_swap(list, i);
                }
                else if(((order==1 && strcmp(list[i].nombre, list[i+1].nombre) < 0) || (order==0 && strcmp(list[i].nombre, list[i+1].nombre) > 0)) && list[i].precio == list[i+1].precio)
                {
                    flag=1;
                    pan_swap(list, i);
                }
            }
        }
    }
    return retorno;
}

void pan_printPantallaOrdenadaPrecioNombre(Pantalla* list, int len)
{

    pan_sortPantalla(list, len, 0);
    pan_imprimirPantalla(list, len);
}

static int pan_swap(Pantalla* list, int i)
{
    int retorno=-1;
    Pantalla aux[1];
    if(list!=NULL && i>-1)
    {
        strncpy(aux[0].direccion, list[i].direccion,sizeof(list[i].direccion));
        strncpy(list[i].direccion,list[i+1].direccion,sizeof(list[i+1].direccion));
        strncpy(list[i+1].direccion,aux[0].direccion,sizeof(aux[0].direccion));

        aux[0].idPantalla=list[i].idPantalla;
        list[i].idPantalla=list[i+1].idPantalla;
        list[i+1].idPantalla=aux[0].idPantalla;

        strncpy(aux[0].nombre,list[i].nombre,sizeof(list[i].nombre));
        strncpy(list[i].nombre,list[i+1].nombre,sizeof(list[i+1].nombre));
        strncpy(list[i+1].nombre,aux[0].nombre,sizeof(aux[0].nombre));

        aux[0].precio=list[i].precio;
        list[i].precio=list[i+1].precio;
        list[i+1].precio=aux[0].precio;

        aux[0].tipo=list[i].tipo;
        list[i].tipo=list[i+1].tipo;
        list[i+1].tipo=aux[0].tipo;

        aux[0].isEmpty=list[i].isEmpty;
        list[i].isEmpty=list[i+1].isEmpty;
        list[i+1].isEmpty=aux[0].isEmpty;
        retorno=0;
    }
    return retorno;
}

static int pan_imprimirPantalla(Pantalla* list, int len)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {
                printf("IDPantalla: %d\nNombre: %s\nDireccion: %s\nPrecio: %.2f\nTipo: %d\n**********\n",
                    list[i].idPantalla,
                    list[i].nombre,
                    list[i].direccion,
                    list[i].precio,
                    list[i].tipo);
            }
        }
        retorno=0;
    }
    return retorno;
}

void pan_getPorCriterio(Pantalla* list, int len, int criterio, int valor)
{
    //1  <
    //2  >
    //3  ==
    //4  >=
    //5  <=
    if(list!=NULL && len>0 && criterio>0 && criterio<6)
    {
        /*for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {
                printf("IDPantalla: %d\nNombre: %s\nDireccion: %s\nPrecio: %.2f\nTipo: %d\n**********\n",
                    list[i].idPantalla,
                    list[i].nombre,
                    list[i].direccion,
                    list[i].precio,
                    list[i].tipo);
            }
        }*/

    }
}

void pantalla_ordenarPrecioNombre(Pantalla* list, int len)
{
    int i;
    int flagSwap;
    Pantalla listAux;
    if(list!=NULL && len>0)
    {
        do
        {
            flagSwap=0;
            for(i=0; i<len-1;i++)
            {
                if((list[i].precio>list[i+1].precio) || (list[i].precio==list[i+1].precio && strcmp(list[i].nombre, list[i+1].nombre) < 0))
                {
                    listAux = list[i];
                    list[i] = list[i+1];
                    list[i+1] = listAux;
                    flagSwap = 1;
            }

        }while(flagSwap==1)






    }
}
pan_ordenarPorCriterio(array, QTY, 5,
