#ifndef Descripcion_h
#define Descripcion_h
#include <string>
using namespace std;

class Descripcion{
private:
    string nombreAvion;
    int capacidadMax;
public:
    Descripcion();
    Descripcion(string nombreAvion, int capacidadMax);
    void setNombreAvion(string nombreAvion);
    void setCapacidadMax(int capacidadMax);
    string getNombreAvion();
    int getCapacidadMax();
    void show();
};

Descripcion::Descripcion(){
    nombreAvion="";
    capacidadMax=0;
}
Descripcion::Descripcion(string nombreAvion, int capacidadMax){
    this->nombreAvion=nombreAvion;
    this->capacidadMax=capacidadMax;
}

void Descripcion::setNombreAvion(string nombreAvion){
    this->nombreAvion=nombreAvion;
}
void Descripcion::setCapacidadMax(int capacidadMax){
    this->capacidadMax=capacidadMax;
}

string Descripcion::getNombreAvion(){
    return nombreAvion;
}
int Descripcion::getCapacidadMax(){
    return capacidadMax;
}

void Descripcion::show(){
    cout <<"Avion " <<  nombreAvion<<" capacidad " << capacidadMax << endl;
}
#endif 