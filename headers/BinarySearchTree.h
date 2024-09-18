#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class BinarySearchTree {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int data);
    bool search(int data) const;
    void inorder() const;

private:
    Node* root;

    void insert(Node*& node, int data);
    bool search(Node* node, int data) const;
    void inorder(Node* node) const;
    void clear(Node* node);
};

#endif // BINARY_SEARCH_TREE_H
