
#include "Categoria.h"
#include <iostream>

Categoria::Categoria(const std::string& nombre) : nombre(nombre), equipos() {

}

std::string Categoria::getNombre() const {
    return nombre;
}

void Categoria::setNombre(std::string n){
nombre = n;
}

int Categoria::getnumEquiposAsociados(){
    return equipos.getCantEquipos();
}

void Categoria::agregarEquipo(Equipo* equipo){
    equipos.agregarEquipo(equipo);
}

void Categoria::retirarEquipo(int cod){
    equipos.retirarEquipo(cod);
}

void Categoria::listarEquiposAsociados(){
    equipos.listarCatalogoAscendentePorCodigo();
}

void Categoria::toString(){
    std::cout<< "Nombre: " << getNombre()
    << ", # de equipos asociados: " << equipos.getCantEquipos()<< std::endl;
    equipos.listarCatalogoAscendentePorCodigo();
}

