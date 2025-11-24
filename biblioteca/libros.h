#ifndef LIBROS_H_
#define LIBROS_H_

#include <string>

#ifndef LIBROS_H
#define LIBROS_H
#include"fecha.h"
#include <cstring>
#include <cstdio>
#include <string>
class Libros {
private:
    int idLibro;
    char titulo[50];
    char autor[30];
    char editorial[30];
    int stock;
    bool eliminado;
    Fecha fechaalta;
public:

   //metodos
    void cargar();
    void mostrar() const;

    //getters

    int getIdLibro() const { return idLibro; }
    int getStock() const { return stock; }
    bool getEliminado() const { return eliminado; }
    const char* getAutor() const { return autor; }
    //setters
    void setEliminado(bool e) { eliminado = e; }
    void setStock(int s) { stock = s; }
    void buscar (int id);
    void buscarPorAutor();

    /// Manejo de archivo
    bool guardar();
    bool leer(int pos);
    bool modificar(int pos);
    bool existeId(int id);
    void idAutomatico();
    void cargarLibrosDesdeTexto();
};

#endif // LIBROS_H

#endif // LIBROS_H_
