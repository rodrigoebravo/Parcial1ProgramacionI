#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "lib.h"
static int emp_buscarIndiceVacio(Employee* pBuffer,int limite,int*indice);
int emp_inicializarArray(Employee* pBuffer,int limite){
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i].isEmpty=1;
    }
    return 0;
}
int emp_obtenerID(){
    static int ID=0;
    return ID++;
}
static int emp_buscarIndiceVacio(Employee* pBuffer,int limite,int*indice){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==1){
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int emp_alta(Employee* pBuffer,int id,int limite,char* name,char* lastName,float salary,int sector){
    int indice;
    if(emp_buscarIndiceVacio(pBuffer,limite,&indice)==0){
        pBuffer[indice].id=id;
        pBuffer[indice].isEmpty=0;
        strcpy(pBuffer[indice].lastname,lastName);
        strcpy(pBuffer[indice].name,name);
        pBuffer[indice].salary=salary;
        pBuffer[indice].sector=sector;
    }
    return 0;
}
int emp_modificarById(Employee* pBuffer,int limite,int id){
    int i;
    int auxSector,opcion;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for (i=0;i<limite;i++){
            if(pBuffer[i].id==id&& pBuffer[i].isEmpty==0){
                retorno=0;
                if(utn_getEntero(&opcion,3,"\n1-Modificar nombre\n2-Modificar Apellido\n3-Modificar salario\n4-Modificar sector\nINGRESE UNA OPCION: ","ERROR...Ingrese una opcion valida",1,4)==0){
                    switch (opcion){
                        case 1:
                            if(utn_getLetras(auxName,CANTIDADEMPLOYEES,3,"\nIngrese el nombre: ","\nError...Ingrese un nombre valido")==0){
                                strcpy(pBuffer[i].name,auxName);
                            }
                            break;
                        case 2:
                            if(utn_getLetras(auxLastName,CANTIDADEMPLOYEES,3,"\nIngrese el apellido: ","\nError...Ingrese un apellido valido")==0){
                                strncpy(pBuffer[i].lastname,auxLastName,51);
                            }
                            break;
                        case 3:
                            if(utn_getFloat(&auxSalary,3,"\nIngrese el salario: ","\nError...Ingrese un salario valio",0,999999)==0){
                                pBuffer[i].salary=auxSalary;
                            }
                            break;
                        case 4:
                            if(utn_getEntero(&auxSector,3,"\nIngrese el sector: ","\nError...Ingrese un sector valido",1,3)==0){
                                pBuffer[i].sector=auxSector;
                            }
                            break;
                    }
                }
                break;
            }
        }
    }
    return retorno;
}
int emp_borrarbyId(Employee* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==0&& pBuffer[i].id==id){
            pBuffer[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}
int emp_swap(Employee* pBuffer,int indiceDestino,int indiceOrigen){
    Employee aux[1];
    if(pBuffer!=NULL && indiceDestino!=indiceOrigen){
        strcpy(aux[0].lastname,pBuffer[indiceDestino].lastname);
        strcpy(aux[0].name,pBuffer[indiceDestino].name);
        aux[0].id=pBuffer[indiceDestino].id;
        aux[0].isEmpty=pBuffer[indiceDestino].isEmpty;
        aux[0].salary=pBuffer[indiceDestino].salary;
        aux[0].sector=pBuffer[indiceDestino].sector;

        strcpy(pBuffer[indiceDestino].lastname,pBuffer[indiceOrigen].lastname);
        strcpy(pBuffer[indiceDestino].name,pBuffer[indiceOrigen].name);
        pBuffer[indiceDestino].salary=pBuffer[indiceOrigen].salary;
        pBuffer[indiceDestino].id=pBuffer[indiceOrigen].id;
        pBuffer[indiceDestino].sector=pBuffer[indiceOrigen].sector;
        pBuffer[indiceDestino].isEmpty=pBuffer[indiceOrigen].isEmpty;

        strcpy(pBuffer[indiceOrigen].lastname,aux[0].lastname);
        strcpy(pBuffer[indiceOrigen].name,aux[0].name);
        pBuffer[indiceOrigen].salary=aux[0].salary;
        pBuffer[indiceOrigen].id=aux[0].id;
        pBuffer[indiceOrigen].sector=aux[0].sector;
        pBuffer[indiceOrigen].isEmpty=aux[0].isEmpty;
    }
    return 0;
}
int emp_ordenarByLastNameOrSector(Employee* pBuffer,int limite,int flag){
    int i;
    int flagOrden=1;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0&&(flag==0||flag==1)){
        while(flagOrden==1){
            flagOrden=0;
            for(i=0;i<(limite-1);i++){
                if((flag== 0 &&strcmp(pBuffer[i].lastname,pBuffer[i+1].lastname)<0)||
                    (flag==1&& strcmp(pBuffer[i].lastname,pBuffer[i+1].lastname)>0)){
                        emp_swap(pBuffer,i,i+1);
                        flagOrden=1;
                        retorno=0;
                }else
                if(strcmp(pBuffer[i].lastname,pBuffer[i+1].lastname)==0&&(
                    (flag== 0 && pBuffer[i].sector<pBuffer[i+1].sector)||
                    (flag== 1 && pBuffer[i].sector>pBuffer[i+1].sector))){
                        flagOrden=1;
                        retorno=0;
                        emp_swap(pBuffer,i,i+1);
                }
            }
        }
    }
    return retorno;
}
int emp_totalPromedioYMayoresAlPromedio(Employee* pbuffer,int limite,int*cantidadMayor,float*total,float*promedio){
    int i;
    int contador=0;
    float acumulador=0;
    if(pbuffer!=NULL&&limite>0&&cantidadMayor!=NULL&&total!=NULL&&promedio!=NULL){
        for(i=0;i<limite;i++){
            if(pbuffer[i].isEmpty==0){
                acumulador+=pbuffer[i].salary;
                contador++;
            }
        }
        *total=acumulador;
        *promedio=acumulador/contador;
        contador=0;
        for(i=0;i<limite;i++){
            if(pbuffer[i].isEmpty==0&& pbuffer[i].salary>*promedio){
                contador++;
            }
        }
    }
    *cantidadMayor=contador;
    return 0;
}
int emp_imprimir(Employee* pBuffer,int limite){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0){
                retorno=0;
                printf("\nID: %d",pBuffer[i].id);
                printf("\tNombre: %s",pBuffer[i].name);
                printf("\tApellido: %s",pBuffer[i].lastname);
                printf("\tSalario %.2f",pBuffer[i].salary);
                printf("\tSector: %d",pBuffer[i].sector);
            }
        }
    }
    return retorno;
}
