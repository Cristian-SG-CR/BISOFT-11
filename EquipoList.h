#ifndef EQUIPOLIST_H
#define EQUIPOLIST_H

#include "EquipoNode.h"

class EquipoList {
private:
    EquipoNode* head;  

public:
    EquipoList();
    ~EquipoList();

    void agregarEquipo(Equipo* equipo);
    void deleteSortedLinkedList(EquipoNode* head);
    void retirarEquipo(int codigo);
    Equipo* consultarEquipo(int codigo);
    void modificarEquipo(int codigo, const std::string& nuevoNombre, const std::string& nuevoEstado);
    void listarCatalogoAscendentePorCodigo();
    void listarCatalogoDescendentePorCodigo();
    void listarCatalogoAscendentePorNombre();
    void listarCatalogoDescendentePorNombre();
    void listarEquiposConDescripcion(const std::string& descripcion);
    void listarEquiposRangoAnio(int anioInicio, int anioFin);
    void listarEquiposPorNivelesAcidez(int minPh, int maxPh);
    int getCantEquipos();
};

#endif // EQUIPOLIST_H
