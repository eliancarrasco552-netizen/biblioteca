
#include <iostream>

#include "persona.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <limits>

using namespace std;

Persona::Persona() {
    strcpy(nombre, "");
    strcpy(apellido, "");
    strcpy(mail, "");
    strcpy(pais, "");
}

void Persona::cargar() {
    cout << "Nombre: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(nombre, 30);
    cout << "Apellido: ";
    cin.getline(apellido, 30);
    cout << "Mail: ";
    cin.getline(mail, 50);
    cout << "Pais: ";
    cin.getline(pais, 30);
}

void Persona::mostrar() const {
    cout << nombre << " " << apellido << " | " << mail << " | " << pais;
}

void Persona::setNombre(const char* n){ strncpy(nombre,n,29); nombre[29]=0; }
void Persona::setApellido(const char* a){ strncpy(apellido,a,29); apellido[29]=0; }
void Persona::setMail(const char* m){ strncpy(mail,m,49); mail[49]=0; }
void Persona::setPais(const char* p){ strncpy(pais,p,29); pais[29]=0; }
