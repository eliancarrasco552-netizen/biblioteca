#include <iostream>
#include <string>

#include <iostream>
#include <cstdio>
#include <limits>
#include "funciones.h"
#include "Prestamo.h"
#include "libros.h"
#include "socio.h"
using namespace std;


void Prestamo::cargar() {
    cout << "ID Socio: "; cin >> idSocio;
    Socio soc;
    int posSoc = 0;
    bool encontradoSoc = false;
    bool encontradoLib = false;
    while (soc.leer(posSoc)){
            if (soc.getIdSocio()==idSocio){
                encontradoSoc = true;
                cout << "ID Libro: "; cin >> idLibro;
                Libros lib;
                int posLib = 0;
                while (lib.leer(posLib)){
                        if (lib.getIdLibro()==idLibro){
                            encontradoLib = true;
                            if (lib.getStock()>0 ){
                                    idAutomatico();
                                    cout << "Fecha Prestamo: \n"; fechaPrestamo.cargar();
                                    cout << "Fecha Devolucion: \n"; fechaDevolucion.cargardo();
                                    int stock = lib.getStock() - 1;
                                    lib.setStock(stock);
                                    lib.modificar(posLib);
                                    activo = true;
                                    cout<<"Se ingreso el prestamo con exito"<<endl;
                                    guardar();
                            }
                            else{
                                cout<<"No hay stock"<<endl;
                                break;
                            }
                        }
                        posLib++;
                }
            }
            posSoc++;
    }
    if(!encontradoLib){
            cout<<"No Existe el libro"<<endl;
                            }
    if (!encontradoSoc){
                cout<<"No existe el socio"<<endl;
    }
}
void Prestamo::mostrar() const {
    cout << "Prestamo ID: " << idPrestamo
         << " | Socio: " << idSocio
         << " | Libro: " << idLibro
         << " | Prestado: "; fechaPrestamo.mostrar();
    cout << " | Devuelto: "; fechaDevolucion.mostrar();
    cout << endl;
}

/// Archivo
bool Prestamo::guardar() {
    FILE *p = fopen("prestamos.dat", "ab");
    if (p == NULL) return false;
    fwrite(this, sizeof(Prestamo), 1, p);
    fclose(p);
    return true;
}
void Prestamo::buscar(int id){
    bool comprobado=false;
    Prestamo prestamo;
    FILE *p =fopen("prestamos.dat","rb");
    while (fread(&prestamo,sizeof(prestamo),1,p)){
        if(prestamo.getIdPrestamo()==id){
            prestamo.mostrar();
            comprobado=true;
        }

    }

     if (comprobado==false){cout<<"no existe id"<<endl;}
    fclose(p);
}
bool Prestamo::leer(int pos) {
    FILE *p = fopen("prestamos.dat", "rb");
    if (p == NULL) return false;
    fseek(p, pos * sizeof(Prestamo), 0);
    bool leyo = fread(this, sizeof(Prestamo), 1, p);
    fclose(p);
    return leyo;
}
void Prestamo::buscaranio(int num){
int cont=0;
bool comprobado=false;
    Prestamo prestamo;
    FILE *p =fopen("prestamos.dat","rb");
    while (fread(&prestamo,sizeof(prestamo),1,p)){
        if(prestamo.fechaPrestamo.getanio()==num){
            prestamo.mostrar();
            comprobado=true;
            cont=cont+1;
        }

    }
    cout<<"la cantidad de prestamos registrada es: "<<cont<<endl;
     if (comprobado==false){cout<<"no existen prestamos registrados"<<endl;}
    fclose(p);



}
void Prestamo::idAutomatico(){
    Prestamo prestamo;
    idPrestamo=1;
    int id=1;
    int pos=0;
    while (leer(pos++)){
        id++;
        if(prestamo.getIdPrestamo()!=id){
            idPrestamo=id;
        }
    }
}
void Prestamo::historial(){
    string nombremeses[12]={"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    Prestamo prestamo;
    Fecha fecha;
    FILE *p =fopen("prestamos.dat","rb");

    for (int contmes = 0 ;contmes<12 ;contmes++){
             int cont=0;
             fseek(p, 0,SEEK_SET);
    cout<<"================================================================"<<endl;
        while (fread(&prestamo,sizeof(prestamo),1,p)){
            if(prestamo.fechaPrestamo.getmes()==contmes+1){
            prestamo.mostrar();
            cont=cont+1;
        }

    }
     cout<<"la cantidad de libros prestados en el mes de "<<nombremeses[contmes]<< " fueron de "<<cont<<endl;



}
fclose(p);}
void Prestamo::devolucion(){


/// ===============================
/// BUSCAR PRESTAMO POR ID DE LIBRO
/// ===============================

void Prestamo::buscarPorIdLibro() {
    int idBuscado;
    cout << "INGRESE EL ID DEL LIBRO: ";
    cin >> idBuscado;

    Prestamo reg;
    FILE *p = fopen("prestamos.dat", "rb");
    if(p == NULL){
        cout << "NO SE PUDO ABRIR EL ARCHIVO prestamos.dat" << endl;
        return;
    }

    bool encontrado = false;

    while(fread(&reg, sizeof(Prestamo), 1, p)){
        if(reg.idLibro == idBuscado){   /// acceso directo a la propiedad
            cout << "\n--- PRESTAMO ENCONTRADO ---\n";
            reg.mostrar();
            encontrado = true;
        }
    }

    fclose(p);

    if(!encontrado){
        cout << "NO SE ENCONTRARON PRESTAMOS PARA ESE LIBRO." << endl;
    }
}


/// ===================================
/// BUSCAR PRESTAMO POR NOMBRE DE SOCIO
/// ===================================

void Prestamo::buscarPorNombreSocio() {

    char nombre[50];
    cout << "INGRESE EL NOMBRE DEL SOCIO: ";
    cin.ignore();
    cin.getline(nombre, 50);

    Socio s;
    Prestamo p;

    /// 1) Buscar el ID del socio por nombre
    int idSocioBuscado = -1;
    FILE *fs = fopen("socios.dat", "rb");
    if(fs == NULL){
        cout << "NO SE PUDO ABRIR socios.dat" << endl;
        return;
    }

    while(fread(&s, sizeof(Socio), 1, fs)){
        if(strcmp(s.getNombre(), nombre) == 0){
            idSocioBuscado = s.getIdSocio();
            break;
        }
    }

    fclose(fs);

    if(idSocioBuscado == -1){
        cout << "NO EXISTE UN SOCIO CON ESE NOMBRE." << endl;
        return;
    }

    /// 2) Buscar pr�stamos con ese ID de socio
    FILE *fp = fopen("prestamos.dat", "rb");
    if(fp == NULL){
        cout << "NO SE PUDO ABRIR prestamos.dat" << endl;
        return;
    }

    bool encontrado = false;

    while(fread(&p, sizeof(Prestamo), 1, fp)){
        if(p.idSocio == idSocioBuscado){
            cout << "\n--- PRESTAMO DEL SOCIO ---\n";
            p.mostrar();
            encontrado = true;
        }
    }

    fclose(fp);

    if(!encontrado){
        cout << "EL SOCIO NO TIENE PRESTAMOS REGISTRADOS." << endl;
    }
}
    int idDevolucion;
    cout<<"Ingrese id prestamo Devuelto"<<endl;
    cin>>idDevolucion;
    int pos=0;
     while (leer(pos)) {
                    if (getIdPrestamo() == idDevolucion) {
                        cout<<"Esta seguro que desea devoldver el prestamo: "<<endl;
                        mostrar();
                        cout<<"1 - Devolver"<<endl;
                        cout<<"0 - Volver"<<endl;
                        bool f = true;
                        int tecla;
                        cin>>tecla;
                        while (f){
                            if (tecla == 1){
                                    activo= false;
                                    cout << "Devolucion registrada.\n";
                                    f = false;
                            }
                            else{
                                cout<<"Opcion incorrecta"<<endl;
                            }
                        }
                        break;
                    }
                    pos++;
                }
}
