#include "NodeQueue.h"


#ifndef COLA 

#define COLA 1

template <class T>
class ColaPriori {

    private:
        Node<T> *frente;
        Node<T> *end;
        Node<T> *aux;
        Node<T> *posiBuscar;
        Node<T> *antesPosiBuscar;
        Node<T> *searchPosition;
        int quantity;

    public:
        ColaPriori() {
            frente = NULL;
            end = NULL;
            posiBuscar = NULL;
            antesPosiBuscar = NULL;
            searchPosition = NULL;
            quantity = 0;
        }

        void enqueue(T* pData, int pPrioridad) {
            Node<T> *newNode = new Node(pData, pPrioridad);  //creamos espacio en memoria para almacenar nodo
            newNode->setNext(NULL);  //hacemos que apunte a null
            if(frente == NULL) {
                //si esta  vacia
                this->frente = newNode;
                this->end = newNode;
            } else {
                //si ya hay mas nodos
               // end->setNext(newNode); //el sig se hace el nuevo  YYYYYYYYYYYYYYYYYYYYYYY
               if(pPrioridad < this->frente->getPrioridad()) {
                //vemos si la prioridad del nodo actual es menor que la del primero
                newNode->setNext(this->frente);  //ponemos el nuevo que apunte al primero
                this->frente = newNode;  //y nombramos el nuevo como frente
               } else if(pPrioridad >= this->end->getPrioridad()) {
                //si la prioridad del nodo actual es mayor o igual a la del final
                this->end->setNext(newNode);  //ponemos el siguiente del ultimo como el nuevo
                this->end = newNode;   //y asi lo nombramos
                this->end->setNext(NULL); //el final apunta a null
               } else {
                //en caso de que la prioridad este en el 'medio'
                posiBuscar = this->frente;
                antesPosiBuscar = posiBuscar;
                posiBuscar = this->frente->getNext(); 
                while(posiBuscar != NULL) {
                    //para recorrer el queue
                    if(posiBuscar->getPrioridad() > pPrioridad) {
                        //si la prioridad del nodo nuevo es menor que la de la posicion que 
                        //estamos recorriendo
                        newNode->setNext(posiBuscar);   //lo ponemos al nuevo antes de la posicion
                        antesPosiBuscar->setNext(newNode);  //y el anterior a la posicion apunta a el nuevo
                        break;
                    } else {
                        //si la priori del newnode es mayor que la de la posicion
                        posiBuscar = posiBuscar->getNext();
                        antesPosiBuscar = antesPosiBuscar->getNext();
                    }
                }
               }
            }
            quantity++;
        }    

        Node<T>* first() {
            return this->frente;
        }

        int getSize() {
            return quantity;
        }

        bool isEmpty() {
            return !frente;
        }

        T* front() {
            return frente->getData();
        }

        T* find(int pPosition) {
            T* result = NULL;
            searchPosition = this->frente;

            if(pPosition < quantity) {     
                while(pPosition > 0) {  
                    
                    searchPosition = searchPosition->getNext();   
                    
                    pPosition--;
                }
                result = searchPosition->getData();
            }
            return result;
        }

        void dequeue() {

            Node<T> *aux = frente;

            if(quantity == 1) {
                //si solo tiene un nodo
                frente = NULL;
                end = NULL;
            } else{
                //si hay mas de uno
                frente = aux->getNext();
            }

            delete aux;
            quantity--;
        }

};

#endif
