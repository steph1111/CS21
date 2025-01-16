#include <iostream>
#include "binary_search_tree.h"

// public:
/**
 * Constructs an empty `BinarySearchTree` object.
*/
BinarySearchTree::BinarySearchTree() {}

/**
 * Destructor for `BinarySearchTree`. Cleans up allocated memory.
*/
BinarySearchTree::~BinarySearchTree() {
    std::vector<Node*> nodes;
    this->postorder(this->root, nodes);
    for (unsigned i = 0; i < nodes.size(); i++) {
        delete nodes[i];
    }
}

/**
 * Searches for a `key` value.
 * 
 * @param key Key value to search for.
 * @return true if the `key` exists in the tree, otherwise false.
*/
bool BinarySearchTree::search(int key) const {
    return this->search(this->root, key) != nullptr;
}

/**
 * Minimum element in the tree.
 * 
 * @return Minimum element in the tree, `nullptr` if the tree is empty.
*/
int* BinarySearchTree::min() const {
    Node* temp = this->min(this->root);
    return temp ? (new int(temp->key)) : nullptr;
}

/**
 * Maximum element in the tree.
 * 
 * @return Maximum element in the tree, `nullptr` if the tree is empty.
*/
int* BinarySearchTree::max() const {
    Node* temp = this->max(this->root);
    return temp ? (new int(temp->key)) : nullptr;
}

/**
 * Insert a value `key` into the tree.
 * 
 * @param key Value to insert.
*/
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

/**
 * Successor of `key`.
 * 
 * The successor of a node is defined as the node with the 
 * smallest key greater than the input node.
 * 
 * @param key Key of the node to find the successor of
 * @return The key of the node which has the smallest key
 *         greater than `key`. `nullptr` if the tree is empty.
*/
int* BinarySearchTree::successor(int key) const {
    Node* temp = this->successor(this->search(this->root, key));
    return temp ? (new int(temp->key)) : nullptr;
}

/**
 * Predecessor of `key`.
 * 
 * The predecessor of a node is defined as the node with the 
 * largest key smaller than the input node.
 * 
 * @param key Key of the node to find the successor of
 * @return The key of the node which has the largest key
 *         smaller than `key`. `nullptr` if the tree is empty.
*/
int* BinarySearchTree::predecessor(int key) const {
    Node* temp = this->predecessor(this->search(this->root, key));
    return temp ? (new int(temp->key)) : nullptr;
}

/**
 * Removes the node from the tree with key value `key`.
 * 
 * @param key Key of the node to remove.
 * @return `true` if the removal was successful, otherwise `false`.
*/
bool BinarySearchTree::remove(int key) {
    return this->remove(this->search(this->root, key));
}

/**
 * Traverses the binary tree from the root in order.
 * 
 * @return A vector of ints containing the BST inorder.
*/
std::vector<int> BinarySearchTree::inorder() {
    std::vector<Node*> nodes;
    this->inorder(this->root, nodes);
    std::vector<int> keys(nodes.size());
    for (unsigned i = 0; i < nodes.size(); i++) {
        keys[i] = nodes[i]->key;
    }
    return keys;
}

/**
 * Traverses the binary tree from the root in postorder.
 * 
 * @return A vector of ints containing the BST in postorder.
*/
std::vector<int> BinarySearchTree::postorder() {
    std::vector<Node*> nodes;
    this->postorder(this->root, nodes);
    std::vector<int> keys(nodes.size());
    for (unsigned i = 0; i < nodes.size(); i++) {
        keys[i] = nodes[i]->key;
    }
    return keys;
}

/**
 * Traverses the binary tree from the root in preorder.
 * 
 * @return A vector of ints containing the BST in preorder.
*/
std::vector<int> BinarySearchTree::preorder() {
    std::vector<Node*> nodes;
    this->preorder(this->root, nodes);
    std::vector<int> keys(nodes.size());
    for (unsigned i = 0; i < nodes.size(); i++) {
        keys[i] = nodes[i]->key;
    }
    return keys;
}

// private:

/**
 * Search for a key from a start node
 * 
 * @param node Pointer to the node to start from
 * @param key Key to search for
*/
BinarySearchTree::Node* BinarySearchTree::search(Node* node, int key) const {
    if (node == nullptr || node->key == key) return node;
    if (key < node->key) return this->search(node->left, key);
    else return this->search(node->right, key);
}

/**
 * Minimum value in the tree from a starting node.
 * 
 * @param node Pointer to the node to start from.
*/
BinarySearchTree::Node* BinarySearchTree::min(Node* node) const {
    if (node == nullptr) return nullptr;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

/**
 * Maximum value in the tree from a starting node.
 * 
 * @param node Pointer to the node to start from.
*/
BinarySearchTree::Node* BinarySearchTree::max(Node* node) const {
    if (node == nullptr) return nullptr;
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

/**
 * Successor of a `node`.
 * 
 * @param Node to find the successor of.
*/
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

/**
 * Predecessor of a `node`.
 * 
 * @param node Node to find the predecessor of.
*/
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

/**
 * Remove a node from the tree.
 * 
 * @param node Node to remove.
*/
bool BinarySearchTree::remove(Node* node) {
    // If the node does not exist, do nothing
    if (node == nullptr) return false;
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
    return true;
}

 /**
 * Traverses the binary tree from a given start node `x` in order.
 * Stores the nodes in vector `nodes`.
 * 
 * @param x Node to start from.
 * @param nodes Empty vector to store nodes in inorder traversal in.
*/
void BinarySearchTree::inorder(Node* x, std::vector<Node*>& nodes) {
    if (x == nullptr) return;
    this->inorder(x->left, nodes);
    nodes.push_back(x);
    this->inorder(x->right, nodes);
}

/**
 * Traverses the binary tree from a given start node `x` in post order.
 * Stores the nodes in vector `nodes`.
 * 
 * @param x Node to start from.
 * @param nodes Empty vector to store nodes in postorder traversal in.
*/
void BinarySearchTree::postorder(Node* x, std::vector<Node*>& nodes) {
    if (x == nullptr) return;
    this->postorder(x->left, nodes);
    this->postorder(x->right, nodes);
    nodes.push_back(x);
}

/**
 * Traverses the binary tree from a given start node `x` in pre order.
 * Stores the nodes in vector `nodes`.
 * 
 * @param x Node to start from.
 * @param nodes Empty vector to store nodes in preorder traversal in.
*/
void BinarySearchTree::preorder(Node* x, std::vector<Node*>& nodes) {
    if (x == nullptr) return;
    nodes.push_back(x);
    this->preorder(x->left, nodes);
    this->preorder(x->right, nodes);
}

