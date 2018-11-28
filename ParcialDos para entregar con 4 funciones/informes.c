#include "informes.h"
/** \brief Toma el elemento pasado como parametro y devuelve la cantidad vendida.
 * \param pElement void* Venta a aplicar criterio
 * \return int con la cantidad vendida
 */
int inf_contarTotalUnidadesVendidas(void* pElement)
{
    int contadorRetorno=0;
    int cantidadAux;
    if(pElement!=NULL && Venta_getCantidad(pElement, &cantidadAux)==TODOOK)
        contadorRetorno=cantidadAux;
    return contadorRetorno;
}

/** \brief Toma el elemento pasado como parametro y devuelve si la venta es mayor o no a 10k.
 * \param pElement void* Venta a aplicar criterio
 * \return int 1 si es mayor a 10k, sino 0
 */
int inf_contarPorCriterioMontoMayor10mil(void* pElement)
{
    int cantidadAux;
    float precioUnitarioAux;
    int retorno=0;
    if( pElement!=NULL &&
        Venta_getCantidad(pElement, &cantidadAux)==TODOOK &&
        Venta_getPrecioUnitario(pElement, &precioUnitarioAux)==TODOOK &&
        (cantidadAux * precioUnitarioAux) >10000)
        retorno=1;

    return retorno;
}

/** \brief Toma el elemento pasado como parametro y devuelve si la venta es mayor o no a 20k.
 * \param pElement void* Venta a aplicar criterio
 * \return int 1 si es mayor a 20k, sino 0
 */
int inf_contarPorCriterioMontoMayor20mil(void* pElement)
{
    int cantidadAux;
    float precioUnitarioAux;
    int retorno=0;
    if( pElement!=NULL &&
        Venta_getCantidad(pElement, &cantidadAux)==TODOOK &&
        Venta_getPrecioUnitario(pElement, &precioUnitarioAux)==TODOOK &&
        (cantidadAux * precioUnitarioAux) > 20000)
        retorno=1;

    return retorno;
}

/** \brief Toma el elemento pasado como parametro y si es LCD_TV el codigoProducto, devuelve la cantidad
 * \param pElement void* Venta a aplicar criterio
 * \return int cantidadVendida si es LCD_TC el codigoProducto, sino 0
 */
int inf_contarTotalUnidadesLCDVendidas(void* pElement)
{
    int contadorRetorno=0;
    int cantidadAux;
    char codigoProductoAux[20];
    char codigoProductoTvLcd[]="LCD_TV";
    if( pElement!=NULL &&
        Venta_getCantidad(pElement, &cantidadAux)==TODOOK &&
        Venta_getCodigoProducto(pElement, codigoProductoAux)==TODOOK &&
        strcmp(codigoProductoAux, codigoProductoTvLcd)==0)
        contadorRetorno=cantidadAux;
    return contadorRetorno;
}

/** \brief Guarda en archivo de texto el informe final, con los cuatro valores ingresados por parametro, e imprime el informe por pantalla.
 * \param nombreArchivo *char
 * \param cantidadUnidadesTotales int
 * \param cantidadVentasMontoMayor10mil int
 * \param cantidadVentasMontoMayor20mil int
 * \param cantidadTvsVendidas int
 * \return void
 */
void inf_guardarInformeEnTexto(char* nombreArchivo, int cantidadUnidadesTotales, int cantidadVentasMontoMayor10mil, int cantidadVentasMontoMayor20mil, int cantidadTvsVendidas)
{
    char leyendaCantidadUnidadesTotales[]="- Cantidad de unidades vendidas totales: ";
    char leyendaCantidadVentasMontoMayor10mil[]="- Cantidad de ventas por un monto mayor a $10000: ";
    char leyendaCantidadVentasMontoMayor20mil[]="- Cantidad de ventas por un monto mayor a $20000: ";
    char leyendaCantidadTvsVendidas[]="- Cantidad de TVs LCD vendidas: ";
    FILE* archivoInforme=fopen(nombreArchivo, "w");
        fprintf(archivoInforme, "********************\nInforme de ventas\n********************\n%s%d\n%s%d\n%s%d\n%s%d\n********************",
                                leyendaCantidadUnidadesTotales,
                                cantidadUnidadesTotales,
                                leyendaCantidadVentasMontoMayor10mil,
                                cantidadVentasMontoMayor10mil,
                                leyendaCantidadVentasMontoMayor20mil,
                                cantidadVentasMontoMayor20mil,
                                leyendaCantidadTvsVendidas,
                                cantidadTvsVendidas);
    fclose(archivoInforme);
    printf("El archivo %s fue generado exitosamente.\n\n", nombreArchivo);
}

/** \brief Imprime en pantalla el informe final, con los cuatro valores ingresados por parametro.
 * \param cantidadUnidadesTotales int
 * \param cantidadVentasMontoMayor10mil int
 * \param cantidadVentasMontoMayor20mil int
 * \param cantidadTvsVendidas int
 * \return void
 */
void inf_printInformeEnPantalla(int cantidadUnidadesTotales, int cantidadVentasMontoMayor10mil, int cantidadVentasMontoMayor20mil, int cantidadTvsVendidas)
{
    char leyendaCantidadUnidadesTotales[]="- Cantidad de unidades vendidas totales: ";
    char leyendaCantidadVentasMontoMayor10mil[]="- Cantidad de ventas por un monto mayor a $10000: ";
    char leyendaCantidadVentasMontoMayor20mil[]="- Cantidad de ventas por un monto mayor a $20000: ";
    char leyendaCantidadTvsVendidas[]="- Cantidad de TVs LCD vendidas: ";
    printf("********************\nInforme de ventas\n********************\n%s%d\n%s%d\n%s%d\n%s%d\n********************\n\n",
                            leyendaCantidadUnidadesTotales,
                            cantidadUnidadesTotales,
                            leyendaCantidadVentasMontoMayor10mil,
                            cantidadVentasMontoMayor10mil,
                            leyendaCantidadVentasMontoMayor20mil,
                            cantidadVentasMontoMayor20mil,
                            leyendaCantidadTvsVendidas,
                            cantidadTvsVendidas);
}
