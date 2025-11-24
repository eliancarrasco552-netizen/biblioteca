#include <iostream>

#include <iostream>
#include "Fecha.h"
#include <ctime>
using namespace std;

/*void Fecha::cargar() {
    cout << "Dia: "; cin >> dia;
    cout << "Mes: "; cin >> mes;
    cout << "Anio: "; cin >> anio;
}*/

void Fecha::mostrar() const {
    cout << dia << "/" << mes << "/" << anio;
}

int Fecha::getanio()const{return anio;}
int Fecha::getmes()const{return mes;}

void Fecha::cargar(){
    time_t now=time(0);
    tm *t =localtime(&now);
     dia=t->tm_mday;
     mes=t->tm_mon+1;
     anio=t->tm_year+1900;
}

void Fecha::cargardo(){
    time_t now=time(0);
    tm *t =localtime(&now);
     dia=t->tm_mday;

     mes=t->tm_mon+4;

     anio=t->tm_year+1900;

     if (mes==13){
        mes=1;
        anio+=1;

     }
}
