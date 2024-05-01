#include <iostream>
#include "binary_search_tree.h"

// public:
BinarySearchTree::BinarySearchTree() {}

BinarySearchTree::~BinarySearchTree() {
    this->postorder(this->root, [](Node* node) { delete node; });
}

bool BinarySearchTree::search(int key) const {
    return this->search(this->root, key) != nullptr;
}

int* BinarySearchTree::min() const {
    Node* temp = this->min(this->root);
    return temp ? (new int(temp->key)) : nullptr;
}

int* BinarySearchTree::max() const {
    Node* temp = this->max(this->root);
    return temp ? (new int(temp->key)) : nullptr;
}

void BinarySearchTree::insert(int key) {
   Node* node = new Node;
   node->key = key;
   // TODO: Ask why I cannot use Node* node = new Node{key};
   Node* prev = nullptr;
   Node* temp = this->root;
   // Traverse to the end of a branch
   while (temp != nullptr) {
       prev = temp;
       if (node->key < temp->key) temp = temp->left;
       else temp = temp->right;
   }
   // temp is a nullptr here, this is either because the tree is empty
   // or have traversed to the end of a branch
   node->parent = prev;
   if (prev == nullptr) {
       this->root = node;
       return;
   }
   // Attach to the left or right
   if (node->key < prev->key) prev->left = node;
   else prev->right = node;
}

int* BinarySearchTree::successor(int key) const {
    Node* temp = this->successor(this->search(this->root, key));
    return temp ? &temp->key : nullptr;
}

int* BinarySearchTree::predecessor(int key) const {
    Node* temp = this->successor(this->search(this->root, key));
    return temp ? &temp->key : nullptr;
}

void BinarySearchTree::remove(int key) {
    this->remove(this->search(this->root, key));
}

// private:
BinarySearchTree::Node* BinarySearchTree::search(Node* node, int key) const {
    if (node == nullptr || node->key == key) return node;
    if (key < node->key) return this->search(node->left, key);
    else return this->search(node->right, key);
}

BinarySearchTree::Node* BinarySearchTree::min(Node* node) const {
    if (node == nullptr) return nullptr;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BinarySearchTree::Node* BinarySearchTree::max(Node* node) const {
    if (node == nullptr) return nullptr;
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

BinarySearchTree::Node* BinarySearchTree::successor(Node* node) const {
    if (node == nullptr) return nullptr;
    if (node->right) return this->min(node->right);
    // Find the lowest ancestor whose left child is also an ancestor of mine
    Node* temp = node->parent;
    while (temp && node == temp->right) {
        node = temp;
        temp = temp->parent;
    }
    return temp;
}

BinarySearchTree::Node* BinarySearchTree::predecessor(Node* node) const {
    if (node == nullptr) return nullptr;
    if (node->left) return this->max(node->left);
    // Find the lowest ancestor whose left child is also an ancestor of mine
    Node* temp = node->parent;
    while (temp && node == temp->left) {
        node = temp;
        temp = temp->parent;
    }
    return temp;
}

void BinarySearchTree::remove(Node* node) {
    // If the node does not exist, do nothing
    if (node == nullptr) return;
    // Target is the node to be removed
    Node* target = node;
    if (node->left && node->right) {
        target = this->successor(node);
    }
    
    Node* temp;
    if (target->left) {
        temp = target->left;
    } else {
        temp = target->right;
    }
    if (temp) {
        temp->parent = target->parent;
    }
    if (target->parent == nullptr) {
        this->root = temp;
    } else {
        if (target == target->parent->left) {
            target->parent->left = temp;
        } else {
            target->parent->right = temp;
        }
    }
    if (target != node) {
        // copy target into node node
        node = target;
    }
    delete target;
}

void BinarySearchTree::inorder(Node* x, std::function<void(Node*)> func) {
    if (x == nullptr) return;
    this->inorder(x->left, func);
    func(x);
    this->inorder(x->right, func);
}

void BinarySearchTree::postorder(Node* x, std::function<void(Node*)> func) {
    if (x == nullptr) return;
    this->postorder(x->left, func);
    this->postorder(x->right, func);
    func(x);
}

void BinarySearchTree::preorder(Node* x, std::function<void(Node*)> func) {
    if (x == nullptr) return;
    func(x);
    this->preorder(x->left, func);
    this->preorder(x->right, func);
}

