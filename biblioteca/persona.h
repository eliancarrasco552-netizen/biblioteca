#ifndef PERSONA_H_
#define PERSONA_H_

/* CORREGIDO: versi�n completa y consistente del proyecto */
#ifndef PERSONA_H
#define PERSONA_H
class Persona {
protected:
    char nombre[30];
    char apellido[30];
    char mail[50];
    char pais[30];
public:
    Persona();

   //metodos
    void cargar();
    void mostrar() const;


   //getters
    const char* getNombre() const { return nombre; }
    const char* getApellido() const { return apellido; }
    const char* getMail() const { return mail; }
    const char* getPais() const { return pais; }


   //setters
    void setNombre(const char* n);
    void setApellido(const char* a);
    void setMail(const char* m);
    void setPais(const char* p);
};

#endif // PERSONA_H

#endif // PERSONA_H_
