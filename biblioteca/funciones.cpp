#include <iostream>

#include <iostream>
#include <cstring>
#include <cstdio>
#include "libros.h"
#include "Socio.h"
#include "Prestamo.h"
using namespace std;

void menuLibros() {
    int op;
    do {
        cout << "\n--- MENU LIBROS ---\n";
        cout << "1. Alta\n";
        cout << "2. Listar\n";
        cout << "3. Baja Logica\n";
        cout << "4. Buscar por ID\n";
        cout << "5. Buscar por Autor\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        switch (op) {
            case 1: {
                Libros obj;
                obj.idAutomatico();
                obj.cargar();
                obj.guardar();
                break;
            }

            case 2: {
                Libros obj;
                int pos = 0;
                while (obj.leer(pos++)) {
                    obj.mostrar();
                }
                break;
            }

            case 3: {
                int id;
                cout << "Ingrese ID libro a eliminar: ";
                cin >> id;
                Libros obj;
                int pos = 0;
                while (obj.leer(pos)) {
                    if (obj.getIdLibro() == id && !obj.getEliminado()) {
                        obj.setEliminado(true);
                        obj.modificar(pos);
                        cout << "Libro dado de baja.\n";
                        break;
                    }
                    pos++;
                }
                break;
            }

            case 4: {
                int id;
                cout << "Ingrese ID del libro a buscar: ";
                cin >> id;
                Libros obj;
                obj.buscar(id);
                break;
            }
             case 5: {
                Libros obj;
                obj. buscarPorAutor();
                break;
            }
            case 0:
                cout << "Volviendo al menú principal...\n";
                break;

            default:
                cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }

    } while (op != 0);
}

void menuSocios() {
    int op;
    do {
        cout << "\n--- MENU SOCIOS ---\n";
        cout << "1. Alta\n";
        cout << "2. Listar\n";
        cout << "3. Baja Logica\n";
        cout << "4. Buscar por ID\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        switch (op) {
            case 1: {
                Socio obj;
                obj.idAutomatico();
                obj.cargar();
                obj.guardar();
                break;
            }

            case 2: {
                Socio obj;
                int pos = 0;
                while (obj.leer(pos++)){
                        if(!obj.getEliminado()){
                            obj.mostrar();
                        }
                }
                break;
            }

            case 3: {
                int id;
                cout << "Ingrese ID socio a eliminar: ";
                cin >> id;
                Socio obj;
                int pos = 0;
                while (obj.leer(pos)) {
                    if (obj.getIdSocio() == id && !obj.getEliminado()) {
                        cout<<"Esta seguro que desea eliminar al socio: "<<endl;
                        obj.mostrar();
                        cout<<"1 - Eliminar"<<endl;
                        cout<<"0 - Volver"<<endl;
                        bool f;
                        int tecla;
                        cin>>tecla;
                        while (f){
                            if (tecla == 1){
                                    obj.setEliminado(true);
                                    obj.modificar(pos);
                                    cout << "Socio dado de baja.\n";
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
                break;
            }

            case 4: {
                int id;
                cout << "Ingrese ID del socio a buscar: ";
                cin >> id;
                Socio obj;
                obj.buscar(id);
                break;
            }

            case 0:
                cout << "Volviendo al menú principal...\n";
                break;

            default:
                cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }

    } while (op != 0);
}

void menuPrestamos() {
    int op;
    do {
        cout << "\n--- MENU PRESTAMOS ---\n";
        cout << "1. Alta\n";
        cout << "2. Listar\n";
        cout << "3. Buscar por ID de prestamo\n";
        cout << "4. Historial por año\n";
        cout << "5. Historial por mes\n";
        cout << "6. Devolucion\n";
        cout << "7. Buscar préstamo por ID de libro\n";
        cout << "8. Buscar préstamo por nombre de socio\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        switch (op) {

            case 1: {
                Prestamo obj;
                obj.idAutomatico();
                obj.cargar();
                obj.guardar();
                break;
            }

            case 2: {
                Prestamo obj;
                int pos = 0;
                while (obj.leer(pos++)) {
                    if (obj.getActivo()) {
                        obj.mostrar();
                    }
                }
                break;
            }

            case 3: {
                int id;
                Prestamo obj;
                cout << "Ingrese ID del préstamo: ";
                cin >> id;
                obj.buscar(id);
                break;
            }

            case 4: {
                int anio;
                Prestamo obj;
                cout << "Ingrese año del préstamo: ";
                cin >> anio;
                obj.buscaranio(anio);
                break;
            }

            case 5: {
                Prestamo obj;
                obj.historial();
                break;
            }

            case 6: {
                Prestamo obj;
                obj.devolucion();
                break;
            }

            case 7: {
                Prestamo obj;
                obj.buscarPorIdLibro();
                break;
            }

            case 8: {
                Prestamo obj;
                obj.buscarPorNombreSocio();
                break;
            }

            case 0:
                cout << "Volviendo al menú principal...\n";
                break;

            default:
                cout << "Opción inválida. Intente nuevamente.\n";
                break;
        }

    } while (op != 0);
}
