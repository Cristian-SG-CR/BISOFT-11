#include "CategoriaNode.h"

CategoriaNode::CategoriaNode(Categoria* categoria) : categoria(categoria), next(nullptr) {
    
}

Categoria* CategoriaNode::getCategoria() const {
    return categoria;
}

CategoriaNode* CategoriaNode::getNext() const {
    return next;
}

void CategoriaNode::setNext(CategoriaNode* nextNode) {
    next = nextNode;
}
