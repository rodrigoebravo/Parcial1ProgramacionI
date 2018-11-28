#include "Parser.h"
static int parser_GuardarVentasDesdeArchivo(FILE* pFile , LinkedList* listaVentas);
/** \brief Abre el archivo en modo escritura y ejecuta el guardado en la lista desde el archivo
 * \param fileName *char
 * \param LinkedList* listaVentas
 * \return int
 */

int parser_parseVentas(char* fileName, LinkedList* listaVentas)
{
    int retorno=ERROR;
    FILE* pFile;

    pFile=fopen(fileName, "r");
    if(pFile!=NULL)
        retorno=parser_GuardarVentasDesdeArchivo(pFile, listaVentas);
    fclose(pFile);

    return retorno;
}

/** \brief Guarda en la lista el contenido del archivo como ventas
 * \param fileName *char
 * \param LinkedList* listaVentas
 * \return int
 */
static int parser_GuardarVentasDesdeArchivo(FILE* pFile , LinkedList* listaVentas)
{
    char idAux[1024];
    char fechaAux[1024];
    char codigoProductoAux[1024];
    char cantidadAux[1024];
    char precioUnitarioAux[1024];
    char cuitClienteAux[1024];
    int retorno=ERROR;
    int flagOnce=TRUE;
    Venta* pVenta;
    //char linea[1024];

    if(pFile != NULL && listaVentas!=NULL)
    {
        retorno=TODOOK;
        printf("Procesando archivo...\n");
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce=FALSE;
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, fechaAux, codigoProductoAux, cantidadAux, precioUnitarioAux, cuitClienteAux);
            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux, fechaAux, codigoProductoAux, cantidadAux, precioUnitarioAux, cuitClienteAux);
            pVenta=Venta_newConParametros(idAux, fechaAux, codigoProductoAux, cantidadAux, precioUnitarioAux, cuitClienteAux);
            if(pVenta!=NULL)
                ll_add(listaVentas, pVenta);
        }

        printf("Archivo cargado exitosamente.\nTotal de registros ingresados: %d\n", ll_len(listaVentas));
    }
    return retorno;
}
