#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include "EquipoList.h"

class Categoria {
private:
    std::string nombre;
    EquipoList equipos;

public:
    Categoria(const std::string& nombre);
    std::string getNombre() const;
    void setNombre(std::string n);
    int getnumEquiposAsociados();
    void agregarEquipo(Equipo* equipo);
    void retirarEquipo(int cod);
    void listarEquiposAsociados();
    void toString();
};

#endif // CATEGORIA_H
