#include "utn.h"

static int esNumero(char* pCadena);
static int esDecimal(char* pCadena);
static int getString(char* pBuffer, int limite);
static void limpiarBuffer(void);
//static int contieneNumero(char* cadena);
//static void utn_toUpperCadena(char* cadena, int len);

int utn_getEntero(int* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError)
{
    char cadenaAux[4096];
    int retorno=ERROR;
    int numeroBufferAux;
    if(numeroBuffer!=NULL && intentos>0 && maximo >= minimo && mensaje != NULL && mensajeError != NULL)
    {
        do
        {
            printf(mensaje);
            getString(cadenaAux, sizeof(cadenaAux));

            if(esNumero(cadenaAux)==TRUE)
            {
                numeroBufferAux=atoi(cadenaAux);
                if(numeroBufferAux<maximo && numeroBufferAux>minimo)
                {
                    retorno=TODOOK;
                    *numeroBuffer=numeroBufferAux;
                    break;
                }
                else
                {
                    //system("cls");//windows
                    system("clear");//linux
                    printf(mensajeError);
                }
            }
            else
            {
                limpiarBuffer();
                printf(mensajeError);
            }

            limpiarBuffer();
            intentos--;

        }
        while(intentos>0);
    }
    return retorno;
}

int utn_getDecimal(float* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError)
{
    int retorno=ERROR;
    char cadenaAux[4096];
    float decimalAux;
    if(numeroBuffer!=NULL && intentos>0 && maximo >= minimo && mensaje != NULL && mensajeError != NULL)
    {
        do
        {
            printf(mensaje);
            getString(cadenaAux, sizeof(cadenaAux));
            if(esDecimal(cadenaAux)==TRUE)
            {
                decimalAux=atof(cadenaAux);

                if(decimalAux<maximo && decimalAux>minimo)
                {
                    *numeroBuffer=decimalAux;
                    retorno=TODOOK;
                    break;
                }
                else
                {
                    //system("cls");//windows
                    system("clear");//linux
                    printf(mensajeError);
                }
            }
            else
            {
                limpiarBuffer();
                printf(mensajeError);
            }
            limpiarBuffer();
            intentos--;
        }
        while(intentos>0);
    }
    return retorno;
}

int utn_getCadena(char* cadenaBuffer, int len, int intentos, char* mensaje, char* mensajeError)
{
    int retorno=ERROR;
    if(cadenaBuffer!=NULL && intentos>0 && mensaje!=NULL && mensajeError!=NULL)
    {
        do
        {
            printf(mensaje);
            if(getString(cadenaBuffer, len)==TODOOK)
            {
                retorno=TODOOK;
                break;
            }
            else
            {
                //system("cls");//windows
                system("clear");//linux
                printf(mensajeError);
            }
            intentos--;
        }
        while(intentos>0);
    }
    return retorno;
}

static int esNumero(char* pCadena)
{
    int retorno=TRUE;
    int i=0;

    while(pCadena[i]!=0 && pCadena[i]!=10)
    {
        if((pCadena[i]<48 || pCadena[i]>57) && pCadena[i]!=45)
        {
            retorno=FALSE;
            break;
        }
        i++;
    }
    return retorno;
}

static int esDecimal(char* pCadena)
{
    int retorno=FALSE;
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
        if(pCadena[i]==44)
        {
            pCadena[i]=46;
        }

        if(pCadena[i]==46)
        {
            contadorSimbolos++;
        }

        if((pCadena[i]>47 && pCadena[i]<58) || pCadena[i]==46 || pCadena[i]==45)
        {
            retorno=TRUE;
        }
        else
        {
            retorno=FALSE;
            break;
        }
        i++;
    }
    if(contadorSimbolos>1)
    {
        retorno=FALSE;
    }

    if(primerValor==45)
    {
        retorno=TRUE;
    }

    if(primerValor==46 || ultimoValor==46)
    {
        retorno=FALSE;
    }

    return retorno;
}

static int getString(char* pBuffer, int limite)
{
    char bufferString[4096];
    int retorno=ERROR;

    if(pBuffer!=NULL && limite>0)
    {
        limpiarBuffer();
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
//utn_getPrecio (acepta simbolos de moneda, redondea en 2 decimales)
//utn_getMail   (no acepta espacios, obliga a poner @ y ., minimo de 3 digitos antes del arroba, minimo de 5 entre el arroba y punto, despues del punto no más de 6)
//utn_getContrasenia (no acepta espacios, obliga a poner numeros, simbolos solo el punto, y numeros, minimo de 6)
//utn_getUsuario (sin espacios)
//utn_getDireccion (obliga a poner numeros, espacio y letras)
//utn_getNombreApellido (obliga a poner 1 espacio)
//

/*
static int contieneNumero(char* cadena)
{
    int retorno=FALSE;
    int i=0;

    while(cadena[i]!='\0')
    {
        if(cadena[i]>47 && cadena[i]<58)
        {
            retorno=TRUE;
            break;
        }
        i++;
    }
    return retorno;
}
*/
int utn_contieneSimboloPesos(char* cadena)
{
    int retorno=FALSE;
    int i=0;

    while(cadena[i]!='\0')
    {
        if(cadena[i]==36)
        {
            retorno=TRUE;
            break;
        }
        i++;
    }
    return retorno;
}
//CORREGIR
void limpiarNumero(char* cadena)
{
    int i=0;
    int j;
    char cadenaAux[sizeof(cadena)];
    char cadenaAuxDos[sizeof(cadena)];

    strncpy(cadenaAux, cadena, strlen(cadena));
    strncpy(cadenaAuxDos, cadena, strlen(cadena));
    while(cadenaAuxDos[i]!='\0')
    {
        if((cadenaAux[i]<48 || cadenaAux[i]>57) && cadenaAux[i]!=45)
        {
            printf("---------------\n");
            j=i;
            while(cadenaAux[j]!='\0')
            {
                printf("cadenaAux[j](%c)=cadenaAuxDos[j+1](%c)\n",cadenaAux[j], cadenaAuxDos[j+1]);
                cadenaAux[j]=cadenaAuxDos[j+1];
                j++;
            }
            strncpy(cadenaAuxDos, cadenaAux, strlen(cadena));
        }
        i++;
    }
    strncpy(cadena, cadenaAux, strlen(cadenaAux));
}

int utn_ordenarArray(int *pArray,int limite,int flagMaxMin)
{
    int i=0;
    int aux;
    int retorno=ERROR;
    int flag=TRUE;

    if(pArray!=NULL&&limite>0)
    {
        retorno=TODOOK;
        aux=pArray[i];
        while(flag==TRUE)
        {
            flag=FALSE;
            for(i=0; i<(limite-1); i++)
            {
                if( (flagMaxMin==1 && pArray[i] > pArray[i+1]) ||
                        (flagMaxMin==0 && pArray[i] < pArray[i+1]))
                {
                    flag=TRUE;
                    aux=pArray[i];
                    pArray[i]=pArray[i+1];
                    pArray[i+1]=aux;
                }
            }
        }

    }
    return retorno;
}

/*static void utn_toUpperCadena(char* cadena, int len)
{
    char cadenaAux[len];
    int i;
    for(i=0; i<len; i++)
    {
        if(cadena[i]=='\0')
        {
            cadenaAux[i]='\0';
            break;
        }
        if(cadena[i]>96 && cadena[i]<123)
        {
            cadenaAux[i]=cadena[i]-32;
        }
        else
        {
            cadenaAux[i]=cadena[i];
        }
    }
    strncpy(cadena, cadenaAux, len);
}*/

int utn_getPrecio(float* decimal, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError)
{
    int retorno=ERROR;
    char decimalAux[4096];
    if(decimal!=NULL && intentos>0 && maximo>=minimo && mensaje!=NULL && mensajeError!=NULL)
    {
        if(utn_getCadena(decimalAux, sizeof(decimalAux), intentos, mensaje, mensajeError)==TODOOK)
        {
            limpiarNumero(decimalAux);
            if(esDecimal(decimalAux)==TRUE)
            {
                *decimal=atof(decimalAux);
                retorno=TRUE;
            }
        }
    }
    return retorno;
}

static void limpiarBuffer(void)
{
    //__fpurge(stdin);
    fflush(stdin);
}
