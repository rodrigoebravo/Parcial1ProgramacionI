#include <stdio.h>
#include <stdlib.h>
#define ENTEROS 3
#define ERROR -1
#define TODOOK 0
int inicializar(int* pBuffer, int len, int valor);
int mostrarArray(int* pBuffer, int len);
int* newArray(int size);
int deleteArray(int* pBuffer);
int* redimencionarArray(int* pBuffer, int size);
int main()
{
    int* pBuffer;
    pBuffer=newArray(ENTEROS);
    inicializar(pBuffer, ENTEROS, 1024);
    mostrarArray(pBuffer, ENTEROS);
    deleteArray(pBuffer);
    pBuffer=redimencionarArray(pBuffer, ENTEROS+5);
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
    return 0;
}
int inicializar(int* pBuffer, int len, int valor)
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
    int* pAux;
    int* retorno=NULL;
    printf("--->%p",pBuffer);
    if(pBuffer!=NULL && size>0)
    {
        pAux = (int *) realloc (pBuffer , sizeof(int) * size);

        if(pAux != NULL)
        {
            retorno = pAux;
        }
    }
    return retorno;
}
