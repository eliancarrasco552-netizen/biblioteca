#ifndef SOCIO_H_
#define SOCIO_H_

#ifndef SOCIO_H
#define SOCIO_H
#include"fecha.h"
#include"persona.h"
class Socio : public Persona {
private:
    //char nombre[30];
    //char apellido[30];
    int idSocio;
    char telefono[30];
    char direccion[50];
    char correo[40];
    Fecha fechaalta;
    bool eliminado;
public:

    //metodos
    void cargar();
    void mostrar() const;

    //getters
    int getIdSocio() const { return idSocio; }
    bool getEliminado() const { return eliminado; }
    //setters
    void setEliminado(bool e) { eliminado = e; }
    void buscar(int id);
    void idAutomatico();

    /// Manejo de archivo
    bool guardar();
    bool leer(int pos);
    bool modificar(int pos);
    bool existeId(int id);

};

#endif // SOCIO_H

#endif // SOCIO_H_
