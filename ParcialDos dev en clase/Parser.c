#include "LinkedList.h"
#include "utn.h"
#include "Venta.h"
#include "parser.h"

static int parser_VentasFromText(FILE* pFile , LinkedList* listaVentas);

int parser_parseVentas(char* fileName, LinkedList* listaVentas)
{
    int retorno=ERROR;
    FILE* pFile;

    pFile=fopen(fileName, "r");
    if(pFile!=NULL)
        retorno=parser_VentasFromText(pFile, listaVentas);
    fclose(pFile);

    return retorno;
}


static int parser_VentasFromText(FILE* pFile , LinkedList* listaVentas)
{
    char idAux[1024];
    char fechaVentaAux[1024];
    char codigoProductoAux[1024];
    char cantidadVendidaAux[1024];
    char precioUnitarioAux[1024];
    char cuitClienteAux[1024];

    int retorno=ERROR;
    int flagOnce=TRUE;
    Venta* pVenta;
    char linea[1024];

    if(pFile != NULL && listaVentas!=NULL)
    {
        retorno=TODOOK;

        printf("Procesando archivo...\n");

        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce=FALSE;
                fscanf(pFile, "%s", linea);
                strcpy(idAux,strtok(linea, ","));
                strcpy(fechaVentaAux,strtok(NULL, ","));
                strcpy(codigoProductoAux,strtok(NULL, ","));
                strcpy(cantidadVendidaAux,strtok(NULL, ","));
                strcpy(precioUnitarioAux,strtok(NULL, ","));
                strcpy(cuitClienteAux,strtok(NULL, "\n"));
                continue;
            }

            fscanf(pFile, "%s", linea);
            strcpy(idAux,strtok(linea, ","));
            strcpy(fechaVentaAux,strtok(NULL, ","));
            strcpy(codigoProductoAux,strtok(NULL, ","));
            strcpy(cantidadVendidaAux,strtok(NULL, ","));
            strcpy(precioUnitarioAux,strtok(NULL, ","));
            strcpy(cuitClienteAux,strtok(NULL, "\n"));


            /*printf("%s,%s,%s,%s,%s,%s\n",
            idAux,
            fechaVentaAux,
            codigoProductoAux,
            cantidadVendidaAux,
            precioUnitarioAux,
            cuitClienteAux);
            */


            pVenta=Venta_newConParametros(idAux,
                                        fechaVentaAux,
                                        codigoProductoAux,
                                        cantidadVendidaAux,
                                        precioUnitarioAux,
                                        cuitClienteAux);

            if(pVenta!=NULL)
            {
                ll_add(listaVentas, pVenta);
                Venta_print(pVenta);
            }
            //printf("%s,%s,%s,%s\n", bufferInt, bufferNombre, bufferHorasTrabajadas,bufferSueldo);
            //
        }
        printf("Archivo cargado exitosamente\n");
    }
    return retorno;
}
