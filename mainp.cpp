
#include<iostream>
#include<conio.h>
#include "Avion.h"
#include "Pista.h"  
#include "Vuelo.h"
#include "Aeropuerto.h"   
#include "ColaPriori.h"
#include<string>

using namespace std;

int main() {

    Pista pista1;  //se crea una pista, (se pueden crear la cantidad k que se desee aca y asignar a V vuelos en 
                   //                    el metodo fillFlights de Aeropuerto.h)

    pista1.setDisponi(1);    //0 siendo desocupada y 1 siendo ocupada, (aunque ya esta desocupada por default 
                             //                                         cuando se crea)
    pista1.setID(0);


    Aeropuerto aereo1;  //se crea un aeropuerto
    aereo1.fillFlights(6, 9, 19, pista1);   //va a darnos una advertencia por usar pista ocupada

    cout << "\nLa desocupamos" << endl;
    pista1.setDisponi(0); //la desocupamos e intentamos de nuevo
    aereo1.fillFlights(6, 9, 19, pista1);

    //Se puede probrar crear mas de cualquier cosa, ya sean A aeropuertos, K pistas, tandas de V vuelos en una pista,
    //y cambiar los rangos de horas 

    return 0;
}
