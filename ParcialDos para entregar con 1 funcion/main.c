#include "Parser.h"
#include "informes.h"

int main()
{
    LinkedList* Lista=ll_newLinkedList();
    parser_parseVentas("data.csv", Lista);
    int monto10Mil=10000;
    int monto20Mil=20000;
    char codigoProductoTvLcd[]="LCD_TV";
    int flagCantidadProductosTotal=0;
    int totalUnidadesVendidas, ventaMontoMayor10mil, ventaMontoMayor20mil, cantidadLCDVendidas;

    totalUnidadesVendidas=ll_count(Lista, inf_contarCantidadVentasPorCriterio, &flagCantidadProductosTotal);
    ventaMontoMayor10mil=ll_count(Lista, inf_contarCantidadVentasPorCriterio, &monto10Mil);
    ventaMontoMayor20mil=ll_count(Lista, inf_contarCantidadVentasPorCriterio, &monto20Mil);
    cantidadLCDVendidas=ll_count(Lista, inf_contarCantidadVentasPorCriterio, codigoProductoTvLcd);

    inf_guardarInformeEnTexto("informes.txt", totalUnidadesVendidas, ventaMontoMayor10mil, ventaMontoMayor20mil, cantidadLCDVendidas);
    inf_printInformeEnPantalla(totalUnidadesVendidas, ventaMontoMayor10mil, ventaMontoMayor20mil, cantidadLCDVendidas);
    return 0;
}
