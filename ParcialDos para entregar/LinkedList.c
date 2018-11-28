#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#define ERROR -1
#define TODOOK 0
#define TRUE 1
#define FALSE 0


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = ERROR;

    if(this!=NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int lenList, i;

    lenList=ll_len(this);
    if(this!=NULL && nodeIndex>=0 && nodeIndex<lenList)
    {

        pNode=this->pFirstNode;
        for(i=0;i<nodeIndex;i++)
        {
            pNode=pNode->pNextNode;
        }
    }
    return pNode;
}


/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = ERROR;
    Node* pNewNode= malloc(sizeof(Node));
    Node* pNode= NULL;

    pNewNode->pElement=pElement;

    if(this!= NULL && nodeIndex>=0 && nodeIndex<= this->size && pNewNode!= NULL)
    {
        if(nodeIndex==0)
        {

            pNewNode->pNextNode=this->pFirstNode;
            this->pFirstNode=pNewNode;
            this->size++;
            returnAux=TODOOK;
        }
        else
        {
            pNode=getNode(this,nodeIndex-1);
            pNewNode->pNextNode=pNode->pNextNode;
            pNode->pNextNode=pNewNode;
            this->size++;
            returnAux=TODOOK;
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = ERROR;

    if(this!=NULL)
        returnAux = addNode(this, this->size, pElement);

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;

    if(this!=NULL && index>=0 && index<(this->size))
    {
        pNode = getNode(this, index);
        if(pNode!=NULL)
            returnAux=pNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = ERROR;
    Node* pNode;
    if(this!=NULL && index>=0 &&index<this->size)
    {
        returnAux = TODOOK;
        pNode=getNode(this, index);
        if(pNode!=NULL)
            pNode->pElement=pElement;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)//TODO: VER Y CAMBIAR!!!!!!!!!!!
{
    int returnAux = ERROR;
    Node *pNodeA, *pNodeB;
    if(this!= NULL && index>=0 && index<this->size)
    {
        returnAux=TODOOK;
        if(this->size==1)
        {
            this->pFirstNode=NULL;
            this->size--;
            free(getNode(this,index));
        }
        else if(index==0)
        {
            pNodeA=getNode(this,index);
            this->pFirstNode=pNodeA->pNextNode;
            this->size--;
            free(pNodeA);
        }
        else
        {
            pNodeA=getNode(this,index);
            if(pNodeA!=NULL)
            {
                pNodeB=getNode(this,index-1);
                pNodeB->pNextNode=pNodeA->pNextNode;
                this->size--;
                free(pNodeA);
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{

    int returnAux = ERROR;
    Node* pNodoA;
    Node* pNodoB;
    int i, size;

    if(this!=NULL)
    {
        size=this->size;
        if(size==0)
        {
            returnAux=TODOOK;
        }
        else
        {
            for(i=0;i<size;i--)
            {
                pNodoA=getNode(this, i);

                if(pNodoA!=NULL)
                {
                    pNodoB=pNodoA->pNextNode;
                    free(pNodoA);
                }
            }
            free(pNodoB);
            returnAux=TODOOK;
        }
        this->size=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = ERROR;

    if(ll_clear(this)==TODOOK)
    {
        free(this);
        returnAux=TODOOK;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = ERROR;
    Node* pNode;
    int i;

    if(this!=NULL)
    {
        pNode=this->pFirstNode;
        for(i=0; i<this->size;i++)
        {
            if(pNode!=NULL && pNode->pElement==pElement)
            {
                returnAux=i;
                break;
            }
            pNode=pNode->pNextNode;
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux=ERROR;

    if(this!=NULL)
    {
        if(this->size==0)
            returnAux=TRUE;
        else
            returnAux=FALSE;
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux=ERROR;
    if(this!=NULL && index>=0 && index<=this->size)
        returnAux=addNode(this, index, pElement);
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index<=this->size)
    {
        returnAux=ll_get(this, index);
        ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = ERROR;

    if(this!=NULL)
    {
        if(ll_indexOf(this, pElement)!=ERROR)
            returnAux=TRUE;
        else
            returnAux=FALSE;
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux=ERROR;
    int i;
    int contElementosIguales=0;
    void* pElementAux;

    if(this!=NULL && this2!=NULL)
    {

        returnAux=FALSE;
        if(this->size>=this2->size)
        {

            if(this==this2)
            {
                returnAux=TRUE;
            }
            else
            {
                for(i=0;i<this2->size;i++)
                {
                    pElementAux=ll_get(this2, i);
                    if(ll_contains(this,pElementAux)==TRUE)
                    {
                        contElementosIguales++;
                        continue;
                    }
                }
            }
            if(contElementosIguales==this2->size)
                returnAux=TRUE;
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNode;
    int i;
    int posicionEnNuevaLista=0;

    if(this!=NULL && from>=0 && to<=this->size)
    {
        cloneArray=ll_newLinkedList();
        for(i=from;i<to;i++)
        {
            pNode=getNode(this, i);
            if(pNode!=NULL)
            {
                addNode(cloneArray, posicionEnNuevaLista, pNode->pElement);
                posicionEnNuevaLista++;
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
        cloneArray=ll_subList(this, 0, this->size);

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux, i, flagOrden;
    void* pElementAux;
    Node* pNode;
    Node* pNextNode;

    returnAux=ERROR;

    if(this!=NULL && pFunc!= NULL && this->size>0 && (order==1 || order==0))
    {
        do{
            flagOrden=FALSE;
            pNode=this->pFirstNode;

            if(pNode!=NULL)
            {
                pNextNode=pNode->pNextNode;
                for(i=0;i<(this->size-1);i++)
                {
                    if((pFunc(pNode->pElement, pNextNode->pElement) ==1 && order==1) ||
                        (pFunc(pNode->pElement, pNextNode->pElement)==-1 && order==0))
                    {
                        pElementAux=pNode->pElement;
                        pNode->pElement=pNextNode->pElement;
                        pNextNode->pElement=pElementAux;
                        flagOrden=TRUE;
                    }
                    if(pNextNode->pNextNode==NULL)
                        break;
                    else
                        pNode=pNextNode;

                    pNextNode=pNode->pNextNode;
                }
            }
        }while(flagOrden);
        returnAux=TODOOK;
    }
    return returnAux;
}

/** \brief Crea una lista nueva que contiene todos aquellos elementos que el criterio permitio
 * \param this LinkedList* Puntero a la lista
 * \param int* func(void*) Puntero a la funcion criterio
 * \return LinkedList* NULL en caso de ERROR o ausencia de datos, o la lista con los elementos
 */
LinkedList* ll_filter(LinkedList* this, int* func(void*))
{
    LinkedList* pThisReturn;
    Node* pNode;
    int i;
    if(this!=NULL && func!=NULL)
    {
        pThisReturn=ll_newLinkedList();
        for(i=0;i<this->size;i++)
        {
            pNode=ll_get(this, i);
            if(pNode!=NULL && func(pNode->pElement))
                ll_add(pThisReturn, pNode);
        }
    }
    return pThisReturn;
}

/**\brief Asigna a el nodo pIteratorNode, variable de la estructura LinkedList, el primer valor de la lista LinkedList a iterar.
 * \param this LinkedList* Puntero a la lista
 * \return void* el Node* pFirstNode de la lista.
 */
void* ll_startIteration(LinkedList* this)
{
    Node* pNodeReturn;
    if(this!=NULL)
    {
        this->pIteratorNode=this->pFirstNode;
        pNodeReturn=this->pIteratorNode;
    }
    return pNodeReturn;
}

void* ll_getNextNode(LinkedList* this)
{
    Node* pNode;
    if(this!=NULL)
    {
        pNode=this->pIteratorNode;
        this->pIteratorNode=pNode->pNextNode;
        return this->pIteratorNode;
    }
    return NULL;
}


void ll_Mapper(LinkedList* this, int func(void*))
{
    Node* pNodeAux;
    if(this!=NULL && func!=NULL)
    {
        pNodeAux=ll_startIteration(this);
        if(pNodeAux!=NULL)
        {
            do{
                func(pNodeAux->pElement);
                pNodeAux=ll_getNextNode(this);
            }while(pNodeAux!=NULL);
        }
    }
}

/*int ll_count(LinkedList* this, int func(void*, void*), void* valorCriterio)
{
    Node* pNodeAux;
    int contadorSegunFunc=0;
    int hayError=TRUE;

    if(this!=NULL && func!=NULL)
    {
        hayError=FALSE;
        pNodeAux=ll_startIteration(this);
        if(pNodeAux!=NULL)
        {
            do{
                contadorSegunFunc+=func(pNodeAux->pElement, valorCriterio);
                pNodeAux=ll_getNextNode(this);
            }while(pNodeAux!=NULL);
        }
    }
    if(hayError)
        return ERROR;
    return contadorSegunFunc;
}*/

int ll_count(LinkedList* this, int func(void*))
{
    Node* pNodeAux;
    int contadorSegunFunc=0;
    int hayError=TRUE;

    if(this!=NULL && func!=NULL)
    {
        hayError=FALSE;
        pNodeAux=ll_startIteration(this);
        if(pNodeAux!=NULL)
        {
            do{
                contadorSegunFunc+=func(pNodeAux->pElement);
                pNodeAux=ll_getNextNode(this);
            }while(pNodeAux!=NULL);
        }
    }
    if(hayError)
        return ERROR;
    return contadorSegunFunc;
}
