#ifndef FECHA_H_
#define FECHA_H_

#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia, mes, anio;
public:
    void cargar();
    void cargardo();
    void mostrar() const;
    int getanio() const;
    int getmes() const;
};

#endif // FECHA_H

#endif // FECHA_H_
