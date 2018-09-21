#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

static int esNumero(char* pCadena);
static int esDecimal(char* pCadena);
static int getString(char* pBuffer, int limite);

int utn_getEntero(char* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError)
{

    int retorno=-1;
    int numero;
    if(numeroBuffer!=NULL && intentos>0 && maximo >= minimo && mensaje != NULL && mensajeError != NULL)
    {
        do{
            printf(mensaje);
            getString(numeroBuffer, sizeof(numeroBuffer));

            if(esNumero(numeroBuffer)==0)
            {
                numero=atoi(numeroBuffer);
                if(numero<maximo && numero>minimo)
                {
                    retorno=0;
                    break;
                }
                else
                {
                    printf(mensajeError);
                }
            }
            else
            {
                printf(mensajeError);
            }
            //fflush(stdin);
            __fpurge(stdin);
            intentos--;
        }while(intentos>0);
    }
    return retorno;
}

int utn_getDecimal(char* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError)
{
    int retorno=-1;
    int decimal;
    if(numeroBuffer!=NULL && intentos>0 && maximo >= minimo && mensaje != NULL && mensajeError != NULL)
    {
        do{
            printf(mensaje);
            retorno=getString(numeroBuffer, sizeof(numeroBuffer));

            if(esDecimal(numeroBuffer)==0)
            {
                decimal=atof(numeroBuffer);
                if(decimal<maximo && decimal>minimo)
                {
                    retorno=0;
                    break;
                }
                else
                {
                    printf(mensajeError);
                }
            }
            else
            {
                printf(mensajeError);
            }
            fflush(stdin);
            intentos--;
        }while(intentos>0);
    }
    return retorno;
}

static int getString(char* pBuffer, int limite)
{
    char bufferString[4096];
    int retorno=-1;

    if(pBuffer!=NULL && limite>0)
    {
        __fpurge(stdin);
        //fflush(stdin);
        fgets(bufferString, sizeof(bufferString), stdin);

        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }

        if(strlen(bufferString)<=limite)
        {
            strncpy(pBuffer, bufferString, limite);
            retorno=0;
        }
    }
    return retorno;

}

int utn_getCadena(char* cadenaBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError)
{
    int retorno=0;

    if(cadenaBuffer!=NULL && intentos>0 && maximo>minimo && mensaje!=NULL&&mensajeError!=NULL)
    {
        if(getString(cadenaBuffer, sizeof(cadenaBuffer)))
        {
            retorno=1;
        }
    }
    return retorno;
}


static int esNumero(char* pCadena)
{
    int retorno=0;
    int i=0;
    //printf(pCadena);

    while(pCadena[i]!=0 && pCadena[i]!=10)
    {
        if(pCadena[i]<48 || pCadena[i]>57)
        {
            retorno=-1;
            break;
        }
         i++;
    }
    return retorno;
}

static int esDecimal(char* pCadena)
{
    int retorno=-1;
    int i=0;
    int contadorSimbolos=0;
    char primerValor;
    char ultimoValor;

    while(pCadena[i]!=0 && pCadena[i]!=10)
    {
        if(i==0)
        {
            primerValor=pCadena[i];
        }
        else
        {
            ultimoValor=pCadena[i];
        }
        if(pCadena[i]==44 || pCadena[i]==46)
        {
            contadorSimbolos++;
            if(contadorSimbolos==1)
            {
                retorno=0;
            }
            else
            {
                retorno=-1;
            }
        }
        if((pCadena[i]>47 && pCadena[i]<58) || pCadena[i]==44 || pCadena[i]==46)
        {
            retorno=0;
        }
        else
        {
            retorno=-1;
        }
        i++;
    }
    if(contadorSimbolos!=1)
    {
        retorno=-1;
    }
    if(primerValor==44 || ultimoValor==44 || primerValor==46 || ultimoValor==46)
    {
        retorno=-1;
    }
    printf("%d",retorno);
    return retorno;
}
