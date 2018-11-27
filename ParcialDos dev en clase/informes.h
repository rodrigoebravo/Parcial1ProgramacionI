#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int inf_contarUnidadesVendidas(void* pElement, int enteroCriterio);
int inf_contarVentasPorMonto(void* pElement, int enteroCriterio);
int inf_contarVentasTV(void* pElement, int enteroCriterio);
void generarInforme(char* path,
                    int cantidadUnidadesVendidasTotales,
                    int cantidadVentasPorMontoMayorADiezMil,
                    int cantidadVentasPorMontoMayorAVeinteMil,
                    int cantidadTVLCD);
#endif // INFORMES_H_INCLUDED
