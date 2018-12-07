#include "Controller.h"

int Controller_cargarLista(char* nombreArchivo, LinkedList* pLista, int fn(void*, void*))
{
    int retorno=ERROR;
    FILE* pFile;
    if(nombreArchivo!=NULL &&  pLista!=NULL)
    {
        pFile=fopen(nombreArchivo, "r");
        retorno=fn(pFile, pLista);
        fclose(pFile);
    }
    return retorno;
}

int Controller_guardarLista(char* nombreArchivo, LinkedList* list, int* nivel)
{

    FILE* pFile=fopen(nombreArchivo, "w");

    LinkedList* listaPorNivel=ll_filter(list, filtrarPorNIvel, nivel);

    fprintf(pFile, "ID,Nombre_Vendedor,Nivel,cantidad_productos_vendidos,Monto_vendido,Comision\n");
    ll_MapperConValor(listaPorNivel, printVendedoresConComisionesEnArchivo, pFile);

    fclose(pFile);
    ll_Mapper(listaPorNivel, Vendedor_printVendedor);
}

void printVendedoresConComisionesEnArchivo(void* pEntidad, FILE* file)
{
    int idAux;
    char nombreVendedorAux[50];
    int nivelAux;
    int cantidadProductosAux;
    float montoVendidoAux;
    float comisionAux;
    char nivelChar[11];
    if(file!=NULL && pEntidad!=NULL &&
        Vendedor_getId(pEntidad, &idAux)==TODOOK &&
        Vendedor_getNombreVendedor(pEntidad, nombreVendedorAux)==TODOOK &&
        Vendedor_getNivel(pEntidad, &nivelAux)==TODOOK &&
        Vendedor_getCantidadProductos(pEntidad, &cantidadProductosAux)==TODOOK &&
        Vendedor_getMontoVendido(pEntidad, &montoVendidoAux)==TODOOK &&
        Vendedor_getComision(pEntidad, &comisionAux)==TODOOK
        )
    {
        switch(nivelAux)
        {
            case 1:
                strcpy(nivelChar, "Junior");
                break;
            case 2:
                strcpy(nivelChar, "Estandard");
                break;
            case 3:
                strcpy(nivelChar, "Experto");
                break;
        }
        fprintf(file,"%d,%s,%s,%d,%.2f,%.2f\n",
                       idAux, nombreVendedorAux, nivelChar, cantidadProductosAux, montoVendidoAux, comisionAux);
    }
}



int CalcularComision(Vendedor* pEntidad)
{
    int retorno=ERROR;
    int nivelAux;
    int cantidadProductosAux;
    float montoVendidoAux;
    float comisionAux;
    if(Vendedor_getNivel(pEntidad, &nivelAux)==TODOOK &&
        Vendedor_getCantidadProductos(pEntidad, &cantidadProductosAux)==TODOOK &&
        Vendedor_getMontoVendido(pEntidad, &montoVendidoAux)==TODOOK
        )
    {
        switch(nivelAux)
        {
            case 1:
                comisionAux=montoVendidoAux*0.02;
                retorno=TODOOK;
                break;
            case 2:
            case 3:
                if(cantidadProductosAux<100)
                    comisionAux=montoVendidoAux*0.035;
                else
                    comisionAux=montoVendidoAux*0.05;
                retorno=TODOOK;
                break;
        };

    }
    Vendedor_setComision(pEntidad, comisionAux);
    return retorno;
}


LinkedList* Controller_procesarLista(LinkedList* list)
{
    int retorno=ERROR;
    if(list!=NULL)
    {
        retorno=TODOOK;
        ll_Mapper(list, CalcularComision);
    }
    return retorno;
}

int filtrarPorNIvel(Vendedor* pEntidad, int* nivel)
{
    int nivelAux;
    printf("------------------aaaaaaaaaa\n");
    if(pEntidad!=NULL && nivel!=NULL
    && Vendedor_getNivel(pEntidad, &nivelAux)==TODOOK
    //&& (*nivel)==nivelAux
    )
    //    return TRUE;
    //return FALSE;

    return TRUE;
}
