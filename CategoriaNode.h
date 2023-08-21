#ifndef CATEGORIANODE_H
#define CATEGORIANODE_H

#include "Categoria.h"

class CategoriaNode {
private:
    Categoria* categoria;
    CategoriaNode* next;

public:
    CategoriaNode(Categoria* categoria);
    Categoria* getCategoria() const;
    CategoriaNode* getNext() const;
    void setNext(CategoriaNode* nextNode);
};

#endif // CATEGORIANODE_H
