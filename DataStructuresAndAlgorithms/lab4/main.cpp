#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* buildBalancedTree(std::vector<int>& values, int start, int end) {
  if (start > end) return nullptr;
  int mid = (start + end) / 2;
  Node* root = new Node(values[mid]);
  root->left = buildBalancedTree(values, start, mid - 1);
  root->right = buildBalancedTree(values, mid + 1, end);
  return root;
}

void preorderTraversal(Node* root) {
  if (!root) return;
  std::cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

Node* findNode(Node* root, int key) {
  if (!root || root->data == key) return root;
  if (key < root->data) return findNode(root->left, key);
  return findNode(root->right, key);
}

Node* findMin(Node* root) {
  while (root && root->left) root = root->left;
  return root;
}

Node* deleteNode(Node* root, int key) {
  if (!root) return root;
  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else {
    if (!root->left) {
      Node* temp = root->right;
      delete root;
      return temp;
    } else if (!root->right) {
      Node* temp = root->left;
      delete root;
      return temp;
    }
    Node* temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int height(Node* root) {
  if (!root) return 0;
  return 1 + std::max(height(root->left), height(root->right));
}

bool isBalanced(Node* root) {
  if (!root) return true;
  int lh = height(root->left);
  int rh = height(root->right);
  return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main() {
  std::vector<int> values = {8, 3, 10, 1, 6, 4, 7, 14, 13};
  std::sort(values.begin(), values.end());
  Node* root = buildBalancedTree(values, 0, values.size() - 1);

  std::cout << "Preorder Traversal: ";
  preorderTraversal(root);
  std::cout << std::endl;

  int key = 6;
  Node* found = findNode(root, key);
  if (found)
    std::cout << "Node " << key << " found!" << std::endl;
  else
    std::cout << "Node " << key << " not found!" << std::endl;

  root = deleteNode(root, key);
  std::cout << "Tree after deleting " << key << ": ";
  preorderTraversal(root);
  std::cout << std::endl;

  if (isBalanced(root))
    std::cout << "Tree is balanced!" << std::endl;
  else
    std::cout << "Tree is not balanced!" << std::endl;

  return 0;
}
