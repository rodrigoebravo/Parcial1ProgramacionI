#include "informes.h"
#include "Venta.h"
#include "LinkedList.h"


int inf_contarUnidadesVendidas(void* pElement, int enteroCriterio)
{
    Venta* pVenta=(Venta*)pElement;
    if(pElement!=NULL)
    {
        return pVenta->cantidadVendida;
    }
    return 0;
}

int inf_contarVentasPorMonto(void* pElement, int enteroCriterio)
{
    Venta* pVenta=(Venta*)pElement;
    float totalDeVenta;

    if(pElement!=NULL)
    {
        totalDeVenta=(pVenta->precioUnitario) * (pVenta->cantidadVendida);
        if(totalDeVenta>(enteroCriterio))
        {
            return 1;
        }    }
    return 0;
}

int inf_contarVentasTV(void* pElement, int enteroCriterio)
{
    Venta* pVenta=(Venta*)pElement;

    if(pElement!=NULL && strcmp(pVenta->codigoProducto, "LCD_TV")==0)
    {
        return pVenta->cantidadVendida;
    }
    return 0;
}

void generarInforme(char* path,
                    int cantidadUnidadesVendidasTotales,
                    int cantidadVentasPorMontoMayorADiezMil,
                    int cantidadVentasPorMontoMayorAVeinteMil,
                    int cantidadTVLCD)
{
    /*int retorno=ERROR;
    FILE*pArchivo;
    char textoAImprimir="Informe de ventas\n cantidad de unidades totales:%d\n cantidad de ventas por un monto mayor a 10000:%d\n cantidad de ventas por un monton mayor a 20000%d\ncantidad de TCsLCD vendidas:%d";



    if(path != NULL)
    {
        pArchivo=fopen(path,"w");

        if(pFile!=NULL){
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        }
    }
    return retorno;*/}


/*int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE*pArchivo;
    int retorno=-1;
    if(path != NULL && pArrayListEmployee != NULL){
        pArchivo=fopen(path,"w");
        if(pArchivo != NULL && !save_EmployeesAsText(pArchivo,pArrayListEmployee)){
            fclose(pArchivo);
            printf("Guardado exitoso");
            getchar();
            retorno=0;
        }else{
            printf("No se pudo abrir el archivo...");
        }
    }
    return retorno;
}*/
