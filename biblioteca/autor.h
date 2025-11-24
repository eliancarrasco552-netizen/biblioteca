#ifndef AUTOR_H_
#define AUTOR_H_

/* CORREGIDO: versi�n completa y consistente del proyecto */
#ifndef AUTOR_H
#define AUTOR_H

#include "persona.h"
#include <cstdio>

class Autor : public Persona {
private:
    int idAutor;
    char nacionalidad[30];
    int cantidadObras;
    bool eliminado;
public:
    Autor();
    void cargar();
    void mostrar() const;

    int getIdAutor() const;
    bool getEliminado() const;

    // archivo
    bool guardar();
    bool leer(int pos);
    void buscar(int id);
    void idAutomatico();
    void setNacionalidad(const char* n);
    void setCantidadObras(int c);
};

#endif // AUTOR_H

#endif // AUTOR_H_
