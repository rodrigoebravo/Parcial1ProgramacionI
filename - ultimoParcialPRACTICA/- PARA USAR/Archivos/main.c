#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

int main()
{
    char bufferIsEmpty[10];
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    int lenList=0;
    int i=0;
    FILE *pArchivo;
    Cliente* pListaClientes[1000];
    pArchivo= fopen("lista","r+");
    if(pArchivo!= NULL){
       /*fprintf(pArchivo,"Federico,Andrade,15,0\n");
        fprintf(pArchivo,"Martin,ElDrogado,1,0\n");
        fprintf(pArchivo,"Mario,bravo,18,0\n");
        fprintf(pArchivo,"Enrique,ElAntiguo,7,0\n");
        */
        do{
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferNombre,bufferApellido,bufferId,bufferIsEmpty);
            pListaClientes[lenList]=clientes_newConParametros(bufferNombre,bufferApellido,bufferId,bufferIsEmpty);
            if(pListaClientes!=NULL){
                lenList++;
            }
        }while(!feof(pArchivo));
        for(i=0;i<lenList;i++){
            printf("%s - %s - %d - %d\n",pListaClientes[i]->nombre,pListaClientes[i]->apellido,pListaClientes[i]->idCliente,pListaClientes[i]->isEmpty);
        }
        fclose(pArchivo);
    }
    return 0;
}
