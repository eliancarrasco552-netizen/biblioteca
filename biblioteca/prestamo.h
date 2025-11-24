#ifndef PRESTAMO_H_
#define PRESTAMO_H_

#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "Fecha.h"

class Prestamo {
    private:
    int idPrestamo;
    int idSocio;
    int idLibro;
    bool activo;
    Fecha fechaPrestamo;
    Fecha fechaDevolucion;
public:

    //metodos
    void cargar();
    void mostrar() const;
    void buscar (int id);
    void buscaranio(int num);
    void idAutomatico();
    void historial();
    void devolucion();
    void buscarPorIdLibro();
   void buscarPorNombreSocio();

    //Getters
    int getIdPrestamo() const { return idPrestamo; }
    int getIdSocio() const { return idSocio; }
    int getIdLibro() const { return idLibro; }
    int getActivo() const { return activo; }

    /// Manejo de archivo
    bool guardar();
    bool leer(int pos);

};

#endif // PRESTAMO_H

#endif // PRESTAMO_H_
