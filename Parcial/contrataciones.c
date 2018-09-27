#include "contrataciones.h"
int con_inicializarLista(Contratacion* con, int len)
{
    int i;
    int retorno=ERROR;
    if(con !=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            con[i].isEmpty=TRUE;
        }
        retorno=TODOOK;
    }
    return retorno;
}


/*int con_Alta(Contratacion* pan, int len, int index)
{
    int id;
    char video;
    float precio;
    int dias;
    int idPantalla;
    char cuit[20];
    int isEmpty;


    int retorno=-1;
    int tipoAux;
    char nombreAux[100];
    char direccionAux[100];
    float precioAux;

    if(pan!=NULL && len > 0 && index>=0 && index<len)
    {

        if(utn_getEntero(&tipoAux, 3, 2, -1, "Ingrese tipo de pantalla( 0-LED 1-LCD): \n", "Error al ingresar tipo\n")==TODOOK)
        {
            if(utn_getCadena(nombreAux, 100, 3,"Ingrese nombre:\n","Error en nombre!\n")==TODOOK)
            {
                if(utn_getCadena(direccionAux, 100, 3, "Ingrese direccion\n","Error al ingresar\n" )==TODOOK)
                {
                    if(utn_getDecimal(&precioAux,3,3000,0,"Ingrese precio: \n", "Error al ingresar precio\n")==TODOOK)
                    {
                        pan[index].tipo=tipoAux;
                        strncpy(pan[index].nombre,nombreAux,sizeof(nombreAux));
                        strncpy(pan[index].direccion,direccionAux,sizeof(direccionAux));
                        pan[index].precio=precioAux;
                        pan[index].id=generarID();
                        pan[index].isEmpty=FALSE;
                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}*/
