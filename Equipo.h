// Equipo.h
#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>

class Equipo {
private:
    int codigo;
    std::string nombre;
    int anio;
    int nivelesAcidez;
    std::string estado;

public:
    Equipo(int codigo, const std::string& nombre, int anio, int nivelesAcidez, const std::string& estado);

    int getCodigo() const;
    std::string getNombre() const;
    int getAnio() const;
    int getNivelesAcidez() const;
    std::string getEstado() const; 

    void setCodigo(int c);
    void setNombre(const std::string& n);
    void setAnio(int a);
    void setNivelesAcidez(int n);
    void setEstado(const std::string& e); 
    void toString();
};

#endif // EQUIPO_H
