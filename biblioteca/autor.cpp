/* CORREGIDO: versi�n completa y consistente del proyecto */
#include <iostream>

#include "autor.h"
#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

Autor::Autor(){
    idAutor = 0;
    strcpy(nacionalidad,"");
    cantidadObras = 0;
    eliminado = false;
}

int Autor::getIdAutor() const { return idAutor; }
bool Autor::getEliminado() const { return eliminado; }

void Autor::setNacionalidad(const char* n){ strncpy(nacionalidad,n,29); nacionalidad[29]=0; }
void Autor::setCantidadObras(int c){ cantidadObras = c; }

void Autor::cargar(){
    idAutomatico();
    Persona::cargar();
    cout << "Nacionalidad: ";
    cin.getline(nacionalidad,30);
    cout << "Cantidad de obras: ";
    cin >> cantidadObras;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    eliminado = false;
}

void Autor::mostrar() const{
    if(!eliminado){
        cout << "ID Autor: " << idAutor << " | ";
        Persona::mostrar();
        cout << " | Nacionalidad: " << nacionalidad << " | Obras: " << cantidadObras << endl;
    }
}

// archivo
bool Autor::guardar(){
    FILE *p = fopen("autores.dat","ab");
    if(!p) return false;
    fwrite(this,sizeof(Autor),1,p);
    fclose(p);
    return true;
}
bool Autor::leer(int pos){
    FILE *p = fopen("autores.dat","rb");
    if(!p) return false;
    fseek(p, pos * sizeof(Autor), 0);
    bool ok = fread(this,sizeof(Autor),1,p);
    fclose(p);
    return ok;
}
void Autor::buscar(int id){
    Autor a;
    FILE *p = fopen("autores.dat","rb");
    if(!p) { cout << "No hay autores.\n"; return; }
    while(fread(&a,sizeof(Autor),1,p)){
        if(!a.getEliminado() && a.getIdAutor() == id){
            a.mostrar();
            fclose(p);
            return;
        }
    }
    fclose(p);
    cout << "Autor no encontrado.\n";
}
void Autor::idAutomatico(){
    Autor a;
    idAutor = 1;
    int id = 1, pos = 0;
    while(a.leer(pos++)){
        id++;
        if(a.getIdAutor() != id){
            idAutor = id;
        }
    }
}
