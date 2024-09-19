#include "../../headers/LinkedList.h"
#include <iostream>

// Constructor: inicializa la lista con un puntero nulo
LinkedList::LinkedList() : head(nullptr) {}

// Destructor: libera toda la memoria usada por los nodos
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Inserta un nodo de forma ordenada en la lista
void LinkedList::insert(int data) {
    Node* newNode = new Node(data); // Crear un nuevo nodo

    // Si la lista está vacía o el nuevo valor debe ser el primero
    if (head == nullptr || head->data >= data) {
        newNode->next = head;
        head = newNode;
    } else {
        // Buscar la posición correcta para insertar el nuevo nodo
        Node* current = head;
        while (current->next != nullptr && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Busca un valor en la lista, devolviendo true si lo encuentra
bool LinkedList::search(int data) {
    std::cerr << "Buscando: " << data << std::endl;
    if (head == nullptr) {
        std::cerr << "Error: Lista vacía." << std::endl;
        return false;
    }

    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            std::cerr << "Encontrado: " << data << std::endl;
            return true;
        }
        current = current->next;
    }
    std::cerr << "No se encontró: " << data << std::endl;
    return false;
}

// Elimina un nodo con un valor específico
void LinkedList::remove(int data) {
    if (head == nullptr) {
        std::cerr << "Error: Lista vacía." << std::endl;
        return;
    }

    // Si el valor a eliminar está en el primer nodo
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Buscar el nodo que precede al nodo que contiene el valor a eliminar
    Node* current = head;
    while (current->next != nullptr && current->next->data != data) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Muestra todos los elementos de la lista
void LinkedList::display() const {
    if (head == nullptr) {
        std::cout << "Lista vacía." << std::endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
