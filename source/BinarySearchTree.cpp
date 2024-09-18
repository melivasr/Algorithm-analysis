
#include "../headers/BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

void BinarySearchTree::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void BinarySearchTree::insert(int data) {
    insert(root, data);
}

void BinarySearchTree::insert(Node*& node, int data) {
    if (node == nullptr) {
        node = new Node(data);
    } else if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

bool BinarySearchTree::search(int data) const {  // Definición pública, ahora es const
    return search(root, data);
}

bool BinarySearchTree::search(Node* node, int data) const {
    if (node == nullptr) {
        return false;
    } else if (node->data == data) {
        return true;
    } else if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

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
