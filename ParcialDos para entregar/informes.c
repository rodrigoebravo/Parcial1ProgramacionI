#include "informes.h"
/** \brief Toma el elemento pasado como parametro y segun el valorCriterio devuelve la cantidad del elemento o si habria que contarlo.
 * \param pElement void*
 * \param valorCriterio void*
 * \return int con la cantidad vendida, 1 Si la venta es correcta contarla o 0 si no es correcta contarla segun el valorCriterio
 */
int inf_contarCantidadVentasPorCriterio(void* pElement, void* valorCriterio)
{
    int* monto=(int*)valorCriterio;
    int cantidad;
    float precioUnitario;
    char codigoProducto[20];
    int valorRetorno=0;

    if(pElement!=NULL && Venta_getCantidad(pElement, &cantidad)==TODOOK && *monto==0)
        return cantidad;

    if((pElement!=NULL && Venta_getCantidad(pElement, &cantidad)==TODOOK && Venta_getPrecioUnitario(pElement, &precioUnitario)==TODOOK && (cantidad * precioUnitario)>*monto)
        ||
       (pElement!=NULL && Venta_getCodigoProducto(pElement, codigoProducto)==TODOOK && strcmp(codigoProducto, valorCriterio)==0)
        )
        valorRetorno=1;
    return valorRetorno;
}

int inf_contarTotalUnidadesVendidas(void* pElement)
{
    int contadorRetorno=0;
    int cantidadAux;
    if(pElement!=NULL && Venta_getCantidad(pElement, &cantidadAux)==TODOOK)
        contadorRetorno=cantidadAux;
    return contadorRetorno;
}

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

/** \brief Imprime el informe final, con los cuatro valores ingresados por parametro
 * \param cantidadUnidadesTotales int
 * \param cantidadVentasMontoMayor10mil int
 * \param cantidadVentasMontoMayor20mil int
 * \param cantidadTvsVendidas int
 * \return void
 */
void inf_printInforme(int cantidadUnidadesTotales, int cantidadVentasMontoMayor10mil, int cantidadVentasMontoMayor20mil, int cantidadTvsVendidas)
{
    char leyendaCantidadUnidadesTotales[]="- Cantidad de unidades vendidas totales: ";
    char leyendaCantidadVentasMontoMayor10mil[]="- Cantidad de ventas por un monto mayor a $10000: ";
    char leyendaCantidadVentasMontoMayor20mil[]="- Cantidad de ventas por un monto mayor a $20000: ";
    char leyendaCantidadTvsVendidas[]="- Cantidad de TVs LCD vendidas: ";
    FILE* archivoInforme=fopen("informes.txt", "w");
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
}
