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
    if(numeroBuffer!=NULL && intentos>0 && maximo >= minimo && mensaje != NULL && mensajeError != NULL)
    {
        do{
            printf(mensaje);
            getString(numeroBuffer, sizeof(numeroBuffer));
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
            printf(mensaje);
            if(getString(cadenaBuffer, sizeof(cadenaBuffer))==TODOOK)
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
        if(pCadena[i]==44)
        {
            pCadena[i]=46;
        }

        if(pCadena[i]==46)
        {
            contadorSimbolos++;
        }

        if((pCadena[i]>47 && pCadena[i]<58) || pCadena[i]==46)
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

    if(contadorSimbolos>1)
    {
        retorno=FALSO;
    }

    if(primerValor==46 || ultimoValor==46)
    {
        retorno=FALSO;
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
