#include "EquipoList.h"
#include <iostream>

EquipoList::EquipoList() : head(nullptr) {
    
}

EquipoList::~EquipoList() {
    
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        EquipoNode* tempNode = currentNode;
        currentNode = currentNode->getNext();
        delete tempNode->getEquipo();
        delete tempNode;
    }
}

// Metodo para agregar equipo 
void EquipoList::agregarEquipo(Equipo* equipo) {
    if(!consultarEquipo(equipo->getCodigo())){
        EquipoNode* newNode = new EquipoNode(equipo);
        newNode->setNext(head);
        head = newNode;
    }else{
        std::cout << "\n ERROR: Equipo con codigo" << equipo->getCodigo() << " ya existe, por lo tanto no se agrego a la lista." << std::endl;
    }
}

// Metodo para ordenar la lista
void EquipoList::deleteSortedLinkedList(EquipoNode* head) {
    while (head != nullptr) {
        EquipoNode* temp = head;
        head = head->getNext();
        delete temp;
    }
}

// Metodo para retirar Equipo
void EquipoList::retirarEquipo(int codigo) {
    EquipoNode* currentNode = head;
    EquipoNode* prevNode = nullptr;

    while (currentNode != nullptr) {
        if (currentNode->getEquipo()->getCodigo() == codigo) {
            if (prevNode == nullptr) {
                head = currentNode->getNext();
            } else {
                prevNode->setNext(currentNode->getNext());
            }
            delete currentNode->getEquipo();
            delete currentNode;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->getNext();
    }

    std::cout << "No se pudo eliminar el Equipo con codigo " << codigo << " ya que no fue encontrado." << std::endl;
}

// Metodo para consultar equipo por su codigo
Equipo* EquipoList::consultarEquipo(int codigo) {
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->getEquipo()->getCodigo() == codigo) {
            return currentNode->getEquipo();
        }
        currentNode = currentNode->getNext();
    }
    return nullptr;  // Equipo not found
}


// Metodo para codificar Equipo
void EquipoList::modificarEquipo(int codigo, const std::string& nuevoNombre, const std::string& nuevoEstado) {
    Equipo* equipo = consultarEquipo(codigo);
    if (equipo != nullptr) {
        equipo->setNombre(nuevoNombre);
        equipo->setEstado(nuevoEstado);
    } else {
        std::cout << "Equipo with codigo " << codigo << " not found." << std::endl;
    }
}

// Metodo para listar catalogo asc por codigo
void EquipoList::listarCatalogoAscendentePorCodigo() {
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                  << ", Nombre: " << currentNode->getEquipo()->getNombre()
                  << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        currentNode = currentNode->getNext();
    }
}

EquipoNode* reverseLinkedList(EquipoNode* head) {
    EquipoNode* prev = nullptr;
    EquipoNode* current = head;
    EquipoNode* next = nullptr;

    while (current != nullptr) {
        next = current->getNext();
        current->setNext(prev);
        prev = current;
        current = next;
    }

    return prev;
}

// Metodo para listar catalogo desc por codigo
void EquipoList::listarCatalogoDescendentePorCodigo() {
    EquipoNode* reversedHead = reverseLinkedList(head);

    EquipoNode* currentNode = reversedHead;
    while (currentNode != nullptr) {
        std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                  << ", Nombre: " << currentNode->getEquipo()->getNombre()
                  << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        currentNode = currentNode->getNext();
    }

    
    head = reverseLinkedList(reversedHead);
}

// Metodo para listar catalogo asc por nombre
void EquipoList::listarCatalogoAscendentePorNombre() {
    
    EquipoNode* sortedHead = nullptr;

    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        
        EquipoNode* prev = nullptr;
        EquipoNode* temp = sortedHead;
        while (temp != nullptr && temp->getEquipo()->getNombre() < currentNode->getEquipo()->getNombre()) {
            prev = temp;
            temp = temp->getNext();
        }

        
        EquipoNode* newNode = new EquipoNode(currentNode->getEquipo());
        if (prev == nullptr) {
            newNode->setNext(sortedHead);
            sortedHead = newNode;
        } else {
            prev->setNext(newNode);
            newNode->setNext(temp);
        }

        currentNode = currentNode->getNext();
    }
    
    currentNode = sortedHead;
    while (currentNode != nullptr) {
        std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                  << ", Nombre: " << currentNode->getEquipo()->getNombre()
                  << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        currentNode = currentNode->getNext();
    }

    
    deleteSortedLinkedList(sortedHead);
}

// Metodo para listar catalogo desc por nombre
void EquipoList::listarCatalogoDescendentePorNombre() {
    
    EquipoNode* sortedHead = nullptr;

    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
    
        EquipoNode* prev = nullptr;
        EquipoNode* temp = sortedHead;
        while (temp != nullptr && temp->getEquipo()->getNombre() > currentNode->getEquipo()->getNombre()) {
            prev = temp;
            temp = temp->getNext();
        }

    
        EquipoNode* newNode = new EquipoNode(currentNode->getEquipo());
        if (prev == nullptr) {
            newNode->setNext(sortedHead);
            sortedHead = newNode;
        } else {
            prev->setNext(newNode);
            newNode->setNext(temp);
        }

        currentNode = currentNode->getNext();
    }

    
    currentNode = sortedHead;
    while (currentNode != nullptr) {
        std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                  << ", Nombre: " << currentNode->getEquipo()->getNombre()
                  << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        currentNode = currentNode->getNext();
    }

    
    deleteSortedLinkedList(sortedHead);
}

// Metodo para listar equipos con descripcion especifica
void EquipoList::listarEquiposConDescripcion(const std::string& descripcion) {
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->getEquipo()->getNombre().find(descripcion) != std::string::npos) {
            std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                      << ", Nombre: " << currentNode->getEquipo()->getNombre()
                      << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        }
        currentNode = currentNode->getNext();
    }
}

// Metodo para listar equipos con un rango de anos
void EquipoList::listarEquiposRangoAnio(int anioInicio, int anioFin) {
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->getEquipo()->getAnio() >= anioInicio && currentNode->getEquipo()->getAnio() <= anioFin) {
            std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                      << ", Nombre: " << currentNode->getEquipo()->getNombre()
                      << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        }
        currentNode = currentNode->getNext();
    }
}

// Metodo para listar equipos que cumplan con nivel de pH ingresado
void EquipoList::listarEquiposPorNivelesAcidez(int minPh, int maxPh) {
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        int ph = currentNode->getEquipo()->getNivelesAcidez();
        if (ph >= minPh && ph <= maxPh) {
            std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                      << ", Nombre: " << currentNode->getEquipo()->getNombre()
                      << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        }
        currentNode = currentNode->getNext();
    }
}

int EquipoList::getCantEquipos(){
    int cont=0;
    EquipoNode* currentNode = head;
        while (currentNode != nullptr) {
            cont=cont+1;
            currentNode = currentNode->getNext();
        }
    return cont;
}

