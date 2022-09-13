#include<iostream>
#include<conio.h>   
#include<string>
using namespace std;


#ifndef AVION

#define AVION 1

class Avion {
    //clase avion
    public: 
        int id;

        void setID(int iden) {
            //poner identificador
            id = iden;
        }

        int getID() {
            return id;
        }
};

#endif