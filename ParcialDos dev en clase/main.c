#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "Parser.h"
#include"informes.h"
int main()
{
    // Definir lista de empleados
    LinkedList* listaVentas;

    // Crear lista empledos
    listaVentas=ll_newLinkedList();

    // Leer empleados de archivo data.csv
    int cantidadUnidadesVendidasTotales;
    int cantidadVentasPorMontoMayorADiezMil;
    int cantidadVentasPorMontoMayorAVeinteMil;
    int cantidadTVLCD;
    if(parser_parseVentas("data.csv", listaVentas)==TODOOK)
    {
        cantidadUnidadesVendidasTotales=ll_count(listaVentas, inf_contarUnidadesVendidas, 0);
        cantidadVentasPorMontoMayorADiezMil=ll_count(listaVentas, inf_contarVentasPorMonto, 10000);
        cantidadVentasPorMontoMayorAVeinteMil=ll_count(listaVentas, inf_contarVentasPorMonto, 20000);
        cantidadTVLCD=ll_count(listaVentas, inf_contarVentasTV, 0);

        if(cantidadUnidadesVendidasTotales!=ERROR
        && cantidadVentasPorMontoMayorADiezMil!=ERROR
        && cantidadVentasPorMontoMayorAVeinteMil!=ERROR
        && cantidadTVLCD!=ERROR)
        {
            /*generarInforme(cantidadUnidadesVendidasTotales,
                            cantidadVentasPorMontoMayorADiezMil,
                            cantidadVentasPorMontoMayorAVeinteMil,
                            cantidadTVLCD);*/        }
    }
    else
    {
        printf("Error al cargar archivo");    }
    return 0;
}


