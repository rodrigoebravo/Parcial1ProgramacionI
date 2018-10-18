
#define ENTEROS 3
#include "empleado.h"
//#include "service.h"
//#include "user.h"
void ordenar(void* lista[], int limite, int(*comparar)(void*,void*));
/*int inicializar(int* pBuffer, int len, int valor);
int mostrarArray(int* pBuffer, int len);
int* newArray(int size);
int deleteArray(int* pBuffer);
int* redimencionarArray(int* pBuffer, int size);*/
int main()
{
    /*int* pBuffer;
    pBuffer=newArray(ENTEROS);
    inicializar(pBuffer, ENTEROS, 1024);
    mostrarArray(pBuffer, ENTEROS);
    //deleteArray(pBuffer);
    pBuffer=redimencionarArray(pBuffer, ENTEROS+5);*/
    //inicializar(pBuffer, ENTEROS+5, 1);
    //mostrarArray(pBuffer, ENTEROS+5);

    /* malloc
    int *a;
    int i;
    a = (int *) malloc (sizeof(int) * 20);
    if(a != NULL)
    {
        for(i=0; i<20;i++)
            *(a+i) = 0;
    }*/
    //realloc
    /*int *a;
    int *pAux;
    a = (int *) malloc (sizeof(int) * 20);
    pAux = (int *) realloc (a , sizeof(int) * 200);

    if(pAux != NULL)
        a = pAux;
    */
    Empleado* listaEmpleados[1000];
    int qtyEmpleados=0;
    char auxiliar[50];
    for(int i=0; i<100;i++)
    {
        sprintf(auxiliar, "Juan_%d", i);
        listaEmpleados[i]=empleado_newParametros(auxiliar, "Perez", 1.45);
        qtyEmpleados++;
    }

    ordenar((void*)listaEmpleados, qtyEmpleados, empleado_compareNombre);

    for(int i=0; i<qtyEmpleados;i++)
    {
        empleado_print(listaEmpleados[i]);
    }


    //c_function_qsort.html
    /*Service* listaService[1000];
    int qtyService=0;
    char auxiliar[50];

    for(int i=0; i<100;i++)
    {
        sprintf(auxiliar, "NOT FOUND_%d", i);
        listaService[i]=service_newParametros(i, auxiliar);
        qtyService++;
    }
    for(int i=0; i<qtyService;i++)
    {
        service_print(listaService[i]);
    }*/

    /*
    User* listaUser[1000];
    int qtyUser=0;
    char auxiliarName[50];
    char auxiliarEmail[50];

    for(int i=0; i<100;i++)
    {
        sprintf(auxiliarName, "Jose Hernandez_%d", i);
        sprintf(auxiliarEmail, "jose_%d@gmail.com", i);
        listaUser[i]=user_newParametros(auxiliarName, auxiliarEmail);
        qtyUser++;
    }
    for(int i=0; i<qtyUser;i++)
    {
        user_print(listaUser[i]);
    }
    */
    return 0;
}
/*int inicializar(int* pBuffer, int len, int valor)
{
    int i;
    int retorno=ERROR;
    if(pBuffer!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            *(pBuffer+i)=valor;
        }
        retorno=TODOOK;
    }
    return retorno;
}

int* newArray(int size)
{
    int* retorno=NULL;
    int* pBufferAux;
    if(size>0)
    {
        pBufferAux=(int *) malloc(sizeof(int) * size);
        if(pBufferAux!=NULL)
        {
            retorno=pBufferAux;
        }
    }
    return retorno;
}

int mostrarArray(int* pBuffer, int len)
{
    int i, retorno=ERROR;
    if(pBuffer!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            printf("posicion: %d, valor: %d\n", i, *(pBuffer+i));
        }
    }
    return retorno;
}

int deleteArray(int* pBuffer)
{
    int retorno=ERROR;
    if(pBuffer!=NULL)
    {
        free(pBuffer);
        retorno=TODOOK;
    }
    return retorno;
}

int* redimencionarArray(int* pBuffer, int size)
{
    int* retorno=NULL;
    printf("--->%p",pBuffer);
    if(pBuffer!=NULL && size>0)
    {
        retorno = (int *) realloc(pBuffer , sizeof(int) * size);
    }
    return retorno;
}
*/

void ordenar(void* lista[], int limite, int(*comparar)(void*,void*))
{
    int flagSwap, i;
    void* auxiliarPuntero;

    do
    {
        flagSwap=FALSE;
        for(i=0;i<limite-1;i++)
        {
            if(comparar(lista[i], lista[i+1]))
            {
                auxiliarPuntero=lista[i];
                lista[i]=lista[i+1];
                lista[i+1]=auxiliarPuntero;
                flagSwap=TRUE;
            }
        }
    }while(flagSwap);
}
