#ifndef FechaHora_h
#define FechaHora_h
#include <string>

using namespace std;

class FechaHora{
private:
	int hora;
	int min;
	int ano;
	int mes;
	int dia;
public:
	FechaHora();
	FechaHora(string fechaHora);
	void setHora(int hora);
	void setMin(int min);
	void setAno(int ano);
	void setMes(int mes);
	void setDia(int dia);
	int getHora();
	int getMin();
	int getAno();
	int getMes();
	int getDia();
	void show();
};

FechaHora::FechaHora(){
	hora=0;
	min=0;
	ano=0;
	mes=0;
	dia=0;
}
FechaHora::FechaHora(string FechaHora){
	hora=stoi(FechaHora.substr(11,2));
	min=stoi(FechaHora.substr(14,2));
	ano=stoi(FechaHora.substr(0,4));
	mes=stoi(FechaHora.substr(5,2));
	dia=stoi(FechaHora.substr(8,2));
}



void FechaHora::setHora(int hora){
	this->hora=hora;
}
void FechaHora::setMin(int min){
	this->min=min;
}
void FechaHora::setAno(int ano){
	this->ano=ano;
}
void FechaHora::setMes(int mes){
	this->mes=mes;
}
void FechaHora::setDia(int dia){
	this->dia=dia;
}
int FechaHora::getHora(){
	return hora;
}
int FechaHora::getMin(){
	return min;
}
int FechaHora::getAno(){
	return ano;
}
int FechaHora::getMes(){
	return mes;
}
int FechaHora::getDia(){
	return dia;
}

void FechaHora::show(){
	cout << "Fecha y hora: " << ano << "/"<< mes << "/" << dia << " "  << hora << ":" << min;
}

#endif
