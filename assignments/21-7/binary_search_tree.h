#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <functional>

class BinarySearchTree {
    // forward definition of Node
    struct Node;
    public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool search(int key) const;
    int* min() const;
    int* max() const;
    void insert(int val);
    int* successor(int key) const;
    int* predecessor(int key) const;
    void remove(int key);

    private:
    Node* search(Node* node, int key) const;
    Node* min(Node* node) const;
    Node* max(Node* node) const;
    Node* successor(Node* node) const; 
    Node* predecessor(Node* node) const;
    void inorder(Node* x, std::function<void(Node*)> func);
    void postorder(Node* x, std::function<void(Node*)> func);
    void preorder(Node* x, std::function<void(Node*)> func);
    void remove(Node* node);
    void print_node(Node* node);
    void delete_node(Node* node);

    struct Node {                                                               
        Node* left = nullptr;                                                   
        Node* right = nullptr;                                                  
        Node* parent = nullptr;                                                 
        int key;                                                                
    }; 
    Node* root;
};

#endif  // BINARY_SEARCH_TREE_H
