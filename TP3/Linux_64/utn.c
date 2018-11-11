#include "utn.h"


static int esDecimal(char* pCadena);
static int getString(char* pBuffer, int limite);


int utn_getMail(char* pBuffer, int len);
//static int pan_obtenerPosicionPorID(Pantalla* pEntidad, int len, int id, int* indexRetorno);
//static int pan_getIdVacio(Pantalla* pan, int len);
//int pan_modificarPantallaPorID(Pantalla* pantalla, int len);
//int pan_bajaPantallaPorID(Pantalla* pan, int lenPan, Contratacion* con, int lenCon);
//int pan_BajaPorPosicion(Pantalla* pan, int lenPan, int index, Contratacion* con, int lenCon);

int utn_getEntero(int* numeroBuffer, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError)
{
    char cadenaAux[4096];
    int retorno=ERROR;
    int numeroBufferAux;
    if(numeroBuffer!=NULL && intentos>0 && maximo >= minimo && mensaje != NULL && mensajeError != NULL)
    {
        do
        {
            printf("%s", mensaje);
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
                    limpiarBuffer();
                    limpiarScreen();
                    printf("%s", mensajeError);
                }
            }
            else
            {
                limpiarBuffer();
                limpiarScreen();
                printf("%s", mensajeError);
            }

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
            printf("%s", mensaje);
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
                    limpiarBuffer();
                    printf("%s", mensajeError);
                }
            }
            else
            {
                limpiarBuffer();
                printf("%s", mensajeError);
            }
            intentos--;
        }
        while(intentos>0);
    }
    return retorno;
}

int utn_getCadena(char* cadenaBuffer, int len, int max, int min, int intentos, char* mensaje, char* mensajeError)
{
    int retorno=ERROR;
    if(cadenaBuffer!=NULL && intentos>0 && mensaje!=NULL && mensajeError!=NULL && max > min)
    {
        do
        {
            printf("%s", mensaje);
            if(getString(cadenaBuffer, len)==TODOOK && strlen(cadenaBuffer) <= max && strlen(cadenaBuffer) >= min)
            {
                retorno=TODOOK;
                break;
            }
            else
            {
                limpiarScreen();
                printf("%s", mensajeError);
            }
            intentos--;
        }
        while(intentos>0);
    }
    return retorno;
}

int esNumero(char* pCadena)
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
//utn_getMail   (no acepta espacios, obliga a poner @ y ., minimo de 3 digitos antes del arroba, minimo de 5 entre el arroba y punto, despues del punto no más de 6)
//utn_getContrasenia (no acepta espacios, obliga a poner numeros, simbolos solo el punto, y numeros, minimo de 6)
//utn_getUsuario (sin espacios)
//utn_getDireccion (obliga a poner numeros, espacio y letras)
//utn_getNombreApellido (obliga a poner 1 espacio)
//




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





/*int utn_getPrecio(float* decimal, int intentos, int maximo, int minimo, char* mensaje, char* mensajeError)
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
}*/

void limpiarBuffer(void)
{
    __fpurge(stdin);
    //fflush(stdin);
}
void limpiarScreen(void)
{
    //system("cls");//windows
    system("clear");//linux
}

int esCuit(char* pBuffer, int len)
{
    int retorno=FALSE;
    if(pBuffer!=NULL && (len > 0 || len < 15) && esNumero(pBuffer) && pBuffer[0]!=45)
        retorno=TRUE;
    return retorno;
}

int utn_getMail(char* pBuffer, int len)
{
    int retorno=TRUE;
    int i;
    int contadorPuntos=0;
    if(pBuffer!=NULL && len > 10 && utn_getCadena(pBuffer, len, 100, 12, 3, "Ingrese mail:\n", "Error en mail")==TODOOK)
    {
        for(i=0; i<3; i++)
        {
            if(pBuffer[i]==64)
            {
                retorno=FALSE;
            }
        }
        for(i=0; i<len && i>3; i++)
        {
            if(pBuffer[i]==46)
                contadorPuntos++;
        }
        if(contadorPuntos>2)
            retorno=FALSE;
    }
    return retorno;
}
