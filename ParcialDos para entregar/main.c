#include "Parser.h"
#include "informes.h"

int main()
{
    LinkedList* Lista=ll_newLinkedList();
    parser_parseVentas("data.csv", Lista);
    //int monto10Mil=10000;
    //int monto20Mil=20000;
    //char codigoProductoTvLcd[]="LCD_TV";
    //int flagCantidadProductor=0;
    inf_printInforme(ll_count(Lista, inf_contarTotalUnidadesVendidas),
                     ll_count(Lista, inf_contarPorCriterioMontoMayor10mil),
                     ll_count(Lista, inf_contarPorCriterioMontoMayor20mil),
                     ll_count(Lista, inf_contarTotalUnidadesLCDVendidas));
    //inf_printInforme(   ll_count(Lista, inf_contarCantidadVentasPorCriterio, &flagCantidadProductor),
    //                    ll_count(Lista, inf_contarCantidadVentasPorCriterio, &monto10Mil),
    //                    ll_count(Lista, inf_contarCantidadVentasPorCriterio, &monto20Mil),
    //                    ll_count(Lista, inf_contarCantidadVentasPorCriterio, codigoProductoTvLcd));
    return 0;
}
