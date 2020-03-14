#ifndef Vuelos_h
#define Vuelos_h
#include <string>
#include "FechaHora.h"

using namespace std;

class Vuelos{
private:
    FechaHora fechaH;
    string vuelo;
    string aerolinea;
    string destino;
    string avion;
    int pasajeros;
    char es;
public:
    Vuelos();
    Vuelos(string avion, int pasajeros);
    Vuelos(FechaHora fechaH,string vuelo,char es,string aerolinea,string destino,string avion,int pasajeros);
    void setFechaH(FechaHora fechaH);
    void setVuelo(string vuelo);
    void setEs(char es);
    void setAerolinea(string aerolinea);
    void setDestino(string destino);
    void setAvion(string avion);
    void setPasajeros(int pasajeros);
    FechaHora getFechaH();
    string getVuelo();
    char getEs();
    string getAerolinea();
    string getDestino();
    string getAvion();
    int getPasajeros();
    void show();
};

Vuelos::Vuelos(){
    FechaHora c = FechaHora();
    fechaH = c;
    vuelo = "";
    es = ' ' ;
    aerolinea = "";
    destino = "";
    avion = "";
    pasajeros = 0;
}
Vuelos::Vuelos(string avion,int pasajeros){
    this->avion=avion;
    this->pasajeros=pasajeros;
}
Vuelos::Vuelos(FechaHora fechaH,string vuelo,char es, string aerolinea,string destino,string avion,int pasajeros){
    this->fechaH=fechaH;
    this->vuelo=vuelo;
    this->es=es;
    this->aerolinea=aerolinea;
    this->destino=destino;
    this->avion=avion;
    this->pasajeros=pasajeros;
}

void Vuelos::setFechaH(FechaHora fechaH){
    this->fechaH=fechaH;
}
void Vuelos::setVuelo(string vuelo){
    this->vuelo=vuelo;
}
void Vuelos::setEs(char es){
    this->es=es;
}
void Vuelos::setAerolinea(string aerolinea){
    this->aerolinea=aerolinea;
}
void Vuelos::setDestino(string destino){
    this->destino=destino;
}
void Vuelos::setAvion(string avion){
    this->avion=avion;
}
void Vuelos::setPasajeros(int pasajeros){
    this->pasajeros=pasajeros;
}

FechaHora Vuelos::getFechaH(){
    return fechaH;
}
string Vuelos::getVuelo(){
    return vuelo;
}
char Vuelos::getEs(){
    return es;
}
string Vuelos::getAerolinea(){
    return aerolinea;
}
string Vuelos::getDestino(){
    return destino;
}
string Vuelos::getAvion(){
    return avion;
}
int Vuelos::getPasajeros(){
    return pasajeros;
}



void Vuelos::show(){
    fechaH.show();
    cout << vuelo << es << aerolinea << destino << avion << pasajeros << endl;
}

#endif