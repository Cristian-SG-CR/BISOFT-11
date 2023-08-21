#ifndef CATEGORIALIST_H
#define CATEGORIALIST_H

#include "CategoriaNode.h"
#include "EquipoList.h"

class CategoriaList {
private:
    CategoriaNode* head; 

public:
    CategoriaList();
    ~CategoriaList();

    void agregarCategoria(Categoria* cat);
    void eliminarCategoria(std::string nombreCategoria);
    void deleteSortedLinkedList(CategoriaNode* head);
    Categoria* consultarCategoria(const std::string& nombreCat);
    void modificarCategoria(const std::string& nombreCat, const std::string& nuevoNombre);
    void listarCatalogoCategorias();
    void agregarEquipoCategoria(Equipo* obtEquipo, std::string nomCategoria);
    void retirarEquipoCategoria();
    void consultarCategoria();
    void listarTodo();
};

#endif // CATEGORIALIST_H
