#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
void guardar(Persona* array[], int size);
void guardar(Persona* array[], int size)
{
    int i;
    int auxId;
    char auxNombre[50];
    FILE* pArchivoBkp=fopen("bkp.txt", "w");
    if(pArchivoBkp!=NULL)
    {
        for(i=0; i<size; i++)
        {
            persona_getId(array[i], &auxId);
            persona_getNombre(array[i], auxNombre);
            fprintf(pArchivoBkp,"ID: %d - NOMBRE: %s", auxId, auxNombre);
        }
    }
    fclose(pArchivoBkp);
}

int main()
{
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];

    Persona* persona[1024];
    FILE *pArchivo;

    /*

    pArchivo = fopen("archivo.ext", "w");
    if(pArchivo != NULL)
    {
        fprintf(pArchivo, "%d,%s,%s\n", id,nombre,apellido);//imprimir archivo
        fclose(pArchivo);
    }
    else
    {
        printf("No se creo!");
    }

    pArchivo = fopen("archivo.ext", "r");
    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            fscanf(pArchivo,"%s", bufferApellido);
            printf("%s", bufferApellido);
        }
        fclose(pArchivo);

    }
    else
    {
        printf("No se creo!");
    }*/
    int size=0;
    int flagOnce=1;
    Persona* auxPersona;
    pArchivo = fopen("archivo.ext", "r");

    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            if(flagOnce)
            {
                fscanf(pArchivo,"%s", bufferId);
                flagOnce=0;
            }
            fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferApellido);
            auxPersona=persona_newConParametros(bufferId, bufferNombre, bufferApellido);
            if(auxPersona!=NULL)
            {
                persona[size]=auxPersona;
                size++;
            }
        }
        fclose(pArchivo);
        guardar(persona, size);
    }
    else
    {
        printf("No se creo!");
    }
    return 0;
}
