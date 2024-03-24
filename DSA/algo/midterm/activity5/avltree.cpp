#include <iostream>
#include <algorithm>

class Node {
public:
    int data;
    int height;
    Node* leftChild;
    Node* rightChild;

    Node(int data) : data(data), height(0), leftChild(nullptr), rightChild(nullptr) {}
};

class AVL {
private:
    Node* root;

    // Remove a node with given data from the subtree rooted at 'node'
    Node* removeNode(int data, Node* node) {
        if (!node) {
            return node;
        }

        if (data < node->data) {
            node->leftChild = removeNode(data, node->leftChild);
        } else if (data > node->data) {
            node->rightChild = removeNode(data, node->rightChild);
        } else {
            if (!node->leftChild && !node->rightChild) {
                delete node;
                return nullptr;
            }

            if (!node->leftChild) {
                Node* tempNode = node->rightChild;
                delete node;
                return tempNode;
            } else if (!node->rightChild) {
                Node* tempNode = node->leftChild;
                delete node;
                return tempNode;
            }

            Node* tempNode = getPredecessor(node->leftChild);
            node->data = tempNode->data;
            node->leftChild = removeNode(tempNode->data, node->leftChild);
        }

        if (!node) {
            return node;
        }

        node->height = std::max(calcHeight(node->leftChild), calcHeight(node->rightChild)) + 1;

        int balance = calcBalance(node);

        if (balance > 1 && calcBalance(node->leftChild) >= 0) {
            return rotateRight(node);
        }

        if (balance > 1 && calcBalance(node->leftChild) < 0) {
            node->leftChild = rotateLeft(node->leftChild);
            return rotateRight(node);
        }

        if (balance < -1 && calcBalance(node->rightChild) <= 0) {
            return rotateLeft(node);
        }

        if (balance < -1 && calcBalance(node->rightChild) > 0) {
            node->rightChild = rotateRight(node->rightChild);
            return rotateLeft(node);
        }

        return node;
    }

    // Helper function to find the predecessor node in the subtree
    Node* getPredecessor(Node* node) {
        if (node->rightChild) {
            return getPredecessor(node->rightChild);
        }
        return node;
    }

    // Helper function to balance the AVL tree after insertion
    Node* settleViolation(int data, Node* node) {
        int balance = calcBalance(node);

        if (balance > 1 && data < node->leftChild->data) {
            return rotateRight(node);
        }

        if (balance < -1 && data > node->rightChild->data) {
            return rotateLeft(node);
        }

        if (balance > 1 && data > node->leftChild->data) {
            node->leftChild = rotateLeft(node->leftChild);
            return rotateRight(node);
        }

        if (balance < -1 && data < node->rightChild->data) {
            node->rightChild = rotateRight(node->rightChild);
            return rotateLeft(node);
        }

        return node;
    }

    // Calculates the height of the node
    int calcHeight(Node* node) {
        if (!node) {
            return -1;
        }
        return node->height;
    }

    // Calculate balance factor of a node
    int calcBalance(Node* node) {
        if (!node) {
            return 0;
        }
        return calcHeight(node->leftChild) - calcHeight(node->rightChild);
    }

    // Perform inorder traversal of the tree
    void traverseInorder(Node* node) {
        if (node->leftChild) {
            traverseInorder(node->leftChild);
        }
        std::cout << node->data << " ";
        if (node->rightChild) {
            traverseInorder(node->rightChild);
        }
    }

    // perform right rotation on a node
    Node* rotateRight(Node* node) {
        Node* tempLeftChild = node->leftChild;
        Node* t = tempLeftChild->rightChild;

        tempLeftChild->rightChild = node;
        node->leftChild = t;

        node->height = std::max(calcHeight(node->leftChild), calcHeight(node->rightChild)) + 1;
        tempLeftChild->height = std::max(calcHeight(tempLeftChild->leftChild), calcHeight(tempLeftChild->rightChild)) + 1;

        return tempLeftChild;
    }

    // rotate the node left
    Node* rotateLeft(Node* node) {
        Node* tempRightChild = node->rightChild;
        Node* t = tempRightChild->leftChild;

        tempRightChild->leftChild = node;
        node->rightChild = t;

        node->height = std::max(calcHeight(node->leftChild), calcHeight(node->rightChild)) + 1;
        tempRightChild->height = std::max(calcHeight(tempRightChild->leftChild), calcHeight(tempRightChild->rightChild)) + 1;

        return tempRightChild;
    }

public:
    AVL() : root(nullptr) {}

    void remove(int data) {
        if (root) {
            root = removeNode(data, root);
        }
    }

    void insert(int data) {
        root = insertNode(data, root);
    }

    Node* insertNode(int data, Node* node) {
        if (!node) {
            return new Node(data);
        }

        if (data < node->data) {
            node->leftChild = insertNode(data, node->leftChild);
        } else {
            node->rightChild = insertNode(data, node->rightChild);
        }

        node->height = std::max(calcHeight(node->leftChild), calcHeight(node->rightChild)) + 1;

        return settleViolation(data, node);
    }

    void traverse() {
        if (root) {
            traverseInorder(root);
        }
    }
};

int main() {
    AVL avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(5);
    avl.insert(6);
    avl.insert(15);
    avl.insert(18);
    avl.insert(4);
    
    avl.remove(15);
    avl.remove(18);
    avl.remove(20);
    avl.remove(10);

    avl.traverse();

    return 0;
}