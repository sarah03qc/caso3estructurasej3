#include <iostream>

#ifndef NODE

#define NODE 1

using namespace std;

template <class T>
class Node {
    private:
        T *data;
        Node *next;
    
    public:

        int prioridad;

        Node() {
            data = NULL;
            next = NULL;
            prioridad = 0;
        }

        Node(T* pData, int laPrioridad) {   
            this->data = pData;
            next = NULL;
            prioridad = laPrioridad;
        }

        T* getData() {
            return data;   
        }

        int getPrioridad() {
            return prioridad;
        }

        Node* getNext() {
            return next;
        }

        void setNext(Node *pValue) {
            this->next = pValue;
        }
};

#endif