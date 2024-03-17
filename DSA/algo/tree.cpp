#include <iostream>

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

int countLevels(Node* root) {
  // Base cases
  if (root == nullptr) {
    return 0;  // Empty tree
  } else if (root->left == nullptr && root->right == nullptr) {
    return 1;  // Single-node tree
  }

  // Divide
  int leftHeight = countLevels(root->left);
  int rightHeight = countLevels(root->right);

  // Conquer
  return std::max(leftHeight, rightHeight) + 1;
}

int main() {
  // Sample binary tree
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);

  int levels = countLevels(root);
  std::cout << "Number of levels: " << levels << std::endl;

  return 0;
}
