#include "LinkedList.h"
#include <string.h>
int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    int retorno=0;
    FILE* pFile;
    char buffer[120];
    Employee* pEmpleado;
    if(fileName!= NULL && listaEmpleados!=NULL){
        pFile=fopen(fileName,"r");
        if(pFile!=NULL){
            fgets(buffer,sizeof(buffer),pFile);
            do{
                pEmpleado=Employee_new();
                buffer=strtok(pFile,",");
                Employee_setId(pEmpleado,(int)buffer);
                buffer=strtok(pFile,",");
                Employee_setNombre(pEmpleado,buffer);
                buffer=strtok(pFile,",");
                Employee_setHorasTrabajadas(pEmpleado,(int)buffer);
            }while(!feof(pFile));
            retorno=1;
        }
    }
    return retorno; // OK
}

