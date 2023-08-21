// Equipo.cpp
#include "Equipo.h"
#include <iostream>

Equipo::Equipo(int codigo, const std::string& nombre, int anio, int nivelesAcidez, const std::string& estado)
    : codigo(codigo), nombre(nombre), anio(anio), nivelesAcidez(nivelesAcidez), estado(estado) {
    
}

int Equipo::getCodigo() const {
    return codigo;
}

std::string Equipo::getNombre() const {
    return nombre;
}

int Equipo::getAnio() const {
    return anio;
}

int Equipo::getNivelesAcidez() const {
    return nivelesAcidez;
}

std::string Equipo::getEstado() const {
    return estado;
}

void Equipo::setCodigo(int c) {
    codigo = c;
}

void Equipo::setNombre(const std::string& n) {
    nombre = n;
}

void Equipo::setAnio(int a) {
    anio = a;
}

void Equipo::setNivelesAcidez(int n) {
    nivelesAcidez = n;
}

void Equipo::setEstado(const std::string& e) {
    estado = e;
}

void Equipo::toString(){
    std::cout << "Codigo: " << getCodigo()
    << ", Nombre: " << getNombre()
    << ", Estado: " << getEstado() << "\n" << std::endl;
}
