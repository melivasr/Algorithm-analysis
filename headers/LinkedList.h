#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList {
public:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    LinkedList();
    ~LinkedList();
    void insert(int data);
    bool search(int data);
    void remove(int data);
    void display() const;

private:
    Node* head;
};

#endif // LINKED_LIST_H
