#include <iostream>
#include <fstream>

#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <limits>
#include "Libros.h"

using namespace std;

void Libros::cargar() {
    bool entro = false;
    Libros lib;
    lib.idAutomatico();
    cout << "Titulo: "; cin.getline(titulo, 50);
    cout << "Autor: "; cin.getline(autor, 30);
    cout << "Editorial: "; cin.getline(editorial, 30);
    cout << "Stock: "; cin>>stock;
    fechaalta.cargar();
    eliminado = false;
}
void Libros::mostrar() const {
    if (!eliminado) {
        cout << "ID: " << idLibro
             << " | Titulo: " << titulo
             << " | Autor: " << autor
             << " | Editorial: " << editorial
             << " | Fecha de alta "; fechaalta.mostrar();
             cout << " | Stock " << stock <<endl;
    }
}
void Libros::buscar(int id){
    bool comprobado = false;
    Libros libro;
    FILE *p =fopen("libros.dat","rb");
    while (fread(&libro,sizeof(libro),1,p)){
        if(libro.getIdLibro()==id){
            libro.mostrar();
            comprobado=true;;
        }
    }

     if (comprobado==false){
        cout<<"no existe id"<<endl;
    }
    fclose(p);
}
/// Archivo
bool Libros::guardar() {
    FILE *p = fopen("libros.dat", "ab");
    if (p == NULL) return false;
    fwrite(this, sizeof(Libros), 1, p);
    fclose(p);
    return true;
}
bool Libros::leer(int pos) {
    FILE *p = fopen("libros.dat", "rb");
    if (p == NULL) return false;
    fseek(p, pos * sizeof(Libros), 0);
    bool leyo = fread(this, sizeof(Libros), 1, p);
    fclose(p);
    return leyo;
}
bool Libros::modificar(int pos) {
    FILE *p = fopen("libros.dat", "rb+");
    if (p == NULL) return false;
    fseek(p, pos * sizeof(Libros), 0);
    bool ok = fwrite(this, sizeof(Libros), 1, p);
    fclose(p);
    return ok;
}
bool Libros::existeId(int id) {
    Libros libro;
    FILE *p = fopen("libros.dat", "rb");
    if (p == NULL) return false;

    while (fread(&libro, sizeof(Libros), 1, p)) {
        if (!libro.getEliminado() && libro.getIdLibro() == id) {
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}
void Libros::buscarPorAutor() {

    int cont=0;
    char autorBuscado[30];
    cout << "Ingrese el nombre del autor a buscar: ";

    cin.getline(autorBuscado, 30);


    FILE *p = fopen("libros.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo de libros.\n";
        return;
    }

    Libros reg;
    bool encontrado = false;

    cout << "\n=== RESULTADOS DE LA BUSQUEDA ===\n";
    while (fread(&reg, sizeof(Libros), 1, p) == 1) {
        if (strstr(reg.getAutor(), autorBuscado) != NULL) {
            reg.mostrar();
            encontrado = true;
            cont=cont+1;
        }
    }
    cout<<"cantidad de libro de ese autor: "<<cont<<endl;
    if (!encontrado) {
        cout << "\nNo se encontraron libros de ese autor.\n";
    }

    fclose(p);
}
void Libros::idAutomatico(){
    Libros lib;
    idLibro=1;
    int id=1;
    int pos=0;
    while (leer(pos++)){
        id++;
        if(lib.getIdLibro()!=id){
            idLibro=id;
        }
    }
}
