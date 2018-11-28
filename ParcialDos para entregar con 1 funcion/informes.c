#include "informes.h"
/** \brief Toma el elemento pasado como parametro y segun el valorCriterio devuelve la cantidad de unidades vendidas o si habria que contar la venta.
 * \param pElement void* elemento para aplicar criterio
 * \param valorCriterio void* si es 0 o codigo producto, contará cantidades de unidades vendidas, sino se usará como monto
 * \return int con la cantidad vendida, 1 Si la venta es correcta contarla o 0 si no es correcta contarla segun el valorCriterio
 */
int inf_contarCantidadVentasPorCriterio(void* pElement, void* valorCriterio)
{
    int* monto=(int*)valorCriterio;
    int cantidad;
    float precioUnitario;
    char codigoProducto[20];
    int valorRetorno=0;

    if((pElement!=NULL && Venta_getCantidad(pElement, &cantidad)==TODOOK && *monto==0) ||
       (pElement!=NULL && Venta_getCantidad(pElement, &cantidad)==TODOOK && Venta_getCodigoProducto(pElement, codigoProducto)==TODOOK && strcmp(codigoProducto, valorCriterio)==0))
        return cantidad;

    if(pElement!=NULL && Venta_getCantidad(pElement, &cantidad)==TODOOK && Venta_getPrecioUnitario(pElement, &precioUnitario)==TODOOK && (cantidad * precioUnitario)>*monto)
        valorRetorno=1;
    return valorRetorno;
}

/** \brief Imprime el informe final, con los cuatro valores ingresados por parametro
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
    if(archivoInforme!=NULL)
    {
        fprintf(archivoInforme, "********************\nInforme de ventas\n********************\n%s%d\n%s%d\n%s%d\n%s%d\n********************",
                leyendaCantidadUnidadesTotales,
                cantidadUnidadesTotales,
                leyendaCantidadVentasMontoMayor10mil,
                cantidadVentasMontoMayor10mil,
                leyendaCantidadVentasMontoMayor20mil,
                cantidadVentasMontoMayor20mil,
                leyendaCantidadTvsVendidas,
                cantidadTvsVendidas);
        printf("Archivo generado correctamente\n\n");
    }
    fclose(archivoInforme);

}

void inf_printInformeEnPantalla(int cantidadUnidadesTotales, int cantidadVentasMontoMayor10mil, int cantidadVentasMontoMayor20mil, int cantidadTvsVendidas)
{
    char leyendaCantidadUnidadesTotales[]="- Cantidad de unidades vendidas totales: ";
    char leyendaCantidadVentasMontoMayor10mil[]="- Cantidad de ventas por un monto mayor a $10000: ";
    char leyendaCantidadVentasMontoMayor20mil[]="- Cantidad de ventas por un monto mayor a $20000: ";
    char leyendaCantidadTvsVendidas[]="- Cantidad de TVs LCD vendidas: ";
    printf("********************\nInforme de ventas\n********************\n%s%d\n%s%d\n%s%d\n%s%d\n********************",
                leyendaCantidadUnidadesTotales,
                cantidadUnidadesTotales,
                leyendaCantidadVentasMontoMayor10mil,
                cantidadVentasMontoMayor10mil,
                leyendaCantidadVentasMontoMayor20mil,
                cantidadVentasMontoMayor20mil,
                leyendaCantidadTvsVendidas,
                cantidadTvsVendidas);
}
