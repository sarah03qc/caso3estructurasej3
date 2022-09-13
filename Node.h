#include <iostream>

#ifndef NODEL 

#define NODEL 1

using namespace std;

template <class T>
class NodeL {
    private:
        T *data;
        NodeL *next;
        NodeL *previous;   
    
    public:
        NodeL() {
            data = NULL;
            next = NULL;
            previous = NULL;   
        }

        NodeL(T *pData) {
            this->data = pData;
            next = NULL;
            previous = NULL; 
        }

        T* getData() {
            return data;
        }

        NodeL* getNext() {
            return next;
        }

        NodeL* getPrevious() {    
            return previous;     
        }

        void setNext(NodeL *pValue) {
            this->next = pValue;
        }

        void setPrevious(NodeL *pValue) {   
            this->previous = pValue;          
        }
        
};

#endif