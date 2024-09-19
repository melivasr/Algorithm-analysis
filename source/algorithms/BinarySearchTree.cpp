#include "../../headers/BinarySearchTree.h"
#include <iostream>

// Constructor: inicializa el árbol con una raíz nula
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Destructor: limpia la memoria liberando los nodos
BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

// Función recursiva para liberar la memoria de los nodos
void BinarySearchTree::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Inserta un valor en el árbol
void BinarySearchTree::insert(int data) {
    insert(root, data); // Llamada a la función recursiva
}

// Función recursiva para insertar un valor en el árbol
void BinarySearchTree::insert(Node*& node, int data) {
    if (node == nullptr) {
        node = new Node(data); // Crear un nuevo nodo si el nodo actual es nulo
    } else if (data < node->data) {
        insert(node->left, data); // Insertar en el subárbol izquierdo
    } else {
        insert(node->right, data); // Insertar en el subárbol derecho
    }
}

// Busca un valor en el árbol, retorna true si lo encuentra
bool BinarySearchTree::search(int data) const {
    return search(root, data);
}

// Función recursiva para buscar un valor en el árbol
bool BinarySearchTree::search(Node* node, int data) const {
    if (node == nullptr) {
        return false;
    } else if (node->data == data) {
        return true;
    } else if (data < node->data) {
        return search(node->left, data); // Buscar en el subárbol izquierdo
    } else {
        return search(node->right, data); // Buscar en el subárbol derecho
    }
}

// Muestra los elementos del árbol en orden ascendente
void BinarySearchTree::inorder() const {
    inorder(root);
}

void BinarySearchTree::inorder(Node* node) const {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

