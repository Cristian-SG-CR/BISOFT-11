#ifndef EQUIPONODE_H
#define EQUIPONODE_H

#include "Equipo.h"

class EquipoNode {
private:
    Equipo* equipo;
    EquipoNode* next;

public:
    EquipoNode(Equipo* equipo);
    Equipo* getEquipo() const;
    EquipoNode* getNext() const;
    void setNext(EquipoNode* nextNode);
};

#endif // EQUIPONODE_H
