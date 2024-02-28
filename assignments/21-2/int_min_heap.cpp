/**
 * @file    min_heap.cpp
 * @author  Stephanie L'Heureux (slheure)
 * Email:   stephanielh1111@gmail.com
 * @date    02/29/24
 * CS21:    Assignment#2
 *
 * Definitions of methods of intMinHeap class. The intMinHeap class 
 * defines a minimum priority heap (queue)
*/


#include <iostream>
#include <sstream>
#include "int_min_heap.h"

// public: 

/**
 * Constructor for intMinHeap object. Creates a intMinHeap
 * with capacity `cap`
 * 
 * @param cap Capacity of intMinHeap
 */
intMinHeap::intMinHeap(int cap) {
    this->capacity = cap;
    this->size = 0;
    this->A = new int[cap];
} 

/**
 * Destructor for intMinHeap object, clean up allocated memory 
*/
intMinHeap::~intMinHeap() {
    delete [] this->A;
} 

/**
 * Sorts heap into a sorted array 
 * 
 * @return A pair in which the first element is the sorted array
 *         and the second element is the size.
*/
std::pair<int *, int> intMinHeap::heapsort() {
    // Store orig heap in variables
    int* ptr_to_orig_A = A;
    int orig_size = this->size;
    this->A = new int[this->size];

    for (int i = 0; i < this->size; i++) this->A[i] = ptr_to_orig_A[i];
    
    // Heap sort algo
    for(int i = this->size - 1; i > 0; i--) {
        this->swap(0, i);
        this->size--;
        this->heapify(0);
    }
    
    // Create pair to return of sorted array an it size
    std::pair<int *, int> sorted_pair = std::make_pair(this->A, orig_size);

    // Cleanup
    this->size = orig_size;
    this->A = ptr_to_orig_A;

    return sorted_pair;
}

/**
 * Converts contents of heap to a formatted string
 * 
 * @return Contents of heap as a formatted string
*/
std::string intMinHeap::toString() {
    std::stringstream sstream;
    
    sstream << "heap size " << this->size << ": ";
    for (int i = 0; i < this->size - 1; i++) {
        sstream << this->A[i] << ", ";
    }
    if (!this->isEmpty()) sstream << this->A[this->size - 1];

    return sstream.str();
}

/**
 * Insert a new value into the heap
 * 
 * @param val Value to insert
 * @return True if the insert worked, other false if not
*/
bool intMinHeap::heapinsert(int val) {
    if (this->isFull()) return false;

    this->size++;                       // Increase size
    A[size - 1] = val + 1;              // Add one so decrease key works
    this->decreasekey(size - 1, val);   // Moves to correct position

    return true;
}

/**
 * Returns the minimum value in the heap, A[root].
 * 
 * @return A[root], 0 if empty heap
 */
inline int intMinHeap::minimum() { return (this->isEmpty()) ? 0 :  this->A[0]; }

/**
 * Removes and returns the minimum value in the heap, A[root].
 * 
 * @return A[root], 0 if the the size is 0
*/
int intMinHeap::extractmin() {
    if (this->isEmpty()) return 0;

    int min = A[0];
    A[0] = A[--this->size];
    this->heapify(0);
    return min;
}

/**
 * Promote value at index `i` to `k`
 * 
 * @param i Index to promote 
 * @param k Value to promote to
*/
void intMinHeap::decreasekey(int i, int k) {
    // Bounds check
    if (i < 0 || i >= this->size || this->A[i] <= k) return;
    A[i] = k; // Promote to k (key) value
    // Move value to the right spot
    while (i > 0 && this->A[this->parent(i)] > this->A[i]) {
        this->swap(i, this->parent(i));
        i = this->parent(i);
    }
}

/**
 * Returns if the heap is empty
 * 
 * @return true if the heap is empty, otherwise false
 */
inline bool intMinHeap::isEmpty() { return this->size == 0; }

/**
 * Returns if the heap size is the capacity
 * 
 * @return true if the heap is full, otherwise false
 */
inline bool intMinHeap::isFull() { return this->size == this->capacity; }

// private:

/**
 * Swaps elements in the heap at provided indexes.
 * Assumes indexes provided are valid.
 * 
 * @param i, j Indexes of nodes to swap
 */
void intMinHeap::swap(int i, int j) {
    int temp = this->A[i];
    this->A[i] = this->A[j];
    this->A[j] = temp;
}

/**
 * Returns the max minimum of three nodes
 * 
 * @param i, j, k Indexes of nodes to compare
 * @return Index of the minimum value node 
*/
int intMinHeap::minOf3(int i, int j, int k) {
    if (j >= this->size || j < 0) j = i;
    if (k >= this->size || k < 0) k = i;
    int min_index_i_j = this->A[i] < this->A[j] ? i : j;
    return this->A[min_index_i_j] < this->A[k] ? min_index_i_j : k;
}

/**
 * Returns the right node index
 * 
 * @param i Index of node to find the right node of
 * @return The index of the right node to `i`
 */
inline int intMinHeap::left(int i) { return 2 * i + 1; }

/**
 * Returns the right node index
 * 
 * @param i Index of node to find the right node of
 * @return The index of the right node to `i`
 */
inline int intMinHeap::right(int i) { return 2 * i + 2; }

/**
 * Returns the parent node index
 * 
 * @param i Index of node to find the right node of
 * @return The index of the right node to `i`
 */
inline int intMinHeap::parent(int i) { return (i - 1) / 2; }

/**
 * Converts an array to a integer minimum heap
*/
void intMinHeap::buildheap() {
    for (int i = this->size / 2 - 1; i >= 0; i--) {
        this->heapify(i);
    }
}

/**
 * Preserve the heap property A[i] >= A[parent(i)]
 *  
 * @param i Index of the node to apply heapify on 
 */
void intMinHeap::heapify(int i) {
    int n = this->minOf3(i, this->left(i), this->right(i));
    if (n != i) {
        this->swap(i, n);
        this->heapify(n);
    }
}
