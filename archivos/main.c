#include <stdio.h>
#include <stdlib.h>

int main()
{
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
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

    pArchivo = fopen("archivo.ext", "r");
    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            fscanf(pArchivo,"%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferApellido);
            printf("Id; %s  Apellido:%s  Nombre:%s", bufferId, bufferApellido, bufferNombre);
        }
        fclose(pArchivo);

    }
    else
    {
        printf("No se creo!");
    }
    return 0;
}
