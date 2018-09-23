#include "utn.h"

static int esNumero(char* pCadena);
static int esDecimal(char* pCadena);
static int getString(char* pBuffer, int limite);

int utn_getEntero(char* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError)
{

    int retorno=ERROR;
    int numero;
    if(numeroBuffer!=NULL && intentos>0 && maximo >= minimo && mensaje != NULL && mensajeError != NULL)
    {
        do{
            printf(mensaje);
            getString(numeroBuffer, sizeof(numeroBuffer));

            if(esNumero(numeroBuffer)==VERDADERO)
            {
                numero=atoi(numeroBuffer);
                if(numero<maximo && numero>minimo)
                {
                    retorno=TODOOK;
                    break;
                }
                else
                {
                    system("cls");
                    printf(mensajeError);
                }
            }
            else
            {
                system("cls");
                printf(mensajeError);
            }
            fflush(stdin);
            //__fpurge(stdin);
            intentos--;
        }while(intentos>0);
    }
    return retorno;
}

int utn_getDecimal(char* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError)
{
    int retorno=ERROR;
    float decimal;
    //printf("---------1- retorno:%d---------\n", retorno);
    if(numeroBuffer!=NULL && intentos>0 && maximo >= minimo && mensaje != NULL && mensajeError != NULL)
    {
        do{
            printf(mensaje);
            retorno=getString(numeroBuffer, sizeof(numeroBuffer));
            if(esDecimal(numeroBuffer)==VERDADERO)
            {
                decimal=atof(numeroBuffer);
                if(decimal<maximo && decimal>minimo)
                {
                    retorno=TODOOK;
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
            //__fpurge(stdin);
            intentos--;
        }while(intentos>0);
    }
    return retorno;
}

static int getString(char* pBuffer, int limite)
{
    char bufferString[4096];
    int retorno=ERROR;

    if(pBuffer!=NULL && limite>0)
    {
        //__fpurge(stdin);
        fflush(stdin);
        fgets(bufferString, sizeof(bufferString), stdin);
        if(bufferString[strlen(bufferString)-1]=='\n')
        {
            bufferString[strlen(bufferString)-1]='\0';
        }

        if(strlen(bufferString)<=limite)
        {
            strncpy(pBuffer, bufferString, limite);
            retorno=TODOOK;
        }
    }
    return retorno;

}
int utn_getCadena(char* cadenaBuffer, int intentos, char* mensaje, char* mensajeError)
{
    int retorno=ERROR;
    if(cadenaBuffer!=NULL && intentos>0 && mensaje!=NULL && mensajeError!=NULL)
    {
        do{
            if(getString(cadenaBuffer, sizeof(cadenaBuffer)))
            {
                retorno=TODOOK;
                break;
            }
            intentos--;
        }while(intentos>0);
    }
    return retorno;
}

static int esNumero(char* pCadena)
{
    int retorno=VERDADERO;
    int i=0;

    while(pCadena[i]!=0 && pCadena[i]!=10)
    {
        if(pCadena[i]<48 || pCadena[i]>57)
        {
            retorno=FALSO;
            break;
        }
         i++;
    }
    return retorno;
}

static int esDecimal(char* pCadena)
{
    int retorno=FALSO;
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
        }
        if((pCadena[i]>47 && pCadena[i]<58) || pCadena[i]==44 || pCadena[i]==46)
        {
            retorno=VERDADERO;
        }
        else
        {
            retorno=FALSO;
            break;
        }
        i++;
    }

    if(contadorSimbolos!=1)
    {
        retorno=FALSO;
    }
    if(primerValor==44 || ultimoValor==44 || primerValor==46 || ultimoValor==46)
    {
        retorno=FALSO;
    }

    printf("lo que devuelve esDecimal es: %d", retorno);
    return retorno;
}
