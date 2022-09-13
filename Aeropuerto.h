
#include<iostream>
#include<conio.h>
#include "Avion.h"
#include "Pista.h"  
#include "Vuelo.h"   
#include "ColaPriori.h" 
#include "List.h" 
#include<string>
#include <time.h>
using namespace std;

#ifndef AEROPUERTO

#define AEROPUERTO 1

class Aeropuerto {
    //clase aeropuerto
    public: 
        ColaPriori<Vuelo>* colap1 = new ColaPriori<Vuelo>();    //creo una cola de vuelos

        List<ColaPriori<Vuelo>>* lista = new List<ColaPriori<Vuelo>>();  //creamos lista de colas, cada elemento
                                                                     //de la lista debe ser una cola de vuelos
                                                                    //por una pista determinada

        void fillFlights(int pCantidad, int pStartHour, int pEndHour, Pista pista) { 
            //este metodo crea una tanda de vuelos en horas aleatorias (pero no iguales) dentro de un rango, para
            //una pista determinada y le asigna un avion a cada vuelo
            int horaSalida;
            int minutoSalida;
            if(pista.getDisponi() == 1) {  //para revisar que la pista dada este desocupada
                //siginifica que esta ocupada
                cout << "\nSeleccione una pista desocupada, o desocupe la seleccionada." << endl;
            } else {
                //si la pista dada esta desocupada
                
                cout << "\nCreando " << pCantidad << " de vuelos, en rango de: " << pStartHour << " a " << pEndHour << endl;
                cout << "\n";
                pEndHour++;   //porque sino el rango se genera hasta uno menos que el maximo recibido
                srand((unsigned) time(NULL));   //la semilla
                int idcontar = 0;
                while(pCantidad > 0) {
                    //ciclo para crear pCantidad de vuelos
                    horaSalida = rand() % (pEndHour - pStartHour) + pStartHour; //el rango de hora, sacado por el min y el max
                    //ahora minutos
                    int max = 43;
                    int min = 17;
                    minutoSalida = rand() % (max - min) + min;     //el rango de minutos debe tomar en cuenta 17 para atras y delante (posible atraso)

                    Vuelo *vuelo = new Vuelo(horaSalida, minutoSalida);
                    Avion avion;  
                    avion.setID(idcontar);    //le damos id al avion
                    idcontar++;
                    vuelo->asignarAvion(avion);  //asiganmos un avion al vuelo
                    vuelo->asignarPista(pista);
 
                    int contad = 0;  //ahora hay que tomar en cuenta que no sea la misma hora
                    while(contad < colap1->getSize()) {
                        //se hace loop para poder revisar todos los elementos bien
                        for(int i = 0; i < colap1->getSize(); i++) {
                            //iteramos a traves de la lista para tener cuidado de que los vuelos 
                            //no tengan el mismo tiempo de salida, si lo hacen se modifica
                            Vuelo *currentElement = colap1->find(i);
            
                            int elIntdeI = currentElement->getIntTimeValue(); //guardamos el valor int del elemento i
                            int intActual = vuelo->getIntTimeValue();  //igual con el vuelo actual
                            if(intActual == elIntdeI) {
                                //si es la misma que otra hora, se cambia
                                minutoSalida = rand() % (max - min) + min;
                            }
                        }
                        contad++; 
                    }
                    colap1->enqueue(vuelo, vuelo->getIntTimeValue());   //despues ya agregamos el vuelo 
                    cout << "\nVuelo creado a las: " << vuelo->flightTimeString() << " y el entero es: " << vuelo->getIntTimeValue() << endl;
                    cout << "  " << endl;
                    pCantidad--;
                }
    
                lista->add(colap1);  //le agregamos la cola de vuelos finalizada a la lista de colas

                int contID = 0;
                while(colap1->getSize() > contID) {
                    colap1->find(contID)->setID(contID);
                    cout << "Se asigna numero #" << colap1->find(contID)->vueloNUM << " al vuelo de: " << colap1->find(contID)->flightTimeString() << endl;
                    contID++;
                }
            }
            //ahora para despegar los vuelos de esta pista
            int aDespegar = 0;
            while(colap1->getSize() > 0) {
                //se van quitando de la cola conforme despegan
                //mientras que la cola de vuelos de la pista deseada aun tenga vuelos...
                cout << "\nVuelo #" << colap1->find(aDespegar)->vueloNUM << " ha despegado a las: " << colap1->find(aDespegar)->flightTimeString() << " en la pista: " << pista.getID() << endl;
                colap1->dequeue();  //...se siguen despegando
            }
        }
};

#endif