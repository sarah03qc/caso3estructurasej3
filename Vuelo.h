#include<iostream>
#include<conio.h>
#include "Avion.h"
#include "Pista.h"    
#include<string>
#include<cstdlib>
#include <sstream>
#include <ctime>
using namespace std;

#ifndef VUELO

#define VUELO 1

class Vuelo {
    //clase vuelo

    private: 
        time_t flightTime; 

    public: 
        int vueloNUM;
        Avion avionDesignado;
        Pista pistaDesignada;
        
        string hour;
        string minutee;
        string completa;
        string completa2;
        int horaAsint;
        int contCuidar = 0;
        
        Vuelo(int pHour, int pMinutes) {
            //el constructor, genera una hora random y construye con esta cosas necesarias
            flightTime = time(NULL);
            tm *currentTime = localtime(&flightTime);
            currentTime->tm_hour = pHour;    //se cambia la hora por la especificada
            currentTime->tm_min = pMinutes;  //al igual que los minutos

            //construimos esto aca para tener acceso a las horas asignadas, pero se retorna en 
            //sus metodos correspondientes
            stringstream h;
            stringstream m;
            h << pHour;    //usamos stringstream para pasar de int a string
            m << pMinutes;

            if(h.str().size() == 1) {
                //significa que la hora es entre 0 y 9, por lo que hay que agregar un cero
                hour = "0" + h.str();    //lo juntamos en un string
            } else {
                //solo se pone normal
                hour = h.str();
            }
            if(m.str().size() == 1) {
                //significa que los minutos son entre 0 y 9, por lo que hay que agregar un cero
                minutee = "0" + m.str();
            } else {
                //solo se pone normal
                minutee = m.str();
            }
            completa = hour + ":" + minutee;  //para dar la string como hora
            completa2 = hour + minutee;     //para el metodo que representa hora como un int (luego se hara int)
        }

        string flightTimeString() {
            //retorna una string del tiempo asignado
            //se construyo antes, pero se le agregan cosas
            int year;
            int mes; 
            int day;
            string fecha;

            flightTime = time(NULL);
            tm *currentTime = localtime(&flightTime);

            year = currentTime->tm_year;
            mes = currentTime->tm_mon;
            day = currentTime->tm_mday;  

            year = 1900 + year; //para que sea exacto, como es desde 1900
            mes++;  //porque empiezan desde cero

            stringstream y;
            stringstream mo;
            stringstream d;
            y << year;    //usamos stringstream para pasar de int a string
            mo << mes;
            d << day;
            
            if(contCuidar == 0) {   //para que no se repita, porque estaba pasando
                fecha = d.str() + "/" + mo.str() + "/" + y.str();
                completa = completa + " de la fecha: " + fecha;
                contCuidar++;
            }
            
            return completa;
        }

        int getIntTimeValue() {
            stringstream convertir(completa2);
            convertir >> horaAsint;             //lo volvemos a convertir a entero y lo retornamos
            return horaAsint;   
        }

        void asignarAvion(Avion avionNew) {
            //metodo que asigna avion
            avionDesignado = avionNew; //se asigna
            cout << "Avion " << avionNew.getID() << " asignado a vuelo" << endl;
        }

        void asignarPista(Pista pistaNew) {
            //metodo que asigna pista
            if(pistaNew.disponibilidad == 0) {
                //significa que esta disponible
                pistaDesignada = pistaNew; //se asigna
                cout << "Pista " << pistaNew.getID() << " asignada al vuelo" << endl;
            } else {
                cout << "Elija una pista disponible." << endl;
            }
            
        }

        void setID(int iden) {
            //poner identificador
            vueloNUM = iden;
        }
};

#endif