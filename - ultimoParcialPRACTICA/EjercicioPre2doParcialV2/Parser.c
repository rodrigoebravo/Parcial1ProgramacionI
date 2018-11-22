#include "LinkedList.h"
#include "utn.h"
#include "Empleado.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* listaEmpleados);
int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    int retorno=ERROR;
    FILE* pFile;

    pFile=fopen(fileName, "r");
    if(pFile!=NULL)
        retorno=parser_EmployeeFromText(pFile, listaEmpleados);
    fclose(pFile);

    return retorno;
}


int parser_EmployeeFromText(FILE* pFile , LinkedList* listaEmpleados)
{
    char bufferInt[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    int retorno=ERROR;
    int flagOnce=TRUE;
    Empleado* pEmpleado;
    char linea[1024];

    if(pFile != NULL && listaEmpleados!=NULL)
    {
        retorno=TODOOK;

        printf("Procesando archivo...\n");

        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce=FALSE;
                fscanf(pFile, "%s", linea);
                strcpy(bufferInt,strtok(linea, ","));
                strcpy(bufferNombre,strtok(NULL, ","));
                strcpy(bufferHorasTrabajadas,strtok(NULL, "\n"));
                //printf("%s,%s,%s\n", bufferInt, bufferNombre, bufferHorasTrabajadas);
                continue;
                //fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
            }
            //fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferInt, bufferNombre, bufferHorasTrabajadas, bufferSueldo);

            fscanf(pFile, "%s", linea);
            strcpy(bufferInt,strtok(linea, ","));
            strcpy(bufferNombre,strtok(NULL, ","));
            strcpy(bufferHorasTrabajadas,strtok(NULL, "\n"));
            printf("%s,%s,%s\n", bufferInt, bufferNombre, bufferHorasTrabajadas);
            pEmpleado=Empleado_newConParametros(bufferInt, bufferNombre, bufferHorasTrabajadas);
            if(pEmpleado!=NULL)
            {
                ll_add(listaEmpleados, pEmpleado);
                Empleado_print(pEmpleado);
            }
            //printf("%s,%s,%s,%s\n", bufferInt, bufferNombre, bufferHorasTrabajadas,bufferSueldo);
            //
        }
        printf("Archivo cargado exitosamente\n");
    }
    return retorno;
}
