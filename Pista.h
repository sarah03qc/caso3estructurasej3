#include<iostream>
#include<conio.h>
//#include "Avion.h"
#include "ColaPriori.h"  
//#include "Vuelo.h"   
#include<string>
using namespace std;


#ifndef PISTA 

#define PISTA 1

class Pista {
    //clase pista
    public: 
        int disponibilidad = 0;   //0 siendo desocupada y 1 siendo ocupada, esta inicializada como desocupada
        int idPista;  

        void setID(int iden) {
            //el identificador
            idPista = iden;
        }

        void setDisponi(int disp) {
            disponibilidad = disp;
        }

        int getDisponi() {
            return disponibilidad;
        }

        int getID() {
            return idPista;
        }
    
};

#endif