#include "utn.h"

static int esNumero(char* pCadena);
static int esDecimal(char* pCadena);
static int getString(char* pBuffer, int limite);
static int contieneNumero(char* cadena);
static void toUpperCadena(char* cadena, int len);
static int ordenarArrayInsercion(int *pArray,int limite,int flagMaxMin);
int utn_getMail(char* pBuffer, int len);
static int generarID(void);
static int pan_obtenerPosicionPorID(Pantalla* pEntidad, int len, int id, int* indexRetorno);
static int pan_getIdVacio(Pantalla* pan, int len);
int pan_modificarPantallaPorID(Pantalla* pantalla, int len);
int pan_bajaPantallaPorID(Pantalla* pan, int lenPan, Contratacion* con, int lenCon);
int pan_BajaPorPosicion(Pantalla* pan, int lenPan, int index, Contratacion* con, int lenCon);

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
                    limpiarBuffer();
                    limpiarScreen();
                    printf(mensajeError);
                }
            }
            else
            {
                limpiarBuffer();
                limpiarScreen();
                printf(mensajeError);
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
                    limpiarBuffer();
                    printf(mensajeError);
                }
            }
            else
            {
                limpiarBuffer();
                printf(mensajeError);
            }
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
//utn_getMail   (no acepta espacios, obliga a poner @ y ., minimo de 3 digitos antes del arroba, minimo de 5 entre el arroba y punto, despues del punto no más de 6)
//utn_getContrasenia (no acepta espacios, obliga a poner numeros, simbolos solo el punto, y numeros, minimo de 6)
//utn_getUsuario (sin espacios)
//utn_getDireccion (obliga a poner numeros, espacio y letras)
//utn_getNombreApellido (obliga a poner 1 espacio)
//


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

int ordenarArrayInsercion(int *pArray,int limite,int flagMaxMin)
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

static void toUpperCadena(char* cadena, int len)
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
    //__fpurge(stdin);
    fflush(stdin);
}
void limpiarScreen(void)
{
    system("cls");//windows
    //system("clear");//linux
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
    if(pBuffer!=NULL && len > 10 && utn_getCadena(pBuffer, len, 3, "Ingrese mail:\n", "Error en mail")==TODOOK)
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


/* *********************************************************** */
/* *********************************************************** */
/* *********************************************************** */
/* *********************PANTALLA****************************** */
/* *********************************************************** */
/* *********************************************************** */

/*INICIALIZAR*/
int ent_inicializarLista(Pantalla* pEntidad, int len)
{
    int i;
    int retorno=ERROR;
    if(pEntidad !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            pEntidad[i].isEmpty=TRUE;
        }
        retorno=TODOOK;
    }
    return retorno;
}

/*ALTA*/
int pan_Alta(Pantalla* pan, int len, int index)
{
    int retorno=ERROR;
    int tipoAux;
    char nombreAux[100];
    char direccionAux[100];
    float precioAux;

    if(pan!=NULL && len > 0 && index>=0 && index<len &&
            utn_getEntero(&tipoAux, 3, 2, -1, "Ingrese tipo de pantalla( 0-LED 1-LCD): \n", "Error al ingresar tipo\n")==TODOOK &&
            utn_getCadena(nombreAux, 100, 3,"Ingrese nombre:\n","Error en nombre!\n")==TODOOK &&
            utn_getCadena(direccionAux, 100, 3, "Ingrese direccion\n","Error al ingresar\n" )==TODOOK &&
            utn_getDecimal(&precioAux,3,3000,0,"Ingrese precio: \n", "Error al ingresar precio\n")==TODOOK
      )
    {
        pan[index].tipo=tipoAux;
        strncpy(pan[index].nombre,nombreAux,sizeof(nombreAux));
        strncpy(pan[index].direccion,direccionAux,sizeof(direccionAux));
        pan[index].precio=precioAux;
        pan[index].id=generarID();
        pan[index].isEmpty=FALSE;
        retorno=TODOOK;

    }
    return retorno;
}

/*DA DE ALTA*/
int pan_darAltaPantalla(Pantalla* pEntidad, int len)
{
    int id=0;
    int retorno=ERROR;
    int indexRetorno;

    id=pan_getIdVacio(pEntidad, len);
    pan_Alta(pEntidad, len, id);

    if(pan_obtenerPosicionPorID(pEntidad, len, id, &indexRetorno)==TODOOK)
    {
        retorno=indexRetorno;
    }
    return retorno;
}

/*GENERA ID*/
static int generarID(void)
{
    static int id=-1;
    id++;
    return id;
}
/*DEVUELVE LA POSICION DEL ID*/
static int pan_obtenerPosicionPorID(Pantalla* pEntidad, int len, int id, int* indexRetorno)
{
    int i;
    int retorno=ERROR;
    for(i=0; i<len; i++)
    {
        if(pEntidad[i].id==id && !pEntidad[i].isEmpty)
        {
            *indexRetorno=i;
            retorno=TODOOK;
            break;
        }
    }
    return retorno;
}

/*DEVUELVE PRIMER ID VACIO*/
static int pan_getIdVacio(Pantalla* pan, int len)
{
    int i=0;
    int retorno;
    if(pan !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(pan[i].isEmpty==TRUE)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/*MODIFICA PIDIENDO ID*/
int pan_modificarPantallaPorID(Pantalla* pantalla, int len)
{
    int retorno=ERROR;
    int idModificar;
    int indexModificar;
    if(utn_getEntero(&idModificar, 3, len, -1, "Ingrese ID a modificar:\n", "ID erroneo\n")==TODOOK &&
       pan_obtenerPosicionPorID(pantalla, len, idModificar, &indexModificar)==TODOOK &&
       pan_pantallaVacia(pantalla, len, indexModificar)==FALSE &&
       pan_Alta(pantalla, len, indexModificar)==TODOOK)
        {
            retorno=TODOOK;
        }
    return retorno;
}

/*BAJA DE ENTIDAD POR ID, BAJA TAMBIEN SU PAR EN LA OTRA LISTA*/
int pan_bajaPantallaPorID(Pantalla* pan, int lenPan, Contratacion* con, int lenCon)
{
    int retorno=ERROR;
    int idBaja;
    int indexBaja;

    if(pan!=NULL && lenPan>0)
    {
        if(utn_getEntero(&idBaja, 3, lenPan, -1, "Ingrese ID a dar de baja\n", "Error al dar de baja el ID\n")==TODOOK)
        {
            if(pan_obtenerPosicionPorID(pan, lenPan, idBaja, &indexBaja)==TODOOK)
            {
                if(pan_pantallaVacia(pan, lenPan, indexBaja)==FALSE)
                {
                    retorno=pan_BajaPorPosicion(pan, lenPan, indexBaja, con, lenCon);
                }
            }
        }
    }

    return retorno;
}

/*BAJA POR POSICION*/
int pan_BajaPorPosicion(Pantalla* pan, int lenPan, int index, Contratacion* con, int lenCon)
{
    int retorno=ERROR;
    int i;
    if(pan!=NULL && con!=NULL && lenCon>0 && lenPan>0 && index>=0)
    {
        pan[index].isEmpty=TRUE;
        for(i=0; i<lenCon; i++)
        {
            if(con[i].idPantalla==pan[index].id && con[i].isEmpty==FALSE)
            {
                con[i].isEmpty=TRUE;
            }
        }
        retorno=TODOOK;
    }
    return retorno;
}

/*CONTRATA PÁNTALLA POR ID*/
int contratarPantallasPorID(Pantalla* pan, int lenPan, Contratacion* con, int lenCon)
{
    int retorno=ERROR;
    int idContratar;
    if(pan!=NULL && con!=NULL && lenPan>0 && lenCon>0)
    {
        if(utn_getEntero(&idContratar, 3, lenPan, -1, "Ingrese ID de pantalla a contratar\n", "Error al cargar el ID de pantalla a contratar")==TODOOK)
        {
            if(pan_pantallaVacia(pan, lenPan, idContratar)==FALSE)
            {
                retorno=con_Alta(con, lenCon, pan, lenPan, idContratar);
            }
        }
    }
    return retorno;
}
/*ORDENAR POR MUCHOS CRITERIOIS*/
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

/*ORDENAR POR MUCHOS CRITERIOIS*/
int pantalla_ordenarPrecioNombre(Pantalla arrayPantallas[],int limiteArrayPantallas)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Pantalla auxiliarPantalla;
    if(arrayPantallas != NULL && limiteArrayPantallas > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limiteArrayPantallas-1;i++)
            {
                if( arrayPantallas[i].precio > arrayPantallas[i+1].precio ||
                    (arrayPantallas[i].precio == arrayPantallas[i+1].precio &&
                    strcmp(arrayPantallas[i].nombre,arrayPantallas[i+1].nombre)<0))
                {
                    flagSwap = 1;
                    auxiliarPantalla = arrayPantallas[i];
                    arrayPantallas[i] = arrayPantallas[i+1];
                    arrayPantallas[i+1] = auxiliarPantalla;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}







/* *********************************************************** */
/* *********************************************************** */
/* *********************************************************** */
/* *********************CONTRATACIONES************************ */
/* *********************************************************** */
/* *********************************************************** */

/*PIDE CUIT E IMPRIME TODAS LAS ENTIDADES QUE VA A IMPRIMIR*/
int con_printPantallaPorCuit(Contratacion* con, int lenCon, char* cuit, int lenCuit, Pantalla* pan, int lenPan)
{
    int retorno=ERROR;
    int i;
    int j;
    if(con!=NULL && lenCon>0 && lenCuit>0)
    {
        if(esCuit(cuit, lenCuit)==TRUE)
        {
            for(i=0; i<lenCon; i++)
            {
                if(strcmp(con[i].cuit, cuit)==TODOOK && con[i].isEmpty==FALSE)
                {
                    for(j=0; j<lenPan; j++)
                    {
                        if(con[i].idPantalla==pan[j].id && pan[j].isEmpty==FALSE)
                        {
                            printf("id: \t%d\nTipo:\t%d\nNombre:\t%s\nDireccion:\t%s\nPrecio:\t%f\nEsta vacio?\t%d\n",
                                   pan[j].id,
                                   pan[j].tipo,
                                   pan[j].nombre,
                                   pan[j].direccion,
                                   pan[j].precio,
                                   pan[j].isEmpty);
                            printf("******************\n");
                        }
                    }
                }
            }
            retorno=TODOOK;
        }
    }
    return retorno;
}


int con_cancelar(Contratacion* con, int lenCon, Pantalla* pan, int lenPan)
{
    char cuitAux[20];
    int idBaja;
    int retorno=ERROR;
    if(utn_getCadena(cuitAux, 20, 3, "Ingrese cuit a cancelar\n", "Error al ingresar cuit\n")==TODOOK)
    {
        if(con_printPantallaPorCuit(con, lenCon, cuitAux, 20, pan, lenPan)==TODOOK)
        {
            if(utn_getEntero(&idBaja, 3, lenPan, -1, "Ingrese ID a cancelar\n", "Error al ingresar ID\n")==TODOOK)
            {
                con_bajaPorCuitId(con, lenCon, idBaja, cuitAux);

                retorno=TODOOK;

            }
        }
    }
    return retorno;
}




/*INFORMARRRRRRRRRRRRRRR*/







typedef struct
{
    char cuit[50];
    float importe;
    int cantidadCont;
    int isEmpty;
} InfoCliente;

InfoCliente arrayIC[1000];

static int estaCuitEnInfoCliente(InfoCliente arrayInfoC[],int limiteInfoC, char cuit[]);

static void initInfoCliente( Contratacion arrayCont[],int limiteCont,
                            InfoCliente arrayInfoC[],int limiteInfoC)
{
    int i;
    int proximoLibre=0;
    for(i=0;i<limiteInfoC;i++)
    {
        arrayInfoC[i].isEmpty = 1;
    }

    for(i=0;i<limiteCont;i++)
    {
        if(!estaCuitEnInfoCliente(arrayInfoC,limiteInfoC,arrayCont[i].cuit))
        {
            strcpy(arrayInfoC[proximoLibre].cuit,arrayCont[i].cuit);
            arrayInfoC[proximoLibre].isEmpty = 0;
            proximoLibre++;
        }
    }
}

static void cargaInfoCliente( Contratacion arrayCont[],int limiteCont,
                            InfoCliente arrayInfoC[],int limiteInfoC,
                            Pantalla* pantallas, int lenPantallas)
{
    int i,j;
    int qtyContrataciones = 0;
    Pantalla* auxPatalla;

    for(i=0;i<limiteInfoC;i++)
    {
        if(!arrayInfoC[i].isEmpty)
        {
            qtyContrataciones=0;
            arrayInfoC[i].importe = 0;
            for(j=0;j<limiteCont;j++)
            {
                if(!strcmp(arrayInfoC[i].cuit,arrayCont[j].cuit))
                {
                    qtyContrataciones++;
                    auxPatalla = getPantallaById(pantallas,lenPantallas,arrayCont[j].idPantalla);
                    arrayInfoC[i].importe += auxPatalla->precio * arrayCont[j].dias;
                }
            }
            arrayInfoC[i].cantidadCont = qtyContrataciones;
        }
    }
}



static int estaCuitEnInfoCliente(InfoCliente arrayInfoC[],int limiteInfoC, char cuit[])
{
    int i;
    int retorno = 0;
    for(i=0;i<limiteInfoC;i++)
    {
        if(!arrayInfoC[i].isEmpty && !strcmp(arrayInfoC[i].cuit, cuit))
        {
            retorno = 1;
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

/*
A.  Realizar un solo listado de las pantallas ordenadas
    por los siguientes criterios:
        o Precio (descendentemente)
        o Nombre (ascendentemente)
*/

int informar_listadoPantallas(Pantalla arrayPantallas[],int limiteArrayPantallas)
{
    int retorno = -1;
    if(arrayPantallas != NULL && limiteArrayPantallas > 0)
    {
        pantalla_ordenarPrecioNombre(arrayPantallas,limiteArrayPantallas);
        pantalla_mostrarDebug(arrayPantallas,limiteArrayPantallas);
    }
    return retorno;
}


