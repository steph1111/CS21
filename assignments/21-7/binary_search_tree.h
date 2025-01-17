/**
 * @file    binary_search_tree.h
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    05/02/24
 * CS21:    Assignment#7
 * Status:  Working/tested
 *
 * Declarations of methods of `BinarySearchTree` class.
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <vector>

class BinarySearchTree {
    // forward definition of Node
    struct Node;
    public:
    /**
     * Constructs an empty `BinarySearchTree` object.
    */
    BinarySearchTree();

    /**
     * Destructor for `BinarySearchTree`. Cleans up allocated memory.
    */
    ~BinarySearchTree();

    /**
     * Searches for a `key` value.
     * 
     * @param key Key value to search for.
     * @return true if the `key` exists in the tree, otherwise false.
    */
    bool search(int key) const;

    /**
     * Minimum element in the tree.
     * 
     * @return Minimum element in the tree, `nullptr` if the tree is empty.
    */
    int* min() const;

    /**
     * Maximum element in the tree.
     * 
     * @return Maximum element in the tree, `nullptr` if the tree is empty.
    */
    int* max() const;

    /**
     * Insert a value `key` into the tree.
     * 
     * @param key Value to insert.
    */
    void insert(int val);

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
    int* successor(int key) const;

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
    int* predecessor(int key) const;

    /**
     * Removes the node from the tree with key value `key`.
     * 
     * @param key Key of the node to remove.
     * @return `true` if the removal was successful, otherwise `false`.
    */
    bool remove(int key);

    /**
     * Traverses the binary tree from the root in order.
     * 
     * @return A vector of ints containing the BST inorder.
    */
    std::vector<int> inorder();

    /**
     * Traverses the binary tree from the root in postorder.
     * 
     * @return A vector of ints containing the BST in postorder.
    */
    std::vector<int> postorder();

    /**
     * Traverses the binary tree from the root in preorder.
     * 
     * @return A vector of ints containing the BST in preorder.
    */
    std::vector<int> preorder();

    private:
    /**
     * Search for a key from a start node
     * 
     * @param node Pointer to the node to start from
     * @param key Key to search for
    */
    Node* search(Node* node, int key) const;

    /**
     * Minimum value in the tree from a starting node.
     * 
     * @param node Pointer to the node to start from.
    */
    Node* min(Node* node) const;

    /**
     * Maximum value in the tree from a starting node.
     * 
     * @param node Pointer to the node to start from.
    */
    Node* max(Node* node) const;

    /**
     * Successor of a `node`.
     * 
     * @param Node to find the successor of.
    */
    Node* successor(Node* node) const; 

    /**
     * Predecessor of a `node`.
     * 
     * @param node Node to find the predecessor of.
    */
    Node* predecessor(Node* node) const;

    /**
     * Remove a node from the tree.
     * 
     * @param node Node to remove.
    */
    bool remove(Node* node);

    /**
     * Traverses the binary tree from a given start node `x` in order.
     * Stores the nodes in vector `nodes`.
     * 
     * @param x Node to start from.
     * @param nodes Empty vector to store nodes in inorder traversal in.
    */
    void inorder(Node* x, std::vector<Node*>& nodes);

    /**
     * Traverses the binary tree from a given start node `x` in post order.
     * Stores the nodes in vector `nodes`.
     * 
     * @param x Node to start from.
     * @param nodes Empty vector to store nodes in postorder traversal in.
    */
    void postorder(Node* x, std::vector<Node*>& nodes);

    /**
     * Traverses the binary tree from a given start node `x` in pre order.
     * Stores the nodes in vector `nodes`.
     * 
     * @param x Node to start from.
     * @param nodes Empty vector to store nodes in preorder traversal in.
    */
    void preorder(Node* x, std::vector<Node*>& nodes);
   

    struct Node {                                                               
        Node* left = nullptr;                                                   
        Node* right = nullptr;                                                  
        Node* parent = nullptr;                                                 
        int key;                                                                
    }; 
    // TODO: Look at this later
    Node* root = nullptr;
};

#endif  // BINARY_SEARCH_TREE_H
