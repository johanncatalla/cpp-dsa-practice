#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    Node *head;

    SinglyLinkedList() {
        this->head = nullptr;
    }

    void push(int data) {
        Node *new_node = new Node(data);
        new_node->next = this->head;
        this->head = new_node;
    
    }

    void display() const{
        Node *current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
    ~SinglyLinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }
};

int main() {

    SinglyLinkedList ll;
    ll.push(1);    
    ll.push(2);
    ll.push(3);

    ll.display();

    _CrtDumpMemoryLeaks();
    return 0;
}