#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Vuelos.h"
#include "FechaHora.h"
#include "Descripcion.h"

int main(){

    FechaHora fecha;
    string fechaStr;
    string horaStr;
    string vuelo;
    char es;  // Entrada a salida
    string aerolinea;
    string destino;
    string avion;
    int pasajeros;
    int capacidad;
    int horas[24]={0};
    int anoAnt=0;  // Para validar si cambio la fecha
    int mesAnt=0;
    int diaAnt=0;
    int cantidadDias=0;
    int cantidadVuelos=0;
    FechaHora datosVuelos[5000];
    int total1=0;
    int total2=0;
    int opc=0;
    Descripcion aviones[13];
    Vuelos datosVuelosT[5000];
    int totalPasajeros=0;
    FechaHora fechaH;
    int horaAnt=0;
    int cantidadAviones=0;

    cout << "Menu:" << endl;
    cout << "1. Hora con mayor saturacion de cada dia." << endl;
    cout << "2. Cantidad de llegadas por hora promedio." << endl;
    cout << "3. Candidad de salidas por hora promedio." << endl;
    cout << "4. Cantidad de llegadas y salidas por aerolinea." << endl;
    cout << "5. Cantidad de pasajeros atendidos por dia." << endl;
    cout << "6. Porcentaje promedio de capacidad en los aviones." << endl;
    cout << "7. Cantidad de pasajeros por aerolinea promedio." << endl;
    cin >> opc;
    while(opc!=8){
        fstream archivo;
        archivo.open("datos_vuelos.txt");
        while (archivo >> fechaStr >> horaStr >> vuelo >> es >> aerolinea >> destino >> avion >> pasajeros){
            fechaStr = fechaStr+" "+horaStr;
            fechaH=FechaHora(fechaStr);
            datosVuelosT[cantidadVuelos]=Vuelos(fechaH,vuelo,es,aerolinea,destino,avion,pasajeros);
            cantidadVuelos++;
            totalPasajeros+=pasajeros;
        }
        archivo.close();
        archivo.open("aviones.txt");
        while (archivo >> avion >> capacidad){
            aviones[cantidadAviones]=Descripcion(avion,capacidad);
            cantidadAviones++;
        }
        archivo.close();
        if (opc==1){
            int dias[5]={0};
            int f=0;
            int saturacion[5][24]={0};
            int maxAnt[5]={0};
            int horaSat[5]={0};

            for (int i=0; i < cantidadVuelos; i++){
                if (anoAnt != datosVuelosT[i].getFechaH().getAno() || mesAnt != datosVuelosT[i].getFechaH().getMes() || diaAnt != datosVuelosT[i].getFechaH().getDia()){
                    //cout << "Fecha: " << datosVuelos[cantidadVuelos].getAno() << " Mes: " << datosVuelos[cantidadVuelos].getMes() << " Dia: " << datosVuelos[cantidadVuelos].getDia() << endl;
                    if (diaAnt != datosVuelosT[i].getFechaH().getDia()){
                        dias[f]=datosVuelosT[i].getFechaH().getDia();
                        cantidadDias++;
                        f++;
                    }
                    anoAnt = datosVuelosT[i].getFechaH().getAno();
                    mesAnt = datosVuelosT[i].getFechaH().getMes();
                    diaAnt = datosVuelosT[i].getFechaH().getDia();
                }
                if (diaAnt == datosVuelosT[i].getFechaH().getDia()){
                    saturacion[f-1][datosVuelosT[i].getFechaH().getHora()]+=pasajeros;
                }
                if (maxAnt[f-1] < saturacion[f-1][datosVuelosT[i].getFechaH().getHora()]){
                    maxAnt[f-1]=saturacion[f-1][datosVuelosT[i].getFechaH().getHora()];
                    horaSat[f-1]=datosVuelosT[i].getFechaH().getHora();
                }
               /* if (datosVuelos[].getDia()==13){
                    pasajerosDias[0]+=pasajeros;
                }*/
            }
            /*for (int i=0; i<f;i++){
                cout << horaSat[i] << endl;
            }*/
            for (int i=0; i<f; i++){
                cout << "Dia: " << i+9 << " Hora: " << horaSat[i] << " Pasajeros: " << maxAnt[i] << endl;
            }
            
        }

        if (opc==2){
            cantidadVuelos=0;
            cantidadDias=0;
            horas[24]={0};
            ifstream archivo;
            archivo.open("datos_vuelos.txt");
            while (archivo >> fechaStr >> horaStr >> vuelo >> es >> aerolinea >> destino >> avion >> pasajeros){
                fechaStr = fechaStr + " " + horaStr;
                datosVuelos[cantidadVuelos] = FechaHora(fechaStr);
                

                if (anoAnt != datosVuelos[cantidadVuelos].getAno() || mesAnt != datosVuelos[cantidadVuelos].getMes() || diaAnt != datosVuelos[cantidadVuelos].getDia()){
                    //cout << "Fecha: " << datosVuelos[cantidadVuelos].getAno() << " Mes: " << datosVuelos[cantidadVuelos].getMes() << " Dia: " << datosVuelos[cantidadVuelos].getDia() << endl;
                    if (diaAnt != datosVuelos[cantidadVuelos].getDia()){
                        cantidadDias++;
                    }
                    anoAnt = datosVuelos[cantidadVuelos].getAno();
                    mesAnt = datosVuelos[cantidadVuelos].getMes();
                    diaAnt = datosVuelos[cantidadVuelos].getDia();
                }
                if (es == 'A'){
                    horas[datosVuelos[cantidadVuelos].getHora()]++;
                }
                cantidadVuelos++;
            }

            archivo.close();

            for (int i=0; i<24; i++){
                cout << "Hora: " << i <<"-"<< "Vuelos: " << horas[i] << " Promedio: " << double(horas[i])/cantidadDias * 1.0 << endl; 
                total1 += horas[i];          
            }
            //cout << total1 << endl;

        }

        if (opc==3){
            cantidadVuelos=0;
            cantidadDias=0;
            horas[24]={0};
            ifstream archivo;
            archivo.open("datos_vuelos.txt");
            while (archivo >> fechaStr >> horaStr >> vuelo >> es >> aerolinea >> destino >> avion >> pasajeros){
                fechaStr = fechaStr + " " + horaStr;
                datosVuelos[cantidadVuelos] = FechaHora(fechaStr);
                
                if (anoAnt != datosVuelos[cantidadVuelos].getAno() || mesAnt != datosVuelos[cantidadVuelos].getMes() || diaAnt != datosVuelos[cantidadVuelos].getDia()){
                    cout << "Fecha: " << datosVuelos[cantidadVuelos].getAno() << " Mes: " << datosVuelos[cantidadVuelos].getMes() << " Dia: " << datosVuelos[cantidadVuelos].getDia() << endl;
                    if (diaAnt != datosVuelos[cantidadVuelos].getDia()){
                        cantidadDias++;
                    }
                    anoAnt = datosVuelos[cantidadVuelos].getAno();
                    mesAnt = datosVuelos[cantidadVuelos].getMes();
                    diaAnt = datosVuelos[cantidadVuelos].getDia();
                }
                if (es == 'S'){
                    horas[datosVuelos[cantidadVuelos].getHora()]++;
                }
                cantidadVuelos++;
            }

            archivo.close();

            for (int i=0; i<24; i++){
                cout << "Hora: " << i <<"-"<< "Vuelos: " << horas[i] << " Promedio: " << double(horas[i])/cantidadDias * 1.0 << endl; 
                total2 += horas[i];          
            }
            //cout << total2 << endl;

        }

        if (opc==4){
            int aerolineas[13][2]={0};
            cantidadAviones=0;
            string aerolineaAnt[1000];
            int aero=0;
            
            fstream archivo;
            archivo.open("datos_vuelos.txt");
            while (archivo >> fechaStr >> horaStr >> vuelo >> es >> aerolinea >> destino >> avion >> pasajeros){
                fechaStr = fechaStr+" "+horaStr;
                fechaH=FechaHora(fechaStr);
                datosVuelosT[cantidadVuelos]=Vuelos(fechaH,vuelo,es,aerolinea,destino,avion,pasajeros);
                
                if (aerolineaAnt[aero] != datosVuelosT[cantidadVuelos].getAerolinea()){
                    aerolineaAnt[aero]=datosVuelosT[cantidadVuelos].getAerolinea();
                    aero++;
                }
                
                
                
                cantidadVuelos++;
            }
            cout << aero << endl;
        }
        
        if (opc==5){
            cantidadVuelos=0;
            cantidadDias=0;
            horas[24]={0};
            int pasajerosDias[5]={0};
            ifstream archivo;
            archivo.open("datos_vuelos.txt");
            while (archivo >> fechaStr >> horaStr >> vuelo >> es >> aerolinea >> destino >> avion >> pasajeros){
                fechaStr = fechaStr + " " + horaStr;
                datosVuelos[cantidadVuelos] = FechaHora(fechaStr);
                
                if (anoAnt != datosVuelos[cantidadVuelos].getAno() || mesAnt != datosVuelos[cantidadVuelos].getMes() || diaAnt != datosVuelos[cantidadVuelos].getDia()){
                    if (diaAnt != datosVuelos[cantidadVuelos].getDia()){
                        cantidadDias++;
                    }
                    anoAnt = datosVuelos[cantidadVuelos].getAno();
                    mesAnt = datosVuelos[cantidadVuelos].getMes();
                    diaAnt = datosVuelos[cantidadVuelos].getDia();
                }
                
                if (datosVuelos[cantidadVuelos].getDia()==13){
                    pasajerosDias[0]+=pasajeros;
                }
               
                pasajerosDias[cantidadDias]+=pasajeros;
                totalPasajeros+=pasajeros;
                cantidadVuelos++;
            }

            archivo.close();
            for (int i=0; i<cantidadDias; i++){
                cout << "Dia " << i+9 << " Pasajeros: " << pasajerosDias[i] << endl; 
            }
                          
        }

        if (opc==6){

        }

        if (opc==7){
            int cantidadAviones =0;
            string avion;
            int capacidad;
            fstream archivo;
            archivo.open("aviones.txt");
            while (archivo >> avion >> capacidad){
            aviones[cantidadAviones]=Descripcion(avion,capacidad);
            cantidadAviones++;
            }
            for (int i=0; i<13; i++){
                cout << "Aerolinea: " << aviones[i].getNombreAvion() << " Promedio: " << double(totalPasajeros/cantidadAviones) << endl;
            }
            
        }
       
        cout << "Menu:" << endl;
        cout << "1. Hora con mayor saturacion de cada dia." << endl;
        cout << "2. Cantidad de llegadas por hora promedio." << endl;
        cout << "3. Candidad de salidas por hora promedio." << endl;
        cout << "4. Cantidad de llegadas y salidas por aerolinea." << endl;
        cout << "5. Cantidad de pasajeros atendidos por dia." << endl;
        cout << "6. Porcentaje promedio de capacidad en los aviones." << endl;
        cout << "7. Cantidad de pasajeros por aerolinea promedio." << endl;
        cout << "8. Salir" << endl;
        cin >> opc;
        archivo.close();
    }
    
    return 0;
}