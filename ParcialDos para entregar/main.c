#include "Parser.h"
#include "informes.h"

int main()
{
    LinkedList* Lista=ll_newLinkedList();
    //Venta* venta=Venta_newConParametros("1","10/10/2010","ARG_123","1","23.3","23-335976287-9");
    //ll_add(Lista, venta);
    //Venta_print(ll_get(Lista, 0));
    parser_parseVentas("data.csv", Lista);
    int monto10Mil=10000;
    int monto20Mil=20000;
    char codigoProductoTvLcd[]="LCD_TV";
    int flagCantidadProductor=0;
    //inf_printInforme(ll_count(Lista, inf_contarPorCriterioUnidadesVendidasTotales, 0),
    //                 ll_count(Lista, inf_contarPorCriterioVentasMayorAMonto, &monto10Mil),
    //                 ll_count(Lista, inf_contarPorCriterioVentasMayorAMonto, &monto20Mil),
    //                 ll_count(Lista, inf_contarPorCriterioCodigoProducto, codigoProductoTvLcd));
    inf_printInforme(   ll_count(Lista, inf_contarCantidadVentasPorCriterio, &flagCantidadProductor),
                        ll_count(Lista, inf_contarCantidadVentasPorCriterio, &monto10Mil),
                        ll_count(Lista, inf_contarCantidadVentasPorCriterio, &monto20Mil),
                        ll_count(Lista, inf_contarCantidadVentasPorCriterio, codigoProductoTvLcd));
    return 0;
}
