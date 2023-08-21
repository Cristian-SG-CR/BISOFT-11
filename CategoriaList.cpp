#include "CategoriaList.h"
#include <iostream>

CategoriaList::CategoriaList() : head(nullptr) {
    
}

CategoriaList::~CategoriaList() {    
    CategoriaNode* currentNode = head;
    while (currentNode != nullptr) {
        CategoriaNode* tempNode = currentNode;
        currentNode = currentNode->getNext();
        delete tempNode->getCategoria();
        delete tempNode;
    }
}

// Metodo para agregar categoria a la lista
void CategoriaList::agregarCategoria(Categoria* categoria) {
    if(!consultarCategoria(categoria->getNombre())){
        CategoriaNode* currentNode = head;
        if(currentNode != nullptr){
            while (currentNode != nullptr) {
                if(currentNode->getNext()){
                    std::string nomcatc = currentNode->getCategoria()->getNombre();
                    std::string nomcatn = currentNode->getNext()->getCategoria()->getNombre();
                    if(nomcatc.compare(categoria->getNombre())<0 && nomcatn.compare(categoria->getNombre())>0){
                        CategoriaNode* newNode = new CategoriaNode(categoria);
                        newNode->setNext(currentNode->getNext());
                        currentNode->setNext(newNode);
                        break;
                    }else{
                      currentNode = currentNode->getNext();
                    }
                }else{
                    CategoriaNode* newNode = new CategoriaNode(categoria);
                    newNode->setNext(nullptr);
                    currentNode->setNext(newNode);
                    break;
                }
            }
        }else{
            CategoriaNode* newNode = new CategoriaNode(categoria);
            newNode->setNext(head);
            head = newNode;
        }
    }else{
        std::cout << "ERROR: Categoria con nombre " << categoria->getNombre() << " ya existe, por lo tanto no se agrego a la lista." << std::endl;
    }
}

// Metodo para eliminar Categoria
void CategoriaList::eliminarCategoria(std::string nombreCategoria){
    CategoriaNode* currentNode = head;
    CategoriaNode* prevNode = nullptr;

    while (currentNode != nullptr) {
        if (currentNode->getCategoria()->getNombre() == nombreCategoria) {
            if (prevNode == nullptr) {
                head = currentNode->getNext();
            } else {
                prevNode->setNext(currentNode->getNext());
            }
            delete currentNode->getCategoria();
            delete currentNode;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->getNext();
    }

    std::cout << "No se pudo eliminar la Categoria con nombre " << nombreCategoria << " ya que no fue encontrado." << std::endl;
}

// Metodo para eliminar lista ordenada
void CategoriaList::deleteSortedLinkedList(CategoriaNode* head) {
    while (head != nullptr) {
        CategoriaNode* temp = head;
        head = head->getNext();
        delete temp;
    }
}

// Metodo para buscar categoria por su nombre
Categoria* CategoriaList::consultarCategoria(const std::string&  nombrecat) {
    CategoriaNode* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->getCategoria()->getNombre() == nombrecat) {
            return currentNode->getCategoria();
        }
        currentNode = currentNode->getNext();
    }
    return nullptr;  // Categoria not found
}


// Metodo para modificar el nombre de la categoria
void CategoriaList::modificarCategoria(const std::string&  nombreCat, const std::string& nuevoNombre) {
    Categoria* categoria = consultarCategoria(nombreCat);
    if (categoria != nullptr) {
        categoria->setNombre(nuevoNombre);
    } else {
        std::cout << "Categoria with nombre " << nombreCat << " not found." << std::endl;
    }
}

// Metodo para listar catalogo ascendentemente por nombre
void CategoriaList::listarCatalogoCategorias() {
    CategoriaNode* currentNode = head;
    while (currentNode != nullptr) {
        std::cout << "Nombre: " << currentNode->getCategoria()->getNombre()
                  << ", # de equipos asociados: " << currentNode->getCategoria()->getnumEquiposAsociados() << std::endl;
        currentNode = currentNode->getNext();
    }
}

// Metodo para revertir orden de la lista
CategoriaNode* reverseLinkedList(CategoriaNode* head) {
    CategoriaNode* prev = nullptr;
    CategoriaNode* current = head;
    CategoriaNode* next = nullptr;

    while (current != nullptr) {
        next = current->getNext();
        current->setNext(prev);
        prev = current;
        current = next;
    }

    return prev;
}

// Metodo para agregar Equipos a categoria
void CategoriaList::agregarEquipoCategoria(Equipo* obtEquipo, std::string nomCategoria){
    CategoriaNode* currentNode = head;
    while (currentNode != nullptr) {
        if(currentNode->getCategoria()->getNombre()==nomCategoria){
            currentNode->getCategoria()->agregarEquipo(obtEquipo);
        }
        currentNode = currentNode->getNext();
    }
}


// Metodo para retirar categoria
void CategoriaList::retirarEquipoCategoria(){
    std::string nomcat = "";
    int codequipo = 0;
    listarCatalogoCategorias();
    std::cout <<"Digite el nombre de la categoria a la que desea retirar un equipo: \n"<< std::endl;
    std::cin >> nomcat;
    Categoria* cat = consultarCategoria(nomcat);
    cat->listarEquiposAsociados();
    std::cout <<"Digite el codigo del equipo que desea retirar de la categoria: \n"<< std::endl;
    std::cin >> codequipo;
    cat->retirarEquipo(codequipo);
}

// Metodo para consultar Categoria
void CategoriaList::consultarCategoria(){
    std::string nomcat = "";
    listarCatalogoCategorias();
    std::cout <<"Digite el nombre de la categoria a la que desea consultar: \n"<< std::endl;
    std::cin >> nomcat;
    Categoria* cat = consultarCategoria(nomcat);
    cat->toString();
}

// Metodo para listar todas las listas.
void CategoriaList::listarTodo(){
  CategoriaNode* currentNode = head;
    while (currentNode != nullptr) {
       currentNode->getCategoria()->toString();

       std::cout <<"\n\n"<<std::endl;
       currentNode = currentNode->getNext();
    }
}

