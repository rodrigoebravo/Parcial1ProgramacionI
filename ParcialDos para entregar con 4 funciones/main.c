#include "Parser.h"
#include "informes.h"

int main()
{
    LinkedList* Lista=ll_newLinkedList();
    parser_parseVentas("data.csv", Lista);
    int totalUnidadesVendidas, ventaMontoMayor10mil, ventaMontoMayor20mil, cantidadLCDVendidas;

    totalUnidadesVendidas=ll_count(Lista, inf_contarTotalUnidadesVendidas);
    ventaMontoMayor10mil=ll_count(Lista, inf_contarPorCriterioMontoMayor10mil);
    ventaMontoMayor20mil=ll_count(Lista, inf_contarPorCriterioMontoMayor20mil);
    cantidadLCDVendidas=ll_count(Lista, inf_contarTotalUnidadesLCDVendidas);

    inf_guardarInformeEnTexto("informes.txt", totalUnidadesVendidas, ventaMontoMayor10mil, ventaMontoMayor20mil, cantidadLCDVendidas);
    inf_printInformeEnPantalla(totalUnidadesVendidas, ventaMontoMayor10mil, ventaMontoMayor20mil, cantidadLCDVendidas);

    return 0;
}
