#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{

    LinkedList* this= (LinkedList*)malloc(sizeof(LinkedList));
    if (this != NULL)//Si se consigue espacio en memoria:
    {   //Se inicializa el tamanio y puntero al primer nodo.
        this->pFirstNode= NULL; //Apunta a null por ser el 1ro.
        this->size=0; //No hay elementos en la lista.
    }
    return this;//Retorna null o puntero a estructura.
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int cantidadNodos = -1;

    if(this != NULL)
    {
        cantidadNodos = this->size; //tam
    }
    return cantidadNodos; //Retorna size, se actualiza cada vez que se agregue un nuevo nodo.
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList* this, int nodeIndex)
{

    Node* pNode = NULL;// Debe retornar un puntero a nodo, se declara variable del mismo tipo.
    if(this != NULL && nodeIndex >= 0 &&nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode; //Primer nodo

        //Iterar hasta el indice buscado.
        while(nodeIndex > 0)
        {
            pNode = pNode->pNextNode;
            nodeIndex--;//Que siga al nodo siguiente.
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
    int returnAux = -1;
    Node* nuevoNodo= NULL;
    Node* nodoAnterior= NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));
        if(nuevoNodo != NULL)
        {
            nuevoNodo->pElement = pElement;//Apunta al elemento, su carga(datos).
            nuevoNodo->pNextNode= NULL; //En caso de ser el ultimo que apunte a null

            if(nodeIndex == 0)//Si se lo quiere ubicar en el indice 0...
            {
                nuevoNodo->pNextNode = this->pFirstNode;//dm del 1er nodo.(en la Linkedlist).
                this->pFirstNode = nuevoNodo;// Se ubica el Newnodo en el 1er nodo.

            } else {
                        nodoAnterior= getNode(this, nodeIndex -1);//Se consigue la referencia del nodo anterior.

                        nuevoNodo->pNextNode = nodoAnterior->pNextNode;//Va a tener la referencia del q se quiere reemplazar.
                        nodoAnterior->pNextNode= nuevoNodo;//Que el nodo anterior apunte al nuevo nodo.
                    }

            this->size++; //Se incrementa el size por el nodo nuevo agregado.
            returnAux = 0;
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
 /* Agrega un elemento a la lista en el ultimo lugar de la lista.*/
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam;

    tam= ll_len(this);

    if(addNode(this,tam,pElement)==0)
    {
        returnAux=0; //exito
    }

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
    int tam;
    Node* auxNode=NULL;

    tam = ll_len(this);
    if(this != NULL && index >=0 && index < tam)
    {
       auxNode = getNode(this, index);
       if(auxNode != NULL)
       {
           returnAux = auxNode->pElement;
       }
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
 /*
 Modifica la carga del nodo que le paso por indice.
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode=NULL;
    int tam;

    tam= ll_len(this);

    if(this != NULL && index >= 0 && index < tam)
    {
        auxNode=getNode(this,index);//getNode devuelve el nodo donde se va a pisar el pElement
        if(auxNode !=NULL)
        {
            auxNode->pElement= pElement;
            returnAux=0;
        }
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

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* actualNodo;
    Node* anteriorNodo;
    int tam;

    tam= ll_len(this);

    if(this != NULL && index >=0 && index< tam)
    {

        actualNodo= getNode(this,index);//Se obtiene la d.m del 1er vagon.
        if(actualNodo !=NULL)
        {
            //Si el que se quiere remover es el 1er nodo..
            if(index ==0)
            {
                this->pFirstNode= actualNodo->pNextNode;
                this->size--;//Actualiza la cantidad
                free(actualNodo);
                returnAux =0; //exito.

            }
            else //Si es el resto de los nodos..
            {
                anteriorNodo= getNode(this,index - 1);
                if(anteriorNodo !=NULL)
                {
                    anteriorNodo->pNextNode = actualNodo->pNextNode;
                    this->size--;
                    free(actualNodo);
                    returnAux=0;//exito
                }
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
    int returnAux = -1;
    if(this !=NULL)
    {

        while (ll_len(this)!=0)
        {
            ll_remove(this,0);
        }
        returnAux=0;
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
    int returnAux = -1;

    if(this != NULL)
    {
        if(!ll_clear(this)) //Si pudo eliminar
        {
            free(this);
            returnAux=0;
        }

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
    int returnAux = -1;
    Node* auxNode=NULL;
    int tam;

    tam= ll_len(this);

    if(this != NULL)
    {
        for(int i=0; i < tam; i++)
        {
            auxNode= getNode(this,i);

            if(auxNode != NULL && (auxNode->pElement) == pElement)
               {
                   returnAux= i;
                   break;
               }

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
    int returnAux = -1;//error lista null
    if(this != NULL)
    {
        returnAux=0;//exito

        if(!ll_len(this))//ll_len==0
        {
            returnAux=1;//error lista vacia
        }
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
    int returnAux= -1;
    int tam;

    tam= ll_len(this);

    if(this != NULL && index >=0 && index <= tam)
    {
         returnAux = addNode(this,index, pElement);
    }

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
//Debe retornar el elemento antes de elimnar el nodo con el elemento adentro. 1ro retorna el pElemnt del nodo y despues lo elimina.
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    returnAux = ll_get(this,index);//Retorna dm del elemento(la carga)
    ll_remove(this,index);//Elimina el nodo.


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
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_indexOf(this,pElement)== -1)
        {
            returnAux=0;// no contiene el elemento.
        } else {
            returnAux=1; //Si encuentra el elemento con el indexOf -> exito.
        }
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
    //Se fije si los elementos de la 2da lista estan en la 1ra lista.
    int returnAux = -1;
    int tam;
    void* pElement;

    tam= ll_len(this2);

    if(this!= NULL && this2 != NULL)
    {
        returnAux =1;

        for(int i=0; i < tam; i++)
        {
            pElement = ll_get(this2,i);
            if(!ll_contains(this,pElement))
            {
                returnAux=0;//los elementos NO estan en la lista 1.
                break;
            }

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

//Devuelve un nuevo linkedList
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;
    int tam;

    tam =ll_len(this);

    if(this != NULL && from >= 0 && from < tam && to > from && to <= tam)
    {
        cloneArray = ll_newLinkedList();//Se pide espacio para la nuevaLinkedList

    	if(cloneArray != NULL)
    	{
    		for(int i = from; i < to; i++)
			{
    			pElement = ll_get(this, i);
    			ll_add(cloneArray, pElement);
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
    int tam;

    tam = ll_len(this);

    if (this != NULL)
    {
        //desde 0 hasta el tamanio de this
        cloneArray= ll_subList(this,0,tam);//Quiero una sublista del mismo tama que list.
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int tam;
    void* pElement1;
    void* pElement2;
    void* auxElement;

    tam = ll_len(this);
    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)&& tam > 0)
    {

        for(int i = 0; i < tam-1; i++)
        {

            for(int j = i+1; j < tam; j++)
            {
                pElement1 = ll_get(this,i);//Obtiene un elemento en el indice especificado.
                pElement2 = ll_get(this,j);//Obtiene un elemento en el indice especificado.

                if((pFunc(pElement1, pElement2) > 0 && order == 1))
                 {
                     auxElement= pElement1;
                     ll_set(this,i,pElement2); //copio el elemento 2 en el lugar del 1.
                     ll_set(this,j,auxElement); //copio el elemento 1 en el lugar del 2.
                 }
                 else if((pFunc(pElement1, pElement2) < 0 && order == 0))
                 {
                     auxElement= pElement1;
                     ll_set(this,i,pElement2); //copio el elemento 2 en el lugar del 1.
                     ll_set(this,j,auxElement); //copio el elemento 1 en el lugar del 2.
                 }

            }
        }
        returnAux = 0;
    }

    return returnAux;

}
/** \brief Filtra los elementos de la lista y retorna otra nueva
 *
 * \param lista a filtrar
 * \param funcion que sabe filtrar el elemento
 * \return Retorna un nuevo linkedList cargado con los elementos
 *
 */
LinkedList* ll_filter(LinkedList *this, int (*pFunc)(void*)) //Devuelve nueva lista filtrada.
{
	void *pElement;
	LinkedList* listaFiltrada = NULL;
	int tam;

	if (this != NULL && *pFunc != NULL) {

		listaFiltrada = ll_newLinkedList();
		if (listaFiltrada != NULL) {
			tam = ll_len(this); //Tamanio de la lista original.

			for (int i = 0; i < tam; i++) //Recorro la lista original.
            {
				pElement = ll_get(this, i);
				if (pFunc(pElement)==1) // Si cumple la condicion de pFunc retorna 1, entonces:
				{
					ll_add(listaFiltrada, pElement); //Se los agrega a la nueva listafiltrada.
				}
			}
		}
	}
	return listaFiltrada;
}

